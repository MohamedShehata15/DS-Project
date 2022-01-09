#ifndef CEllipse_H
#define CEllipse_H

#include "CFigure.h"

class CEllipse : public CFigure
{
private:
	Point center;
public:
	CEllipse(Point, GfxInfo FigureGfxInfo);
	virtual void DrawMe(GUI* pOut) const;
	virtual bool isWithinArea(int, int);
	virtual void PrintInfo(GUI* pGUI);
};

#endif