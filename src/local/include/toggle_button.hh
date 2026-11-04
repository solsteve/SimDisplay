// ====================================================================== BEGIN FILE =====
// **                         N M D   T O G G L E   B U T T O N                         **
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
/** @brief  Toggle Button.
 *  @file   toggle_button.hh
 *  @author Stephen W. Soliday
 *  @date   2026-Nov-03
 *
 *  Provides the interface for a toggle button.
 */
// =======================================================================================

#ifndef __NMD_TOGGLEBUTTON_HH
#define __NMD_TOGGLEBUTTON_HH

#include <wx/wx.h>

#include <TLogger.hh>

namespace nmd {


// =======================================================================================
class ToggleButton : public wxButton {
  // -------------------------------------------------------------------------------------
 public:
  
  // =====================================================================================
  class Listener {
    // -----------------------------------------------------------------------------------
   public:
    Listener();
    virtual ~Listener();
    virtual void firstPress(const int id) = 0;
    virtual void on(const int id)         = 0;
    virtual void off(const int id)        = 0;
  }; // end class ToggleButton::Listener




  ToggleButton  (wxPanel* parent, const int id=0);
  ~ToggleButton ();

  void setListener(nmd::ToggleButton::Listener* L);

  void setOnText  (const std::string& text, const std::string& fg, const std::string& bg);
  void setOffText (const std::string& text, const std::string& fg, const std::string& bg);

 protected:
  Listener*   button_listener;
  int         button_id;

  std::string on_text;
  wxColor     on_foreground;
  wxColor     on_background;

  std::string off_text;
  wxColor     off_foreground;
  wxColor     off_background;

  bool        first_press;
  bool        onState; // true = waiting for on press

  void buttonPressed(wxCommandEvent& event);

  TLOGGER_HEADER(logger);

  EMPTY_PROTOTYPE(ToggleButton);

}; // end class ToggleButton


}; // end namespace nmd


#endif


// =======================================================================================
// **                         N M D   T O G G L E   B U T T O N                         **
// ======================================================================== END FILE =====
