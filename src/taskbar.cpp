
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
//#include <wx/notifmsg.h>
#include "taskbar.h"

// for windows we should use XPM too ...
#if defined(__WXGTK__) || defined(__WXMOTIF__) || defined(__WXMAC__) || defined(__WXMGL__) || defined(__WXX11__)
    #include "sheep.xpm"
#endif

enum {
    ID_EXIT = 10001,
    ID_ABOUT,
    ID_START_STOP,
    ID_OPEN_URI
};

BEGIN_EVENT_TABLE(WSTaskBarIcon, wxTaskBarIcon)
    EVT_MENU(ID_EXIT,       WSTaskBarIcon::OnMenuExit)
    EVT_MENU(ID_ABOUT,      WSTaskBarIcon::OnMenuAbout)
    EVT_MENU(ID_START_STOP, WSTaskBarIcon::OnMenuStartStop)
    EVT_MENU(ID_OPEN_URI,   WSTaskBarIcon::OnMenuOpenURI)
END_EVENT_TABLE()

void WSTaskBarIcon::setup(void) {
    if (!this->SetIcon(wxICON(sheep), wxT("wxTaskBarIcon Sample")))
        wxMessageBox(wxT("Could not set icon."));

    isStarted = false;
}

void WSTaskBarIcon::OnMenuExit(wxCommandEvent& ) {
    // Stop Refuge before quitting
    StopRefuge();

    ::wxExit();
}

void WSTaskBarIcon::OnMenuAbout(wxCommandEvent& ) {
    wxAboutDialogInfo info;
    info.SetName(_("WhiteSheep"));
    info.SetVersion(_("0.0.1"));
    info.SetDescription(_("This program does something great."));
    info.SetWebSite(_("http://refuge.io/"));
    info.SetCopyright(_T("(C) 2011"));
    info.AddDeveloper(_("Benoit Chesneau <benoitc@gmail.com>"));
    info.AddDeveloper(_("Nicolas R Dufour <nicolas.dufour@nemoworld.info>"));
    info.SetIcon(wxICON(sheep));

    wxAboutBox(info);
}

void WSTaskBarIcon::OnMenuStartStop(wxCommandEvent&) {
    if(isStarted == true) {
        // time to stop it
        StopRefuge();

        // then update the menu items
        startStopItem->SetItemLabel(_T("&Start Refuge"));
        //openURIItem->Enable(false);

        // Notification
        wxMessageBox(_T("Refuge is stopping."));
        //wxNotificationMessage message;
        //message.SetMessage(_T("Refuge is stopping"));
        //message.Show();

        isStarted = false;
    } else {
        // time to start it
        StartRefuge();

        // then update the menu items
        startStopItem->SetItemLabel(_T("&Stop Refuge"));
        //openURIItem->Enable(true);

        // Notification
        wxMessageBox(_T("Refuge is starting."));
        //wxNotificationMessage message;
        //message.SetMessage(_T("Refuge is starting"));
        //message.Show();

        isStarted = true;
    }
}

void WSTaskBarIcon::OnMenuOpenURI(wxCommandEvent&) {
    wxMessageBox(_("Hello!"));
}

// Overridables
wxMenu *WSTaskBarIcon::CreatePopupMenu() {
    wxMenu *menu = new wxMenu;
    startStopItem = menu->Append(ID_START_STOP, _T("&Start Refuge"));
    openURIItem = menu->Append(ID_OPEN_URI, _T("Open &Web Interface"));
    menu->Append(ID_ABOUT, _T("&About"));
#ifndef __WXMAC_OSX__ /*Mac has built-in quit menu*/
    menu->AppendSeparator();
    menu->Append(ID_EXIT,    _T("E&xit"));
#endif
    return menu;
}

// ----

void WSTaskBarIcon::StartRefuge(void) {

}

void WSTaskBarIcon::StopRefuge(void) {

}
