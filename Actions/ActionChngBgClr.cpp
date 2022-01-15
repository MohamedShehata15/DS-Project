#include "ActionChngBgClr.h"
#include "..\ApplicationManager.h"
#include "..\GUI\GUI.h"




ActionChngBgClr::ActionChngBgClr(ApplicationManager* pApp) :Action(pApp)
{

}


void ActionChngBgClr::Execute()
{
	GUI* pGUI = pManager->GetGUI();
	pGUI->PrintMessage("Select A color for Your backGround ,Please");

	newColor = pManager->GetUserAction();

	switch (newColor)
	{
	case CLR_BLUE:
		pGUI->setnewBackgroundColor(BLUE);
		break;

	case CLR_BLACK:
		pGUI->setnewBackgroundColor(BLACK);
		break;

	case CLR_GREEN:
		pGUI->setnewBackgroundColor(GREEN);
		break;

	case CLR_YELLOW:
		pGUI->setnewBackgroundColor(YELLOW);
		break;

	case CLR_RED:
		pGUI->setnewBackgroundColor(RED);
		break;

	default:
		break;
	}


}

