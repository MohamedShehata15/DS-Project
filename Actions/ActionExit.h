#ifndef ACTION_EXIT_H
#define ACTION_EXIT_H

#include "Action.h"

//Add Square Action class
class ActionExit : public Action
{
public:
	ActionExit(ApplicationManager* pApp);

	//Add Square to the ApplicationManager
	virtual void Execute();

};

#endif