#include "PickAndHide.h"
#include <iostream>



void PickAndHide::pickColor(bool flag) {
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
}

void PickAndHide::pickFigure(bool flag) {
	int Lifes = 3;
	score = correct = uncorrect = 0;
	do
	{
		CFigure* fig = Random();
		int n = fig->GetNumber();
		Message(2, fig);
		do
		{
			selected = NULL;
			actType = pGUI->MapInputToActionType(P.x, P.y);
			if (P.y >= 0 && P.y < UI.ToolBarHeight && P.x <= UI.MenuItemWidth * PLAY_ITM_COUNT)
			{
				flag = true;
				break;
			}
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

		} while (n != 0 && CheckFigure(fig, GetType(fig)) && Lifes != 0);

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
}


void PickAndHide::pickFill(bool flag) {
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

	if (actType == PICK_COLOR || actType == PICK_FIGURE || actType == PICK_FIGURE_COLOR)
		return;

	else if (actType == TO_DRAW)
	{
		FigureList.clear();
		pGUI->CreateDrawToolBar();
		pGUI->ClearStatusBar();
		return;
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
		return;
	}
	else
	{
		pGUI->PrintMessage("You Lost... click any where to try again  ");
		pGUI->GetPointClicked(P.x, P.y);
		return;
	}
}