// ====================================================================== BEGIN FILE =====
// **                             S C R E E N   B U F F E R                             **
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
/** @brief  Screen Buffer.
 *  @file   screen_buffer.hh
 *  @author Stephen W. Soliday
 *  @date   2026-Oct-11
 *
 *  Provides the interface for a screen buffer.
 */
// =======================================================================================


#ifndef __SCREEN_BUFFER_HH
#define __SCREEN_BUFFER_HH


#include <Array2D.hh>
#include <mutex>          // std::mutex


namespace nmd {


// =======================================================================================
class ScreenBuffer {
  // -------------------------------------------------------------------------------------
 public:
  ScreenBuffer  (const int nr, const int nc);
  ~ScreenBuffer (void);

  void  set     (const int ir, const int ic, const int clr);
  int   get     (const int ir, const int ic);
  int   size    (const int d=0) const;
  void  clear   (const int clr = 0);


 protected:
  Array2D<int,int> data;      //< grid data.
  int              num_rows;  //< number of grid rows.
  int              num_cols;  //< number of grid columns.
  std::mutex       mtx;       //< thread synchonizing mutex.

}; // end class ScreenBuffer


// =======================================================================================
/** Size.
 * @param[in] dimension.
 * @return size of dimension 0==rows, 1==columns.
 */
// ---------------------------------------------------------------------------------------
inline int ScreenBuffer::size(const int d) const {
  // -------------------------------------------------------------------------------------
  return ((0==d)?(num_rows):(num_cols));
}


}; // end namespace nmd


#endif


// =======================================================================================
// **                             S C R E E N   B U F F E R                             **
// ======================================================================== END FILE =====
