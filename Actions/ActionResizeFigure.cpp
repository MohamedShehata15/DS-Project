#include "ActionResizeFigure.h"

#include "..\ApplicationManager.h"
#include "..\GUI\GUI.h"
#include <iostream>



ActionResizeFigure::ActionResizeFigure(ApplicationManager* pApp, ActionType ActType) :Action(pApp), act_type_(ActType)
{}



//Execute the action
void ActionResizeFigure::Execute()
{
	float resizeFactor = 1;
	GUI* pGUI = pManager->GetGUI();
	int selectedFigureIndex = pManager->getIndexOfSelectedFigure();
	if (selectedFigureIndex == -1)
		pGUI->PrintMessage("Please Select the Shape first!!!");
	else
	{
		CFigure* selectedFigure = pManager->getSelectedFigure(selectedFigureIndex);
		switch (act_type_)
		{
		case QUARTER_FACTOR:
			resizeFactor = 0.25;
			break;
		case HALF_FACTOR:
			resizeFactor = 0.5;
			break;
		case DOUBLE_FACTOR:
			resizeFactor = 2;
			break;
		case QUADRUPLE_FACTOR:
			resizeFactor = 4;
			break;
		}
		selectedFigure->Resize(pGUI, resizeFactor);
	}

	pGUI->ClearDrawArea();
}
