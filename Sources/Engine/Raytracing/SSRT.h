/* Copyright (c) 2020-2021 Sultim Tsyrendashiev
This program is free software; you can redistribute it and/or modify
it under the terms of version 2 of the GNU General Public License as published by
the Free Software Foundation


This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License along
with this program; if not, write to the Free Software Foundation, Inc.,
51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA. */

#pragma once

#include <Engine/Entities/Entity.h>
#include <Engine/Brushes/Brush.h>

#include <Engine/Raytracing/Scene.h>
#include <Engine/Raytracing/TextureUploader.h>

#include <RTGL1/RTGL1.h>


namespace SSRT
{
class SSRTMain
{
public:
  SSRTMain();
  ~SSRTMain();

  SSRTMain(const SSRTMain &other) = delete;
  SSRTMain(SSRTMain &&other) noexcept = delete;
  SSRTMain &operator=(const SSRTMain &other) = delete;
  SSRTMain &operator=(SSRTMain &&other) noexcept = delete;

  void StartFrame(CViewPort *pvp);

  // Process world geometry: build acceleration structures and reload textures 
  // when required (always for dynamic objects, once for static).
  // Must be called every frame if the world is visible
  void ProcessWorld(const CWorldRenderingInfo &info);
  // First person models are rendered directly from .es script,
  // so a separate function is required to handle this
  void ProcessFirstPersonModel(const CFirstPersonModelInfo &info);
  // HUD elements will be drawn using rasterization
  void ProcessHudElement(const CHudElementInfo &hud);
  void ProcessLensFlare(const CHudElementInfo &hud, const FLOAT3D &pointToCheck);

  void EndFrame();
  void NotifyGameStopped();

  // Functions for GFX wrapper
  void SetProjectionMatrix(const float *pMatrix);
  void SetViewMatrix(const float *pMatrix);
  void SetViewport(float leftUpperX, float leftUpperY, float width, float height, float minDepth, float maxDepth);
  void DeleteTexture(uint32_t textureID);

  // Called on GfxLibrary initialization
  static void InitShellVariables();
  static void NormalizeShellVariables();

private:
  CWorldRenderingInfo   worldRenderInfo;

  Scene                 *currentScene;
  bool                  wasWorldProcessed;

  // each first person model (left, right revolver, other weapons) should have its 
  // fake entity to attach to, this counter will be used to simulate ID for fake entity
  ULONG                 currentFirstPersonModelCount;

  bool                  isFrameStarted;
  uint32_t              curWindowWidth, curWindowHeight;

  // this matrices are used for rasterized geometry, such as HUD
  float                 projMatrix[16];
  float                 viewMatrix[16];
  RgViewport            currentViewport;

  TextureUploader       *textureUploader;

  RgInstance            instance;
};

}