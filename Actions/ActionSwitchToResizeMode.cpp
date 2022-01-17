#include "ActionSwitchToResizeMode.h"

#include "..\ApplicationManager.h"
#include "..\GUI\GUI.h"
#include <iostream>



ActionSwitchToResizeMode::ActionSwitchToResizeMode(ApplicationManager* pApp) :Action(pApp)
{}




//Execute the action
void ActionSwitchToResizeMode::Execute()
{

	GUI* pGUI = pManager->GetGUI();
	pGUI->CreateResizeToolBar();

}
