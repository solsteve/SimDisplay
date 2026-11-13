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
 *  @file   drawable_ellipse.cc
 *  @author Stephen W. Soliday
 *  @date   2026-Nov-11
 *
 *  Provides the interface for a drawable ellipse object.
 *  These objects are meant to be contained in a canvas display.
 */
// =======================================================================================


#include <drawable_ellipse.hh>



// =======================================================================================
/** Constructor.
 * @param[in] x_ horizontal real world component.
 * @param[in] y_ vertical   real world component.
 * @param[in] a_ semi-major axis in real world units.
 * @param[in] b_ semi-minor axis in real world units.
 * @param[in] t_ rotation in degrees from positive x towards positive y axis.
 * @param[in] n_ number of vertices.
 */
// ---------------------------------------------------------------------------------------
nmd::DrawableEllipse::DrawableEllipse(const vec2&   p, const vec2&  d,
                                      const real8_t t, const size_t n) :
    DrawablePoly(p, t),
    a{d.x},
    b{d.y},
    has_init{false},
    npts{n}
{
  // -------------------------------------------------------------------------------------
  build();
}


// =======================================================================================
/** Constructor.
 * @param[in] x_ horizontal real world component.
 * @param[in] y_ vertical   real world component.
 * @param[in] a_ semi-major axis in real world units.
 * @param[in] b_ semi-minor axis in real world units.
 * @param[in] n_ number of vertices.
 */
// ---------------------------------------------------------------------------------------
nmd::DrawableEllipse::DrawableEllipse(const vec2& p, const vec2& d, const real8_t t) :
    DrawablePoly(p, t),
    a{d.x},
    b{d.y},
    has_init{false},
    npts{32}
{
  // -------------------------------------------------------------------------------------
  build();
}


// =======================================================================================
/** Constructor.
 * @param[in] x_ horizontal real world component.
 * @param[in] y_ vertical   real world component.
 * @param[in] a_ semi-major axis in real world units.
 * @param[in] b_ semi-minor axis in real world units.
 * @param[in] t_ rotation in degrees from positive x towards positive y axis.
 */
// ---------------------------------------------------------------------------------------
nmd::DrawableEllipse::DrawableEllipse(const vec2& p, const vec2& d, const size_t n) :
    DrawablePoly(p, 0.0e0),
    a{d.x},
    b{d.y},
    has_init{false},
    npts{n}
{
  // -------------------------------------------------------------------------------------
  build();
}


// =======================================================================================
/** Constructor.
 * @param[in] x_ horizontal real world component.
 * @param[in] y_ vertical   real world component.
 * @param[in] a_ semi-major axis in real world units.
 * @param[in] b_ semi-minor axis in real world units.
 */
// ---------------------------------------------------------------------------------------
nmd::DrawableEllipse::DrawableEllipse(const vec2& p, const vec2& d) :
    DrawablePoly(p, 0.0e0),
    a{d.x},
    b{d.y},
    has_init{false},
    npts{32}
{
  // -------------------------------------------------------------------------------------
  build();
}


// =======================================================================================
/** Destructor.
 */
// ---------------------------------------------------------------------------------------
nmd::DrawableEllipse::~DrawableEllipse() {
  // -------------------------------------------------------------------------------------
}


// =======================================================================================
/** Build Vertices.
 */
// ---------------------------------------------------------------------------------------
void nmd::DrawableEllipse::build() {
  // -------------------------------------------------------------------------------------
  is_closed = true;

  real8_t t = D_ZERO;
  const real8_t dt = D_2PI / static_cast<real8_t>(npts);

  if (has_init) {
    for (size_t i=0; i<npts; i++) {
      add(vec2{a * cos(t), b * sin(t)});
      t += dt;
    }
  } else {
    has_init = true;
    for (size_t i=0; i<npts; i++) {
      setVertex(i, vec2{a * cos(t), b * sin(t)});
      t += dt;
    }
  }

}


// =======================================================================================
// **                          D R A W A B L E   E L L I P S E                          **
// ======================================================================== END FILE =====
