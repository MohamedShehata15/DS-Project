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
	virtual void Resize(float);
	virtual CFigure* GetCopy();
	void upload(ifstream& file); //for upload the shape
	virtual void increase();
	virtual void decrease();
	virtual int GetNumber()const; //to know how many shapes are drawn
};

#endif