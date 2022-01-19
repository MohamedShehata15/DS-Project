#include "ActionSaveFile.h"
#include "..\ApplicationManager.h"
#include "..\GUI\GUI.h"
#include <iostream>



ActionSaveFile::ActionSaveFile(ApplicationManager* pApp) :Action(pApp)
{}


//Execute the action
void ActionSaveFile::Execute()
{
	GUI* pGUI = pManager->GetGUI();
	color currentDrawColor = UI.DrawColor;
	color currentFillColor = UI.FillColor;
	color currentBgColor = UI.BkGrndColor;

	pGUI->PrintMessage("Enter name to save the file ,please");
	//take filename from user input
	FileName = pGUI->GetSrting() + ".txt";
	pGUI->ClearStatusBar();
	//open TheFile
	FileToSave.open(FileName);


	if (FileToSave.is_open())
	{
		string Draw_Color; // variable for drawing color
		string Fill_Color; //variable for filling color
		string bgColor; //variable for bgcolor

		if (currentDrawColor == BLUE)
		{
			Draw_Color= "BLUE";
		}
		else if (currentDrawColor == BLACK)
		{
			Draw_Color = "BLACK";
		}

		else if (currentDrawColor == LIGHTGOLDENRODYELLOW)
		{
		   Draw_Color= "OFFWHITE";
		}

		else if (currentDrawColor == GREEN)
		{
			Draw_Color = "GREEN";
		}

		else if (currentDrawColor == YELLOW)
		{
			Draw_Color = "YELLOW";
		}

		else if (currentDrawColor == RED)
		{
			Draw_Color = "RED";
		}

		//filling color
		if (currentFillColor == BLUE)
		{
			Fill_Color = "BLUE";
		}
		else if (currentFillColor == BLACK)
		{
			Fill_Color = "BLACK";
		}

		else if (currentFillColor == LIGHTGOLDENRODYELLOW)
		{
			Fill_Color = "OFFWHITE";
		}

		else if (currentFillColor == GREEN)
		{
			Fill_Color = "GREEN";
		}

		else if (currentFillColor == YELLOW)
		{
			Fill_Color = "YELLOW";
		}

		else if (currentFillColor == RED)
		{
			Fill_Color = "RED";
		}

		//background color

		if (currentBgColor == BLUE)
		{
			bgColor = "BLUE";
		}
		else if (currentBgColor == BLACK)
		{
			bgColor = "BLACK";
		}

		else if (currentBgColor == LIGHTGOLDENRODYELLOW)
		{
			bgColor = "OFFWHITE";
		}

		else if (currentBgColor == GREEN)
		{
			bgColor = "GREEN";
		}

		else if (currentBgColor == YELLOW)
		{
			bgColor = "YELLOW";
		}

		else if (currentBgColor == RED)
		{
			bgColor = "RED";
		}


		FileToSave << Draw_Color << " " << Fill_Color <<" "<<bgColor<< endl; //write drawcolor  &  fillcolor in the file

		FileToSave << pManager->getFigCount() << endl; //write number of figures in the second line of file

		pManager->SaveAllFigures(FileToSave);


		pGUI->PrintMessage("The graph was save to the file successfully");

		FileToSave.close();
	}




	// wrong name for file
	else
	{
		pGUI->PrintMessage("Failed to save");
	}


}