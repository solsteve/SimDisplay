// ====================================================================== BEGIN FILE =====
// **                              F R A M E   B U F F E R                              **
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
/** @brief  Frame Buffer
 *  @file   frame_buffer.hh
 *  @author Stephen W. Soliday
 *  @date   2026-Oct-13
 *
 *  Provides an interface for a frame buffer.
 */
// =======================================================================================

#ifndef __FRAME_BUFFER_HH
#define __FRAME_BUFFER_HH

#include <wx/wx.h>
#include <wx/dcbuffer.h>
#include <wx/image.h>
#include <wx/bitmap.h>

#include <screen_buffer.hh>
#include <rgb_pallet.hh>

namespace nmd {


// =======================================================================================
class FrameBuffer : public wxPanel {
  // -------------------------------------------------------------------------------------
 protected:

  wxImage        image;
  wxBitmap       bitmap;
  ScreenBuffer*  buffer;
  RGB_Pallet*    pallet;


    void OnPaint(wxPaintEvent& event);

  EMPTY_PROTOTYPE(FrameBuffer);

 public:

  explicit FrameBuffer(wxWindow* parent, ScreenBuffer* b, RGB_Pallet* r);

    void updateFrame();
    void setRefresh(const int n);

}; // end class FrameBuffer


}; // end namespace nmd


#endif


// =======================================================================================
// **                              F R A M E   B U F F E R                              **
// ======================================================================== END FILE =====
