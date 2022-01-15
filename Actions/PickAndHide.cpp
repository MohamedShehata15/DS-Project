#include "PickAndHide.h"

PickAndHide::PickAndHide(ApplicationManager* pApp) :Action(pApp)
{
	score = correct = uncorrect = 0;
	pGUI = pManager->GetGUI();
	pGUI->CreatePlayToolBar();
}

void PickAndHide::ReadActionParameters()
{
	for (int i = 0; i < pManager->GetCount(); i++)
		FigureList.push_back(pManager->GetCopyFromFigureList(i)->GetCopy());
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

int PickAndHide::GetType(CFigure* fig) const
{
	if (dynamic_cast<CSquare*>(fig)) return 1;
	if (dynamic_cast<CEllipse*>(fig)) return 2;

	//waiting for Hex
}

//bool PickAndHide::checkColor_Figure(int f, color c, CFigure* rand) const
//{
//
//}

bool PickAndHide::CheckFigure(CFigure* fig, int m) const
{
	if (m == 1)
	{
		if (dynamic_cast<CSquare*>(fig)) return true;
	}
	else if (m == 2)
	{
		if (dynamic_cast<CEllipse*>(fig)) return true;
	}
	//waiting for hex

	return false;
}

/*bool PickAndHide::IfColorExisting(CFigure* f) const
{}*/

CFigure* PickAndHide::Random() const
{
	return FigureList[FigureList.size() / 2];
}

void PickAndHide::Message(int mode, CFigure* fig) const
{}

bool PickAndHide::SameColor(color c1, color c2) const
{
	if (c1.ucBlue == c2.ucBlue && c1.ucGreen == c2.ucGreen && c1.ucRed == c2.ucRed)
		return true;
	return false;
}

void PickAndHide::Delete(CFigure* fig)
{
	for (int i = 0; i < FigureList.size(); i++)
		if (FigureList[i] == fig)
		{
			FigureList.erase(FigureList.begin() + i);
			UpdateInterface();
			break;
		}
}

void PickAndHide::Execute()
{}

PickAndHide::~PickAndHide(void)
{}
