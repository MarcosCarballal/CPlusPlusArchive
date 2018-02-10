// File: CLife.cpp
// Author: Marcos Carballal
// Project: CS215 Project 3 Spring
// Description of file contents: All implementations of functions called by the CLife
// class and its sub-class CLifeSquare.

#include "CLife.h"
#include <time.h>
#include <string>

CBitmap bgImage;
static CBitmap images [(MAXTYPES + 1) * MAXCOLORS]; //This is necessary to acount for the number of possiblities introduced by color implementation.

using namespace std;

/*1*/ CLife::CLife ()
{
	// This function will: Default constructir for a CLife object

	// srand (time (NULL));
	numRows = numCols = 1;
	grid = new CLifeSquare * [numRows+2];
	for (int r = 0; r < numRows+2; r++)
		grid[r] = new CLifeSquare [numCols+2];
	seed = 0;
	CLifeStatus = NEW;
	isRedTurn = true; //Added
	plys_taken = 0; //Added
}

/*2*/ CLife::CLife (const CLife & other)
{
	// Default copy constructor. Not used in my implementation

}

/*3*/CLife::~CLife ()
{
	// This function will: delete a CLife grid and free up space in memory

	for (int r = 0; r < numRows + 2; r++)
		delete[] grid[r];
	delete[] grid;

}

/*4*/ CLife & CLife::operator = (const CLife & other)
{
	// This function will: Make a CLife object copy of another CLife object

	return *this;
}

