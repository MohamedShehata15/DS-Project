#include "CEllipse.h"
#include "..\ApplicationManager.h"
#include "..\GUI\GUI.h"

#include <iostream>
#include <fstream>


CEllipse::CEllipse(Point P1, int xr,int yr, GfxInfo FigureGfxInfo):CFigure(FigureGfxInfo)
{
	ID = ++ellipseNum;
	center = P1;
	xradius = xr;
	yradius = yr;
}

int CEllipse::ellipseNum = 0;


bool CEllipse::isWithinArea(int x ,int y)
{

	return ((((pow((x - center.x), 2)) / (yradius * yradius)) + ((pow((y - center.y), 2)) / (xradius * xradius))) <= 1);
}
void CEllipse::Resize(GUI* pGUI,float resizeFactor)
{
	int oldXRadius = xradius;
	int oldYRadius = yradius;
	xradius *= resizeFactor;
	yradius *= resizeFactor;
	checkSize(pGUI, oldXRadius ,oldYRadius);
}

void CEllipse::checkSize(GUI* pGUI, int oldXRadius, int oldYRadius)
{
	// check if the size of the square became bigger than the drawing area
	if (!(center.y + yradius <= (UI.height - UI.StatusBarHeight) && center.y - yradius >= UI.StatusBarHeight && center.x + xradius <= UI.width && center.x - xradius >= 0))
	{
		xradius = oldXRadius;
		yradius = oldYRadius;
		pGUI->PrintMessage("I can't be bigger than this :(");
	}
	// check if the square size smaller than normal
	else if (xradius <= 20 || yradius <= 20)
	{
		xradius = oldXRadius;
		yradius = oldYRadius;
		pGUI->PrintMessage("I can't be smaller than this :(");
	}
}
void CEllipse::PrintInfo(GUI* pGUI)
{
	pGUI->PrintMessage(
		"Ellipse Id: " + to_string(ID) +
		", center: (" + to_string(center.x) + ", " + to_string(center.y) + ")" +
		", Y Radius: " + to_string(yradius) +
		", X Radius: " + to_string(xradius) +
		", area: " + to_string(3.14* yradius * xradius) +
		", border-color: (" + to_string(FigGfxInfo.DrawClr.ucRed) + ", " + to_string(FigGfxInfo.DrawClr.ucGreen) + ", " + to_string(FigGfxInfo.DrawClr.ucBlue) + ")" +
		", fill-color: (" + to_string(FigGfxInfo.FillClr.ucRed) + ", " + to_string(FigGfxInfo.FillClr.ucGreen) + ", " + to_string(FigGfxInfo.FillClr.ucBlue) + ")" +
		", Border-Width: " + to_string(FigGfxInfo.BorderWdth));
};

void CEllipse::DrawMe(GUI* pGUI) const
{
	//void GUI::DrawEllipse(Point center, int xCord, int yCord, GfxInfo EllGfxInfo, bool selected) const
	//Call Output::DrawRect to draw a Square on the screen	
	pGUI->DrawEllipse(center, xradius, yradius, FigGfxInfo, Selected);


}

CFigure* CEllipse::GetCopy()
{
	CFigure* Copy = new CEllipse(*this);
	return Copy;
}

//Upload Ellipse
void CEllipse::upload(GUI* pGUI,ifstream &file)
{

	//variables for colors
	string DrawColor;
	string FillColor;
	file >> ID;
	file >> center.x;
	file >> center.y;
	file >> yradius; //integer radius
	file >> xradius; //integer radius
	file >> DrawColor;
	file >> FillColor;
	//which color for draw
	    color CurrentDrawColor = pGUI->ChangeColor(DrawColor);
		FigGfxInfo.DrawClr = CurrentDrawColor;
	
	//which color for filling
	if (FillColor == "NO_FILL")
	{
		FigGfxInfo.isFilled = false;
		FigGfxInfo.FillClr = WHITE;
	}
	else
	{
		FigGfxInfo.isFilled = true;
		color CurrentFillColor = pGUI->ChangeColor(FillColor);
		FigGfxInfo.FillClr = CurrentFillColor;

	}
}//end of upload





