// ====================================================================== BEGIN FILE =====
// **                               E N T R Y   P O I N T                               **
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
/** @brief  Entry Point
 *  @file   entry_point.hh
 *  @author Stephen W. Soliday
 *  @date   2026-Oct-16
 *
 *  Provides an interface for the GUI entry point.
 */
// =======================================================================================

#ifndef __ENTRY_POINT_HH
#define __ENTRY_POINT_HH

#include <wx/wx.h>

#include <simulation.hh>


namespace nmd {

// =======================================================================================
class EntryPoint : public wxApp {
  // -------------------------------------------------------------------------------------
 protected:
  static Configuration* startupConfiguration;

  Configuration* config = nullptr;

  EMPTY_PROTOTYPE(EntryPoint);

  TLOGGER_HEADER(logger);

 public:
  static void SetStartupConfiguration(Configuration* cfg);

  EntryPoint() {};

  bool OnInit() override;
  int  OnExit() override;
}; // end class EntryPoint


}; // end namespace nmd


#endif


// =======================================================================================
// **                               E N T R Y   P O I N T                               **
// ======================================================================== END FILE =====