/*5*/ void CLife::LoadResources ()
{
	// This function will: Determine what image is to be used based on CLifeSquare.what and CLifeSquare.whatColor

	int res = bgImage.LoadBitmap(CString("BACKGROUND_BMP"));
	// For .whatColor = None
	res = images[7 * BORDER + NONE].LoadBitmap(CString("EMPTY_BMP"));
	res = images[7 * EMPTY + NONE].LoadBitmap(CString("EMPTY_BMP"));		
	res = images[7 * ADDING + NONE].LoadBitmap(CString("EMPTY_BMP")); // Non-sensical with current game mechanics but could be used to make modifications to the game
	res = images[7 * PERSON + NONE].LoadBitmap(CString("EMPTY_BMP"));// Non-sensical with current game mechanics but could be used to make modifications to the game
	res = images[7 * DELETING + NONE].LoadBitmap(CString("EMPTY_BMP"));// Non-sensical with current game mechanics but could be used to make modifications to the game
	// For .whatColor = RED
	res = images[7 * BORDER + RED].LoadBitmap(CString("EMPTY_BMP"));// Non-sensical with current game mechanics but could be used to make modifications to the game
	res = images[7 * EMPTY + RED].LoadBitmap(CString("EMPTY_BMP"));// Non-sensical with current game mechanics but could be used to make modifications to the game
	res = images[7 * ADDING + RED].LoadBitmap(CString("PERSON1BORN_BMP"));// Non-sensical with current game mechanics but could be used to make modifications to the game
	res = images[7 * PERSON + RED].LoadBitmap(CString("PERSON1_BMP"));
	res = images[7 * DELETING + RED].LoadBitmap(CString("PERSON1DIE_BMP"));// Non-sensical with current game mechanics but could be used to make modifications to the game
	// For .whatColor = BLUE
	res = images[7 * BORDER + BLUE].LoadBitmap(CString("EMPTY_BMP"));// Non-sensical with current game mechanics but could be used to make modifications to the game
	res = images[7 * EMPTY + BLUE].LoadBitmap(CString("EMPTY_BMP"));// Non-sensical with current game mechanics but could be used to make modifications to the game
	res = images[7 * ADDING + BLUE].LoadBitmap(CString("PERSON2BORN_BMP"));// Non-sensical with current game mechanics but could be used to make modifications to the game
	res = images[7 * PERSON + BLUE].LoadBitmap(CString("PERSON2_BMP"));
	res = images[7 * DELETING + BLUE].LoadBitmap(CString("PERSON2DIE_BMP"));// Non-sensical with current game mechanics but could be used to make modifications to the game
	// For .whatColor = CHANGING_NONE_B
	res = images[7 * BORDER + CHANGING_NONE_B].LoadBitmap(CString("EMPTY_BMP"));// Non-sensical with current game mechanics but could be used to make modifications to the game
	res = images[7 * EMPTY + CHANGING_NONE_B].LoadBitmap(CString("EMPTY_BMP"));// Non-sensical with current game mechanics but could be used to make modifications to the game
	res = images[7 * ADDING + CHANGING_NONE_B].LoadBitmap(CString("PERSON2BORN_BMP"));// Non-sensical with current game mechanics but could be used to make modifications to the game
	res = images[7 * PERSON + CHANGING_NONE_B].LoadBitmap(CString("PERSON2BORN_BMP"));// Non-sensical with current game mechanics but could be used to make modifications to the game
	res = images[7 * DELETING + CHANGING_NONE_B].LoadBitmap(CString("PERSON2DIE_BMP"));
	// For .whatColor = CHANGING_NONE_R
	res = images[7 * BORDER + CHANGING_NONE_R].LoadBitmap(CString("EMPTY_BMP"));// Non-sensical with current game mechanics but could be used to make modifications to the game
	res = images[7 * EMPTY + CHANGING_NONE_R].LoadBitmap(CString("EMPTY_BMP"));// Non-sensical with current game mechanics but could be used to make modifications to the game
	res = images[7 * ADDING + CHANGING_NONE_R].LoadBitmap(CString("PERSON1BORN_BMP"));// Non-sensical with current game mechanics but could be used to make modifications to the game
	res = images[7 * PERSON + CHANGING_NONE_R].LoadBitmap(CString("PERSON1_BMP"));// Non-sensical with current game mechanics but could be used to make modifications to the game
	res = images[7 * DELETING + CHANGING_NONE_R].LoadBitmap(CString("PERSON1DIE_BMP"));
	// For .whatColor = CHANGING_RED
	res = images[7 * BORDER + CHANGING_RED].LoadBitmap(CString("EMPTY_BMP"));// Non-sensical with current game mechanics but could be used to make modifications to the game
	res = images[7 * EMPTY + CHANGING_RED].LoadBitmap(CString("EMPTY_BMP"));// Non-sensical with current game mechanics but could be used to make modifications to the game
	res = images[7 * ADDING + CHANGING_RED].LoadBitmap(CString("PERSON1BORN_BMP"));
	res = images[7 * PERSON + CHANGING_RED].LoadBitmap(CString("PERSON1_BMP"));// Non-sensical with current game mechanics but could be used to make modifications to the game
	res = images[7 * DELETING + CHANGING_RED].LoadBitmap(CString("PERSON1DIE_BMP"));// Non-sensical with current game mechanics but could be used to make modifications to the game
	// For .whatColor = CHANGING_BLUE
	res = images[7 * BORDER + CHANGING_BLUE].LoadBitmap(CString("EMPTY_BMP"));// Non-sensical with current game mechanics but could be used to make modifications to the game
	res = images[7 * EMPTY + CHANGING_BLUE].LoadBitmap(CString("EMPTY_BMP"));// Non-sensical with current game mechanics but could be used to make modifications to the game
	res = images[7 * ADDING + CHANGING_BLUE].LoadBitmap(CString("PERSON2BORN_BMP"));
	res = images[7 * PERSON + CHANGING_BLUE].LoadBitmap(CString("PERSON2_BMP"));// Non-sensical with current game mechanics but could be used to make modifications to the game
	res = images[7 * DELETING + CHANGING_BLUE].LoadBitmap(CString("PERSON2DIE_BMP"));// Non-sensical with current game mechanics but could be used to make modifications to the game

}

/*6*/ void CLife::Init (int R, int C, CFrameWnd * windowP)
{
	// This function will: Initialize a CLife object.

	for (int r = 0; r < numRows + 2; r++)
		delete[] grid[r];
	delete[] grid;
	generationsMap.clear();
	numRows = R < DEF_ROWS ? DEF_ROWS : R;
	numCols = C < DEF_COLS ? DEF_COLS : C;
	grid = new CLifeSquare *[numRows + 2];
	for (int r = 0; r < numRows + 2; r++)
		grid[r] = new CLifeSquare[numCols + 2];
	for (int r = 1; r <= numRows; r++)
		for (int c = 1; c <= numCols; c++)
			grid[r][c].what = EMPTY;
	populationSize = 0;
	generations = 0;	
	finished = 0;
	evaluating = true;
	CLifeStatus = NEW;
}

