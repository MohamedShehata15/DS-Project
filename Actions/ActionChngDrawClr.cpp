#include "ActionChngDrawClr.h"
#include "..\ApplicationManager.h"
#include "..\GUI\GUI.h"
#include <iostream>



ActionChngDrawClr::ActionChngDrawClr(ApplicationManager* pApp) :Action(pApp)
{
	
}


void ActionChngDrawClr::Execute()
{
	GUI* pGUI = pManager->GetGUI();
	pGUI->PrintMessage("Select A color for drawing and for selecting the default click restore icon ");

	int selectedFigureIndex = pManager->getIndexOfSelectedFigure();
	if (selectedFigureIndex > -1) {
		CFigure *selectedFigure = pManager->getSelectedFigure(selectedFigureIndex);
		selectedFigure->ChngDrawClr(pGUI->getAppliedColor());

	} else {
		pGUI->setnewDrawColor(pGUI->getAppliedColor());
	}

	
}

