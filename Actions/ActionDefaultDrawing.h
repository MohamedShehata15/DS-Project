#pragma once
#ifndef ACTION_DEFAULT_DRAWING_H
#define ACTION_DEFAULT_DRAWING_H

#include "Action.h"

//Add Square Action class
class ActionDefaultDrawing : public Action
{
public:
	ActionDefaultDrawing(ApplicationManager* pApp);

	//Add Square to the ApplicationManager
	virtual void Execute();

};

#endif