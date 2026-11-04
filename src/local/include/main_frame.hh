// ====================================================================== BEGIN FILE =====
// **                                M A I N   F R A M E                                **
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
/** @brief  Main Appplication Frame
 *  @file   main_frame.hh
 *  @author Stephen W. Soliday
 *  @date   2026-Oct-15
 *
 *  Provides an interface for the main application frame.
 */
// =======================================================================================

#ifndef __MAIN_FRAME_HH
#define __MAIN_FRAME_HH

#include <wx/wx.h>
#include <wx/timer.h>

#include <simulation.hh>

namespace nmd {


// =======================================================================================
class MainFrame : public wxFrame {
  // -------------------------------------------------------------------------------------
 public:
  MainFrame(Configuration* cfg);

 protected:

  Configuration* config;
  Simulation*    sim_thread;
  FrameBuffer*   frameBuffer;
  StatusText*    statusText;
  int            n_stat_lines;
  wxTimer        refreshTimer;

  void OnRefreshTimer  (wxTimerEvent& event);

  EMPTY_PROTOTYPE(MainFrame);

}; // end class MainFrame


}; // end namespace nmd


#endif


// =======================================================================================
// **                                M A I N   F R A M E                                **
// ======================================================================== END FILE =====
