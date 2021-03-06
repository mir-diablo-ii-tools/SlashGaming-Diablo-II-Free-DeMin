/**
 * SlashGaming Diablo II Free DeMin
 * Copyright (C) 2020  Mir Drualga
 *
 * This file is part of SlashGaming Diablo II Free DeMin.
 *
 *  This program is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU Affero General Public License as published
 *  by the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU Affero General Public License for more details.
 *
 *  You should have received a copy of the GNU Affero General Public License
 *  along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 *  Additional permissions under GNU Affero General Public License version 3
 *  section 7
 *
 *  If you modify this Program, or any covered work, by linking or combining
 *  it with Diablo II (or a modified version of that game and its
 *  libraries), containing parts covered by the terms of Blizzard End User
 *  License Agreement, the licensors of this Program grant you additional
 *  permission to convey the resulting work. This additional permission is
 *  also extended to any combination of expansions, mods, and remasters of
 *  the game.
 *
 *  If you modify this Program, or any covered work, by linking or combining
 *  it with any Graphics Device Interface (GDI), DirectDraw, Direct3D,
 *  Glide, OpenGL, or Rave wrapper (or modified versions of those
 *  libraries), containing parts not covered by a compatible license, the
 *  licensors of this Program grant you additional permission to convey the
 *  resulting work.
 *
 *  If you modify this Program, or any covered work, by linking or combining
 *  it with any library (or a modified version of that library) that links
 *  to Diablo II (or a modified version of that game and its libraries),
 *  containing parts not covered by a compatible license, the licensors of
 *  this Program grant you additional permission to convey the resulting
 *  work.
 */

#include "d2win_disable_auto_minimize_patch_1_03.hpp"

#include "../../../asm_x86_macro.h"
#include "d2win_disable_auto_minimize.hpp"

namespace sgd2fdmn::patches {
namespace {

__declspec(naked) void __cdecl InterceptionFunc_01() {
  // Original code.
  ASM_X86(mov eax, dword ptr [esi + 8]);

  ASM_X86(push ebp);
  ASM_X86(mov ebp, esp);

  ASM_X86(push ecx);
  ASM_X86(push edx);

  ASM_X86(push eax);
  ASM_X86(call ASM_X86_FUNC(SGD2FDMN_D2Win_ShouldSetMinimize));
  ASM_X86(add esp, 4);

  ASM_X86(pop edx);
  ASM_X86(pop ecx);

  // Original code, but building on the previous function.
  ASM_X86(cmp eax, 1);

  ASM_X86(leave);
  ASM_X86(ret);
}

} // namespace

std::vector<mapi::GamePatch> Make_D2Win_DisableAutoMinimizePatch_1_03() {
  std::vector<mapi::GamePatch> patches;

  // Add additional check before choosing to minimize the window.
  mapi::GameAddress game_address_01 = mapi::GameAddress::FromOffset(
      mapi::DefaultLibrary::kD2Win,
      0xFDE5
  );

  patches.push_back(
      mapi::GamePatch::MakeGameBranchPatch(
          std::move(game_address_01),
          mapi::BranchType::kCall,
          InterceptionFunc_01,
          0xFDEA - 0xFDE5
      )
  );

  return patches;
}

} // namespace sgd2fdmn::patches
