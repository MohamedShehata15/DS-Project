#include "CEllipse.h"
#include <iostream>

CEllipse::CEllipse(Point P1, Point P2, GfxInfo FigureGfxInfo):CFigure(FigureGfxInfo)
{
	topLeftCorner = P1;
	bottomRightCorner = P2;
}


bool CEllipse::isWithinArea(int x ,int y)
{

	// todo make this function
	return false;

	//(x - h) ^ 2 / a ^ 2 + (y - k) ^ 2 / b ^ 2 <= 1;
	//return
	// (pow((x - center.x), 2) / pow(xCord, 2)) + (pow((y - center.y), 2) / pow(yCord, 2)) <= 1);
}


void CEllipse::PrintInfo(GUI* pGUI)
{
	pGUI->PrintMessage(
		"Ellipse Id: " + to_string(ID) +
		", Top left corner: (" + to_string(topLeftCorner.x) + ", " + to_string(topLeftCorner.y) + ")" +
		", Bottom Right corner: (" + to_string(bottomRightCorner.x) + ", " + to_string(bottomRightCorner.y) + ")" +
		", border-color: (" + to_string(FigGfxInfo.DrawClr.ucRed) + ", " + to_string(FigGfxInfo.DrawClr.ucGreen) + ", " + to_string(FigGfxInfo.DrawClr.ucBlue) + ")" +
		", fill-color: (" + to_string(FigGfxInfo.FillClr.ucRed) + ", " + to_string(FigGfxInfo.FillClr.ucGreen) + ", " + to_string(FigGfxInfo.FillClr.ucBlue) + ")" +
		", Border-Width: " + to_string(FigGfxInfo.BorderWdth));
};

void CEllipse::DrawMe(GUI* pGUI) const
{
	//void GUI::DrawEllipse(Point center, int xCord, int yCord, GfxInfo EllGfxInfo, bool selected) const
	//Call Output::DrawRect to draw a Square on the screen	
	pGUI->DrawEllipse(topLeftCorner, bottomRightCorner, FigGfxInfo, Selected);


}