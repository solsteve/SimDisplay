// ====================================================================== BEGIN FILE =====
// **                               T E X T   C O N F I G                               **
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
/** @brief  Text Configuration.
 *  @file   text_config.hh
 *  @author Stephen W. Soliday
 *  @date   2026-Oct-22
 *
 *  Provides the interface for.
 */
// =======================================================================================

#ifndef __NMD_TEXTCONFIG_HH
#define __NMD_TEXTCONFIG_HH

#include <wx/wx.h>

#include <mutex>

#include <atomic>
#include <color.hh>


namespace nmd {


// =======================================================================================
class TextConfig {
  // -------------------------------------------------------------------------------------
 protected:
  std::string buffer;
  RGB               foreground;
  RGB               background;
  std::atomic<bool> buffer_changed;      // true if the set was called for the buffer
  std::atomic<bool> foreground_changed;  // true if the set was called for the foreground
  std::atomic<bool> background_changed;  // true if the set was called for the background
  wxTextCtrl*       textCtrl;

  std::mutex        mtx;

  EMPTY_PROTOTYPE(TextConfig);

 public:
  TextConfig         ();
  ~TextConfig        ();

  void setTextCtrl   (wxTextCtrl* tp) { textCtrl = tp; };

  void setText       (const std::string& str);
  void setForeground (const uint8_t r, const uint8_t g, const uint8_t b);
  void setBackground (const uint8_t r, const uint8_t g, const uint8_t b);

  bool update        ();

}; // end class TextConfig


}; // end namespace nmd


#endif


// =======================================================================================
// **                               T E X T   C O N F I G                               **
// ======================================================================== END FILE =====
