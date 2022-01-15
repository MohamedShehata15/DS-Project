#include "ActionBringToFront.h"

#include "..\ApplicationManager.h"
#include "..\GUI\GUI.h"
#include <iostream>



ActionBringToFront::ActionBringToFront(ApplicationManager* pApp) :Action(pApp)
{}




//Execute the action
void ActionBringToFront::Execute()
{

	GUI* pGUI = pManager->GetGUI();


	int selectedFigureIndex = pManager->getIndexOfSelectedFigure();
	if (selectedFigureIndex == -1)
		pGUI->PrintMessage("Please Select the Shape first!!!");
	else
		pManager->moveFigureThenShift(selectedFigureIndex, pManager->getFigCount() - 1);
		

}
