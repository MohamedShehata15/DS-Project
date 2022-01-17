#include "ActionAddEllipse.h"
#include "..\Figures\CEllipse.h"

#include "..\ApplicationManager.h"

#include "..\GUI\GUI.h"
#include <iostream>



ActionAddEllipse::ActionAddEllipse(ApplicationManager* pApp) :Action(pApp)
{}

//Execute the action
void ActionAddEllipse::Execute()
{
	Point center;
	Point P1;
	Point P2;
	int yr, xr;

	// Get a Pointer to the Interface
	GUI* pGUI = pManager->GetGUI();


	GfxInfo EllipseGfxInfo;
	EllipseGfxInfo.isFilled = UI.isFilled;	//default is not filled
	//get drawing, filling colors and pen width from the interface
	EllipseGfxInfo.DrawClr = pGUI->getCrntDrawColor();
	EllipseGfxInfo.FillClr = pGUI->getCrntFillColor();
	EllipseGfxInfo.BorderWdth = pGUI->getCrntPenWidth();



	// this do while to prevent the user from drawing out side the drawing area
	do
	{
		do
		{
			//Step 1 - Read Ellipse data from the user
			pGUI->PrintMessage("New Ellipse: Click on the Center and please consider the canvas area");

			//Read the center point of ellipse
			pGUI->GetPointClicked(center.x, center.y);


		} while (!pGUI->isWithinDrawingArea(center.y));
		do
		{


			pGUI->PrintMessage("New Ellipse: Click on the horizontal Point and please consider the canvas area");

			pGUI->GetPointClicked(P1.x, P1.y);


		} while (!pGUI->isWithinDrawingArea(P1.y));
		do
		{
			pGUI->PrintMessage("New Ellipse: Click on the vertical Point and please consider the canvas area");

			pGUI->GetPointClicked(P2.x, P2.y);


		} while (!pGUI->isWithinDrawingArea(P2.y));

		//The yr length
		//y radius  
		xr = max(abs(P1.x - center.x), abs(P1.y - center.y));
		//x radius
		yr = max(abs(P2.x - center.x), abs(P2.y - center.y));

	} while (!(center.y + yr <= (UI.height - UI.StatusBarHeight) && center.y - yr >= UI.StatusBarHeight && center.x + xr <= UI.width && center.x - xr >= 0));

	pGUI->ClearStatusBar();






	//Step 3 - Create an Ellipse with the parameters read from the user
	CEllipse* E = new CEllipse(center, xr, yr, EllipseGfxInfo);

	//Step 4 - Add the Elipse to the list of figures
	pManager->AddFigure(E);
}
