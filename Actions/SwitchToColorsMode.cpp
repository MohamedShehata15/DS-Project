#include "SwitchToColorsMode.h"
#include "..\ApplicationManager.h"
#include "..\GUI\GUI.h"



SwitchToColorsMode::SwitchToColorsMode(ApplicationManager* pApp) :Action(pApp)
{}


//Execute the action
void SwitchToColorsMode::Execute()
{
	GUI* pGUI = pManager->GetGUI();
	pGUI->CreateColorToolBar();
	pGUI->PrintMessage("Select A color ");
}
