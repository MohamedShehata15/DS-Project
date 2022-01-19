#ifndef CHEXAGON_H
#define CHEXAGON_H

#include "CFigure.h"

class CHexagon : public CFigure
{
private:
	Point center;
	float rotation;
	int radius;
public:
	CHexagon(Point _center, float _rotation, int _radius, GfxInfo FigureGfxInfo);
	virtual void DrawMe(GUI* pOut) const;
	virtual bool isPointIn(int x, int y) const;
	bool Resize(float factor, GUI* pGUI);

	virtual void Save(ofstream& OutFile);
	virtual void Load(ifstream& Infile);
};

#endif