#include "PickAndHide.h"

PickAndHide::PickAndHide(ApplicationManager * pApp) :Action(pApp)
{
	score = correct = uncorrect = 0;
	pGUI = pManager->GetGUI();
	pGUI->CreatePlayToolBar();
}

void PickAndHide::ReadActionParameters()
{
	//for loop related to GetCount() .. not implemented yet in pManager 

}

void PickAndHide::UpdateInterface() const
{
	pGUI->ClearDrawArea();
	for (int i = 0; i < FigureList.size(); i++) {
		FigureList[i]->DrawMe(pGUI); //Call Draw function
	}

}

void PickAndHide::Load()
{
	FigureList.clear();
	ReadActionParameters();
	UpdateInterface();
}

CFigure* PickAndHide::GetFigure(Point P) const
{
	//If a figure is found return a pointer to it, otherwise return NULL

	CFigure* S = NULL;

	//search for a figure given a point x,y
	for (int i = 0; i < FigureList.size(); i++) {
		if (FigureList[i]->isWithinArea(P)) {
			S = FigureList[i];
		}
	}
	return S;
}
