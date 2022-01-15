#include "ActionUploadFile.h"
#include "..\ApplicationManager.h"
#include "..\GUI\GUI.h"



ActionUploadFile::ActionUploadFile(ApplicationManager* pApp) :Action(pApp)
{}


//Execute the action
void ActionUploadFile::Execute()
{

	//Get a Pointer to the Interface
	GUI* pGUI = pManager->GetGUI();
	pGUI->PrintMessage("Type file name to upload");




}
