#ifndef ACTION_SWITCH_TO_RESIZE_MODE_H
#define ACTION_SWITCH_TO_RESIZE_MODE_H

#include "Action.h"

//Add Square Action class
class ActionSwitchToResizeMode : public Action
{
public:
	ActionSwitchToResizeMode(ApplicationManager* pApp);

	//Add Square to the ApplicationManager
	virtual void Execute();

};

#endif