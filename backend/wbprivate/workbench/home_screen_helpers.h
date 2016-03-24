/*
 * Copyright (c) 2016, Oracle and/or its affiliates. All rights reserved.
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License as
 * published by the Free Software Foundation; version 2 of the
 * License.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA
 * 02110-1301  USA
 */

#pragma once

#include <cairo/cairo.h>
#include "mforms/drawbox.h"

namespace wb
{
//--------------------------------------------------------------------------------------------------

  /**
   * Value to tell observers which action was triggered on the home screen.
   */
  enum class HomeScreenAction
  {
    ActionNone,

    ActionOpenConnectionFromList,
    ActionNewConnection,
    ActionManageConnections,
    ActionFilesWithConnection,
    ActionMoveConnectionToGroup,
    ActionMoveConnection,

    ActionSetupRemoteManagement,

    ActionEditSQLScript,

    ActionOpenEERModel,
    ActionNewEERModel,
    ActionOpenEERModelFromList,
    ActionNewModelFromDB,
    ActionNewModelFromScript,

    ActionNewXConnection,
    ActionManageXConnections,

    ActionOpenXTutorial,
    ActionOpenXLearnMore,
    ActionOpenXTraditional
  };

  enum HomeScreenMenuType
  {
    HomeMenuConnection,
    HomeMenuConnectionGroup,
    HomeMenuConnectionGeneric,

    HomeMenuDocumentModelAction,
    HomeMenuDocumentModel,
    HomeMenuDocumentSQLAction,
    HomeMenuDocumentSQL,
  };

  class HomeScreenSettings
  {
  public:
    #ifdef __APPLE__
    static const char* HOME_TITLE_FONT;
    static const char* HOME_NORMAL_FONT;
    static const char* HOME_DETAILS_FONT;
    // Info font is only used on Mac.
    static const char* HOME_INFO_FONT;
    #elif defined(_WIN32)
    static const char* HOME_TITLE_FONT;
    static const char* HOME_NORMAL_FONT;
    static const char* HOME_DETAILS_FONT;
    #else
    static const char* HOME_TITLE_FONT;
    static const char* HOME_NORMAL_FONT;
    static const char* HOME_DETAILS_FONT;
    #endif

    static const int HOME_TITLE_FONT_SIZE = 20;
    static const int HOME_SUBTITLE_FONT_SIZE = 16;

    static const int HOME_TILES_TITLE_FONT_SIZE = 16;
    static const int HOME_SMALL_INFO_FONT_SIZE = 12;
    static const int HOME_DETAILS_FONT_SIZE = 12;

    static const char* TILE_DRAG_FORMAT;
  };

  class HomeAccessibleButton : public mforms::Accessible
  {
  public:
    std::string name;
    std::string default_action;
    base::Rect bounds;
    boost::function <bool (int, int)> default_handler;

    // ------ Accesibility Customized Methods -----

    virtual std::string get_acc_name();
    virtual std::string get_acc_default_action();
    virtual Accessible::Role get_acc_role();
    virtual base::Rect get_acc_bounds();

    virtual void do_default_action();
  };

  // The following helpers are just temporary. They will be replaced by a cairo context class.
  inline void deleteSurface(cairo_surface_t* surface)
  {
    if (surface != nullptr)
      cairo_surface_destroy(surface);
  }
  int imageWidth(cairo_surface_t* image);
  int imageHeight(cairo_surface_t* image);
  void textWithDecoration(cairo_t* cr, double x, double y, const char* text, bool hot, double width);

} /* namespace wb */
