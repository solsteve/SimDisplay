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
 *  @file   drawable.cc
 *  @author Stephen W. Soliday
 *  @date   2026-Nov-08
 *
 *  Provides the methods for a drawable object.
 *  These objects are meant to be contained in a canvas display.
 */
// =======================================================================================


#include <drawable.hh>


// =======================================================================================
/**Constructor.
 * @param[in] v real world coordinate position of the drawable's refence point.
 */
// ---------------------------------------------------------------------------------------
nmd::Drawable::Drawable(const vec2& v) : pos_xy{v} {
  // -------------------------------------------------------------------------------------
}


// =======================================================================================
/** Destructor.
 */
// ---------------------------------------------------------------------------------------
nmd::Drawable::~Drawable() {
  // -------------------------------------------------------------------------------------
}


// =======================================================================================
/** Constructor.
 * @param[in] v real world coordinate position of the drawable's refence point.
 * @param[in] t rotation in degrees from positive x towards positive y axis.
 */
// ---------------------------------------------------------------------------------------
nmd::DrawableRotate::DrawableRotate(const vec2& v, const real8_t t) :
    Drawable(v),
    theta{t}
{
  // -------------------------------------------------------------------------------------
}


// =======================================================================================
/** Destructor.
 */
// ---------------------------------------------------------------------------------------
nmd::DrawableRotate::~DrawableRotate() {
  // -------------------------------------------------------------------------------------
}


// =======================================================================================
// **                                  D R A W A B L E                                  **
// ======================================================================== END FILE =====
