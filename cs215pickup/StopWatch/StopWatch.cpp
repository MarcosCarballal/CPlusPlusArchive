// File: StopWatch.cpp
// Author: Dr. Watts
// Project: CS215 Stop Watch MFC Example
// Description of file contents: Implementations of the stop watch and stop watch
// hand functions.

#include "StopWatch.h"
#include <time.h>

using namespace std;

StopWatch::StopWatchHand::StopWatchHand ()
{
	// This function will: Be called when a new stop watch hand is created.

}

void StopWatch::StopWatchHand::Display (CDC * dc, double angle, CPoint point, float multW, float multH)
{
	// This function will: Display the stop watch hand.

	// Create a memory device context for the stop watch hand image.
	CDC memDC;
	int res = memDC.CreateCompatibleDC(dc);
	// Select the clock hand imaage
	memDC.SelectObject(&handImage);
	// Determine the appropriate locations of the corners of the parallelogram that will hold
	// the rotated stop watch hand image.
	CPoint plgPts [4];
	for (int i = 0; i < 4; i++)
	{
		// Convert the coordinates of the corner from polar to rectangular representations.
		double x = multW * (radius[i] * cos (theta0[i] + angle) + point.x);
		double y = multH * (radius[i] * sin (theta0[i] + angle) + point.y);
		plgPts[i] = CPoint (int (x), int (y));
	}
	// Draw the stop watch hand in the parallelagram with its mask.
	dc->PlgBlt (plgPts, &memDC, 0, 0, width, height, handMask, 0, 0);
	// Delete the loacal memory device context
	DeleteDC(memDC);
}

void StopWatch::StopWatchHand::Init (CString name, CRect rect)
{
	// This function will: Initialize the stop watch hand.

	// Load the image and mask bitmaps
	handImage.LoadBitmap(name + "HAND_BMP");		
	handMask.LoadBitmap(name + "MASK_BMP");
	// Store the size of the image for later drawing
	width = rect.Width();
	height = rect.Height();
	// Convert the coordinates of the corners of the initial loaction from rectangular 
	// to polar representations.
	double dx, dy;
	dx = rect.left;
	dy = rect.top;
	radius[0] = sqrt (dx*dx + dy*dy);
	theta0[0] = atan2 (dy, dx);
	dx = rect.right;
	dy = rect.top;
	radius[1] = sqrt (dx*dx + dy*dy);
	theta0[1] = atan2 (dy, dx);
	dx = rect.left;
	dy = rect.bottom;
	radius[2] = sqrt (dx*dx + dy*dy);
	theta0[2] = atan2 (dy, dx);
	dx = rect.right;
	dy = rect.bottom;
	radius[3] = sqrt (dx*dx + dy*dy);
	theta0[3] = atan2 (dy, dx);
}

StopWatch::StopWatch ()
{
	// This function will: Create and initialize the stop watch variables.

	status = STOP;
	watchTime = 0;
	center = CPoint (300, 390);
	width = 600;
	height = 800;
	// Call the stop watch hand Init fuction to load the appropriate
	// image and mask and to determing the polar coordinates of its
	// initial (zero based) loacation.
	hourHand.Init ("HOUR", CRect (-40,-143,40,17));
	minuteHand.Init ("MINUTE", CRect (-25,-183,25,17));
	secondHand.Init ("SECOND", CRect (-25,-183,25,17));
	// Load the background image
	bgImage.LoadBitmap(CString("BACKGROUND_BMP"));
}

StopWatch::~StopWatch ()
{
	// This function will: Be called when the stop watch object goes out of scope.

}

void StopWatch::Instructions (CFrameWnd * windowP)
{
	// This function will: Display the instructions for using the stopwatch.

	// Create the message for the message box.
	CString message = "Welcome to my StopWatch\n\n";
	message += "The goal of this StopWatch is to mark time.\n\n";		
	message += "This application is designed to demonstrate:\n";
	message += "\tmasking images\n";
	message += "\tusing a timer\n";		
	message += "\tfixing the initial window size and position\n";	
	message += "\t\n\n";
	message += "Use the left button on the watch to start and stop the watch.\n";
	message += "Use the right button on the watch to reset the watch time to 0.\n\n";
	// Set the title for the message box.
	CString title = "Instructions";
	// Display the message box.
	windowP->MessageBox (message, title);
}

