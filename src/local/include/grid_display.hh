// ====================================================================== BEGIN FILE =====
// **                              G R I D   D I S P L A Y                              **
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
/** @brief  Grid Display
 *  @file   grid_display.hh
 *  @author Stephen W. Soliday
 *  @date   2026-Nov-06
 *
 *  Provides the interface for a grid display panel.
 */
// =======================================================================================


#ifndef __GRID_DISPLAY_HH
#define __GRID_DISPLAY_HH


#include <wx/wx.h>
#include <wx/dcbuffer.h>
#include <wx/image.h>
#include <wx/bitmap.h>

#include <display_panel.hh>
#include <grid_data.hh>
#include <rgb_pallet.hh>


namespace nmd {


// =======================================================================================
class GridDisplay : public DisplayPanel {
  // -------------------------------------------------------------------------------------
 public:

  explicit GridDisplay(wxWindow* parent, GridData* b, RGB_Pallet* r);

  virtual void updateDisplay ();
  //void setRefresh  (const int n);

  virtual void OnPaint(wxPaintEvent& event);

 protected:

  wxImage       image;    //< display image.
  wxBitmap      bitmap;   //< display bitmap.
  GridData*     gridData; //< pointer to the shared grid data.
  RGB_Pallet*   pallet;   //< color pallet.


  EMPTY_PROTOTYPE(GridDisplay);

}; // end class GridDisplay


}; // end namespace nmd


#endif


// =======================================================================================
// **                              G R I D   D I S P L A Y                              **
// ======================================================================== END FILE =====
