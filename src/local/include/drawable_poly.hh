// ====================================================================== BEGIN FILE =====
// **                             D R A W A B L E   P O L Y                             **
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
 *  Provides the interface for a drawable polygon object.
 *  These objects are meant to be contained in a canvas display.
 */
// =======================================================================================


#ifndef __NMD_DRAWABLE_POLY_HH
#define __NMD_DRAWABLE_POLY_HH


#include <vector>

#include <drawable.hh>


namespace nmd {

// =======================================================================================
class DrawablePoly : public DrawableRotate {
  // -------------------------------------------------------------------------------------
 public:
  DrawablePoly     (const vec2& v, const real8_t t = 0.0e0);

  ~DrawablePoly    ();

  void   add       (const vec2& v);
  void   setClosed (const bool  c);

  size_t size      () const;
  void   setVertex (const size_t n, const vec2& v);
  void   moveVetex (const size_t n, const vec2& v);
  vec2&  getVertex (const size_t n);

 protected:
  std::vector<vec2>  vertices;
  bool               is_closed;   //< true == closed ploygon, false == open polyline.

}; // end class DrawablePoly


// =======================================================================================
// ---------------------------------------------------------------------------------------
inline  size_t DrawablePoly::size() const {
  // -------------------------------------------------------------------------------------
  return vertices.size();
}


// =======================================================================================
// ---------------------------------------------------------------------------------------
inline  void DrawablePoly::setVertex (const size_t n, const vec2& v) {
  // -------------------------------------------------------------------------------------
  vertices.at(n).copy(v);
}


// =======================================================================================
// ---------------------------------------------------------------------------------------
inline  void DrawablePoly::moveVetex (const size_t n, const vec2& v) {
  // -------------------------------------------------------------------------------------
  vertices.at(n).add(v);
}


// =======================================================================================
// ---------------------------------------------------------------------------------------
inline  vec2& DrawablePoly::getVertex (const size_t n) {
  // -------------------------------------------------------------------------------------
  return vertices.at(n);
}


}; // end namespace nmd


#endif


// =======================================================================================
// **                             D R A W A B L E   P O L Y                             **
// ======================================================================== END FILE =====
