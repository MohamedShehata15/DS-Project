#ifndef ACTION_BRING_TO_FRONT_H
#define ACTION_BRING_TO_FRONT_H

#include "Action.h"

//Add Square Action class
class ActionBringToFront : public Action
{
public:
	ActionBringToFront(ApplicationManager* pApp);

	//Add Square to the ApplicationManager
	virtual void Execute();

};

#endif