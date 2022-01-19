#ifndef ACTION_ADD_HEXAGON_H
#define ACTION_ADD_HEXAGON_H

#include "Action.h"
#include "..\GUI\GUI.h"


class ActionAddHexagon : public Action
{
	GUI* pGUI;
public:
	ActionAddHexagon(ApplicationManager* pApp);

	//Add Hexagon to the ApplicationManager
	virtual void Execute();
	void CreateFigure(Point Center, float Rotation, int Radius, GfxInfo SqrGfxInfo);
};

#endif