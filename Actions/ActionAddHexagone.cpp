#include "ActionAddHexagone.h"
#include "..\Figures\CHexagone.h"

#include "..\ApplicationManager.h"

#include "..\GUI\GUI.h"
#include <iostream>

ActionAddHexagone::ActionAddHexagone(ApplicationManager* pApp) :Action(pApp)
{}

//Execute the action
void ActionAddHexagon::Execute()
{
	Point points[6];

	//Get a Pointer to the Interface
	GUI* pGUI = pManager->GetGUI();


	GfxInfo SqrGfxInfo;
	SqrGfxInfo.isFilled = pGUI->getFillState();

	SqrGfxInfo.DrawClr = pGUI->getCrntDrawColor();
	SqrGfxInfo.FillClr = pGUI->getCrntFillColor();
	SqrGfxInfo.BorderWdth = pGUI->getCrntPenWidth();



	for (int i = 0; i < 6; i++) {
		pGUI->PrintMessage("New Hexagon: Click at point: " + to_string(i));
		pGUI->getPointInsideDrawArea(points[i].x, points[i].y);
	}
	pGUI->ClearStatusBar();



	CHexagone* R = new CHexagone(points, SqrGfxInfo);


	pManager->AddFigure(R);
}