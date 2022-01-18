#ifndef UI_INFO_H
#define UI_INFO_H

#include "..\CMUgraphicsLib\CMUgraphics.h"

//User Interface information file.
//This file contains info that is needed by Input and Output classes to
//handle the user interface

enum GUI_MODE	//Graphical user interface mode
{
	MODE_DRAW,	//Drawing mode (startup mode)
	MODE_PLAY,	//Playing mode
	COLORS_MODE,
	RESIZE_MODE
};

enum DrawMenuItem //The items of the Draw menu (you should add more items)
{
	//Note: Items are ordered here as they appear in menu
	//If you want to change the menu items order, change the order here
	

	
	ITM_SQUR,		//Square item in menu
	ITM_ELPS,		//Ellipse item in menu
	ITM_HEX,        //Hexagone item in menu
	ITM_DRAW_CLR,
	ITM_Bg_CLR,
	ITM_FILL_CLR,
	ITM_SELECT,
	ITM_RESIZE,
	ITM_SEND_BACK,		//Send a figure to the back of all figures
	ITM_BRNG_FRNT,
	ITM_DEL,
	ITM_CLEAR,
	ITM_UPLOAD,
	PLAY,				//Switch to playmode
	ITM_EXIT,			//Exit item
	
	DRAW_ITM_COUNT		//no. of menu items ==> This should be the last line in this enum
	
};

enum PlayMenuItem //The items of the Play menu (you should add more items)
{
	//Note: Items are ordered here as they appear in menu
	//If you want to change the menu items order, change the order here
	
	//TODO: Add more items names here
	PICK_COLOR,
	PICK_FIGURE,
	PICK_FILLED,
	DRAW,
	PLAY_BACK,
	END,
	PLAY_ITM_COUNT		//no. of menu items ==> This should be the last line in this enum
	
};

enum ColorsMenuItem
{
	ITM_BLUE,
	ITM_BLACK,
	ITM_OFFWHITE,
	ITM_GREEN,
	ITM_YELLOW,
	ITM_RED,
	ITM_DEFALT,
	ITM_SLCT,
	ITM_BACK,

	COLORS_ITM_COUNT,
};
enum ResizeMenuItem
{
	FACTOR_QUARTER,
	FACTOR_HALF,
	FACTOR_DOUBLE,
	FACTOR_QUADRUPLE,
	ITEM_SELECT,
	ITEM_BACK,
	FACTOR_ITM_COUNT
};





__declspec(selectany) //This line to prevent "redefinition error"

struct UI_Info	//User Interface Info.
{
	GUI_MODE InterfaceMode;
	
	int	width, height,	//Window width and height
		wx , wy,			//Window starting coordinates
		StatusBarHeight,	//Status Bar Height
		ToolBarHeight,		//Tool Bar Height (distance from top of window to bottom line of toolbar)
		MenuItemWidth;		//Width of each item in toolbar menu
	

	color DrawColor;		//Drawing color
	color FillColor;		//Filling color
	color HighlightColor;	//Highlighting color
	color MsgColor;			//Messages color
	color BkGrndColor;		//Background color
	color StatusBarColor;	//Status bar color
	int PenWidth;			//width of the pen that draws shapes

	/// Add more members if needed
	bool isFilled;
	
}UI;	//create a global object UI

#endif