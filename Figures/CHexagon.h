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
	virtual bool isWithinArea(int x, int y);
	virtual void Resize(GUI* pGUI, float factor);
	void checkSize(GUI*, int, int);
	virtual void PrintInfo(GUI* pGUI);
	virtual void saveFigure(ofstream& file);//save the shape
	virtual void upload(ifstream& Infile);
	/*virtual void increase();
	virtual void decrease();*/
	virtual int GetNumber() const; //to know how many shapes are drawn
	virtual CFigure* GetCopy();

};

#endif







