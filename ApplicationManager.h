#ifndef APPLICATION_MANAGER_H
#define APPLICATION_MANAGER_H

#include "DEFS.h"
#include "Figures\CFigure.h"

class Action;	//Forward Declaration


//Main class that manages everything in the application.
class ApplicationManager
{
	enum { MaxFigCount = 200 };	//Max no of figures

private:
	int FigCount;		//Actual number of figures
	CFigure* FigList[MaxFigCount];	//List of all figures (Array of pointers)
	ActionType DrawingActionType;

	//Pointers to Input and Output classes
	GUI* pGUI;
	

public:	
	ApplicationManager(); 
	~ApplicationManager();

	void Run();		//to run the application
	
	int GetCount()const;
	CFigure* GetCopyFromFigureList(int) const;
	int getFigCount();

	// -- Action-Related Functions
	ActionType GetUserAction() const;
	Action* CreateAction(ActionType);
	void ExecuteAction(Action*&) ; //Execute an action

	
	// -- Figures Management Functions
	void AddFigure(CFigure* pFig); //Adds a new figure to the FigList
	CFigure *GetFigure(int x, int y) const; //Search for a figure given a point inside the figure

	CFigure* ApplicationManager::getSelectedFigure(int index); // Get Selected Figure by index

	void deSelectAllFigures();
	// send to front and bring to back functions
	int getIndexOfSelectedFigure();
	void moveFigureThenShift(int oldPosition, int newPosition);
	// delete Figure
	void deleteFigure(int figPosition);
	// Clear All Figures
	void clearAllFigures();
	void SaveAllFigures(ofstream &file); //save all figures


	// -- Interface Management Functions	
	GUI *GetGUI() const; //Return pointer to the interface
	void UpdateInterface() const;	//Redraws all the drawing window



	Action* ApplicationManager::handleDrawingColorAction(color c);
	Action* ApplicationManager::handleDefault();


};

#endif