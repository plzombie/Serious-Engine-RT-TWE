/* Copyright (c) 2002-2012 Croteam Ltd.
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

#ifndef SE_INCL_GAME_MENU_VIDEOOPTIONS_H
#define SE_INCL_GAME_MENU_VIDEOOPTIONS_H
#ifdef PRAGMA_ONCE
  #pragma once
#endif

#include "GameMenu.h"


class CVideoOptionsMenu : public CGameMenu {
public:
  CMGTitle gm_mgTitle;
  CMGTrigger gm_mgDisplayAPITrigger;
  CMGTrigger gm_mgDisplayAdaptersTrigger;
  CMGTrigger gm_mgFullScreenTrigger;
  CMGTrigger gm_mgResolutionsTrigger;
#ifdef SE1_RAYTRACING
  CMGTrigger gm_mgNvDlssTrigger;
  CMGTrigger gm_mgAmdFsrTrigger;
  CMGTrigger gm_mgRenderScaleTrigger;
  CMGTrigger gm_mgCPUPerformanceTrigger;
#endif
  CMGTrigger gm_mgDisplayPrefsTrigger;
  CMGButton gm_mgVideoRendering;
  CMGTrigger gm_mgBitsPerPixelTrigger;
  CMGButton gm_mgApply;

  void StartMenu(void);
  void Initialize_t(void);
};

#endif  /* include-once check. */