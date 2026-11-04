// ====================================================================== BEGIN FILE =====
// **                                R G B   P A L L E T                                **
// =======================================================================================
// **                                                                                   **
// **  Copyright (c) 2026, Stephen W. Soliday                                           **
// **                      stephen.soliday@trncmp.org                                   **
// **                      http://research.trncmp.org                                   **
// **                                                                                   **
// **  -------------------------------------------------------------------------------  **
// **                                                                                   **
// **  This program is free software: you can redistribute it and/or modify it under    **
// **  the terms of the GNU General Public License as published by the Free Software    **
// **  Foundation, either version 3 of the License, or (at your option)                 **
// **  any later version.                                                               **
// **                                                                                   **
// **  This program is distributed in the hope that it will be useful, but WITHOUT      **
// **  ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS    **
// **  FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.   **
// **                                                                                   **
// **  You should have received a copy of the GNU General Public License along with     **
// **  this program. If not, see <http://www.gnu.org/licenses/>.                        **
// **                                                                                   **
// ----- Modification History ------------------------------------------------------------
//
/** @brief  RGB Pallet
 *  @file   rgb_pallet.cc
 *  @author Stephen W. Soliday
 *  @date   2026-Oct-13
 *
 *  Provides methods for a custom RGB pallet.
 */
// =======================================================================================

#include <rgb_pallet.hh>

// =======================================================================================
nmd::RGB_Pallet::RGB_Pallet(const int n) : color_table{nullptr}, max_colors{n} {
  // -------------------------------------------------------------------------------------
  color_table = new nmd::rgb_s[n];
}


// =======================================================================================
nmd::RGB_Pallet::~RGB_Pallet() {
  // -------------------------------------------------------------------------------------
  delete[] color_table;
}


// =======================================================================================
// **                                R G B   P A L L E T                                **
// ======================================================================== END FILE =====