/*7*/ void CLife::Instructions (CFrameWnd * windowP)
{
	// This function will: Display the initial instructions.

     CString message;
	 message += "Welcome to the Game of Life and Death (GOLAD)\n GOLAD is a two player game \nThe goal of the game is to have more dots than your opponent after 20 turns!\nYou will take turns placing dots.\nCreation of new dots are based on the majority of it's parents.\nDots will die by overpopulation as usual.\n If you are unfamiliar with Conway's game of life\n you will want to study it before playing.\nGood Luck!";
     
	CString title = "Instructions";
	windowP->MessageBox (message, title);
}

/*8*/ void CLife::Display (CFrameWnd * windowP)
{
	// This function will: Display all components of the CLife object

	CPaintDC dc (windowP);
	CRect rect;
	windowP->GetClientRect (&rect);
	CDC memDC;
	int res = memDC.CreateCompatibleDC(&dc);
	memDC.SelectObject(&bgImage);
	dc.TransparentBlt (0, 0, rect.Width(), rect.Height(), &memDC, 0, 0, 1920, 1080, SRCCOPY); 
	DeleteDC (memDC);
	SetUp (rect);
	DisplayGameRect (&dc);
	dc.SetBkMode(TRANSPARENT);	
	CFont font;
	CString fontName = "Comic Sans";
	font.CreatePointFont(rect.Height() / 5, fontName, &dc);
	CFont* def_font = dc.SelectObject(&font);
	COLORREF def_color = dc.SetTextColor (RGB (0, 0, 0));
	DisplayDataRect (&dc);
	DisplayButtonRect (&dc);
	dc.SelectObject(def_font);
	dc.SetTextColor(def_color);
}

/*9*/ void CLife::Click (int y, int x, CFrameWnd * windowP)
{
	// This function will: Determine the appropriate acxtion based on where the click was
		// Will add CLifeSquare objects unless there is already one there.

	if (newRect.PtInRect(CPoint(x, y)))
	{
		seed = time(NULL) % 10000;
		windowP->KillTimer(1);
		Init (numRows, numCols, windowP);
		InitRandom(windowP);
		CLifeStatus = READY;
		windowP->Invalidate(true);
		redPopulationSize = 0;
		bluePopulationSize = 0;
	}
	else
	{
		for (int r = 1; r <= numRows; r++)
		{
			for (int c = 1; c <= numCols; c++)
			{
			if ((grid[r][c].where).PtInRect(CPoint(x, y)))
				{
					if (grid[r][c].what != PERSON)
					{
						if (isRedTurn) // This block of code allows the turns of the players to 
							// alternate such that the final order looks like RED, BLUE, Process, BLUE, RED, Process ....
						{
							Add(r, c, PERSON, RED, windowP);
							plys_taken++;

							if (plys_taken % 2 == 1)
							{
								isRedTurn = !isRedTurn;
							}
							if (plys_taken % 2 == 0)
							{
								Next(windowP);
								Next(windowP);
							}
						}
						else
						{
							Add(r, c, PERSON, BLUE, windowP);
							plys_taken++;

							if (plys_taken % 2 == 1)
							{
								isRedTurn = !isRedTurn;
							}
							if (plys_taken % 2 == 0)
							{
								Next(windowP);
								Next(windowP);
							}
						}
					}
				}
			}
		}
	}
}

/*10*/ void CLife::Move (char direction, CFrameWnd * windowP)
{
	// This function will: Move a character. Not used in my program

	CRect oldWhere;
	switch (direction)
	{
		case 'a': // moving left
			break;
		case 'w': // moving up
			break;
		case 'd': // moving right
			break;
		case 's': // moving down
			break;
	}
	CRect newWhere;
	windowP->InvalidateRect (oldWhere | newWhere);
}

/*11*/ void CLife::UpdateTime (CFrameWnd * windowP)
{
	// This function will: Update a timer. Not used in my program

	if (!finished)
		Next (windowP);
	else
	{
		windowP->KillTimer(1);
		CLifeStatus = FINISHED;
	}
}

/*12*/ void CLife::Message (CFrameWnd * windowP)
{
	// This function will: Send a message based on how the game ends

	CString message = "Thank you for playing!\n\n";
	CString title = "Game Over";
	switch (finished)
	{
		case -1: message += "The community has vanished.";
			break;
		default: message += "The community has entered a stable pattern.";
	}
	windowP->KillTimer(1);
	windowP->MessageBox (message, title);
}

