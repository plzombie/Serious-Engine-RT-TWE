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

#include <Engine/Math/Vector.h>

namespace SSRT
{
class Scene;
class CustomInfo;
class TextureUploader;
}

class CRenderModel;

void RT_AddBrushEntity(CEntity *penBrush, SSRT::Scene *pScene);
void RT_AddRasterizedBrushEntity(CEntity *penBrush, SSRT::Scene *pScene);
void RT_UpdateBrushNonStaticTexture(CEntity *penBrush, SSRT::Scene *pScene);
void RT_CheckWarpPortalsAndMirrors(CEntity *penBrush, SSRT::Scene *pScene);
void RT_UpdateBrushTexCoords(CEntity *penBrush, SSRT::Scene *pScene);
void RT_BrushProcessingClear();
void RT_PrintBrushPolygonInfo(SSRT::Scene *pScene);

void RT_AddModelEntity(CEntity *penModel, SSRT::Scene *pScene);
void RT_AddFirstPersonModel(CModelObject *mo, CRenderModel *rm, ULONG entityId, SSRT::Scene *pScene);
void RT_AddModelEntitiesAroundViewer(SSRT::Scene *pScene);

void RT_ProcessModelLights(CEntity *penModel, SSRT::Scene *pScene);
void RT_AddPotentialLightSources(SSRT::Scene *pScene);


// Process particles to be added to the scene.
// It calls CEntity::RenderParticles function for each model entity,
// which calls RT_Particle_* functions that are defined down below. 
void RT_AddParticlesForEntity(CEntity *pTargetEntity, SSRT::Scene *pScene);
void RT_Particle_PrepareTexture(CTextureObject *pto, enum ParticleBlendType pbt);
void RT_Particle_SetTexturePart(MEX mexWidth, MEX mexHeight, INDEX iCol, INDEX iRow);
void RT_Particle_RenderSquare(const FLOAT3D &vPos, FLOAT fSize, ANGLE aRotation, COLOR col, FLOAT fYRatio);
void RT_Particle_RenderLine(const FLOAT3D &vPos0, const FLOAT3D &vPos1, FLOAT fWidth, COLOR col);
void RT_Particle_RenderQuad3D(const FLOAT3D &vPos0, const FLOAT3D &vPos1, const FLOAT3D &vPos2, const FLOAT3D &vPos3, COLOR col);
void RT_Particle_Flush();

void RT_SetCustomInfoForTextures(SSRT::CustomInfo *pCustomInfo);
unsigned RT_SetTextureAsCurrent(CTextureData *textureData, SSRT::TextureUploader *uploader);
