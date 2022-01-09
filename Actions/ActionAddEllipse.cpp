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
	Point P1;

	//Get a Pointer to the Interface
	GUI* pGUI = pManager->GetGUI();


	GfxInfo EllipseGfxInfo;
	EllipseGfxInfo.isFilled = false;	//default is not filled
	//get drawing, filling colors and pen width from the interface
	EllipseGfxInfo.DrawClr = pGUI->getCrntDrawColor();
	EllipseGfxInfo.FillClr = pGUI->getCrntFillColor();
	EllipseGfxInfo.BorderWdth = pGUI->getCrntPenWidth();


	// this do while to prevent the user from drawing out side the drawing area
	do
	{
		//Step 1 - Read Ellipse data from the user
		pGUI->PrintMessage("New Ellipse: Click at the center");

		//Read the center point of ellipse
		pGUI->GetPointClicked(P1.x, P1.y);

	} while (P1.y <= 54 || P1.y >= 649);

	pGUI->ClearStatusBar();

	//Step 3 - Create an Ellipse with the parameters read from the user
	CEllipse *E = new CEllipse(P1, EllipseGfxInfo);

	//Step 4 - Add the Elipse to the list of figures
	   pManager->AddFigure(E);
}
