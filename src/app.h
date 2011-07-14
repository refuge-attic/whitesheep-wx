
// This file is part of whitesheep released under the Apache 2 license.
// See the NOTICE for more information.

class WSApp: public wxApp
{
public:
    bool OnInit(void);
    int OnExit(void);

protected:
    WSTaskBarIcon   *m_taskBarIcon;
};
