// File: StopWatchWin.h
// Author: Dr. Watts
// Project: CS215 Stop Watch MFC Example
// Description of file contents: Description of the StopWatchWin class.

#include <afxwin.h>
#include "StopWatch.h"

class StopWatchWin : public CFrameWnd
{
	public:
		StopWatchWin ();
		afx_msg void OnPaint ();
		afx_msg void OnLButtonDown( UINT nFlags, CPoint point );
		afx_msg void OnLButtonDblClk( UINT nFlags, CPoint point );
		afx_msg void OnTimer (UINT nIDEvent); 
	private:
		StopWatch myStopWatch;
		bool firstTime;
		DECLARE_MESSAGE_MAP ()
};
