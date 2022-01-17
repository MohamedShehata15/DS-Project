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

	//newColor = pManager->GetUserAction();

	//switch (newColor)
	//{
	//case CLR_BLUE:
	//	pGUI->PrintMessage("Now You can draw with blue");
	//	pGUI->setnewDrawColor(BLUE);
	//	break;

	//case CLR_BLACK:
	//	pGUI->PrintMessage("Now You can draw with black");
	//	pGUI->setnewDrawColor(BLACK);
	//	break;

	//case CLR_GREEN:
	//	pGUI->PrintMessage("Now You can draw with green");
	//	pGUI->setnewDrawColor(GREEN);
	//	break;

	//case CLR_YELLOW:
	//	pGUI->PrintMessage("Now You can draw with yellow");
	//	pGUI->setnewDrawColor(YELLOW);
	//	break;

	//case CLR_RED:
	//	pGUI->PrintMessage("Now You can draw with red");
	//	pGUI->setnewDrawColor(RED);
	//	break;

	//case default_setting:
	//	pGUI->PrintMessage("Now You can draw with default color");
	//	pGUI->setnewDrawColor(BLACK);
	//	break;

	//default:
	//	break;
	//}
	
	
}

