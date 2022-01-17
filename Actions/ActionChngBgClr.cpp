#include "ActionChngBgClr.h"
#include "..\ApplicationManager.h"
#include "..\GUI\GUI.h"
#include <iostream>




ActionChngBgClr::ActionChngBgClr(ApplicationManager* pApp) :Action(pApp)
{

}


void ActionChngBgClr::Execute()
{

	cout << "Action change Background color" << endl;

	GUI* pGUI = pManager->GetGUI();

	pGUI->setnewBackgroundColor(pGUI->getAppliedColor());
}

