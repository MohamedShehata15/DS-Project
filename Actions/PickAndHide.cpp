#include "PickAndHide.h"
#include <iostream>

#include "ActionExit.h"

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
	if (dynamic_cast<CHexagon*>(fig)) return 3;
}

bool PickAndHide::checkColor_Figure(int f, color c, CFigure* rand) const
{
	for (int i = 0; i < FigureList.size(); i++)
	{

		if (dynamic_cast<CSquare*>(FigureList[i]))
		{
			if (f == 1)
			{
				if (FigureList[i]->IsFilled() && rand->IsFilled())
				{
					if (SameColor(FigureList[i]->GetCurrentColor(), c))
						return true;
				}
			}
		}
		else if (dynamic_cast<CEllipse*>(FigureList[i]))
		{
			if (f == 2)
			{
				if (FigureList[i]->IsFilled() && rand->IsFilled())
				{
					if (SameColor(FigureList[i]->GetCurrentColor(), c))
						return true;
				}
			}
		}
		else if (dynamic_cast<CHexagon*>(FigureList[i]))
		{
			if (f == 3)
			{
				if (FigureList[i]->IsFilled() && rand->IsFilled())
				{
					if (SameColor(FigureList[i]->GetCurrentColor(), c))
						return true;
				}
			}
		}
	}
	return false;
}

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
	else if (m == 3)
	{
		if (dynamic_cast<CHexagon*>(fig)) return true;
	}

	return false;
}

bool PickAndHide::IfColorExisting(CFigure* f) const
{
	for (int i = 0; i < FigureList.size(); i++)
		if (FigureList[i]->IsFilled() && f->IsFilled())
		{
			if (SameColor(FigureList[i]->GetCurrentColor(), f->GetCurrentColor()))
				return true;
		}
		else if (!FigureList[i]->IsFilled() && !f->IsFilled())
			return true;
	return false;
}

CFigure* PickAndHide::Random() const
{
	return FigureList[FigureList.size() / 2];
}

void PickAndHide::Message(int mode, CFigure* fig) const
{
	string Mode;
	string Figure;
	string Color;

	int type = GetType(fig); //check figures
	switch (type)
	{
	case 1:
		Figure = "Square ";
		break;
	case 2:
		Figure = "Ellipse ";
		break;
	case 3:
		Figure = "Hexagon ";
		break;
	}

	if (!fig->IsFilled()) //check colors
		Color = "Non-Filled ";
	else if (SameColor(fig->GetCurrentColor(), YELLOW))
		Color = "Yellow ";
	else if (SameColor(fig->GetCurrentColor(), RED))
		Color = "Red ";
	else if (SameColor(fig->GetCurrentColor(), GREEN))
		Color = "Green ";
	else if (SameColor(fig->GetCurrentColor(), BLACK))
		Color = "Black ";
	else if (SameColor(fig->GetCurrentColor(), BLUE))
		Color = "Blue ";
	
	if (mode == 1) //check modes
	{
		Mode = "Pick by color, ";
		pGUI->PrintMessage(Mode + Color);
		return;

	}
	else if (mode == 2)
	{
		Mode = "Pick by figure, ";
		pGUI->PrintMessage(Mode + Figure);
		return;
	}
	else if (mode == 3)
	{
		Mode = "Pick by Figure & color ";
		pGUI->PrintMessage(Mode + Figure + Color);
	}

}

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
{

	ReadActionParameters();
	bool flag = false;
	do
	{
		//pGUI->GetPointClickekd(P.x, P.y);
		Load();
		pGUI->ClearStatusBar();
		if (!flag)
			actType = pGUI->MapInputToActionType(P.x, P.y);
		flag = false;
		switch (actType)
		{
		case PICK_CLR:
		{
			cout << "PICK_CLR\n";
			cout << P.x << "," << P.y << endl;
			/**********/
			pickColor(flag);
			/***********/
			break;
		}
		case PICK_FIG:
		{
			cout << "PICK_FIG\n";
			/***********/
			pickFigure(flag);

			/**********/
			break;
		}
		case PICK_FIG_CLR:
		{
			cout << "PICK_FILL\n";
			/***********/
			pickFill(flag);


			/**********/
			break;
		}
		case TO_DRAW:
		{
			FigureList.clear();
			pGUI->CreateDrawToolBar();
			break;
		}
		case EXIT:
		{
			Action* exitAction = new ActionExit(pManager);
			pManager->ExecuteAction(exitAction);
			break;
		}
		}
	} while (actType != TO_DRAW || flag);
}

PickAndHide::~PickAndHide(void)
{}