/*13*/ bool CLife::Done(CFrameWnd * windowP)
{
	// This function will: determine whether or not the game is over

	return finished != 0;
}

/*14*/ CLife::CLifeSquare::CLifeSquare ()
{
	// This function will: Initialize a CLifeSquare Object

	what = BORDER;
	whatColor = NONE;
}

/*15*/ void CLife::CLifeSquare::Display (CDC * deviceContextP)
{
	// This function will: Refresh the display for a given CLifeSquare by calling the images array

	deviceContextP->Rectangle(where);
	CDC memDC;
	int res = memDC.CreateCompatibleDC(deviceContextP);
	memDC.SelectObject(&images[7 * what + whatColor]);
	res = deviceContextP->TransparentBlt (where.left, where.top, where.Width(), where.Height(), &memDC, 0, 0, 100, 100, SRCCOPY); 
	DeleteDC (memDC);	
}

/*16*/ string CLife::CLifeSquare::Reset(CFrameWnd * windowP) 
{
	// This function will: Process the determinations made by the Evaluate functions
	// It must take into account what color is changing as well if it is deleting.
	if (what == ADDING)
	{
		what = PERSON;
		windowP->InvalidateRect(where);
		if (whatColor == CHANGING_RED)
		{
			whatColor = RED;
			return "Red++";
		}
		if (whatColor == CHANGING_BLUE)
		{
			whatColor = BLUE;
			return "Blue++";
		}
	}
	if (what == DELETING)
	{
		what = EMPTY;
		if (whatColor == CHANGING_NONE_R)
		{
			whatColor = NONE;
			return "Red--";
		}

		if (whatColor == CHANGING_NONE_B)
		{
			whatColor = NONE;
			return "Blue--";
		}
			
		
		windowP->InvalidateRect(where);
	}
	return " ";
}

/*17*/ void CLife::SetUp (CRect rect)
{
	// This function will: Initialize many variables such as the rectangles for display and constants

	int tbBorder = rect.Height() / 12;
	int lrBorder = rect.Width() / 12;
	gameRect = CRect (rect.Width() / 3, tbBorder, rect.Width()-lrBorder, rect.Height()-tbBorder);
	dataRect = CRect (lrBorder, rect.Height() / 3, rect.Width() / 4, 2 * rect.Height() / 3);
	buttonRect = CRect (lrBorder, 3 * rect.Height() / 4, rect.Width() / 4, rect.Height() - tbBorder);
	int thirdW = buttonRect.Width() / 3;
	newRect = CRect (buttonRect.left, buttonRect.top, buttonRect.left + thirdW, buttonRect.bottom);

	int sqHeight = gameRect.Height() / numRows;
	int sqWidth = gameRect.Width() / numCols;
	int top = gameRect.top + (gameRect.Height() - sqHeight * numRows) / 2;
	int left = gameRect.left + (gameRect.Width() - sqWidth * numCols) / 2;
	int size = sqHeight < sqWidth ? sqHeight : sqWidth;
	for (int r = 1; r <= numRows; r++)
		for (int c = 1; c <= numCols; c++)
		{
			grid[r][c].where = CRect(left + (c-1)*sqWidth + 1, top + (r-1)*sqHeight + 1, left + (c)*sqWidth, top + (r)*sqHeight);
		}
}

/*18*/ void CLife::DisplayGameRect (CDC * deviceContextP)
{
	// This function will: Display the game rectangle by parsing through all CLifeSquares in the grid

	for (int r = 1; r <= numRows; r++)
		for (int c = 1; c <= numCols; c++)
			grid [r][c].Display (deviceContextP);
}

