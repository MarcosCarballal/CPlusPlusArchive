// File: StopWatchWin.cpp
// Author: Dr. Watts
// Project: CS215 Stop Watch MFC Example
// Description of file contents: Implementations of the StopWatchWin class functions.

#include <afxwin.h>
#include "StopWatchWin.h"

StopWatchWin::StopWatchWin ()
{
	// This function will: Create and initalialize the StopWatchWin class

	// Create a string to hold the title
	CString WindowTitle = "A Simple Stop Watch";
	// Create a window and initialize its initial position and size.
	Create (NULL, WindowTitle, WS_OVERLAPPEDWINDOW, CRect (300, 100, 300+20+600, 100+42+800));
	firstTime = true;
}

afx_msg void StopWatchWin::OnPaint ()
{
	// This function will: Paint the stop watch each time it is modified

	myStopWatch.Display (this);
	if (firstTime)
	{
		myStopWatch.Instructions(this);
		firstTime = false;
	}
}

afx_msg void StopWatchWin::OnLButtonDown( UINT nFlags, CPoint point )
{
	// This function will: Handle left mouse button clicks.

	myStopWatch.Click (point, this);
}

afx_msg void StopWatchWin::OnLButtonDblClk( UINT nFlags, CPoint point )
{	
	// This function will: Handle left mouse button double clicks.

	OnLButtonDown (nFlags, point);
}

afx_msg void StopWatchWin::OnTimer (UINT nIDEvent)
{	
	// This function will: Handle timer events

	if (nIDEvent == 1)
		myStopWatch.UpdateTime (this);  
}

// The message map indcates to the compiler which of the CFrameWnd
// functions will be handled by this window.
BEGIN_MESSAGE_MAP (StopWatchWin, CFrameWnd)
	ON_WM_PAINT ()
	ON_WM_LBUTTONDOWN( )
	ON_WM_LBUTTONDBLCLK( )
	ON_WM_TIMER ()
END_MESSAGE_MAP ()
