// File: StopWatch.h
// Author: Dr. Watts
// Project: CS215 Stop Watch MFC Example
// Description of file contents:  Description of the stop watch class and the 
// stop watch hand struct.

#ifndef StopWatch_H
#define StopWatch_H

#include <afxwin.h>
#include <vector>
#include <string>

using namespace std;

enum StopWatch_status {GO, STOP};

class StopWatch
{
	public:
		StopWatch ();
		StopWatch (const StopWatch & other);
		~StopWatch ();
		StopWatch & operator = (const StopWatch & other);
		void Init (int I);
		void Instructions (CFrameWnd * windowP);
		void Display (CFrameWnd * windowP);
		void Click (CPoint point, CFrameWnd * windowP);
		void UpdateTime (CFrameWnd * windowP);
	private:
		struct StopWatchHand
		{
			StopWatchHand ();
			void Display (CDC * dc, double angle, CPoint point, float multW, float multH);
			void Init (CString name, CRect rect);
			double radius [4];
			double theta0 [4];
			CBitmap handImage;
			CBitmap handMask;
			int width, height;
		};

		void SetUp (CRect window);
		void DisplayTimeRect (CDC * deviceContextP);
		StopWatch_status status;
		int watchTime;	
		CPoint center;
		StopWatchHand hourHand;
		StopWatchHand minuteHand;
		StopWatchHand secondHand;
		CRect TimeRect;
		CRect StopStartRect;
		CRect ResetRect;
		CBitmap bgImage;
		int width, height;
};

#endif
