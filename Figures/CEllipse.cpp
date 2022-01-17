#include "CEllipse.h"
#include <iostream>

CEllipse::CEllipse(Point P1, int yr,int xr, GfxInfo FigureGfxInfo):CFigure(FigureGfxInfo)
{
	center = P1;
	yradius = yr;
	xradius = xr;
}


bool CEllipse::isWithinArea(int x ,int y)
{

	return ((((pow((x - center.x), 2)) / (yradius * yradius)) + ((pow((y - center.y), 2)) / (xradius * xradius))) <= 1);
}
void CEllipse::Resize(float resizeFactor)
{
	//todo;
}
void CEllipse::PrintInfo(GUI* pGUI)
{
	pGUI->PrintMessage(
		"Ellipse Id: " + to_string(ID) +
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
	pGUI->DrawEllipse(center, yradius,xradius, FigGfxInfo, Selected);


}

CFigure* CEllipse::GetCopy()
{
	CFigure* Copy = new CEllipse(*this);
	return Copy;
}

int CEllipse::GetNumber()const
{
	return ellipseNum;
}
void CEllipse::increase()
{
	ellipseNum++;
}
void CEllipse::decrease()
{
	ellipseNum--;
}