void StopWatch::Display (CFrameWnd * windowP)
{
	// This function will: Display the stop watch and its hands; it will also display the
	//					   elapsed time in digital format.

	CPaintDC dc (windowP);
	CRect rect;
	windowP->GetClientRect (&rect);
	// Set the background mode for text to transparent.
	dc.SetBkMode(TRANSPARENT);		
	// Create a memory device context for the background image.
	CDC memDC;
	int res = memDC.CreateCompatibleDC(&dc);
	// Select the background image.
	memDC.SelectObject(&bgImage);
	dc.TransparentBlt (0, 0, rect.Width(), rect.Height(), &memDC, 0, 0, width, height, SRCCOPY); 
	DeleteDC (memDC);
	// call SetUp to determine the location of the digital time rectangle and the locations of
	// the start/stop and reset buttons on the stop watch.
	SetUp (rect);
	// Determine the correct angle for each of the hands based on the elapsed time.
	double hourAngle = 6.29128 / 12 * (watchTime / 3600.0);
	double minuteAngle = 6.29128 / 60 * ((watchTime % 3600) / 60.0);
	double secondAngle = 6.29128 / 60 * (watchTime % 60);
	// Determine the width and height stretch ratios based on the actual size of the window
	float ratioW = rect.Width() / float (width);
	float ratioH = rect.Height() / float (height);
	// Call display for each of the stop watch hands
	hourHand.Display(&dc, hourAngle, center, ratioW, ratioH);
	minuteHand.Display(&dc, minuteAngle, center, ratioW, ratioH);
	secondHand.Display(&dc, secondAngle, center, ratioW, ratioH);
	// Display the digital representation of the elapsed time.
	DisplayTimeRect (&dc);
}

void StopWatch::SetUp (CRect rect)
{
	// This function will: Determine the location of the digital time rectangle
	// and the locations of the start/stop and reset buttons on the stop watch.

	TimeRect = CRect (rect.left + rect.Width()/4, 6 * rect.Height()/7, rect.right - rect.Width()/4, rect.bottom - rect.Height()/28);
	StopStartRect = CRect (9*rect.Width()/33, 4*rect.Height()/25, 12*rect.Width()/33, 5*rect.Height()/25);
	ResetRect = CRect (21*rect.Width()/33, 4*rect.Height()/25, 24*rect.Width()/33, 5*rect.Height()/25);
}

void StopWatch::DisplayTimeRect (CDC * deviceContextP)
{
	// This function will: Display the elapsed time in digital format.

	// Create a black brush.
	CBrush brush;
	brush.CreateSolidBrush (RGB (0, 0, 0));
	CBrush* def_brush = deviceContextP->SelectObject(&brush);
	// Draw a rectangle with rounded corners.
	deviceContextP->RoundRect (TimeRect, CPoint (TimeRect.Height()/5, TimeRect.Height()/5));
	// Restore the original brush.
	deviceContextP->SelectObject(def_brush);
	// Create a string for the time and calculate the time components.
	char timeStr [50];
	int hours = watchTime / 3600;
	int minutes = (watchTime % 3600) / 60;
	int seconds = watchTime % 60;
	// Write the formated time to the string
	sprintf_s (timeStr, "%d:%02d:%02d", hours, minutes, seconds);
	// Create a new font for the time
	CFont font;
	CString fontName = "Quartz MS";
	font.CreatePointFont(TimeRect.Height()*5, fontName, deviceContextP);
	CFont* def_font = deviceContextP->SelectObject(&font);	
	// Set the color of the font to dark red.
	deviceContextP->SetTextColor (RGB (177, 0, 1));
	// Draw the time string in the time rectangle.
	deviceContextP->DrawText (CString (timeStr), TimeRect, DT_CENTER);
	// Restore the original font and text color.
 	deviceContextP->SetTextColor (RGB (0, 0, 0));       
	deviceContextP->SelectObject(def_font);
}

void StopWatch::Click (CPoint point, CFrameWnd * windowP)
{
	// This function will: Handle left mouse button clicks on the stop watch buttons.

	// Check to see if the click is in the Start/Stop button rectangle.
	if (StopStartRect.PtInRect(point))
	{
		if (status == GO)
		{ 
			// Stop the timer.
			windowP->KillTimer (1);
			status = STOP;
		}		
		else
		{
			// Start the timer.
			windowP->SetTimer (1, 1000, NULL);
			status = GO;
		}
		windowP->Invalidate(TRUE);
	}
	// Check to see if the click is in the Reset button rectangle.
	if (ResetRect.PtInRect(point))
	{
		// Reset the time to 0.
		watchTime = 0;
		windowP->Invalidate(TRUE);
	}
	// Ignore all other click locations
}

void StopWatch::UpdateTime (CFrameWnd * windowP)
{
	// This function will: Update the elapsed time each time it is called by OnTimer.

		watchTime++;
		windowP->Invalidate (TRUE);
}