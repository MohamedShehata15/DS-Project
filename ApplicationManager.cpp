#include "ApplicationManager.h"
#include "Actions\ActionAddSquare.h"
#include "Actions\ActionAddEllipse.h"
#include "Actions/ActionSelect.h"
#include "Actions/ActionChngDrawClr.h"
#include "Actions/ActionChngBgClr.h"
#include "Actions/PickAndHide.h"
#include "Actions/ActionUploadFile.h"
#include <iostream>


//Constructor
ApplicationManager::ApplicationManager()
{
	//Create Input and output
	pGUI = new GUI;	
	
	FigCount = 0;
		
	//Create an array of figure pointers and set them to NULL		
	for(int i=0; i<MaxFigCount; i++)
		FigList[i] = NULL;	
}

void ApplicationManager::Run()
{
	ActionType ActType;
	do
	{

		//1- Read user action
		ActType = pGUI->MapInputToActionType();

		//2- Create the corresponding Action
		Action* pAct = CreateAction(ActType);

		//3- Execute the action
		ExecuteAction(pAct);

		//4- Update the interface
		UpdateInterface();
		


	}while(ActType != EXIT);
	
}


//==================================================================================//
//								Actions Related Functions							//
//==================================================================================//

ActionType ApplicationManager::GetUserAction() const
{
	//Ask the input to get the action from the user.
	return pGUI->MapInputToActionType();
}

//Creates an action
Action* ApplicationManager::CreateAction(ActionType ActType) 
{
	Action* newAct = NULL;
	
	//According to Action Type, create the corresponding action object
	switch (ActType)
	{
		case DRAW_SQUARE:
			newAct = new ActionAddSquare(this);
			break;

		case DRAW_ELPS:
			newAct = new ActionAddEllipse(this);
			break;


		case CHNG_DRAW_CLR:
			newAct = new ActionChngDrawClr(this);
			break;

		case CHNG_BK_CLR:
			newAct = new ActionChngBgClr(this);
			break;

		case LOAD:
			newAct = new ActionUploadFile(this);

		case SELECT:
			newAct =  new ActionSelect(this);
			break;

		case EXIT:
			///create ExitAction here
			
			break;
		
		case STATUS:	//a click on the status bar ==> no action
			return NULL;
			break;
	}	
	return newAct;
}
//////////////////////////////////////////////////////////////////////
//Executes the created Action
void ApplicationManager::ExecuteAction(Action* &pAct) 
{	
	//Execute the created action
	if(pAct != NULL)
	{
		pAct->Execute();//Execute
		delete pAct;	//Action is not needed any more ==> delete it
		pAct = NULL;
	}
}
//==================================================================================//
//						Figures Management Functions								//
//==================================================================================//

//Add a figure to the list of figures
void ApplicationManager::AddFigure(CFigure* pFig)
{
	if(FigCount < MaxFigCount )
		FigList[FigCount++] = pFig;	
}
////////////////////////////////////////////////////////////////////////////////////
CFigure *ApplicationManager::GetFigure(int x, int y) const
{
	//If a figure is found return a pointer to it.
	//if this point (x,y) does not belong to any figure return NULL

	///Add your code here to search for a figure given a point x,y	

	// 1- loop in the figlist from the end of the figList
	for (int i = FigCount - 1; i >= 0; i--)
	{
		if (FigList[i]->isWithinArea(x, y))
			return FigList[i];
	}
	return NULL;
}

//==================================================================================//
//							Interface Management Functions							//
//==================================================================================//

//Draw all figures on the user interface
void ApplicationManager::UpdateInterface() const
{	
	for(int i=0; i<FigCount; i++)
		FigList[i]->DrawMe(pGUI);		//Call Draw function (virtual member fn)
}
////////////////////////////////////////////////////////////////////////////////////
//Return a pointer to the interface
GUI *ApplicationManager::GetGUI() const
{	return pGUI; }
////////////////////////////////////////////////////////////////////////////////////
int ApplicationManager::GetCount()const
{
	return FigCount;
}
/// ///////////////////////////////////////////////////////////////////////////////
CFigure* ApplicationManager::GetCopyFromFigureList(int i)const
{
	return FigList[i];
}










































//Destructor
ApplicationManager::~ApplicationManager()
{
	for(int i=0; i<FigCount; i++)
		delete FigList[i];
	delete pGUI;
	
}
