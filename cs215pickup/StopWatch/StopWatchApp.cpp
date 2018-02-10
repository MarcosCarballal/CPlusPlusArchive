// File: StopWatchApp.cpp
// Author: Dr. Watts
// Project: CS215 Stop Watch MFC Example
// Description of file contents: Implementations of the StopWatchApp class functions.

#include <afxwin.h>
#include "StopWatchApp.h"


BOOL StopWatchApp::InitInstance ()
{
	// This function will: Initialize an instance of the StopWatchApp

	m_pMainWnd = new StopWatchWin();
	m_pMainWnd->ShowWindow (m_nCmdShow);
	m_pMainWnd->UpdateWindow ();

	return TRUE;
}

// Create an instance of the StopWatchApp
StopWatchApp StopWatchApp;
