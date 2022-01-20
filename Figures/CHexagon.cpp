#include "CHexagon.h"
#include "..\ApplicationManager.h"
#include "..\GUI\GUI.h"

#include <iostream>
#include <fstream>

CHexagon::CHexagon(Point _center, float _rotation, int _radius, GfxInfo FigureGfxInfo) :CFigure(FigureGfxInfo)
{
	center = _center;
	rotation = _rotation;
	radius = _radius;
}


void CHexagon::DrawMe(GUI* pGUI) const
{
	//Call Output::DrawRect to draw a Square on the screen	
	pGUI->DrawHexagon(center, rotation, radius, FigGfxInfo, Selected);
}

bool CHexagon::isWithinArea(int x, int y)
{
	int length = sqrt(pow(center.x - x, 2) + pow(center.y - y, 2));
	return length <= radius;
}

void CHexagon::Resize(GUI* pGUI, float factor)
{
	HexagonInfo hexagon;
	hexagon.inBounds = false;
	hexagon.center = center;
	hexagon.rotation = rotation;
	hexagon.radius = radius * factor;

	// Get the drawing info
	pGUI->GetHexagonDrawingInfo(hexagon);

	if (hexagon.inBounds) {
		radius *= factor;
	}

}

void CHexagon::saveFigure(ofstream& OutFile) {
	// Figure	ID	center.x	center.y	rotation	radius		drawColor	fillColor
	// HXGN		

	if (OutFile.is_open()) {
		// FigureType
		//OutFile << TYPE_HEXAGON << "\t";
		// center.x		center.y
		OutFile << "Ellipse ";
		OutFile << center.x << " " << center.y << " ";
		// rotation		radius

		OutFile << rotation << " " << radius << " ";
		// drawColor
		OutFile << (int)FigGfxInfo.DrawClr.ucRed << "," << (int)FigGfxInfo.DrawClr.ucBlue << "," << (int)FigGfxInfo.DrawClr.ucGreen;

		// isFilled, fillColor
		if (FigGfxInfo.isFilled) {
			OutFile << " " << (int)FigGfxInfo.FillClr.ucRed << "," << (int)FigGfxInfo.FillClr.ucBlue << "," << (int)FigGfxInfo.FillClr.ucGreen;
		}
		OutFile << "\n";
	}
}


void CHexagon::PrintInfo(GUI* pGUI)
{
	pGUI->PrintMessage(
		"Hexagon Id: " + to_string(ID) +
		", center: (" + to_string(center.x) + ", " + to_string(center.y) + ")" +
		", radius: " + to_string(radius) +
		", border-color: (" + to_string(FigGfxInfo.DrawClr.ucRed) + ", " + to_string(FigGfxInfo.DrawClr.ucGreen) + ", " + to_string(FigGfxInfo.DrawClr.ucBlue) + ")" +
		", fill-color: (" + to_string(FigGfxInfo.FillClr.ucRed) + ", " + to_string(FigGfxInfo.FillClr.ucGreen) + ", " + to_string(FigGfxInfo.FillClr.ucBlue) + ")" +
		", Border-Width: " + to_string(FigGfxInfo.BorderWdth));
}

void CHexagon::upload(ifstream& Infile)
{
	//todo
}

int CHexagon::GetNumber()const
{
	return hexNum;
}

void CHexagon::increase()
{
	hexNum++;
}

void CHexagon::decrease()
{
	hexNum--;
}

CFigure* CHexagon::GetCopy()
{
	CFigure* Copy = new CHexagon(*this);
	return Copy;
}



























