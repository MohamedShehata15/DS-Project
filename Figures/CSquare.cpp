#include "CSquare.h"
#include <fstream>
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
void CSquare::Resize(float resizeFactor)
{
	//todo;
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

CFigure* CSquare::GetCopy()
{
	CFigure* Copy = new CSquare(*this);
	return Copy;
}
void CSquare::upload(ifstream& file)
{
	//variables for colors
	string DrawColor;
	string FillColor;
	file >> ID;
	file >> TopLeftCorner.x;
	file >> TopLeftCorner.y;
	file >> length;
	file >> DrawColor;
	file >> FillColor;
	//which color for draw
	if (DrawColor == "BLUE")
	{
		FigGfxInfo.DrawClr = BLUE;
	}
	else if (DrawColor == "BLACK")
	{
		FigGfxInfo.DrawClr = BLACK;
	}

	else if (DrawColor == "OFFWHITE")
	{
		FigGfxInfo.DrawClr = LIGHTGOLDENRODYELLOW;
	}

	else if (DrawColor == "GREEN")
	{
		FigGfxInfo.DrawClr = GREEN;
	}

	else if (DrawColor == "YELLOW")
	{
		FigGfxInfo.DrawClr = YELLOW;
	}

	else if (DrawColor == "RED")
	{
		FigGfxInfo.DrawClr = RED;
	}//end of drawing color

	//which color for filling
	if (FillColor == "NO_FILL")
	{
		FigGfxInfo.isFilled = false;
		FigGfxInfo.FillClr = LIGHTGOLDENRODYELLOW;
	}
	else
	{
		FigGfxInfo.isFilled = true;

		if (FillColor == "BLUE")
		{
			FigGfxInfo.FillClr = BLUE;
		}
		else if (FillColor == "BLACK")
		{
			FigGfxInfo.FillClr = BLACK;
		}

		else if (FillColor == "GREEN")
		{
			FigGfxInfo.FillClr = GREEN;
		}

		else if (FillColor == "YELLOW")
		{
			FigGfxInfo.FillClr = YELLOW;
		}

		else if (FillColor == "RED")
		{
			FigGfxInfo.FillClr = RED;
		}

	}

}

int CSquare::GetNumber()const
{
	return squareNum;
}
void CSquare::increase()
{
	squareNum++;
}
void CSquare::decrease()
{
	squareNum--;
}