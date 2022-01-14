#ifndef ACTION_CHNG_DRAW_H
#define ACTION_CHNG_DRAW_H

#include "Action.h"
#include "../Figures/CFigure.h"



//Add Ellipse Action class
class ActionChngDrawClr : public Action
{
private:
		ActionType newColor;

public:
	ActionChngDrawClr(ApplicationManager* pApp);

	//change color
	virtual void Execute();

};












#endif