#ifndef ACTION_SELECT_H
#define ACTION_SELECT_H

#include "Action.h"

//Add Square Action class
class ActionSelect : public Action
{
public:
	ActionSelect(ApplicationManager* pApp);

	//Add Square to the ApplicationManager
	virtual void Execute();

};

#endif