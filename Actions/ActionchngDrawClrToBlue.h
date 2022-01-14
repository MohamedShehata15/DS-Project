#ifndef ACTION_CHNG_DRAW_TO_BLUE_H
#define ACTION_CHNG_DRAW_TO_BLUE_H

#include "Action.h"
#include "../Figures/CFigure.h"



//Add Ellipse Action class
class ActionchngDrawClrToBlue : public Action
{

private:
	color CurrentColor;

public:
	ActionchngDrawClrToBlue(ApplicationManager* pApp);

	virtual void Execute();

};


#endif#
