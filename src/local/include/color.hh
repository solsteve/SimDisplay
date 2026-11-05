// ====================================================================== BEGIN FILE =====
// **                                     C O L O R                                     **
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
/** @brief  Color.
 *  @file   color.hh
 *  @author Stephen W. Soliday
 *  @date   2026-Oct-22
 *
 *  Provides the interface for an RGB data structure.
 */
// =======================================================================================


#ifndef __NMD_COLOR_HH
#define __NMD_COLOR_HH


#include <trncmp.hh>


namespace nmd {


// =======================================================================================
struct RGB {
  // -------------------------------------------------------------------------------------
  uint8_t red = 0;   //< red   component (0-255)
  uint8_t grn = 0;   //< green component (0-255)
  uint8_t blu = 0;   //< blue  component (0-255)
}; // end class TextConfig


}; // end namespace nmd


#endif


// =======================================================================================
// **                                     C O L O R                                     **
// ======================================================================== END FILE =====
