#include "ActionAddSquare.h"
#include "..\Figures\CSquare.h"

#include "..\ApplicationManager.h"

#include "..\GUI\GUI.h"
#include <iostream>



ActionAddSquare::ActionAddSquare(ApplicationManager* pApp) :Action(pApp)
{}

//Execute the action
void ActionAddSquare::Execute()
{
	Point P1, P2;
	Point topLeft;
	int SideLength;
	//Get a Pointer to the Interface
	GUI* pGUI = pManager->GetGUI();


	GfxInfo SqrGfxInfo;
	SqrGfxInfo.isFilled = UI.isFilled; 	//default is not filled

	//get drawing, filling colors and pen width from the interface
	SqrGfxInfo.DrawClr = pGUI->getCrntDrawColor();
	SqrGfxInfo.FillClr = pGUI->getCrntFillColor();
	SqrGfxInfo.BorderWdth = pGUI->getCrntPenWidth();


	// this do while to prevent the user from drawing out side the drawing area
	do
	{
		do
		{
			//Step 1 - Read Square data from the user
			pGUI->PrintMessage("New Square: Click at first point");

			//Read 1st point and store in point P1
			pGUI->GetPointClicked(P1.x, P1.y);

		} while (!pGUI->isWithinDrawingArea(P1.y));

		do
		{
			pGUI->PrintMessage("New Square: Click at second point");

			//Read 2nd point and store in point P2
			pGUI->GetPointClicked(P2.x, P2.y);

		} while (!pGUI->isWithinDrawingArea(P2.y));

		//Step 2 - prepare square data
		//User has entered two points P1&P2
		//2.1- Identify the Top left corner of the square

		topLeft.x = P1.x < P2.x ? P1.x : P2.x;
		topLeft.y = P1.y < P2.y ? P1.y : P2.y;

		//2.2- Calcuate square side legnth
		//The square side length would be the longer distance between the two points coordinates
		SideLength = max(abs(P1.x - P2.x), abs(P1.y - P2.y));

	} while (!(P2.y + SideLength <= UI.height - UI.StatusBarHeight && P1.y + SideLength <= UI.height - UI.StatusBarHeight));

	pGUI->ClearStatusBar();

	//Step 3 - Create a Square with the parameters read from the user
	CSquare* R = new CSquare(topLeft, SideLength, SqrGfxInfo);

	//Step 4 - Add the Square to the list of figures
	pManager->AddFigure(R);
}
