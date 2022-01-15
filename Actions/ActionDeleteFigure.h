#ifndef ACTION_DELETE_FIGURE_H
#define ACTION_DELETE_FIGURE_H

#include "Action.h"

//Add Square Action class
class ActionDeleteFigure : public Action
{
public:
	ActionDeleteFigure(ApplicationManager* pApp);

	//Add Square to the ApplicationManager
	virtual void Execute();

};

#endif