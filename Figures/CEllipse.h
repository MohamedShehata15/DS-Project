#pragma once
#ifndef CEllipse_H
#define CEllipse_H

#include "CFigure.h"

class CEllipse : public CFigure
{
private:
	Point center;
	int yradius;
	int xradius;

public:
	CEllipse(Point, int,int, GfxInfo FigureGfxInfo);
	virtual void DrawMe(GUI* pOut) const;
	virtual bool isWithinArea(int, int);
	virtual void PrintInfo(GUI* pGUI);
	virtual void Resize(GUI*,float);
	void checkSize(GUI*, int, int);
	virtual CFigure* GetCopy();
	virtual void upload(GUI* pGUI, ifstream& file); //for upload the shape
	virtual void saveFigure(ofstream& file);//save the shape
	/*virtual void increase();
	virtual void decrease();*/
	virtual int GetNumber()const; //to know how many shapes are drawn
};

#endif