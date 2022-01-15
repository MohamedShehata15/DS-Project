#ifndef ACTION_ADD_HEX_H
#define ACTION_ADD_HEX_H

#include "Action.h"

//Add Hexagone Action class
class ActionAddHexagone : public Action
{
public:
	ActionAddHexagone(ApplicationManager* pApp);

	//Add Hexagone to the ApplicationManager
	virtual void Execute();

};

#endif
