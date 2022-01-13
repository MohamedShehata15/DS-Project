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


	// Get a Pointer to the Interface
	GUI* pGUI = pManager->GetGUI();


	GfxInfo EllipseGfxInfo;
	EllipseGfxInfo.isFilled = pGUI->getIsFilled();	//default is not filled
	//get drawing, filling colors and pen width from the interface
	EllipseGfxInfo.DrawClr = pGUI->getCrntDrawColor();
	EllipseGfxInfo.FillClr = pGUI->getCrntFillColor();
	EllipseGfxInfo.BorderWdth = pGUI->getCrntPenWidth();


	// this do while to prevent the user from drawing out side the drawing area
	do
	{
		//Step 1 - Read Ellipse data from the user
		pGUI->PrintMessage("New Ellipse: Click on the Center");

		//Read the center point of ellipse
		pGUI->GetPointClicked(center.x, center.y);

	} while (center.y <= 54 || center.y >= 649);

	do
	{
		//Step 1 - Read Ellipse data from the user
		pGUI->PrintMessage("New Ellipse: Click on the horizontal Point");

		pGUI->GetPointClicked(P1.x, P1.y);

	} while (P1.y <= 54 || P1.y >= 649);


	// this do while to prevent the user from drawing out side the drawing area
	do
	{
		//Step 1 - Read Ellipse data from the user
		pGUI->PrintMessage("New Ellipse: Click on the vertical Point");

		pGUI->GetPointClicked(P2.x, P2.y);

	} while (P2.y <= 54 || P2.y >= 649);


	pGUI->ClearStatusBar();

	//The yr length
	//y radius  
	int yr = max(abs(P1.x - center.x), abs(P1.y - center.y));
	//x radius
	int xr = max(abs(P2.x - center.x), abs(P2.y - center.y));





	//Step 3 - Create an Ellipse with the parameters read from the user
	CEllipse *E = new CEllipse(center,yr,xr, EllipseGfxInfo);

	//Step 4 - Add the Elipse to the list of figures
	   pManager->AddFigure(E);
}
