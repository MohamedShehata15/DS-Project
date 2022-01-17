#include "ActionclearAllFigures.h"
#include "..\ApplicationManager.h"
#include "..\GUI\GUI.h"
#include <iostream>




ActionclearAllFigures::ActionclearAllFigures(ApplicationManager* pApp) :Action(pApp)
{

}


void ActionclearAllFigures::Execute()
{

	GUI* pGUI = pManager->GetGUI();

	pManager->clearAllFigures();
	pGUI->ClearDrawArea();
}

