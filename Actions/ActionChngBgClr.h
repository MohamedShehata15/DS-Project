#ifndef ACTION_CHNG_BG_CLR_H
#define ACTION_CHNG_BG_CLR_H

#include "Action.h"
#include "../Figures/CFigure.h"



//Add Ellipse Action class
class ActionChngBgClr : public Action
{
private:
	ActionType newColor;

public:
	ActionChngBgClr(ApplicationManager* pApp);

	//change color
	virtual void Execute();

};

#endif