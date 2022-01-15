#include "ActionChngFillClr.h"
#include "..\ApplicationManager.h"
#include "..\GUI\GUI.h"




ActionChngFillClr::ActionChngFillClr(ApplicationManager* pApp) :Action(pApp)
{

}


void ActionChngFillClr::Execute()
{
	GUI* pGUI = pManager->GetGUI();

	pGUI->PrintMessage("Select A color for filling and for no filling select restore icon ");

	newColor = pManager->GetUserAction();

	switch (newColor)
	{
	case CLR_BLUE:
		UI.isFilled = true;
		pGUI->setnewFillColor(BLUE);
		pGUI->PrintMessage("Now you can draw shape filled by blue");

		break;

	case CLR_BLACK:
		UI.isFilled = true;
		pGUI->setnewFillColor(BLACK);
		pGUI->PrintMessage("Now you can draw shape filled by black");

		break;

	case CLR_GREEN:
		UI.isFilled = true;
		pGUI->setnewFillColor(GREEN);
		pGUI->PrintMessage("Now you can draw shape filled by green");
		break;

	case CLR_YELLOW:
		UI.isFilled = true;
		pGUI->setnewFillColor(YELLOW);
		pGUI->PrintMessage("Now you can draw shape filled by yellow");

		break;

	case CLR_RED:
		UI.isFilled = true;
		pGUI->setnewFillColor(RED);
		pGUI->PrintMessage("Now you can draw shape filled by red");
		break;

	case default_setting:
		UI.isFilled = false;
		pGUI->PrintMessage("No fill");
		break;

	default:
		break;
	}


}