/*19*/ void CLife::DisplayDataRect (CDC * deviceContextP)
{
	// This function will: Display the rectangle behind the data, the current generation, the current turn,
	// the current red population, and the current blue population. Since there are two plys before each generation,
	// it will also show the turn order.
	
	CPoint corner = CPoint(dataRect.Height()/4, dataRect.Height()/4);  	
	deviceContextP->RoundRect(dataRect, corner);
	CRect genRect = CRect (dataRect.left, dataRect.top, dataRect.right, dataRect.top + dataRect.Height() / 2);
	CRect turnRect = CRect(dataRect.left, dataRect.top, dataRect.right, dataRect.top + dataRect.Height() / 3);
	CRect redPopRect = CRect (dataRect.left, dataRect.top + dataRect.Height() / 2, dataRect.right, dataRect.bottom);
	CRect bluePopRect = CRect(dataRect.left, dataRect.top + dataRect.Height() / 3, dataRect.right, dataRect.bottom);
	CString turnorder = "Turn: ";
	if (isRedTurn)
		turnorder += "Red, then Blue";
	else
		turnorder += "Blue, then Red";
	char buffer[50];
	//sprintf_s(buffer, "Turns: %d", turnorder);
	deviceContextP->DrawText(turnorder, turnRect, DT_SINGLELINE | DT_VCENTER | DT_CENTER);
	sprintf_s (buffer, "Turns: %d", generations);
	deviceContextP->DrawText(CString (buffer), genRect, DT_SINGLELINE | DT_VCENTER | DT_CENTER);
	sprintf_s (buffer, "Red: %d", redPopulationSize);
	deviceContextP->DrawText(CString (buffer), redPopRect, DT_SINGLELINE | DT_VCENTER | DT_CENTER);
	sprintf_s(buffer, "Blue: %d", bluePopulationSize);
	deviceContextP->DrawText(CString(buffer), bluePopRect, DT_SINGLELINE | DT_VCENTER | DT_CENTER);
}

/*20*/ void CLife::DisplayButtonRect (CDC * deviceContextP)
{
	// This function will: Draw the "new" button.
	
	CPoint corner = CPoint(buttonRect.Height()/4, buttonRect.Height()/4);  
	deviceContextP->RoundRect(newRect, corner);
	deviceContextP->DrawText(CString ("New"), newRect, DT_SINGLELINE | DT_VCENTER | DT_CENTER);
}

/*21*/ void CLife::InitRandom(CFrameWnd * windowP)
{
	// This function will: Create a rotationally symmetric board such that each red cell at [a,b]
	// will have a corresponding blue cell at [b,a]

	srand(seed);
	for (int p = 0; p < 30; p++)
	{
		int r = 1 + rand() % numRows;
		int c = 1 + rand() % numCols;
		if (grid[r][c].what != ADDING || grid[r][c].what != PERSON)
		{
			if (p % 2 == 0)
			{
				Add(r, c, PERSON, RED, windowP);
				Add(numRows + 1 - r, numCols + 1 - c, PERSON, BLUE, windowP);
			}
			else
			{
				Add(r, c, PERSON, BLUE, windowP);
				Add(numRows + 1 - r, numCols + 1 - c, PERSON, RED, windowP);
			}
		}
	}
}

/*22*/ void CLife::Next(CFrameWnd * windowP)
{
	// This function will: Increase the number of generations, evaluate where new ones need to be, and then redraw the canvas.
	// It will end the game when generations == 20

	if (evaluating)
		for (int r = 1; r <= numRows; r++)
			for (int c = 1; c <= numCols; c++)
				Evaluate(r, c, windowP);
	else
	{
		generations++;
		for (int r = 1; r <= numRows; r++)
		{
			for (int c = 1; c <= numCols; c++)
			{
				string populationReturnVal = grid[r][c].Reset(windowP);
				if (populationReturnVal == "Red++")
					redPopulationSize++;
				if (populationReturnVal == "Blue++")
					bluePopulationSize++;
				if (populationReturnVal == "Red--")
					redPopulationSize--;
				if (populationReturnVal == "Blue--")
					bluePopulationSize--;
			}
		}
		if ((redPopulationSize + bluePopulationSize) == 0)
			finished = -1;	
		string mapStr = MakeString();
		map<string, int>::iterator itr = generationsMap.find(mapStr);
		if (itr == generationsMap.end())
		{
			generationsMap[mapStr] = generations;
		}
		else
			finished = itr->second;
		windowP->InvalidateRect (dataRect);
	}
	if (generations == 20)
	{
		CString title = "Game Over!";
		string message;
		if (redPopulationSize > bluePopulationSize)
		{
			message = "Game Over!\n Red won with a population of " + to_string(redPopulationSize) + ".\nBlue lost with only a measly " + to_string(bluePopulationSize);
		}
		if (redPopulationSize < bluePopulationSize)
		{
			message = "Game Over!\n Blue won with a population of " + to_string(bluePopulationSize) + ".\nRed lost with only a measly " + to_string(redPopulationSize);
		}
		if (redPopulationSize == bluePopulationSize)
		{
			message = "Game Over!\n It's a tie!\n Both players had " + to_string(redPopulationSize) + "cells!";
		}
		message += "\n To play again, simply hit the new button!";
		CString cMessage = message.c_str();
		windowP->MessageBox(cMessage, title);
	}
	evaluating = !evaluating;
;
}

