#ifndef ACTION_UPLOAD_FILE_H
#define ACTION_UPLOAD_FILE_H

#include "Action.h"
#include <fstream>
using namespace std;

class ActionUploadFile : public Action
{
	ifstream TheFile;
	string FileName;


public:
	ActionUploadFile(ApplicationManager* pApp);

	virtual void Execute();

};

#endif