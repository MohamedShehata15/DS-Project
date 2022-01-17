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


	//int test = 0;
	//int counter = 0;

	//do {
	//	cout << "inside do while" << endl;
	//	cout << counter++ << endl;
	//	newColor = pManager->GetUserAction();
	//	if (newColor == CLR_BLUE)
	//	{
	//		pGUI->setnewBackgroundColor(BLUE);
	//	}
	//	else if (newColor == CLR_BLACK) {
	//		pGUI->setnewBackgroundColor(BLACK);
	//	}
	//	else if (newColor == CLR_GREEN) {
	//		pGUI->setnewBackgroundColor(GREEN);
	//	}
	//	else if (newColor == CLR_YELLOW) {
	//		pGUI->setnewBackgroundColor(YELLOW);
	//	}
	//	else if (newColor == CLR_RED) {
	//		pGUI->setnewBackgroundColor(RED);
	//		test = 1;
	//	}
	//	else if (newColor == default_setting) {
	//		pGUI->PrintMessage("Now Your background color set to default");
	//		pGUI->setnewBackgroundColor(LIGHTGOLDENRODYELLOW);
	//	} else {
	//		break;
	//	}
	//} while (test == 1);


	//do {
	//	cout << "inside do while" << endl;
	//	newColor = pManager->GetUserAction();
	//	switch (newColor)
	//	{
	//	case CLR_BLUE:
	//		pGUI->setnewBackgroundColor(BLUE);
	//		break;

	//	case CLR_BLACK:
	//		pGUI->setnewBackgroundColor(BLACK);
	//		break;

	//	case CLR_GREEN:
	//		pGUI->setnewBackgroundColor(GREEN);
	//		break;

	//	case CLR_YELLOW:
	//		pGUI->setnewBackgroundColor(YELLOW);
	//		break;

	//	case CLR_RED:
	//		pGUI->setnewBackgroundColor(RED);
	//		test = 1;
	//		break;

	//	case default_setting:
	//		pGUI->PrintMessage("Now Your background color set to default");
	//		pGUI->setnewBackgroundColor(LIGHTGOLDENRODYELLOW);
	//		break;

	//	default:
	//		break;
	//	}
	//} while (test == 1);


}

