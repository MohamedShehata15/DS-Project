#include "ApplicationManager.h"
#include "Actions\ActionAddSquare.h"
#include "Actions\ActionAddEllipse.h"
#include "Actions/ActionSelect.h"
#include "Actions/ActionChngDrawClr.h"
#include "Actions/ActionChngBgClr.h"
#include "Actions/ActionChngFillClr.h"
#include "Actions/PickAndHide.h"
#include "Actions/ActionUploadFile.h"
#include "Actions/ActionSwitchToResizeMode.h"
#include <iostream>
#include "GUI/GUI.h"

#include "Actions/ActionBringToFront.h"
#include "Actions/ActionDeleteFigure.h"
#include "Actions/ActionResizeFigure.h"
#include "Actions/ActionSendToBack.h"

#include "Actions\SwitchToColorsMode.h";
#include "Actions\ActionDefaultDrawing.h";
#include "Actions\ActionclearAllFigures.h";


//Constructor
ApplicationManager::ApplicationManager()
{
	//Create Input and output
	pGUI = new GUI;	
	
	FigCount = 0;
	DrawingActionType = EMPTY;
		
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

		case DRAW_HEX:
			//newAct = new ActionAddHexagone(this);
			break;

		case CHNG_DRAW_CLR:
		case CHNG_BK_CLR:
		case CHNG_FILL_CLR:
			DrawingActionType = ActType;
			newAct = new SwitchToColorsMode(this);
			break;

		case SEND_BACK:
			newAct = new ActionSendToBack(this);
			break;
		case BRNG_FRNT:
			newAct = new ActionBringToFront(this);
			break;

		case default_setting:
			newAct = new ActionDefaultDrawing(this);
			break;

		case LOAD:
			newAct = new ActionUploadFile(this);
			break;

		case SELECT:
			newAct =  new ActionSelect(this);
			break;
		case DEL:
			newAct = new ActionDeleteFigure(this);
			break;
		case TO_PLAY:
			cout << "welcome to play mode!\n";
			newAct = new PickAndHide(this);
			break;
		case TO_DRAW:
			cout << "welcome to draw mode again!\n";
			/***********redirect to draw mode************/
			break;

		case CLR_BLUE: 
			newAct = handleDrawingColorAction(BLUE);
			break;
		case CLR_BLACK: 
			newAct = handleDrawingColorAction(BLACK);
			break;
		case CLR_GREEN: 
			newAct = handleDrawingColorAction(GREEN);
			break;
		case CLR_YELLOW: 
			newAct = handleDrawingColorAction(YELLOW);
			break;
		case CLR_RED: 
			newAct = handleDrawingColorAction(RED);
			break;
		case RESIZE:
			newAct = new ActionSwitchToResizeMode(this);
			break;
		case BACK: 
			//newAct = handleDrawingColorAction();
			pGUI->CreateDrawToolBar(); // Remove this later.
			break;
		case CLEAR:
			newAct = new ActionclearAllFigures(this);
			break;


		case QUARTER_FACTOR:
		case HALF_FACTOR:
		case DOUBLE_FACTOR:
		case QUADRUPLE_FACTOR:
			newAct = new ActionResizeFigure(this, ActType);
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
// Responsible for Drawing colors
Action* ApplicationManager::handleDrawingColorAction(color c) {
	pGUI->setAppliedColor(c);

	switch (DrawingActionType) {
		case CHNG_DRAW_CLR:
			return new ActionChngDrawClr(this);

		case CHNG_BK_CLR:
			return new ActionChngBgClr(this);
		case CHNG_FILL_CLR:
				return new ActionChngFillClr(this);
		default:
			return NULL;
	}
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
int ApplicationManager::getFigCount() { return FigCount; }

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
////////////////////////////////////////////////////////////////////////////////////
// Clear All Figures
void ApplicationManager::clearAllFigures() {
	for (int i = 0; i < FigCount; i++) {
		FigList[FigCount - 1] = NULL;
		delete[] FigList[i];
	}
	FigCount = 0;
}

////////////////////////////////////////////////////////////////////////////////////
void ApplicationManager::deSelectAllFigures()
{
	for (int i = 0; i < FigCount; i++)
	{
		FigList[i]->SetSelected(false);
	}
}
////////////////////////////////////////////////////////////////////////////////////
void ApplicationManager::deleteFigure(int figPosition) 
{
	moveFigureThenShift(figPosition, FigCount - 1);
	delete[] FigList[--FigCount];
}
////////////////////////////////////////////////////////////////////////////////////
int ApplicationManager::getIndexOfSelectedFigure()
{
	for (int i = FigCount - 1; i >= 0; i--)
	{
		if (FigList[i]->IsSelected())
			return i;
	}
	return -1;
}

////////////////////////////////////////////////////////////////////////////////////
CFigure* ApplicationManager::getSelectedFigure(int index) {
	if (index > -1)
		return FigList[index];
	return NULL;
}
////////////////////////////////////////////////////////////////////////////////////

// a function that takes two parameters the first parameter is the current figure index
// the second parameter is the required index that you want to  move it to
// and then shift the rest of the elements
void ApplicationManager::moveFigureThenShift(int oldPosition, int newPosition)
{
	CFigure* movingFigure = FigList[oldPosition];
	for (int i = oldPosition; oldPosition >= newPosition? i > newPosition : i < newPosition; oldPosition >= newPosition ? i--: i++)
	{
		if (oldPosition >= newPosition)
			FigList[i] = FigList[i - 1];
		else
			FigList[i] = FigList[i + 1];

	}
	FigList[newPosition] = movingFigure;
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


