// ====================================================================== BEGIN FILE =====
// **                                 G R I D   D A T A                                 **
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
/** @brief  Grid Data.
 *  @file   grid_data.cc
 *  @author Stephen W. Soliday
 *  @date   2026-Oct-11
 *
 *  Provides the methods for a grid data.
 */
// =======================================================================================


#include <grid_data.hh>


// =======================================================================================
/** Constructor.
 * @param[in] nr number of rows.
 * @param[in] nc number of columns.
 */
// ---------------------------------------------------------------------------------------
nmd::GridData::GridData(const int nr, const int nc) :
    data{nr,nc},
    num_rows{nr},
    num_cols{nc},
    mtx{} {
  // -------------------------------------------------------------------------------------
}


// =======================================================================================
/** Destructor.
 */
// ---------------------------------------------------------------------------------------
nmd::GridData::~GridData(void) {
  // -------------------------------------------------------------------------------------
}


// =======================================================================================
/** Set Value.
 * @param[in] nr  number of rows.
 * @param[in] nc  number of columns.
 * @param[in] clr color index.
 */
// ---------------------------------------------------------------------------------------
void nmd::GridData::set(const int ir, const int ic, const int clr) {
  // -------------------------------------------------------------------------------------
  mtx.lock();
  data.set(ir, ic, clr);
  mtx.unlock();
}


// =======================================================================================
/** Get Value.
 * @param[in] nr  number of rows.
 * @param[in] nc  number of columns.
 * @return clr color index.
 */
// ---------------------------------------------------------------------------------------
int nmd::GridData::get(const int ir, const int ic) {
  // -------------------------------------------------------------------------------------
  mtx.lock();
  const int c =  data.get(ir,ic);
  mtx.unlock();
  return c;
}


// =======================================================================================
/** Clear Data.
 * @param[in] clr color index.
 */
// ---------------------------------------------------------------------------------------
void nmd::GridData::clear(const int clr) {
  // -------------------------------------------------------------------------------------
  mtx.lock();
  data.clear(clr);
  mtx.unlock();
}


// =======================================================================================
// **                                 G R I D   D A T A                                 **
// ======================================================================== END FILE =====
