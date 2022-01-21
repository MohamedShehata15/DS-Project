#include "CFigure.h"

CFigure::CFigure(GfxInfo FigureGfxInfo)
{ 
	FigGfxInfo = FigureGfxInfo;	//Default status is non-filled.
	Selected = false;
}

void CFigure::SetSelected(bool s)
{	Selected = s; }

bool CFigure::IsSelected() const
{	return Selected; }

void CFigure::ChngDrawClr(color Dclr)
{	FigGfxInfo.DrawClr = Dclr; }

void CFigure::ChngFillClr(color Fclr)
{	
	FigGfxInfo.isFilled = true;
	FigGfxInfo.FillClr = Fclr; 
}

color CFigure::GetCurrentColor()const
{
	return FigGfxInfo.FillClr;
}

bool CFigure::IsFilled()const
{
	return FigGfxInfo.isFilled;
}

int CFigure::GetNumOfSquares() const
{
	return squareNum;
}

int CFigure::GetNumOfEllipses() const
{
	return ellipseNum;
}

int CFigure::GetNumOfHexagons() const
{
	return hexNum;
}

