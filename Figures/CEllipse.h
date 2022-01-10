#ifndef CEllipse_H
#define CEllipse_H

#include "CFigure.h"

class CEllipse : public CFigure
{
private:
	Point topLeftCorner;
	Point bottomRightCorner;

public:
	CEllipse(Point, Point, GfxInfo FigureGfxInfo);
	virtual void DrawMe(GUI* pOut) const;
	virtual bool isWithinArea(int, int);
	virtual void PrintInfo(GUI* pGUI);
};

#endif