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
		

		if (int(UI.DrawColor.ucRed) == 0 && int(UI.DrawColor.ucGreen) == 0 && int(UI.DrawColor.ucBlue) == 0)
			Draw_Color = "BLACK";
		if (int(UI.DrawColor.ucRed) == 255 && int(UI.DrawColor.ucGreen) == 0 && int(UI.DrawColor.ucBlue) == 0)
			Draw_Color = "RED";
		if (int(UI.DrawColor.ucRed) == 0 && int(UI.DrawColor.ucGreen) == 255 && int(UI.DrawColor.ucBlue) == 0)
			Draw_Color = "GREEN";
		if (int(UI.DrawColor.ucRed) == 0 && int(UI.DrawColor.ucGreen) == 0 && int(UI.DrawColor.ucBlue) == 255)
			Draw_Color = "BLUE";
		if (int(UI.DrawColor.ucRed) == 255 && int(UI.DrawColor.ucGreen) == 255 && int(UI.DrawColor.ucBlue) == 0)
			Draw_Color = "YELLOW";
		if (int(UI.DrawColor.ucRed) == 250 && int(UI.DrawColor.ucGreen) == 250 && int(UI.DrawColor.ucBlue) == 210)
			Draw_Color = "OFFWHITE";

		//filling color
		if (int(UI.FillColor.ucRed) == 0 && int(UI.FillColor.ucGreen) == 0 && int(UI.FillColor.ucBlue) == 0)
			Fill_Color = "BLACK";
		if (int(UI.FillColor.ucRed) == 255 && int(UI.FillColor.ucGreen) == 0 && int(UI.FillColor.ucBlue) == 0)
			Fill_Color = "RED";
		if (int(UI.FillColor.ucRed) == 0 && int(UI.FillColor.ucGreen) == 255 && int(UI.FillColor.ucBlue) == 0)
			Fill_Color = "GREEN";
		if (int(UI.FillColor.ucRed) == 0 && int(UI.FillColor.ucGreen) == 0 && int(UI.FillColor.ucBlue) == 255)
			Fill_Color = "BLUE";
		if (int(UI.FillColor.ucRed) == 255 && int(UI.FillColor.ucGreen) == 255 && int(UI.FillColor.ucBlue) == 0)
			Fill_Color = "YELLOW";
		if (int(UI.FillColor.ucRed) == 250 && int(UI.FillColor.ucGreen) == 250 && int(UI.FillColor.ucBlue) == 210)
			Fill_Color = "NO_FILL";

		//background color

		if (int(UI.BkGrndColor.ucRed) == 0 && int(UI.BkGrndColor.ucGreen) == 0 && int(UI.BkGrndColor.ucBlue) == 0)
			bgColor = "BLACK";
		if (int(UI.BkGrndColor.ucRed) == 255 && int(UI.BkGrndColor.ucGreen) == 0 && int(UI.BkGrndColor.ucBlue) == 0)
			bgColor = "RED";
		if (int(UI.BkGrndColor.ucRed) == 0 && int(UI.BkGrndColor.ucGreen) == 255 && int(UI.BkGrndColor.ucBlue) == 0)
			bgColor = "GREEN";
		if (int(UI.BkGrndColor.ucRed) == 0 && int(UI.BkGrndColor.ucGreen) == 0 && int(UI.BkGrndColor.ucBlue) == 255)
			bgColor = "BLUE";
		if (int(UI.BkGrndColor.ucRed) == 255 && int(UI.BkGrndColor.ucGreen) == 255 && int(UI.BkGrndColor.ucBlue) == 0)
			bgColor = "YELLOW";
		if (int(UI.DrawColor.ucRed) == 250 && int(UI.DrawColor.ucGreen) == 250 && int(UI.DrawColor.ucBlue) == 210)
			bgColor = "OFFWHITE";




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