#ifndef ACTION_SEND_TO_BACK_H
#define ACTION_SEND_TO_BACK_H

#include "Action.h"

//Add Square Action class
class ActionSendToBack : public Action
{
public:
	ActionSendToBack(ApplicationManager* pApp);

	//Add Square to the ApplicationManager
	virtual void Execute();



};

#endif