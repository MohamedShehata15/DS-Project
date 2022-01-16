#include "ActionSelect.h"

#include "..\ApplicationManager.h"
#include "..\GUI\GUI.h"
#include <iostream>



ActionSelect::ActionSelect(ApplicationManager* pApp) :Action(pApp)
{}


/**
* selection steps
* 1- Add Select_Enum to the ActionType Enum
* 2- Create class ActionSelect that inherits from Action
* 3- override the exeute function of the ActionSelect class
*	1- get the point that the user clicked on it
*	2- calling the getFigure function to get the selectedd shape ---> see how to implment it
*		1- go to the getFigure Function and make a loop from the end of the figlist
*		2- add a new vitrual function to the CFigure class that takes a x, y
*		and return true or false depending on if this point within the shape area or not
*	4- modify the selected attribute using setSelected();
*/

//Execute the action
void ActionSelect::Execute()
{
	Point P1;

	//Get a Pointer to the Interface
	GUI* pGUI = pManager->GetGUI();

	//Step 1 - get the point of the shape the user wants to select it 
	// this do while to prevent the user from drawing out side the drawing area
	do
	{
		pGUI->PrintMessage("Please click on the required shape :)");

		//Read 1st point and store in point P1
		pGUI->GetPointClicked(P1.x, P1.y);

	} while (P1.y <= 54 || P1.y >= 649);
	
	// Step 2 - get the selected figure from GetFigure Function 
	CFigure* selectedFigure = pManager->GetFigure(P1.x, P1.y);
	if (selectedFigure != nullptr)
	{
		bool isSelectedFigureSelcted = selectedFigure->IsSelected();
		pManager->deSelectAllFigures();
		selectedFigure->SetSelected(isSelectedFigureSelcted);
		// Step 3 - modify the selected field
		if (selectedFigure->IsSelected())
			selectedFigure->SetSelected(false);
		else
			selectedFigure->SetSelected(true);
		selectedFigure->PrintInfo(pGUI);
	}




}
