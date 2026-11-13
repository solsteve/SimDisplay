// ====================================================================== BEGIN FILE =====
// **                           D R A W A B L E   C I R C L E                           **
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
/** @brief  Drawable Circle.
 *  @file   drawable_circle.hh
 *  @author Stephen W. Soliday
 *  @date   2026-Nov-07
 *
 *  Provides the interface for a drawable circle object.
 *  These objects are meant to be contained in a canvas display.
 */
// =======================================================================================


#ifndef __NMD_DRAWABLE_CIRCLE_HH
#define __NMD_DRAWABLE_CIRCLE_HH


#include <drawable.hh>


namespace nmd {

// =======================================================================================
class DrawableCircle : public Drawable {
  // -------------------------------------------------------------------------------------
 public:
  DrawableCircle(const vec2& v, const real8_t r);
  ~DrawableCircle();

  void    setRadius  (const real8_t r);
  real8_t getRadius  () const;

 protected:
  real8_t radius;  //< real world radius.

}; // end class DrawableCircle


// =======================================================================================
inline  void DrawableCircle::setRadius(const real8_t r) {
  // -------------------------------------------------------------------------------------
  radius = r;
}


// =======================================================================================
inline  real8_t DrawableCircle::getRadius() const {
  // -------------------------------------------------------------------------------------
  return radius;
}


}; // end namespace nmd


#endif


// =======================================================================================
// **                           D R A W A B L E   C I R C L E                           **
// ======================================================================== END FILE =====
