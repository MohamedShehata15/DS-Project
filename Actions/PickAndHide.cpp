#include "PickAndHide.h"
#include <iostream>

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
		// add one for hex if implemented
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
	//waiting for hex

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
			int Lifes = 3;
			score = correct = uncorrect = 0;
			do
			{
				cout << P.x << "," << P.y << endl;
				CFigure* fig = Random();
				Message(1, fig);
				do
				{
					cout << P.x << "," << P.y << endl;
					selected = NULL;

					actType = pGUI->MapInputToActionType(P.x, P.y);

					if (P.y >= 0 && P.y < UI.ToolBarHeight && P.x <= UI.MenuItemWidth * PLAY_ITM_COUNT)
					{
						flag = true;
						break;
					}
					selected = GetFigure(P);
					if (selected != NULL && SameColor(fig->GetCurrentColor(), selected->GetCurrentColor()) && fig->IsFilled() && selected->IsFilled())
					{
						score++;
						correct++;
						Delete(selected);
						pGUI->PlayModeMessage("Right selection well done, Your score :   ", score);
					}
					else if (selected != NULL && !fig->IsFilled() && !selected->IsFilled())
					{
						score++;
						correct++;
						Delete(selected);
						pGUI->PlayModeMessage("Right selection well done, Your score :   ", score);
					}
					else if (selected != NULL)
					{
						Lifes--;
						uncorrect++;
						if (score != 0)
							score--;
						pGUI->PlayModeMessage("Wrong selection Be careful, Your score :   ", score);
					}

				} while (IfColorExisting(fig) && Lifes != 0);

			} while (FigureList.size() != 0 && Lifes != 0 && !flag);

			if (Lifes != 0 && !flag)
			{
				pGUI->PrintMessage("You Win, Click to see the results");
				pGUI->GetPointClicked(P.x, P.y);
			}
			else if (!flag)
			{
				pGUI->PrintMessage("You lose, Click to see the results");
				pGUI->GetPointClicked(P.x, P.y);
			}
			if (!flag)
			{
				pGUI->PlayModeMessage("your final score is  :  ", score);
				pGUI->GetPointClicked(P.x, P.y);
				pGUI->PlayModeMessage("Your correct selection :  ", correct);
				pGUI->GetPointClicked(P.x, P.y);
				pGUI->PlayModeMessage("Your uncorrect selection :  ", uncorrect);
				pGUI->GetPointClicked(P.x, P.y);
				pGUI->ClearStatusBar();
			}
			/***********/
			break;
		}
		case PICK_FIG:
		{
			cout << "PICK_FIG\n";
			/***********/
			int Lifes = 3;
			score = correct = uncorrect = 0;
			do
			{
				CFigure* fig = Random();
				int n = fig->GetNumber();
				Message(2, fig);
				do
				{
					actType = pGUI->MapInputToActionType(P.x, P.y);
					if (P.y >= 0 && P.y < UI.ToolBarHeight && P.x <= UI.MenuItemWidth * PLAY_ITM_COUNT)
					{
						flag = true;
						break;
					}
					selected = NULL;
					selected = GetFigure(P);
					if (selected != NULL && CheckFigure(selected, GetType(fig)))
					{
						n--;
						score++;
						correct++;
						Delete(selected);
						pGUI->PlayModeMessage("Right selection well done, Your score :   ", score);
					}
					else if (selected != NULL)
					{
						Lifes--;
						uncorrect++;
						if (score != 0)
							score--;
						pGUI->PlayModeMessage("Wrong selection Be careful, Your score :   ", score);
					}

				} while (n != 0 && Lifes != 0);

			} while (FigureList.size() != 0 && Lifes != 0 && !flag);

			if (Lifes != 0 && !flag)
			{
				pGUI->PrintMessage("You Win, Click to see the results");
				pGUI->GetPointClicked(P.x, P.y);
			}
			else if (!flag)
			{
				pGUI->PrintMessage("You lose, Click to see the results");
				pGUI->GetPointClicked(P.x, P.y);
			}
			if (!flag)
			{
				pGUI->PlayModeMessage("your final score is  :  ", score);
				pGUI->GetPointClicked(P.x, P.y);
				pGUI->PlayModeMessage("Your correct selection :  ", correct);
				pGUI->GetPointClicked(P.x, P.y);
				pGUI->PlayModeMessage("Your uncorrect selection :  ", uncorrect);
				pGUI->GetPointClicked(P.x, P.y);
				pGUI->ClearStatusBar();
			}

			/**********/
			break;
		}
		case PICK_FILL:
		{
			cout << "PICK_FILL\n";
			/***********/
			Load();
			int lifes = 3;
			score = correct = uncorrect = 0;
			CFigure* rand = Random();
			int number_of_exited = rand->GetNumber();
			Message(3, rand);
			do {

				actType = pGUI->MapInputToActionType(P.x, P.y);
				CFigure* sel = GetFigure(P);
				if (sel != NULL)
				{
					do
					{
						while (sel == NULL) { actType = pGUI->MapInputToActionType(P.x, P.y); sel = GetFigure(P); }
						if (CheckFigure(sel, GetType(rand)))
						{


							if (SameColor(sel->GetCurrentColor(), rand->GetCurrentColor()) && sel->IsFilled() && rand->IsFilled())
							{
								score++;
								correct++;
								Delete(sel);
								number_of_exited--;
								pGUI->PlayModeMessage("right selection your score is : ", score);
								sel = NULL;

							}
							else if (!sel->IsFilled() && !rand->IsFilled())
							{
								score++;
								correct++;
								Delete(sel);
								number_of_exited--;
								pGUI->PlayModeMessage("right selection your score is : ", score);
								sel = NULL;
							}
							else if (!SameColor(sel->GetCurrentColor(), rand->GetCurrentColor()) && sel->IsFilled() && rand->IsFilled())
							{
								if (score != 0)
									score--;
								uncorrect++;
								pGUI->PlayModeMessage("not right selection...(try AGAIN) your score is : ", score);
								sel = NULL;
								lifes--;
							}
							else if (sel->IsFilled() && !rand->IsFilled())
							{
								if (score != 0)
									score--;
								uncorrect++;
								pGUI->PlayModeMessage("not right selection...(try AGAIN) your score is : ", score);
								sel = NULL;
								lifes--;
							}
							else if (!sel->IsFilled() && rand->IsFilled())
							{
								if (score != 0)
									score--;
								uncorrect++;
								pGUI->PlayModeMessage("not right selection...(try AGAIN) your score is : ", score);
								sel = NULL;
								lifes--;
							}

						}
						else
						{
							if (score != 0)
								score--;
							uncorrect++;
							pGUI->PlayModeMessage("not right selection...(try AGAIN) your score is : ", score);
							sel = NULL;
							lifes--;
						}

					} while (number_of_exited != 0 && checkColor_Figure(GetType(rand), rand->GetCurrentColor(), rand) && lifes != 0);
				}
				if (FigureList.size() != 0)
				{
					rand = Random();
					number_of_exited = rand->GetNumber();
					Message(3, rand);
				}
			} while ((actType == DRAWING_AREA || actType == EMPTY) && (FigureList.size() != 0 && lifes != 0));

			if (actType == PICK_COLOR || actType == PICK_FIGURE || actType == PICK_FILLED)
				break;

			else if (actType == TO_DRAW)
			{
				FigureList.clear();
				pGUI->CreateDrawToolBar();
				pGUI->ClearStatusBar();
				break;
			}

			if (lifes != 0)
			{
				pGUI->PrintMessage("You Won... click any where to know your score  ");
				cout << "non zero lives";
				pGUI->GetPointClicked(P.x, P.y);
				cout << "point clicked";
				pGUI->PlayModeMessage("your final score is  :  ", score);
				pGUI->GetPointClicked(P.x, P.y);
				pGUI->PlayModeMessage("your uncorrect selections is  :  ", uncorrect);
				pGUI->GetPointClicked(P.x, P.y);
				pGUI->PlayModeMessage("your correct selections is  :  ", correct);
				break;
			}
			else
			{
				pGUI->PrintMessage("You Lost... click any where to try again  ");
				pGUI->GetPointClicked(P.x, P.y);
				break;
			}


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
			cout << "EXIT\n";
			break;
		}
		}
	} while (actType != TO_DRAW || flag);
}

PickAndHide::~PickAndHide(void)
{}
