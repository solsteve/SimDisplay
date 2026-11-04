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
 *  Provides an interface for a custom RGB pallet.
 */
// =======================================================================================

#ifndef __RGB_PALLET_HH
#define __RGB_PALLET_HH

#include <trncmp.hh>


namespace nmd {


// =======================================================================================
struct rgb_s {
  // -------------------------------------------------------------------------------------
  unsigned char red;
  unsigned char grn;
  unsigned char blu;
}; // end struct RGB


// =======================================================================================
class RGB_Pallet {
  // -------------------------------------------------------------------------------------
 protected:
  rgb_s* color_table;
  int    max_colors;

  EMPTY_PROTOTYPE(RGB_Pallet);


 public:
  RGB_Pallet          (const int n);
  virtual ~RGB_Pallet ();

  void  set  (const int n,
              const unsigned char r, const unsigned char g, const unsigned char b);
  rgb_s get  (const int n) const;
  int   size () const;

}; // end class RGB_Pallet


// =======================================================================================
inline  void RGB_Pallet::set(const int n,
                 const unsigned char r, const unsigned char g, const unsigned char b) {
  // -------------------------------------------------------------------------------------
  const int i = n % max_colors;
  color_table[i].red = r;
  color_table[i].grn = g;
  color_table[i].blu = b;
}


// =======================================================================================
inline  rgb_s RGB_Pallet::get(const int n) const {
  // -------------------------------------------------------------------------------------
  return color_table[n % max_colors];
}


// =======================================================================================
inline  int RGB_Pallet::size() const {
  // -------------------------------------------------------------------------------------
  return max_colors;
}


}; // end namespace nmd


#endif


// =======================================================================================
// **                                R G B   P A L L E T                                **
// ======================================================================== END FILE =====
