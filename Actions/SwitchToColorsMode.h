#ifndef SWITCH_TO_COLOR_MODE_H
#define SWITCH_TO_COLOR_MODE_H

#include "Action.h"

//Add Ellipse Action class
class SwitchToColorsMode : public Action
{
public:
	SwitchToColorsMode(ApplicationManager* pApp);

	virtual void Execute();

};

#endif