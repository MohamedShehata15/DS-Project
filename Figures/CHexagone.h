#ifndef CHexagone_H
#define CHexagone_H

#include "CFigure.h"

class CHexagone : public CFigure
{
private:
	Point points[6];

public:
	CHexagone(Point[], GfxInfo FigureGfxInfo);
	virtual void DrawMe(GUI* pOut) const;
	virtual bool isWithinArea(int, int);
	virtual void PrintInfo(GUI* pGUI);
	virtual CFigure* GetCopy();
};

#endif
