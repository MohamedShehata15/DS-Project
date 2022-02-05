#include "CHexagon.h"
#include "..\ApplicationManager.h"
#include "..\GUI\GUI.h"

#include <iostream>
#include <fstream>

CHexagon::CHexagon(Point _center, float _angle, int _radius, GfxInfo FigureGfxInfo) :CFigure(FigureGfxInfo)
{
	ID = ++hexNum;
	center = _center;
	angle = _angle;
	radius = _radius;
	GetHexagonCoordinates(center, radius, angle, xCoordinates, yCoordinates);

}

int CHexagon::hexNum = 0;

void CHexagon::GetHexagonCoordinates(Point center, float radius, float angle, int* xCoordinates, int* yCoordinates)
{
	for (int i = 0; i < 6; i++) {
		xCoordinates[i] = (float)center.x + (radius * cos(angle));
		yCoordinates[i] = (float)center.y + (radius * sin(angle));

		angle += (3.14159265 / 3);
	}
}


void CHexagon::DrawMe(GUI* pGUI) const
{
	//Call Output::DrawRect to draw a Square on the screen	
	pGUI->DrawHexagon(center, angle, radius, FigGfxInfo, Selected);
}

bool CHexagon::isWithinArea(int x, int y)
{
	int length = sqrt(pow(center.x - x, 2) + pow(center.y - y, 2));
	return length <= radius;
}

void CHexagon::Resize(GUI* pGUI, float factor)
{

	float oldRadius = radius;
	radius *= factor;
	checkSize(pGUI, oldRadius);

}

void CHexagon::checkSize(GUI* pGUI, int oldRadius)
{
	if (!(center.x + radius <= UI.width && center.y + radius <= UI.height - UI.StatusBarHeight &&  center.y - radius >=  UI.StatusBarHeight && center.x - radius >= 0))
	{
		radius = oldRadius;
		pGUI->PrintMessage("I can't be bigger than this :(");
	}
	// check if the square size smaller than normal
	else if (radius <= 10)
	{
		radius = oldRadius;
		pGUI->PrintMessage("I can't be smaller than this :(");
	}
}
void CHexagon::saveFigure(ofstream& file) {
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

	file << "HEXA" << "  " << ID << "  " << center.x << "  " << center.y << "  " << angle << "  " << radius << "  " << Draw_Color << "  " << Fill_Color << "  " << endl;

}


void CHexagon::PrintInfo(GUI* pGUI)
{
	pGUI->PrintMessage(
		"Hexagon Id: " + to_string(ID) +
		", center: (" + to_string(center.x) + ", " + to_string(center.y) + ")" +
		",angle:" + to_string(angle)+
		", radius: " + to_string(radius) +
		", border-color: (" + to_string(FigGfxInfo.DrawClr.ucRed) + ", " + to_string(FigGfxInfo.DrawClr.ucGreen) + ", " + to_string(FigGfxInfo.DrawClr.ucBlue) + ")" +
		", fill-color: (" + to_string(FigGfxInfo.FillClr.ucRed) + ", " + to_string(FigGfxInfo.FillClr.ucGreen) + ", " + to_string(FigGfxInfo.FillClr.ucBlue) + ")" +
		", Border-Width: " + to_string(FigGfxInfo.BorderWdth));
}

void CHexagon::upload(GUI* pGUI, ifstream& file)
{
	Selected = false;
	string DrawColor;
	string FillColor;
	file >> ID;
	file >> center.x;
	file >> center.y;
	file >> angle;
	file >> radius;
	file >> DrawColor >> FillColor;

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

	
}

int CHexagon::GetNumber()const
{
	return hexNum;
}

//void CHexagon::increase()
//{
//	hexNum++;
//}
//
//void CHexagon::decrease()
//{
//	hexNum--;
//}

CFigure* CHexagon::GetCopy()
{
	CFigure* Copy = new CHexagon(*this);
	return Copy;
}



























