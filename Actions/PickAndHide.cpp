#include "PickAndHide.h"

PickAndHide::PickAndHide(ApplicationManager* pApp) :Action(pApp)
{
	score = correct = uncorrect = 0;
	//TODO: pout and pin getoutput, getinput, createplaytoolbar

}

void PickAndHide::ReadActionParameters()
{
	//for loop

}

void PickAndHide::UpdateInterface() const
{
	

}

void PickAndHide::Load()
{
	FigureList.clear();
	ReadActionParameters();
	UpdateInterface();
}