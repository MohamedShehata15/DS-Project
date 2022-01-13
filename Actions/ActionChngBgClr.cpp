#include "ActionChngBgClr.h"
#include "..\ApplicationManager.h"
#include "..\GUI\GUI.h"
#include "..\CMUgraphicsLib\CMUgraphics.h"




ActionChngBgClr::ActionChngBgClr(ApplicationManager* pApp) :Action(pApp)
{

}


void ActionChngBgClr::Execute()
{
	GUI* pGUI = pManager->GetGUI();
	pGUI->PrintMessage("Select A color for Your backGround ,Please");

	newColor = pManager->GetUserAction();
	pGUI->setIsFilled(true);

	switch (newColor)
	{
	case CLR_BLUE:
		pGUI->setnewFillColor(BLUE);
		break;

	case CLR_BLACK:
		pGUI->setnewFillColor(BLACK);
		break;

	case CLR_GREEN:
		pGUI->setnewFillColor(GREEN);
		break;

	case CLR_YELLOW:
		pGUI->setnewFillColor(YELLOW);
		break;

	case CLR_RED:
		pGUI->setnewFillColor(RED);
		break;

	default:
		break;
	}


}

