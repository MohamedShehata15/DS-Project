#ifndef ACTION_RESIZE_FIGURE_H
#define ACTION_RESIZE_FIGURE_H

#include "Action.h"

//Add Square Action class
class ActionResizeFigure : public Action
{
private:
	ActionType act_type_;
public:
	ActionResizeFigure(ApplicationManager* pApp, ActionType ActType);

	//Add Square to the ApplicationManager
	virtual void Execute();

};

#endif