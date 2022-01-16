#include "ActionSendToBack.h"

#include "..\ApplicationManager.h"
#include "..\GUI\GUI.h"
#include <iostream>



ActionSendToBack::ActionSendToBack(ApplicationManager* pApp) :Action(pApp)
{}



//Execute the action
void ActionSendToBack::Execute()
{
	Point P1;

	//Get a Pointer to the Interface
	GUI* pGUI = pManager->GetGUI();


	// Step 2 - get the selected figure from GetFigure Function
	int selectedFigureIndex = pManager->getIndexOfSelectedFigure();
	if (selectedFigureIndex == -1)
		pGUI->PrintMessage("Please Select the Shape first!!!");
	else
		pManager->moveFigureThenShift(selectedFigureIndex, 0);

}




