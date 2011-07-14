
// This file is part of whitesheep released under the Apache 2 license.
// See the NOTICE for more information.

#include <wx/taskbar.h>

class WSTaskBarIcon: public wxTaskBarIcon
{
public:
#if defined(__WXCOCOA__)
    WSTaskBarIcon(wxTaskBarIconType iconType = CUSTOM_STATUSITEM)
    :   wxTaskBarIcon(iconType)
#else
    WSTaskBarIcon()
#endif
    {}

    void setup(void);

    void OnMenuExit(wxCommandEvent&);
    void OnMenuAbout(wxCommandEvent&);

    virtual wxMenu *CreatePopupMenu();

DECLARE_EVENT_TABLE()
};
