
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

#include "taskbar.h"
#include "app.h"

IMPLEMENT_APP(WSApp)

bool WSApp::OnInit(void)
{
    m_taskBarIcon = new WSTaskBarIcon();
    m_taskBarIcon->setup();

    return true;
}

int WSApp::OnExit(void) {
    delete m_taskBarIcon;
}

// ----