void CEllipse::saveFigure(ofstream& file)
{
	string Draw_Color;
	string Fill_Color;
	if (int(FigGfxInfo.DrawClr.ucRed) == 0 && int(FigGfxInfo.DrawClr.ucGreen) == 0 && int(FigGfxInfo.DrawClr.ucBlue) == 0)
		Draw_Color = "BLACK";
	if (int(FigGfxInfo.DrawClr.ucRed) == 255 && int(FigGfxInfo.DrawClr.ucGreen) == 0 && int(FigGfxInfo.DrawClr.ucBlue) == 0)
		Draw_Color = "RED";
	if (int(FigGfxInfo.DrawClr.ucRed) == 0 && int(FigGfxInfo.DrawClr.ucGreen) == 255 && int(FigGfxInfo.DrawClr.ucBlue) == 0)
		Draw_Color = "GREEN";
	if (int(FigGfxInfo.DrawClr.ucRed) == 0 && int(FigGfxInfo.DrawClr.ucGreen) == 0 && int(FigGfxInfo.DrawClr.ucBlue) == 255)
		Draw_Color = "BLUE";
	if (int(FigGfxInfo.DrawClr.ucRed) == 255 && int(FigGfxInfo.DrawClr.ucGreen) == 255 && int(FigGfxInfo.DrawClr.ucBlue) == 0)
		Draw_Color = "YELLOW";
	if (int(FigGfxInfo.DrawClr.ucRed) == 250 && int(FigGfxInfo.DrawClr.ucGreen) == 250 && int(FigGfxInfo.DrawClr.ucBlue) == 210)
		Draw_Color = "OFFWHITE";

	if (FigGfxInfo.isFilled)
	{
		//fill
		if (int(FigGfxInfo.FillClr.ucRed) == 0 && int(FigGfxInfo.FillClr.ucGreen) == 0 && int(FigGfxInfo.FillClr.ucBlue) == 0)
			Fill_Color = "BLACK";
		if (int(FigGfxInfo.FillClr.ucRed) == 255 && int(FigGfxInfo.FillClr.ucGreen) == 0 && int(FigGfxInfo.FillClr.ucBlue) == 0)
			Fill_Color = "RED";
		if (int(FigGfxInfo.FillClr.ucRed) == 0 && int(FigGfxInfo.FillClr.ucGreen) == 255 && int(FigGfxInfo.FillClr.ucBlue) == 0)
			Fill_Color = "GREEN";
		if (int(FigGfxInfo.FillClr.ucRed) == 0 && int(FigGfxInfo.FillClr.ucGreen) == 0 && int(FigGfxInfo.FillClr.ucBlue) == 255)
			Fill_Color = "BLUE";
		if (int(FigGfxInfo.FillClr.ucRed) == 255 && int(FigGfxInfo.FillClr.ucGreen) == 255 && int(FigGfxInfo.FillClr.ucBlue) == 0)
			Fill_Color = "YELLOW";
		if (int(FigGfxInfo.FillClr.ucRed) == 250 && int(FigGfxInfo.FillClr.ucGreen) == 250 && int(FigGfxInfo.FillClr.ucBlue) == 210)
			Fill_Color = "OFFWHITE";
	}
	else
		Fill_Color = "NO_FILL";

	file << "ELPS" << "  " << ID<< "  " << center.x<< "  "  << center.y << "  " << yradius << "  " << xradius << "  " << Draw_Color << "  " <<Fill_Color<< "  " <<endl;

}//end of save







int CEllipse::GetNumber()const
{
	return ellipseNum;
}
//void CEllipse::increase()
//{
//	ellipseNum++;
//}
//void CEllipse::decrease()
//{
//	ellipseNum--;
//}