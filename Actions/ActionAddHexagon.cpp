#include "ActionAddHexagon.h"
#include "..\Figures\CHexagon.h"
#include "..\DEFS.h"
#include "..\ApplicationManager.h"
#include "..\GUI\GUI.h"


ActionAddHexagon::ActionAddHexagon(ApplicationManager* pApp) :Action(pApp)
{
	pGUI = pApp->GetGUI();
}

//Execute the action
void ActionAddHexagon::Execute()
{
	Point center, vertex;

	//Get a Pointer to the Interface
	


	//get drawing, filling colors and pen width from the interface
	GfxInfo HexGfxInfo;
	HexGfxInfo.isFilled = UI.isFilled;
	HexGfxInfo.DrawClr = pGUI->getCrntDrawColor();
	HexGfxInfo.FillClr = pGUI->getCrntFillColor();
	HexGfxInfo.BorderWdth = pGUI->getCrntPenWidth();


	//Step 1 - Read Hexagon data from the user

	pGUI->PrintMessage("New Hexagon: Click at center point");
	//Read 1st point and store in point center
	do {
		pGUI->GetPointClicked(center.x, center.y);
	} while (!pGUI->isInsideDrawingArea(center.x, center.y));


	pGUI->PrintMessage("New Hexagon: Click at vertex point");
	//Read 2nd point and store in point vertex
	do {
		pGUI->GetPointClicked(vertex.x, vertex.y);
	} while (!pGUI->isInsideDrawingArea(vertex.x, vertex.y));

	pGUI->ClearStatusBar();

	float angle = pGUI->GetHexagonAngle(center, vertex);
	float radius = pGUI->GetHexagonRadius(center, vertex);
	int xCoordinates[6];
	int yCoordinates[6];
	pGUI->GetHexagonCoordinates(center, radius, angle, xCoordinates, yCoordinates);
	if (pGUI->isInsideDrawingArea(xCoordinates, yCoordinates, 6)) {
		CHexagon* hexagon = new CHexagon(center, angle, radius, HexGfxInfo);
		pManager->AddFigure(hexagon);
	}
	else {
		pGUI->PrintMessage("Can't draw outside the drawing area!");
	}

}



