#include "ActionDefaultDrawing.h"

#include "..\ApplicationManager.h"
#include "..\GUI\GUI.h"
#include <iostream>


ActionDefaultDrawing::ActionDefaultDrawing(ApplicationManager* pApp) :Action(pApp)
{}


//Execute the action
void ActionDefaultDrawing::Execute()
{

	GUI* pGUI = pManager->GetGUI();
	
	pGUI->setnewFillColor(GREEN);
	pGUI->setIsFilled(false);
	pGUI->setnewDrawColor(BLACK);
	pGUI->setnewBackgroundColor(LIGHTGOLDENRODYELLOW);


}
