#ifndef ACTION_CHNG_FILL_CLR_H
#define ACTION_CHNG_FILL_CLR_H

#include "Action.h"
#include "../Figures/CFigure.h"



class ActionChngFillClr : public Action
{
private:
	ActionType newColor;

public:
	ActionChngFillClr (ApplicationManager* pApp);

	//change color
	virtual void Execute();

};








#endif