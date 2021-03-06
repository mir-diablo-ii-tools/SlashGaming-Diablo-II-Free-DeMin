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

#include "required_patches.hpp"

#include "d2win_disable_auto_minimize_patch/d2win_disable_auto_minimize_patch.hpp"

namespace sgd2fdmn::patches {

std::vector<mapi::GamePatch> MakeRequiredPatches() {
  std::vector<mapi::GamePatch> game_patches;

  std::vector d2win_disable_auto_minimize_patch =
      Make_D2Win_DisableAutoMinimizePatch();
  game_patches.insert(
      game_patches.end(),
      std::make_move_iterator(d2win_disable_auto_minimize_patch.begin()),
      std::make_move_iterator(d2win_disable_auto_minimize_patch.end())
  );

  return game_patches;
}

} // namespace sgd2fdmn::patches
