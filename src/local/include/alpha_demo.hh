// ====================================================================== BEGIN FILE =====
// **                                A L P H A   D E M O                                **
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
/** @brief  Alpha Demo.
 *  @file   alpha_demo.hh
 *  @author Stephen W. Soliday
 *  @date   2026-Oct-17
 *
 *  Provides the interface for.
 */
// =======================================================================================

#ifndef __NMD_ALPHADEMO_HH
#define __NMD_ALPHADEMO_HH

#include <simulation.hh>
#include <screen_buffer.hh>
#include <rgb_pallet.hh>

namespace nmd {


// =======================================================================================
class AlphaDemo : public Simulation {
  // -------------------------------------------------------------------------------------
 protected:

  int32_t       delay;
  ScreenBuffer* grid;
  RGB_Pallet*   pallet;

  EMPTY_PROTOTYPE(AlphaDemo);

 public:
  AlphaDemo(Configuration* cfg);
  virtual ~AlphaDemo();

  virtual int          getMoreNumberOfButtons () const;
  virtual wxAnyButton* getMoreButtons         (wxPanel* parent, const int n);

  virtual FrameBuffer* getFrameBuffer         (wxPanel* parent);

  virtual void         runProcess             ();

}; // end class AlphaDemo


}; // end namespace nmd


#endif


// =======================================================================================
// **                                A L P H A   D E M O                                **
// ======================================================================== END FILE =====
