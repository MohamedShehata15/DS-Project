#include "ActionUploadFile.h"
#include "..\ApplicationManager.h"

#include "..\Figures\CEllipse.h"
#include "..\Figures\CSquare.h"
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
	TheFile.open(FileName);
	//check if the file doesn't exists
	if (TheFile.is_open())
	{
		pManager->clearAllFigures(); //delete all figure in drawing area
		pGUI->ClearDrawArea();
		pGUI->PrintMessage("The file was loaded successfully");

		//Read from file

		string Draw_Color; // variable for drawing color
		TheFile >> Draw_Color;
		cout<<Draw_Color;
		if (Draw_Color=="BLUE")
		{
			pGUI->setnewDrawColor(BLUE);
		}
		else if (Draw_Color == "BLACK")
		{
			pGUI->setnewDrawColor(BLACK);
		}

		else if (Draw_Color == "OFFWHITE")
		{
			pGUI->setnewDrawColor(LIGHTGOLDENRODYELLOW);
		}

		else if (Draw_Color == "GREEN")
		{
			pGUI->setnewDrawColor(GREEN);
		}

		else if (Draw_Color == "YELLOW")
		{
			pGUI->setnewDrawColor(YELLOW);
		}

		else if (Draw_Color == "RED")
		{
			pGUI->setnewDrawColor(RED);
		}//end of drawing color


//filling color
		string Fill_Color; // variable for filling color

		TheFile >> Fill_Color;
		cout << Fill_Color;
		if (Fill_Color == "NO_FILL")   //if no fill make fill color=backgroundcolor
		{
			pGUI->setnewFillColor(pGUI->getCrntBgColor());

		}
        //there is fill color
		else {
			pGUI->setIsFilled(true);
			if (Fill_Color == "BLUE")
			{
				pGUI->setnewFillColor(BLUE);
			}
			else if (Fill_Color == "BLACK")
			{
				pGUI->setnewFillColor(BLACK);
			}

			else if (Fill_Color == "OFFWHITE")
			{
				pGUI->setnewFillColor(LIGHTGOLDENRODYELLOW);
			}

			else if (Fill_Color == "GREEN")
			{
				pGUI->setnewFillColor(GREEN);
			}

			else if (Fill_Color == "YELLOW")
			{
				pGUI->setnewFillColor(YELLOW);
			}

			else if (Fill_Color == "RED")
			{
				pGUI->setnewFillColor(RED);
			}
		}// end of filling color



//Background color

		string BG_Color; // variable for BG color
		TheFile >> BG_Color;
		cout << BG_Color;
		if (BG_Color == "BLUE")
		{
			pGUI->setnewBackgroundColor(BLUE);
		}
		else if (BG_Color == "BLACK")
		{
			pGUI->setnewBackgroundColor(BLACK);
		}

		else if (BG_Color == "OFFWHITE")
		{
			pGUI->setnewBackgroundColor(LIGHTGOLDENRODYELLOW);
		}

		else if (BG_Color == "GREEN")
		{
			pGUI->setnewBackgroundColor(GREEN);
		}

		else if (BG_Color == "YELLOW")
		{
			pGUI->setnewBackgroundColor(YELLOW);
		}

		else if (BG_Color == "RED")
		{
			pGUI->setnewBackgroundColor(RED);
		}//end of Background color

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


			//whie there are shapes
			if (loadedFigure != NULL) 
			{
				loadedFigure->upload(TheFile); //upload them
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
