// ====================================================================== BEGIN FILE =====
// **                                  D R A W A B L E                                  **
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
/** @brief  Drawable.
 *  @file   drawable.hh
 *  @author Stephen W. Soliday
 *  @date   2026-Nov-07
 *
 *  Provides the interface for a drawable object.
 *  These objects are meant to be contained in a canvas display.
 */
// =======================================================================================


#ifndef __NMD_DRAWABLE_HH
#define __NMD_DRAWABLE_HH


#include <linalg/vec2.hh>


namespace nmd {

// =======================================================================================
class Drawable {
  // -------------------------------------------------------------------------------------
 public:
  Drawable(const vec2& v);
  ~Drawable();

  void  move   (const vec2& v);
  void  setRef (const vec2& v);
  vec2& getRef ();

 protected:
  vec2 pos_xy;  // real world coordinate position of the drawable's refence point.

}; // end class Drawable


// =======================================================================================
class DrawableRotate : public Drawable {
  // -------------------------------------------------------------------------------------
 public:
  DrawableRotate   (const vec2& v, const real8_t t = 0.0e0);
  ~DrawableRotate  ();

  void    rotate      (const real8_t dt);
  void    setRotation (const real8_t t);
  real8_t getRotation () const;

 protected:
  real8_t theta;  //< rotation in degrees from positive x towards positive y axis.

}; // end class DrawableRotate






// =======================================================================================
/** Move Reference Position.
 * @param[in] d real world offset.
 *
 * Move the real world coordinate position of the drawable's refence point
 * d.x & d.y. For example, x = x + dx and y = y + dy.
 */
// ---------------------------------------------------------------------------------------
inline void Drawable::move(const vec2& d) {
  // -------------------------------------------------------------------------------------
  pos_xy.add(d);
}


// =======================================================================================
/** Set Reference Position.
 * @param[in] v real world position.
 *
 * Set the real world coordinate position of the drawable's refence point
 */
// ---------------------------------------------------------------------------------------
inline void  Drawable::setRef (const vec2& v) {
  // -------------------------------------------------------------------------------------
  pos_xy.copy(v);
}

// =======================================================================================
// ---------------------------------------------------------------------------------------
inline vec2& Drawable::getRef () {
  // -------------------------------------------------------------------------------------
  return pos_xy;
}


// =======================================================================================
/** Set Theta.
 *  @param[in] dt add rotation in degrees from positive x towards positive y axis.
 */
// ---------------------------------------------------------------------------------------
inline void DrawableRotate::rotate(const real8_t dt) {
  // -------------------------------------------------------------------------------------
  theta += dt;
}

// =======================================================================================
/** Set Theta.
 *  @param[in] t new rotation in degrees from positive x towards positive y axis.
 */
// ---------------------------------------------------------------------------------------
inline void DrawableRotate::setRotation(const real8_t t) {
  // -------------------------------------------------------------------------------------
  theta = t;
}


// =======================================================================================
/** Set Theta.
 *  @return rotation angle in degrees from positive x towards positive y axis.
 */
// ---------------------------------------------------------------------------------------
inline real8_t DrawableRotate::getRotation() const {
  // -------------------------------------------------------------------------------------
  return theta;
}


}; // end namespace nmd


#endif


// =======================================================================================
// **                                  D R A W A B L E                                  **
// ======================================================================== END FILE =====
