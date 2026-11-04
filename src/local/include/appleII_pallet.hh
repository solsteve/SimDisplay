// ====================================================================== BEGIN FILE =====
// **                           A P P L E   I I   P A L L E T                           **
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
 *  @file   appleII_pallet.hh
 *  @author Stephen W. Soliday
 *  @date   2026-Oct-13
 *
 *  Provides an interface for a custom Apple II pallet.
 */
// =======================================================================================

#ifndef __APPLEII_PALLET_HH
#define __APPLEII_PALLET_HH

#include <rgb_pallet.hh>


namespace nmd {


// =======================================================================================
class AppleII_Pallet : public RGB_Pallet {
  // -------------------------------------------------------------------------------------
 public:
  AppleII_Pallet          ();
  virtual ~AppleII_Pallet ();
}; // end class AppleII_Pallet


}; // end namespace nmd


#endif


// =======================================================================================
// **                           A P P L E   I I   P A L L E T                           **
// ======================================================================== END FILE =====
