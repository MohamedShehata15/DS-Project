#include "PickAndHide.h"

PickAndHide::PickAndHide(ApplicationManager* pApp) :Action(pApp)
{
	score = correct = uncorrect = 0;
	pGUI = pManager->GetGUI();
	pGUI->CreatePlayToolBar();
}

void PickAndHide::ReadActionParameters()
{
	//for loop

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
		if (FigureList[i]->isWithinArea(P.x, P.y)) {
			S = FigureList[i];
		}
	}
	return S;
}

/*int PickAndHide::GetType(CFigure* fig) const
{}*/

/*bool PickAndHide::checkColor_Figure(int f, color c, CFigure* rand) const
{}*/

/*bool PickAndHide::CheckFigure(CFigure* fig, int m) const
{}*/

/*bool PickAndHide::IfColorExisting(CFigure* f) const
{}*/

/*CFigure* PickAndHide::Random() const
{}*/

void PickAndHide::Message(int mode, CFigure* fig) const
{}

/*bool PickAndHide::SameColor(color c1, color c2) const
{}*/

void PickAndHide::Delete(CFigure* fig)
{}

void PickAndHide::Execute()
{}

PickAndHide::~PickAndHide(void)
{}
