#include "CEllipse.h"
#include <iostream>

CEllipse::CEllipse(Point P1, GfxInfo FigureGfxInfo):CFigure(FigureGfxInfo)
{
	center = P1;
}


bool CEllipse::isWithinArea(int x ,int y)
{
	return ((((pow((x - center.x), 2)) / (100 * 100)) + ((pow((y - center.y), 2)) / (70 * 70))) <= 1);
}


void CEllipse::PrintInfo(GUI* pGUI)
{
	pGUI->PrintMessage(
		"Ellipse Id: " + to_string(ID) +
		", center : (" + to_string(center.x) + ", " + to_string(center.y) + ")" +
		", border-color: (" + to_string(FigGfxInfo.DrawClr.ucRed) + ", " + to_string(FigGfxInfo.DrawClr.ucGreen) + ", " + to_string(FigGfxInfo.DrawClr.ucBlue) + ")" +
		", fill-color: (" + to_string(FigGfxInfo.FillClr.ucRed) + ", " + to_string(FigGfxInfo.FillClr.ucGreen) + ", " + to_string(FigGfxInfo.FillClr.ucBlue) + ")" +
		", Border-Width: " + to_string(FigGfxInfo.BorderWdth));
};

void CEllipse::DrawMe(GUI* pGUI) const
{
	//Call Output::DrawRect to draw a Square on the screen	
	pGUI->DrawEllipse(center, FigGfxInfo, Selected);


}