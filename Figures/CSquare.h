#pragma once
#ifndef CSQUARE_H
#define CSQUARE_H

#include "CFigure.h"


class CSquare : public CFigure
{
private:
	Point TopLeftCorner;	
	int length;
public:
	CSquare(Point , int, GfxInfo FigureGfxInfo );
	virtual void DrawMe(GUI* pOut) const;
	virtual bool isWithinArea(int, int);
	virtual void PrintInfo(GUI* pGUI);
	virtual void Resize(GUI* pGUI, float resizeFactor);
	void checkSize(GUI* pGUI, int oldLength);
	virtual CFigure* GetCopy();
	virtual void upload(GUI* pGUI, ifstream& file); //for upload the shape
	virtual void saveFigure(ofstream& file); //save the shape

	/*virtual void increase();
	virtual void decrease();*/
	virtual int GetNumber()const; //to know how many shapes are drawn
};

#endif