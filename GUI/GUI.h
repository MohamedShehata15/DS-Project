#ifndef GUI_H
#define GUI_H

#include "..\DEFS.h"
#include "UI_Info.h" 
#include "..\CMUgraphicsLib\CMUgraphics.h"


//This class is responsible for Grphical User Interface handling
//All user input and program outputs MUST be done through this class
//No other class is allowed to perform direct i/o
class GUI	
{
	color DrawingColor;
public:	
	window* pWind;	//Pointer to the Graphics Window
public:
	GUI();	
	~GUI();	
	window* CreateWind(int, int, int , int) const; //creates the application window

	/////////// Input Functoinality  /////////////////
	void GetPointClicked(int &x, int &y) const;//Get coordinate where user clicks
	string GetSrting() const ;	 //Returns a string entered by the user
	ActionType MapInputToActionType() const; //Read the user click and map to an action
	ActionType MapInputToActionType(int& X, int& Y) const;

	/////////// Output Functoinality  ////////////////
	void CreateDrawToolBar() const;	//creates Draw mode toolbar & menu
	void CreatePlayToolBar() const;	//creates Play mode toolbar & menu
	void CreateStatusBar() const;	//create the status bar
	void CreateColorToolBar() const; // creates Color Mode toolbar & menu
	void CreateResizeToolBar();
	/******shop*******/;
	void DrawRect(Point P1, Point P2, GfxInfo RectGfxInfo, bool selected) const;
	void ClearToolBar() const;

	void ClearStatusBar() const;	//Clears the status bar
	void ClearDrawArea() const;	//Clears the drawing area

	bool isWithinDrawingArea(int y);
	bool isInsideDrawingArea(int* xs, int* ys, int count) const;
	bool isInsideDrawingArea(int x, int y) const;
	color  GUI::ChangeColor(string color);
	// -- Figures Drawing functions
	void DrawSquare(Point P1, int length, GfxInfo RectGfxInfo, bool selected=false) const;  //Draw a Square
	void DrawEllipse(Point P1, int yr,int xr, GfxInfo EllGfxInfo, bool selected) const; //Draw Ellipse


	

	/*_____ Hexagon Functions _____ */
	void GetHexagonCoordinates(Point center, float radius, float angle, int* xCoordinates, int* yCoordinates);
	float GetHexagonAngle(Point, Point);
	float GetHexagonRadius(Point center, Point vertex);

	void GUI::DrawHexagon(Point center, float angle, int radius, GfxInfo RectGfxInfo, bool selected);


	
	void PrintMessage(string msg) const;	//Print a message on Status bar
	void PlayModeMessage(string msg1, int msg) const; //new style for message in status bar when on playmode

	color getCrntDrawColor() const;	//get current drwawing color
	color getCrntBgColor() const;//get current background color

	void GUI::setnewDrawColor(color c) const; //set new drawing color
	void GUI::setnewBackgroundColor(color bg) const;//set new bg color
	void GUI::setnewFillColor(color bg) const; // set new fill color
	void setIsFilled(bool s);
	color getCrntFillColor() const;	//get current filling color
	int getCrntPenWidth() const;		//get current pen width

	bool getIsFilled() const;


	color getAppliedColor();
	void setAppliedColor(color c);

};


#endif