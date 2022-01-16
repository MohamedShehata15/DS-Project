#include "ActionDeleteFigure.h"

#include "..\ApplicationManager.h"
#include "..\GUI\GUI.h"
#include <iostream>



ActionDeleteFigure::ActionDeleteFigure(ApplicationManager* pApp) :Action(pApp)
{}




//Execute the action
void ActionDeleteFigure::Execute()
{

	GUI* pGUI = pManager->GetGUI();


	int selectedFigureIndex = pManager->getIndexOfSelectedFigure();
	if (selectedFigureIndex == -1)
		pGUI->PrintMessage("Please Select the Shape first!!!");
	else
		pManager->deleteFigure(selectedFigureIndex);
	pGUI->ClearDrawArea();


}
