#ifndef ACTION_CLEAR_ALL_FIGURES_H
#define ACTION_CLEAR_ALL_FIGURES_H

#include "Action.h"

class ActionclearAllFigures : public Action
{
private:
	ActionType newColor;

public:
	ActionclearAllFigures(ApplicationManager* pApp);

	//change color
	virtual void Execute();

};

#endif