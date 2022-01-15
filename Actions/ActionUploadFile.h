#ifndef ACTION_UPLOAD_FILE_H
#define ACTION_UPLOAD_FILE_H

#include "Action.h"

//Add Ellipse Action class
class ActionUploadFile : public Action
{
public:
	ActionUploadFile(ApplicationManager* pApp);

	virtual void Execute();

};

#endif