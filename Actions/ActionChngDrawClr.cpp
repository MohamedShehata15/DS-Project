#include "ActionChngDrawClr.h"
#include "..\ApplicationManager.h"
#include "..\GUI\GUI.h"



ActionChngDrawClr::ActionChngDrawClr(ApplicationManager* pApp) :Action(pApp)
{
	
}


void ActionChngDrawClr::Execute()
{
	GUI* pGUI = pManager->GetGUI();
	pGUI->PrintMessage("Select A color for drawing and for selecting the default click restore icon ");

	pGUI->setnewDrawColor(pGUI->getAppliedColor());
	
}

