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
 *  Provides the interface for the main application frame.
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

  Configuration* config;        //< pointer to the shared configuration.
  Simulation*    sim_thread;    //< pointer to the shared simulation thread.
  FrameBuffer*   frameBuffer;   //< pointer to the shared display panel.
  StatusText*    statusText;    //< pointer to the shared status text collection.
  int            n_stat_lines;  //< number of status lines.
  wxTimer        refreshTimer;  //< original instance of the GUI timer.

  void OnRefreshTimer  (wxTimerEvent& event);

  EMPTY_PROTOTYPE(MainFrame);

}; // end class MainFrame


}; // end namespace nmd


#endif


// =======================================================================================
// **                                M A I N   F R A M E                                **
// ======================================================================== END FILE =====