/*23*/ bool CLife::Add(int row, int col, square_types what, color_types whatColor, CFrameWnd * windowP)
{
	// This function will: Create a CLifeSquare at row, col
	// of type square_types and color whatColor
	// It will also invalidate the area of the rectangle that the .where attribute of the CLifeSquare occupies

	if (row < 1 || row > numRows)
		return false;
	if (col < 1 || col > numCols)
		return false;
	if (grid[row][col].what != EMPTY)
		return false;
	grid[row][col].what = what;
	grid[row][col].whatColor = whatColor;
	windowP->InvalidateRect(grid[row][col].where);
	return true;
}

/*24*/ bool CLife::Delete(int row, int col, color_types whatColor, CFrameWnd * windowP)
{
	// This function will: Deletes a CLifeSquare at row, col
	// Based on its color it will change the color_type so that it can still be used to evaluate
	// cells that are being born

	if (row < 1 || row > numRows)
		return false;
	if (col < 1 || col > numCols)
		return false;
	if (grid[row][col].what <= EMPTY)
		return false;
	grid[row][col].what = EMPTY;
	if (grid[row][col].whatColor == RED)
		grid[row][col].whatColor = CHANGING_NONE_R;
	if (grid[row][col].whatColor == BLUE)
		grid[row][col].whatColor = CHANGING_NONE_B;
	windowP->InvalidateRect (grid[row][col].where);
	return true;
}

/*25*/ void CLife::Evaluate(int row, int col, CFrameWnd * windowP)
{
	// This will make the calculation of the next state of the cell at row, col
	// and change its state accordingly.
	int redNeighborsAlive = 0;
	int blueNeighborsAlive = 0;

	for (int i = -1; i < 2; i++) // Will span between i = -1 and i = 1
	{
		for (int j = -1; j < 2; j++) // Will span between j = -1 and j = 1
		{
			if (!(j == 0 && i == 0)) // NAND for (0,0)
			{
				if (grid[row + i][col + j].what == PERSON || (grid[row + i][col + j].what == DELETING))
				{
					if (grid[row + i][col + j].whatColor == RED || (grid[row + i][col + j].whatColor == CHANGING_NONE_R))
						redNeighborsAlive++;
					if (grid[row + i][col + j].whatColor == BLUE || (grid[row + i][col + j].whatColor == CHANGING_NONE_B))
						blueNeighborsAlive++;
				}
			}
		}
	}
	int NeighborsAlive = redNeighborsAlive + blueNeighborsAlive;
	if ((grid[row][col].what == PERSON && (NeighborsAlive >= 4 || NeighborsAlive <= 1)))
	{
		Delete(row, col, grid[row][col].whatColor, windowP);
	}
	else
	{
		if (NeighborsAlive == 3 && grid[row][col].what == EMPTY)
		{
			if (redNeighborsAlive >= 2)
				Add(row, col, ADDING, CHANGING_RED, windowP);
			else
				Add(row, col, ADDING, CHANGING_BLUE, windowP);
		}
	}
	// Population counter
	redPopulationSize = 0;
	bluePopulationSize = 0;
	for (int r = 1; r <= numRows; r++)
	{
		for (int c = 1; c <= numCols; c++)
		{
			if (grid[r][c].what == PERSON || grid[r][c].what == DELETING)
			{
				if (grid[r][c].whatColor == RED || grid[r][c].whatColor == CHANGING_RED)
					redPopulationSize++;
				if (grid[r][c].whatColor == BLUE || grid[r][c].whatColor == CHANGING_BLUE)
					bluePopulationSize++;

			}
		}
	}
}

/*26*/ string CLife::MakeString() const
{
	// This function will: 
	string str;
	return str;
}
