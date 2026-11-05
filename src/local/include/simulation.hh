// ====================================================================== BEGIN FILE =====
// **                            N M D   S I M U L A T I O N                            **
// =======================================================================================
// **                                                                                   **
// **  Copyright (c) 202y, Stephen W. Soliday                                           **
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
/** @brief  Abstract Simulation.
 *  @file   simulation.hh
 *  @author Stephen W. Soliday
 *  @date   2026-Oct-17
 *
 *  Provides the interface for the abstract simulation.
 */
// =======================================================================================


#ifndef __NMD_SIMULATION_HH
#define __NMD_SIMULATION_HH


#include <wx/wx.h>
#include <wx/timer.h>

#include <status_text.hh>
#include <frame_buffer.hh>
#include <toggle_button.hh>

#include <Thread.hh>
#include <TLogger.hh>


namespace nmd {

constexpr std::string WHITE {"#ffffff"};
constexpr std::string GRAY1 {"#dddddd"};
constexpr std::string GRAY2 {"#444444"};
constexpr std::string BLACK {"#000000"};

struct GUI_Colors {
  std::string mainFrame     = BLACK;
  std::string northPanel    = GRAY2;
  std::string centerPanel   = GRAY2;
  std::string southPanel    = GRAY2;
  std::string linesPanel    = GRAY2;
  std::string controlPanel  = GRAY1;
  std::string displayPanel  = "#0000ff";

  std::string startButtonFG = "#ffffff";
  std::string startButtonBG = "#008800";

  std::string quitButtonFG  = "#000000";
  std::string quitButtonBG  = "#ffff00";
};


class Simulation;


// =======================================================================================
struct Configuration {
  // -------------------------------------------------------------------------------------
  std::string appTitle       {"LOTR"};
  Simulation* simulation     {nullptr};
  wxTimer*    refreshTimer   {nullptr};  //< pointer to the MainFrame's timer.
  int         numRows        {768};
  int         numColumns     {1024};
  int         scale          {1};
  int         numStatLines   {2};
  int32_t     delay          {2};
  GUI_Colors  uiColors       {};
}; // end class Configuration


// =======================================================================================
class Simulation : public Thread, ToggleButton::Listener {
  // -------------------------------------------------------------------------------------
 public:
  Simulation           (Configuration* cfg);
  virtual ~Simulation  ();

  StatusText*          getStatusText          ();
  virtual int          getNumberOfButtons     () const;
  virtual wxAnyButton* getButton              (wxPanel* parent, const int n);

  virtual FrameBuffer* getFrameBuffer         (wxPanel* parent)              = 0;

  virtual void         runProcess             ()                             = 0;

  virtual wxAnyButton* getMoreButtons         (wxPanel* parent, const int n) = 0;
  virtual int          getMoreNumberOfButtons () const                       = 0;

  virtual void run     ();
  void         quitSim (wxCommandEvent&);

 protected:

  Configuration* config;      //< pointer to the shared configuration.
  StatusText*    statusText;  //< pointer to the shared status text collection.

  bool proc_running;

  TLOGGER_HEADER(logger);

  EMPTY_PROTOTYPE(Simulation);

  virtual void firstPress (const int id);
  virtual void on         (const int id);
  virtual void off        (const int id);

}; // end class Simulation


}; // end namespace nmd


#endif


// =======================================================================================
// **                            N M D   S I M U L A T I O N                            **
// ======================================================================== END FILE =====
