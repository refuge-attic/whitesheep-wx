
// This file is part of whitesheep released under the Apache 2 license.
// See the NOTICE for more information.

// For compilers that support precompilation, includes "wx.h".
#include <wx/wxprec.h>

#ifdef __BORLANDC__
#pragma hdrstop
#endif

#ifndef WX_PRECOMP
#include <wx/wx.h>
#endif

#include <wx/aboutdlg.h>
#include "taskbar.h"

// for windows we should use XPM too ...
#if defined(__WXGTK__) || defined(__WXMOTIF__) || defined(__WXMAC__) || defined(__WXMGL__) || defined(__WXX11__)
    #include "sheep.xpm"
#endif

enum {
    PU_EXIT = 10001,
    PU_ABOUT
};

BEGIN_EVENT_TABLE(WSTaskBarIcon, wxTaskBarIcon)
    EVT_MENU(PU_EXIT,    WSTaskBarIcon::OnMenuExit)
    EVT_MENU(PU_ABOUT,   WSTaskBarIcon::OnMenuAbout)
END_EVENT_TABLE()

void WSTaskBarIcon::setup(void) {
    if (!this->SetIcon(wxICON(sheep), wxT("wxTaskBarIcon Sample")))
        wxMessageBox(wxT("Could not set icon."));
}

void WSTaskBarIcon::OnMenuExit(wxCommandEvent& )
{
    // TODO need to stop Refuge here
    ::wxExit();
}

void WSTaskBarIcon::OnMenuAbout(wxCommandEvent& ) {
    wxAboutDialogInfo info;
    info.SetName(_("WhiteSheep"));
    info.SetVersion(_("0.0.1"));
    info.SetDescription(_("This program does something great."));
    info.SetWebSite("http://refuge.io/");
    info.SetCopyright(_T("(C) 2011"));
    info.AddDeveloper("Benoit Chesneau <benoitc@gmail.com>");
    info.AddDeveloper("Nicolas R Dufour <nicolas.dufour@nemoworld.info>");
    info.SetIcon(wxICON(sheep));

    wxAboutBox(info);
}

// Overridables
wxMenu *WSTaskBarIcon::CreatePopupMenu()
{
    // Try creating menus different ways
    // TODO: Probably try calling SetBitmap with some XPMs here
    wxMenu *menu = new wxMenu;
    menu->Append(PU_ABOUT, _T("&About"));
#ifndef __WXMAC_OSX__ /*Mac has built-in quit menu*/
    menu->AppendSeparator();
    menu->Append(PU_EXIT,    _T("E&xit"));
#endif
    return menu;
}
