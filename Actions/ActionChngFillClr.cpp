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

	pGUI->setnewFillColor(pGUI->getAppliedColor());
}

