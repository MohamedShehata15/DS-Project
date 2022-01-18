#include "ActionChngFillClr.h"
#include "..\ApplicationManager.h"
#include "..\GUI\GUI.h"
#include <iostream>




ActionChngFillClr::ActionChngFillClr(ApplicationManager* pApp) :Action(pApp)
{

}


void ActionChngFillClr::Execute()
{
	GUI* pGUI = pManager->GetGUI();
	pGUI->PrintMessage("You selected a new color, for no filling click restore icon and to draw go back");


	int selectedFigureIndex = pManager->getIndexOfSelectedFigure();
	if (selectedFigureIndex > -1) {
		CFigure* selectedFigure = pManager->getSelectedFigure(selectedFigureIndex);
		selectedFigure->ChngFillClr(pGUI->getAppliedColor());
	}
	else {
		pGUI->setIsFilled(true);
		pGUI->setnewFillColor(pGUI->getAppliedColor());
	}

}

