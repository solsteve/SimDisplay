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
 *  @file   rgb_pallet.hh
 *  @author Stephen W. Soliday
 *  @date   2026-Oct-13
 *
 *  Provides the interface for a custom RGB pallet.
 */
// =======================================================================================


#ifndef __RGB_PALLET_HH
#define __RGB_PALLET_HH


#include <trncmp.hh>


namespace nmd {


// =======================================================================================
struct rgb_s {
  // -------------------------------------------------------------------------------------
  unsigned char red;   //< red   component (0-255)
  unsigned char grn;   //< green component (0-255)
  unsigned char blu;   //< blue  component (0-255)
}; // end struct RGB


// =======================================================================================
class RGB_Pallet {
  // -------------------------------------------------------------------------------------
 public:
  RGB_Pallet          (const int n);
  virtual ~RGB_Pallet ();

  void  set  (const int n,
              const unsigned char r, const unsigned char g, const unsigned char b);
  rgb_s get  (const int n) const;
  int   size () const;


 protected:
  rgb_s* color_table;  //< table of RGB values.
  int    max_colors;   //< number of table entries.

  EMPTY_PROTOTYPE(RGB_Pallet);

}; // end class RGB_Pallet


// =======================================================================================
/** Set Color.
 * @param[in] n color index.
 * @param[in] r red   component value.
 * @param[in] g green component value.
 * @param[in] b blue  component value.
 *
 * Set a table entry with an RGB value.
 */
// ---------------------------------------------------------------------------------------
inline  void RGB_Pallet::set(const int n,
                             const unsigned char r, const unsigned char g, const unsigned char b) {
  // -------------------------------------------------------------------------------------
  const int i = n % max_colors;
  color_table[i].red = r;
  color_table[i].grn = g;
  color_table[i].blu = b;
}


// =======================================================================================
/** Get Color
 * @param[in] n color index.
 * @return rgb structure intance.
 */
// ---------------------------------------------------------------------------------------
inline  rgb_s RGB_Pallet::get(const int n) const {
  // -------------------------------------------------------------------------------------
  return color_table[n % max_colors];
}


// =======================================================================================
/** Size.
 * @return number of colors in the pallet.
 */
// ---------------------------------------------------------------------------------------
inline  int RGB_Pallet::size() const {
  // -------------------------------------------------------------------------------------
  return max_colors;
}


}; // end namespace nmd


#endif


// =======================================================================================
// **                                R G B   P A L L E T                                **
// ======================================================================== END FILE =====
