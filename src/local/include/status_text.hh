// ====================================================================== BEGIN FILE =====
// **                               S T A T U S   T E X T                               **
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
/** @brief  Status  text.
 *  @file   status_text.hh
 *  @author Stephen W. Soliday
 *  @date   2026-Oct-24
 *
 *  Provides the interface for.
 */
// =======================================================================================

#ifndef __NMD_STATUS_TEXT_HH
#define __NMD_STATUS_TEXT_HH

#include <wx/wx.h>

#include <text_config.hh>
#include <TLogger.hh>


namespace nmd {

// =======================================================================================
enum class TextPos {
  // -------------------------------------------------------------------------------------
  NORTH,
  SOUTH,
  NW,
  NE,
  SW,
  SE
};


// =======================================================================================
class StatusText {
  // -------------------------------------------------------------------------------------
 protected:
  TextConfig  north;
  TextConfig  south;
  TextConfig  ne;
  TextConfig  nw;
  TextConfig  se;
  TextConfig  sw;
  TextConfig* lines;
  int         num_lines;

  EMPTY_PROTOTYPE(StatusText);

  TLOGGER_HEADER(logger);

 public:
  StatusText         (const int n);
  ~StatusText        ();

  int  size          () const { return num_lines; };

  void setTextCtrl   (TextPos pos, wxTextCtrl* tp);
  void setText       (TextPos pos, const std::string& str);
  void setForeground (TextPos pos, const uint8_t r, const uint8_t g, const uint8_t b);
  void setBackground (TextPos pos, const uint8_t r, const uint8_t g, const uint8_t b);

  void setTextCtrl   (const int n, wxTextCtrl* tp);
  void setText       (const int n, const std::string& str);
  void setForeground (const int n, const uint8_t r, const uint8_t g, const uint8_t b);
  void setBackground (const int n, const uint8_t r, const uint8_t g, const uint8_t b);

  void updateText();
 
}; // end class StatusText


}; // end namespace nmd



#endif


// =======================================================================================
// **                               S T A T U S   T E X T                               **
// ======================================================================== END FILE =====
