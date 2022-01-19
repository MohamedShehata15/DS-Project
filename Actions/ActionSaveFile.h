#pragma once
#ifndef ACTION_SAVE_FILE_H
#define ACTION_SAVE_FILE_H
#include "Action.h"
#include <fstream>


class ActionSaveFile : public Action
{
	ofstream FileToSave;
	string FileName;

public:
	ActionSaveFile(ApplicationManager* pApp);
	virtual void Execute();

};

#endif