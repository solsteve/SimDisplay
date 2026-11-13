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
 *  @file   drawable_circle.cc
 *  @author Stephen W. Soliday
 *  @date   2026-Nov-08
 *
 *  Provides the methods for a drawable polygon object.
 *  These objects are meant to be contained in a canvas display.
 */
// =======================================================================================


#include <drawable_poly.hh>


// =======================================================================================
/** Constructor.
 * @param[in] n_ number of vertices.
 * @param[in] x_ horizontal real world component.
 * @param[in] y_ vertical   real world component.
 * @param[in] t_ rotation in degrees from positive x towards positive y axis.
 */
// ---------------------------------------------------------------------------------------
nmd::DrawablePoly::DrawablePoly(const vec2& v, const real8_t t) :
    DrawableRotate(v, t),
    vertices{},
    is_closed{false}
{
  // -------------------------------------------------------------------------------------
}


// =======================================================================================
/** Destructor.
 */
// ---------------------------------------------------------------------------------------
nmd::DrawablePoly::~DrawablePoly() {
  // -------------------------------------------------------------------------------------
}


// =======================================================================================
/** Set Closed.
 * @param[in] c true == closed ploygon, false == open polyline.
 */
// ---------------------------------------------------------------------------------------
void nmd::DrawablePoly::setClosed(const bool c) {
// ---------------------------------------------------------------------------------------
  is_closed = c;
}


// =======================================================================================
/** Add Vertex.
 * @param[in] v vertex position in real world coordinates relative to the
 *              reference position.
 */
// ---------------------------------------------------------------------------------------
void nmd::DrawablePoly::add(const vec2& v) {
  vertices.push_back(v);
}


// =======================================================================================
// **                             D R A W A B L E   P O L Y                             **
// ======================================================================== END FILE =====
