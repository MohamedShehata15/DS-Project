#include "CEllipse.h"
#include <iostream>
#include <fstream>

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
		", Center: (" + to_string(center.x) + ", " + to_string(center.y) + ")" +
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

//Upload Ellipse
void CEllipse::upload(ifstream &file)
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
		FigGfxInfo.DrawClr =LIGHTGOLDENRODYELLOW;
	}

	else if (DrawColor == "GREEN")
	{
		FigGfxInfo.DrawClr=GREEN;
	}

	else if (DrawColor == "YELLOW")
	{
		FigGfxInfo.DrawClr=YELLOW;
	}

	else if (DrawColor == "RED")
	{
		FigGfxInfo.DrawClr=RED;
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

}//end of upload



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