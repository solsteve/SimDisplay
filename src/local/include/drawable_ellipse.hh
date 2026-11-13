// ====================================================================== BEGIN FILE =====
// **                          D R A W A B L E   E L L I P S E                          **
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
/** @brief  Drawable Ellipse.
 *  @file   drawable_ellipse.hh
 *  @author Stephen W. Soliday
 *  @date   2026-Nov-11
 *
 *  Provides the interface for a drawable ellipse object.
 *  These objects are meant to be contained in a canvas display.
 */
// =======================================================================================


#ifndef __NMD_DRAWABLE_ELLIPSE_HH
#define __NMD_DRAWABLE_ELLIPSE_HH


#include <drawable_poly.hh>


namespace nmd {

// =======================================================================================
class DrawableEllipse : public DrawablePoly {
  // -------------------------------------------------------------------------------------
 public:
  DrawableEllipse  (const vec2& p, const vec2& d, const real8_t t, const size_t n);

  DrawableEllipse  (const vec2& p, const vec2& d, const real8_t t);

  DrawableEllipse  (const vec2& p, const vec2& d,                  const size_t n);

  DrawableEllipse  (const vec2& p, const vec2& d);

  ~DrawableEllipse ();

  void    setDims      (const vec2& d);
  real8_t getSemiMajor () const;
  real8_t getSemiMinor () const;

 protected:
  real8_t a;
  real8_t b;
  bool    has_init;
  size_t  npts;

  void build();

}; // end class DrawablePoly


// =======================================================================================
inline  void DrawableEllipse::setDims(const vec2& d) {
  // -------------------------------------------------------------------------------------
  a = d.x;
  b = d.y;
  build();
}

// =======================================================================================
inline  real8_t DrawableEllipse::getSemiMajor() const {
  // -------------------------------------------------------------------------------------
  return a;
}

// =======================================================================================
inline  real8_t DrawableEllipse::getSemiMinor() const {
  // -------------------------------------------------------------------------------------
  return b;
}


}; // end namespace nmd


#endif


// =======================================================================================
// **                          D R A W A B L E   E L L I P S E                          **
// ======================================================================== END FILE =====
