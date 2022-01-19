#include "ApplicationManager.h"
#include "GUI\GUI.h"



//void ellipse(int x, int y, int stangle, int endangle, int xradius, int yradius);
int main()
{
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



