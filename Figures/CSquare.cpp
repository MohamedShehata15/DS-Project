#include "CSquare.h"
#include <fstream>
#include <iostream>

CSquare::CSquare(Point P1, int len, GfxInfo FigureGfxInfo):CFigure(FigureGfxInfo)
{
	ID = ++squareNum;
	TopLeftCorner = P1;
	length = len;
}

int CSquare::squareNum = 0;
	
bool CSquare::isWithinArea(int x, int y)
{
	return (x >= TopLeftCorner.x && x <= TopLeftCorner.x + length && y >= TopLeftCorner.y && y <= TopLeftCorner.y + length);
}
void CSquare::Resize(GUI* pGUI,float resizeFactor)
{
	int oldLength = length;
	length *= resizeFactor;
	checkSize(pGUI, oldLength); 

}
void CSquare::checkSize(GUI* pGUI, int oldLength)
{
	// check if the size of the square became bigger than the drawing area
	if (!(TopLeftCorner.x + length <= UI.width && TopLeftCorner.y + length <= UI.height - UI.StatusBarHeight))
	{
		length = oldLength;
		pGUI->PrintMessage("I can't be bigger than this :(");
	}
	// check if the square size smaller than normal
	else if (length <= 20)
	{
		length = oldLength;
		pGUI->PrintMessage("I can't be smaller than this :(");
	}
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
	file >> TopLeftCorner.x >> TopLeftCorner.y >> length;
	file >> DrawColor >> FillColor;
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



void CSquare::saveFigure(ofstream &file)
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


	//fill
	if (FigGfxInfo.isFilled)
	{
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
	}
	else 
	{
		Fill_Color = "NO_FILL";
	}

	file << "SQR" << "  " << ID << "  "  << TopLeftCorner.x << "  "  << TopLeftCorner.y << "  " << length << "  "  << Draw_Color << "  " << Fill_Color << "  " << endl;

}//end of save


int CSquare::GetNumber()const
{
	return squareNum;
}
//void CSquare::increase()
//{
//	squareNum++;
//}
//void CSquare::decrease()
//{
//	squareNum--;
//}