#include "ApplicationManager.h"
#include "GUI\GUI.h"

int main()
{
	// ayman 08-01-2022
	/*
	GUI* g=new GUI();
	
	
	window* w=g->CreateWind(200, 300, 10, 10);
	int x, y;
	w->WaitMouseClick(x, y);
	*/
	
	ApplicationManager AppManager;
	AppManager.Run();	
	
	return 0;
}

