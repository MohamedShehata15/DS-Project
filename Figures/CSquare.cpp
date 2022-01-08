#include "CSquare.h"
#include <iostream>

CSquare::CSquare(Point P1, int len, GfxInfo FigureGfxInfo):CFigure(FigureGfxInfo)
{
	TopLeftCorner = P1;
	length = len;
}
	
bool CSquare::isWithinArea(int x, int y)
{
	return (x >= TopLeftCorner.x && x <= TopLeftCorner.x + length && y >= TopLeftCorner.y && y <= TopLeftCorner.y + length);
}

void CSquare::PrintInfo(GUI* pGUI)
{
	pGUI->PrintMessage(
		"Square Id: " + to_string(ID) + 
		", Top left corner: (" + to_string(TopLeftCorner.x) + ", " + to_string(TopLeftCorner.y) + ")" + 
		", length: " + to_string(length) + 
		", area: " + to_string(length * length) + 
		", border-color: (" + to_string(FigGfxInfo.DrawClr.ucRed) + ", " + to_string(FigGfxInfo.DrawClr.ucGreen) + ", " + to_string(FigGfxInfo.DrawClr.ucBlue) + ")" + 
		", fill-color: (" + to_string(FigGfxInfo.FillClr.ucRed) + ", " + to_string(FigGfxInfo.FillClr.ucGreen) + ", " + to_string(FigGfxInfo.FillClr.ucBlue) + ")" + 
		", Border-Width: " + to_string(FigGfxInfo.BorderWdth));
};

void CSquare::DrawMe(GUI* pGUI) const
{
	//Call Output::DrawRect to draw a Square on the screen	
	pGUI->DrawSquare(TopLeftCorner, length, FigGfxInfo, Selected);
	

}