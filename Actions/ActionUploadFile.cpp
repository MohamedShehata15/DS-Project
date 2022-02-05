#include "ActionUploadFile.h"
#include "..\ApplicationManager.h"

#include "..\Figures\CEllipse.h"
#include "..\Figures\CSquare.h"
#include "..\Figures\CHexagon.h"
#include "..\GUI\GUI.h"
#include <fstream>
#include <iostream>
using namespace std;


ActionUploadFile::ActionUploadFile(ApplicationManager* pApp) :Action(pApp)
{}


//Execute the action
void ActionUploadFile::Execute()
{
	//Get a Pointer to the Interface
	GUI* pGUI = pManager->GetGUI();
	pGUI->PrintMessage("Type file name to upload");
	//take filename from user input
	FileName = pGUI->GetSrting() + ".txt";
	pGUI->ClearStatusBar();
	//open TheFile
	TheFile.open("./FiguresFiles/"+FileName);
	//check if the file doesn't exists
	if (TheFile.is_open())
	{
		pManager->clearAllFigures(); //delete all figure in drawing area
		pGUI->ClearDrawArea();
		pGUI->PrintMessage("The file was loaded successfully");

// drawing color
		string Draw_Color; 
		TheFile >> Draw_Color;
		color CurrentDrawColor = pGUI->ChangeColor(Draw_Color);
		pGUI->setnewDrawColor(CurrentDrawColor);
	

//filling color
		string Fill_Color; // variable for filling color

		TheFile >> Fill_Color;
		if (Fill_Color == "NO_FILL")   //if no fill make fill color=backgroundcolor
		{
			pGUI->setIsFilled(false);
		}
        //there is fill color
		else {
			pGUI->setIsFilled(true);
			color CurrentFillColor = pGUI->ChangeColor(Fill_Color);
			pGUI->setnewFillColor(CurrentFillColor);
		     }

//Background color

		string BG_Color; // variable for BG color
		TheFile >> BG_Color;
		cout << BG_Color;
		color CurrentbgColor = pGUI->ChangeColor(BG_Color);
		pGUI->setnewBackgroundColor(CurrentbgColor);

//get shapes
		int Number_of_Figures; //variable for num of figures
		TheFile >> Number_of_Figures; 
		cout<< Number_of_Figures;

		//shape type
		while (!TheFile.eof()) //until the end of the file
		{
			CFigure* loadedFigure = NULL; //pointer to loaded figure
			string shape_type; //variable for type of shape
			GfxInfo FigGfxInfo; //style for the shape
			FigGfxInfo.BorderWdth = UI.PenWidth;


			TheFile >> shape_type;
			cout << shape_type;
			if (shape_type == "SQR")
			{
				Point topLeft;
				int SideLength = 0;
				topLeft.x = 0; topLeft.y = 0;
				loadedFigure = new CSquare(topLeft,SideLength,FigGfxInfo);
			}
			else if (shape_type == "ELPS")
			{
				Point center;
				int yradius=0;
				int xradius=0;
				center.x = 0; 
				center.y = 0;
				loadedFigure = new CEllipse(center, yradius, xradius, FigGfxInfo);
			}
			else if (shape_type == "HEXA")
			{
				Point center;
				center.x = 0;
				center.y = 0;
				loadedFigure = new CHexagon(center, NULL, NULL, FigGfxInfo);
			}


			//whie there are shapes
			if (loadedFigure != NULL) 
			{
				loadedFigure->upload(pGUI,TheFile); //upload them
				pManager->AddFigure(loadedFigure);//add them to drawing area
			}

			shape_type.clear(); 
			loadedFigure = NULL; //reset pointer
		}

	} //end of case(file oppened)
	// wrong name for file
	else
	{
		pGUI->PrintMessage("This file not exists");
	}





}
