#include "ActionExit.h"
#include <stdlib.h>
#include "..\ApplicationManager.h"
#include "..\GUI\GUI.h"
#include <iostream>

#include "ActionSaveFile.h"


ActionExit::ActionExit(ApplicationManager* pApp) :Action(pApp)
{}




//Execute the action
void ActionExit::Execute()
{
/*
hint: if figureCount > 0 {
	message box : (do you wan't to save changes?)
		yes ? ActionSave; exit(); : exit();
}*/

	GUI* pGUI = pManager->GetGUI();

	if (pManager->getFigCount() > 0)
	{
        const int msgboxID = MessageBox(
            nullptr, 
            "Their is unsaved figure\nDo you want to save it?", 
            "Exit the game",
            MB_ICONWARNING | MB_YESNOCANCEL | MB_DEFBUTTON2
        );
        switch (msgboxID)
        {
        case IDYES:
        {
	        Action* newAct = new ActionSaveFile(pManager);
	        pManager->ExecuteAction(newAct);
        };
        case IDNO:
            exit(EXIT_SUCCESS);
        case IDCANCEL:
            break;
        }
	}
}
