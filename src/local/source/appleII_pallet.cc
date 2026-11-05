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
/** @brief  Apple II Pallet
 *  @file   appleII_pallet.cc
 *  @author Stephen W. Soliday
 *  @date   2026-Oct-13
 *
 *  Provides the methods for a custom Apple II pallet.
 */
// =======================================================================================


#include <appleII_pallet.hh>


// =======================================================================================
/** Constructor
 */
// ---------------------------------------------------------------------------------------
nmd::AppleII_Pallet::AppleII_Pallet() : nmd::RGB_Pallet(15) {
  // -------------------------------------------------------------------------------------
  this->set( 0, 0x00, 0x00, 0x00);   // Black
  this->set( 1, 0x51, 0x5C, 0x16);   // Olive
  this->set( 2, 0x84, 0x3D, 0x52);   // Magenta
  this->set( 3, 0xEA, 0x7D, 0x27);   // Orange
  this->set( 4, 0x51, 0x48, 0x88);   // Purple
  this->set( 5, 0xE8, 0x5D, 0xEF);   // Pink
  this->set( 6, 0xF5, 0xB7, 0xC9);   // LightPink
  this->set( 7, 0x00, 0x67, 0x52);   // Green"
  this->set( 8, 0x00, 0xC8, 0x2C);   // BrightGreen
  this->set( 9, 0x91, 0x91, 0x91);   // Gray
  this->set(10, 0xC9, 0xD1, 0x99);   // LightOlive
  this->set(11, 0x00, 0xA6, 0xF0);   // Blue
  this->set(12, 0x98, 0xDB, 0xC9);   // Cyan
  this->set(13, 0xC8, 0xC1, 0xF7);   // LightPurple
  this->set(14, 0xFF, 0xFF, 0xFF);   // White
}


// =======================================================================================
/** Destructor
 */
// ---------------------------------------------------------------------------------------
nmd::AppleII_Pallet::~AppleII_Pallet() {
  // -------------------------------------------------------------------------------------
}


// =======================================================================================
// **                                R G B   P A L L E T                                **
// ======================================================================== END FILE =====
