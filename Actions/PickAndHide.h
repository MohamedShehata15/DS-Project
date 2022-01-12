#pragma once

#include <vector>
#include "Action.h"
#include "..\ApplicationManager.h"
#include "..\Figures\CFigure.h"
#include "..\Figures\CSquare.h"
#include "..\Figures\CEllipse.h"

//TODO: add the remaining cfigures.h files

class PickAndHide :public Action {
protected:
	vector<CFigure*>FigureList;
	GUI* pGUI;
	int score, correct, uncorrect;
	ActionType actType;
	Point P;
	CFigure* selected;

public:
	PickAndHide(ApplicationManager*);
	CFigure* Random() const;
	void Message(int, CFigure*) const;
	void UpdateInterface() const;
	void Delete(CFigure* fig);
	void Load();
	int GetType(CFigure*) const;
	virtual void ReadActionParameters();
	bool SameColor(color, color)const;
	virtual void Execute();
	CFigure* GetFigure(Point P) const;
	bool CheckFigure(CFigure*, int)const;
	bool IfColorExisting(CFigure*)const;
	bool checkColor_Figure(int f, color c, CFigure* rand) const;

	~PickAndHide(void);
};