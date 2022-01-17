#include "GUI.h"
#include "../Figures/CEllipse.h"
#include <iostream>
#
//constructor make necessary initializations
GUI::GUI()
{
	//Initialize user interface parameters
	UI.InterfaceMode = MODE_DRAW;
	
	UI.width = 1300;
	UI.height = 700;
	UI.wx = 5;
	UI.wy =5;

	
	UI.StatusBarHeight = 50;
	UI.ToolBarHeight = 50;
	UI.MenuItemWidth = 80;
	
	UI.DrawColor = BLACK;	//Drawing color
	UI.FillColor = GREEN;	//Filling color
	UI.MsgColor = RED;		//Messages color
	UI.BkGrndColor = LIGHTGOLDENRODYELLOW;	//Background color
	UI.HighlightColor = MAGENTA;	//This color should NOT be used to draw figures. use if for highlight only
	UI.StatusBarColor = TURQUOISE;
	UI.PenWidth = 4;	//width of the figures frames

	UI.isFilled = false;

	DrawingColor = RED;

	
	//Create the output window
	pWind = CreateWind(UI.width, UI.height, UI.wx, UI.wy);
	//Change the title
	pWind->ChangeTitle("Paint for Kids - Programming Techniques Project");
	
	CreateDrawToolBar();
	CreateStatusBar();
}


//======================================================================================//
//								Input Functions										    //
//======================================================================================//

bool GUI::isWithinDrawingArea(int y)
{
	return y >= UI.StatusBarHeight && y <= UI.height - UI.StatusBarHeight;
}

void GUI::GetPointClicked(int &x, int &y) const
{
	pWind->WaitMouseClick(x, y);	//Wait for mouse click
}

string GUI::GetSrting() const 
{
	string Label;
	char Key;
	while(1)
	{
		pWind->WaitKeyPress(Key);
		if(Key == 27 )	//ESCAPE key is pressed
			return "";	//returns nothing as user has cancelled label
		if(Key == 13 )	//ENTER key is pressed
			return Label;
		if(Key == 8 )	//BackSpace is pressed
			Label.resize(Label.size() -1 );			
		else
			Label+= Key;
		PrintMessage(Label);
	}
}

//This function reads the position where the user clicks to determine the desired action
ActionType GUI::MapInputToActionType() const
{	
	int x,y;
	pWind->WaitMouseClick(x, y);	//Get the coordinates of the user click

	if(UI.InterfaceMode == MODE_DRAW)	//GUI in the DRAW mode
	{
		//[1] If user clicks on the Toolbar
		if ( y >= 0 && y < UI.ToolBarHeight)
		{	
			//Check whick Menu item was clicked
			//==> This assumes that menu items are lined up horizontally <==
			int ClickedItemOrder = (x / UI.MenuItemWidth);
			//Divide x coord of the point clicked by the menu item width (int division)
			//if division result is 0 ==> first item is clicked, if 1 ==> 2nd item and so on

			switch (ClickedItemOrder)
			{
			case ITM_SQUR: return DRAW_SQUARE;
			case ITM_ELPS: return DRAW_ELPS;
			case ITM_HEX: return DRAW_HEX;
			case ITM_DRAW_CLR: return CHNG_DRAW_CLR;
			case ITM_Bg_CLR: return CHNG_BK_CLR;
			case ITM_FILL_CLR:return CHNG_FILL_CLR;
			case ITM_DEFALT: return  default_setting;
			case ITM_UPLOAD: return LOAD;
			case PLAY: return TO_PLAY;
			case ITM_SEND_BACK: return 	SEND_BACK;		
			case ITM_BRNG_FRNT: return BRNG_FRNT;
			case ITM_DEL: return DEL;
			case ITM_RESIZE: return RESIZE;
			case ITM_SELECT: return SELECT;
			case ITM_CLEAR: return CLEAR;
			case ITM_EXIT: return EXIT;	
			
			default: return EMPTY;	//A click on empty place in desgin toolbar
			}
		}

		//[2] User clicks on the drawing area
		if ( y >= UI.ToolBarHeight && y < UI.height - UI.StatusBarHeight)
		{
			return DRAWING_AREA;	
		}
		
		//[3] User clicks on the status bar
		return STATUS;
	}
	else if(UI.InterfaceMode == MODE_PLAY)	//GUI is in PLAY mode
	{
		///TODO:
		//perform checks similar to Draw mode checks above
		//and return the correspoding action
		if (y >= 0 && y < UI.ToolBarHeight)
		{
			//Check which Menu item was clicked
			//==> This assumes that menu items are lined up horizontally <==
			int ClickedItemOrder = (x / UI.MenuItemWidth);
			//Divide x coord of the point clicked by the menu item width (int division)
			//if division result is 0 ==> first item is clicked, if 1 ==> 2nd item and so on

			switch (ClickedItemOrder)
			{
			case PICK_FIGURE: return PICK_FIG;
			case PICK_COLOR: return PICK_CLR;
			case PICK_FILLED: return PICK_FILL;
			case DRAW: return TO_DRAW;
			case PLAY_BACK: return BACK;
			case END: return EXIT;

			default: return EMPTY;

			}
		}

		//[2] User clicks on the drawing area
		if (y >= UI.ToolBarHeight && y < UI.height - UI.StatusBarHeight)
		{
			return DRAWING_AREA;
		}

		//[3] User clicks on the status bar

		return STATUS;
	}
	else if (UI.InterfaceMode == RESIZE_MODE)	
	{
		if (y >= 0 && y < UI.ToolBarHeight)
		{
			//Check which Menu item was clicked
			//==> This assumes that menu items are lined up horizontally <==
			int ClickedItemOrder = (x / UI.MenuItemWidth);
			//Divide x coord of the point clicked by the menu item width (int division)
			//if division result is 0 ==> first item is clicked, if 1 ==> 2nd item and so on

			switch (ClickedItemOrder)
			{
			case FACTOR_QUARTER		: return	QUARTER_FACTOR;
			case FACTOR_HALF		: return	HALF_FACTOR;
			case FACTOR_DOUBLE		: return	DOUBLE_FACTOR;
			case FACTOR_QUADRUPLE	: return	QUADRUPLE_FACTOR;
			case ITEM_SELECT		: return	SELECT;
			case ITEM_BACK			: return	BACK;

			default: return EMPTY;
			}
		}

		//[2] User clicks on the drawing area
		if (y >= UI.ToolBarHeight && y < UI.height - UI.StatusBarHeight)
		{
			return DRAWING_AREA;
		}

		//[3] User clicks on the status bar

		return STATUS;
	}



	else 
	{
		if (y >= 0 && y < UI.ToolBarHeight)
		{
			//Check which Menu item was clicked
			//==> This assumes that menu items are lined up horizontally <==
			int ClickedItemOrder = (x / UI.MenuItemWidth);
			//Divide x coord of the point clicked by the menu item width (int division)
			//if division result is 0 ==> first item is clicked, if 1 ==> 2nd item and so on

			switch (ClickedItemOrder)
			{
			case ITM_BLUE: return CLR_BLUE;
			case ITM_BLACK: return CLR_BLACK;
			case ITM_GREEN: return CLR_GREEN;
			case ITM_YELLOW: return CLR_YELLOW;
			case ITM_RED: return  CLR_RED;
			case ITM_BACK: return  BACK;

			default: return EMPTY;

			}
		}

		//[2] User clicks on the drawing area
		if (y >= UI.ToolBarHeight && y < UI.height - UI.StatusBarHeight)
		{
			return DRAWING_AREA;
		}

		//[3] User clicks on the status bar

		return STATUS;


	}
}	


//======================================================================================//
//								Output Functions										//
//======================================================================================//

window* GUI::CreateWind(int w, int h, int x, int y) const
{ 
	window* pW = new window(w, h, x, y);
	pW->SetBrush(UI.BkGrndColor);
	pW->SetPen(UI.BkGrndColor, 1);
	pW->DrawRectangle(0, UI.ToolBarHeight, w, h);	
	return pW;
}
//////////////////////////////////////////////////////////////////////////////////////////
void GUI::CreateStatusBar() const
{
	pWind->SetPen(UI.StatusBarColor, 1);
	pWind->SetBrush(UI.StatusBarColor);
	pWind->DrawRectangle(0, UI.height - UI.StatusBarHeight, UI.width, UI.height);
}
//////////////////////////////////////////////////////////////////////////////////////////
void GUI::ClearStatusBar() const
{
	//Clear Status bar by drawing a filled white Square
	pWind->SetPen(UI.StatusBarColor, 1);
	pWind->SetBrush(UI.StatusBarColor);
	pWind->DrawRectangle(0, UI.height - UI.StatusBarHeight, UI.width, UI.height);
}
//////////////////////////////////////////////////////////////////////////////////////////
void GUI::CreateDrawToolBar() const
{
	UI.InterfaceMode = MODE_DRAW;
	// ***clear play mode tool bar***
	ClearToolBar();
	//You can draw the tool bar icons in any way you want.
	//Below is one possible way
	
	//First prepare List of images for each menu item
	//To control the order of these images in the menu, 
	//reoder them in UI_Info.h ==> enum DrawMenuItem
	string MenuItemImages[DRAW_ITM_COUNT];
	MenuItemImages[ITM_SQUR] = "images\\MenuItems\\Menu_Sqr.jpg";
	MenuItemImages[ITM_ELPS] = "images\\MenuItems\\Menu_Elps.jpg";
	MenuItemImages[ITM_HEX] = "images\\MenuItems\\Menu_Hex.jpg";
	MenuItemImages[ITM_DRAW_CLR] = "images\\MenuItems\\brush.jpg";
	MenuItemImages[ITM_Bg_CLR] = "images\\MenuItems\\bg.JPG";
	MenuItemImages[ITM_FILL_CLR] = "images\\MenuItems\\fill.JPG";
	MenuItemImages[ITM_SELECT] = "images\\MenuItems\\Menu_Select.JPG";
	MenuItemImages[ITM_RESIZE] = "images\\MenuItems\\resize.jpg";
	MenuItemImages[ITM_DEL] = "images\\MenuItems\\delete.jpg";
	MenuItemImages[ITM_SEND_BACK] = "images\\MenuItems\\send_to_back.jpg";
	MenuItemImages[ITM_BRNG_FRNT]= "images\\MenuItems\\bring_to_front.jpg";
	MenuItemImages[ITM_UPLOAD] = "images\\MenuItems\\upload.JPG";
	MenuItemImages[ITM_DEFALT]= "images\\MenuItems\\restore.JPG";
	MenuItemImages[ITM_CLEAR]= "images\\MenuItems\\clear_all.jpg";
	MenuItemImages[PLAY] = "images\\MenuItems\\Mode_Play.jpg";
	MenuItemImages[ITM_EXIT] = "images\\MenuItems\\Menu_Exit.jpg";

	//TODO: Prepare images for each menu item and add it to the list

	//Draw menu item one image at a time
	for(int i=0; i<DRAW_ITM_COUNT; i++)
		pWind->DrawImage(MenuItemImages[i], i*UI.MenuItemWidth,0,UI.MenuItemWidth, UI.ToolBarHeight);



	//Draw a line under the toolbar
	pWind->SetPen(RED, 3);
	pWind->DrawLine(0, UI.ToolBarHeight, UI.width, UI.ToolBarHeight);	

}
//////////////////////////////////////////////////////////////////////////////////////////

void GUI::CreatePlayToolBar() const
{
	UI.InterfaceMode = MODE_PLAY;
	// ***clear draw mode tool bar***
	ClearToolBar();
	///TODO: write code to create Play mode menu
	string MenuItemImagesPlayMode[PLAY_ITM_COUNT];
	MenuItemImagesPlayMode[PICK_FIGURE] = "images\\MenuItems\\Pick_Figure.jpg";
	MenuItemImagesPlayMode[PICK_COLOR] = "images\\MenuItems\\Pick_Color.jpg";
	MenuItemImagesPlayMode[PICK_FILLED] = "images\\MenuItems\\Pick_Filled.jpg";
	MenuItemImagesPlayMode[DRAW] = "images\\MenuItems\\Mode_Draw.jpg";
	MenuItemImagesPlayMode[PLAY_BACK] = "images\\MenuItems\\right_arrow.jpg";
	MenuItemImagesPlayMode[END] = "images\\MenuItems\\Menu_Exit.jpg";

	//Draw menu item one image at a time
	for (int i = 0; i < PLAY_ITM_COUNT; i++)
		pWind->DrawImage(MenuItemImagesPlayMode[i], i * UI.MenuItemWidth, 0, UI.MenuItemWidth, UI.ToolBarHeight);

	//Draw a line under the toolbar
	pWind->SetPen(RED, 3);
	pWind->DrawLine(0, UI.ToolBarHeight, UI.width, UI.ToolBarHeight);
}
//////////////////////////////////////////////////////////////////////////////////////////

void GUI::CreateColorToolBar() const {
	UI.InterfaceMode = COLORS_MODE;
	// ***clear play mode tool bar***
	ClearToolBar();
	string MenuItemColorsIcons[COLORS_ITM_COUNT];
	MenuItemColorsIcons[ITM_BLUE] = "images\\MenuItems\\blue.jpg";
	MenuItemColorsIcons[ITM_BLACK] = "images\\MenuItems\\black.jpg";
	MenuItemColorsIcons[ITM_GREEN] = "images\\MenuItems\\green.jpg";
	MenuItemColorsIcons[ITM_YELLOW] = "images\\MenuItems\\yellow.jpg";
	MenuItemColorsIcons[ITM_RED] = "images\\MenuItems\\red.jpg";
	MenuItemColorsIcons[ITM_BACK] = "images\\MenuItems\\right_arrow.jpg";

	//Draw menu item one image at a time
	for (int i = 0; i < COLORS_ITM_COUNT; i++)
		pWind->DrawImage(MenuItemColorsIcons[i], i * UI.MenuItemWidth, 0, UI.MenuItemWidth, UI.ToolBarHeight);

	//Draw a line under the toolbar
	pWind->SetPen(RED, 3);
	pWind->DrawLine(0, UI.ToolBarHeight, UI.width, UI.ToolBarHeight);
}
//////////////////////////////////////////////////////////////////////////////////////////

void GUI::CreateResizeToolBar()
{
	UI.InterfaceMode = RESIZE_MODE;
	ClearToolBar();	
	string MenuItemResizeIcons[FACTOR_ITM_COUNT];
	MenuItemResizeIcons[FACTOR_QUARTER] = "images\\MenuItems\\quarter_icon.jpg";
	MenuItemResizeIcons[FACTOR_HALF] = "images\\MenuItems\\half_icon.jpg";
	MenuItemResizeIcons[FACTOR_DOUBLE] = "images\\MenuItems\\double_icon.jpg";
	MenuItemResizeIcons[FACTOR_QUADRUPLE] = "images\\MenuItems\\quadritic_icon.jpg";
	MenuItemResizeIcons[ITEM_SELECT] = "images\\MenuItems\\Menu_Select.JPG";
	MenuItemResizeIcons[ITEM_BACK] = "images\\MenuItems\\right_arrow.jpg";

	//Draw menu item one image at a time
	for (int i = 0; i < FACTOR_ITM_COUNT; i++)
		pWind->DrawImage(MenuItemResizeIcons[i], i * UI.MenuItemWidth, 0, UI.MenuItemWidth, UI.ToolBarHeight);

	//Draw a line under the toolbar
	pWind->SetPen(RED, 3);
	pWind->DrawLine(0, UI.ToolBarHeight, UI.width, UI.ToolBarHeight);
}
//////////////////////////////////////////////////////////////////////////////////////////
void GUI::ClearDrawArea() const
{
	pWind->SetPen(UI.BkGrndColor, 1);
	pWind->SetBrush(UI.BkGrndColor);
	pWind->DrawRectangle(0, UI.ToolBarHeight, UI.width, UI.height - UI.StatusBarHeight);	
	
}
/****************************************************************************************/
/******** Play Mode:  
	DrawRect -> Draw Rectangle as a Tool Bar Background
	ClearToolBar -> Clear Tool Bar Items and Call DrawRect Function
							*********/
void GUI::DrawRect(Point P1, Point P2, GfxInfo RectGfxInfo, bool selected) const
{
	color DrawingClr;
	if (selected)
		DrawingClr = UI.HighlightColor; //Figure should be drawn highlighted
	else
		DrawingClr = RectGfxInfo.DrawClr;

	pWind->SetPen(DrawingClr, 1);
	drawstyle style;
	if (RectGfxInfo.isFilled)
	{
		style = FILLED;
		pWind->SetBrush(RectGfxInfo.FillClr);
	}
	else
		style = FRAME;


	pWind->DrawRectangle(P1.x, P1.y, P2.x, P2.y, style);

}

void GUI::ClearToolBar()const
{
	GfxInfo gfxInfo;
	Point P1, P2;
	P1.x = 0; P1.y = 0;
	P2.x = UI.width; P2.y = UI.ToolBarHeight + 3;
	gfxInfo.DrawClr = WHITE;	//any color for border
	gfxInfo.FillClr = WHITE;	//any color for filling
	gfxInfo.isFilled = true;	//Figure is filled

	DrawRect(P1, P2, gfxInfo, false);
}
/****************************************************************************************/
//////////////////////////////////////////////////////////////////////////////////////////

void GUI::PrintMessage(string msg) const	//Prints a message on status bar
{
	ClearStatusBar();	//First clear the status bar
	
	pWind->SetPen(UI.MsgColor, 50);
	pWind->SetFont(20, BOLD , BY_NAME, "Arial");   
	pWind->DrawString(10, UI.height - (int)(UI.StatusBarHeight/1.5), msg);
}
//////////////////////////////////////////////////////////////////////////////////////////

color GUI::getCrntDrawColor() const	//get current drwawing color
{	return UI.DrawColor;	}
//////////////////////////////////////////////////////////////////////////////////////////

void GUI::setnewDrawColor(color c) const  //set new draw color
{
	UI.DrawColor = c;
}

void GUI::setnewBackgroundColor(color bg) const //set new bg color
{
	UI.BkGrndColor = bg;
	ClearDrawArea();
}
void GUI::setnewFillColor(color bg) const {  //set new fill color
	UI.FillColor = bg;
}

void GUI::setIsFilled(bool s) {
	UI.isFilled = s;
}

color GUI::getCrntFillColor() const	//get current filling color
{	return UI.FillColor;	}
//////////////////////////////////////////////////////////////////////////////////////////
	
int GUI::getCrntPenWidth() const		//get current pen width
{	return UI.PenWidth;	}

//////////////////////////////////////////////////////////////////////////////////////////
bool GUI::getIsFilled()const {
	return UI.isFilled;}

//////////////////////////////////////////////////////////////////////////////////////////
color GUI::getAppliedColor() {
	return DrawingColor;
}
void GUI::setAppliedColor(color c) {
	DrawingColor = c;
}
// //////////////////////////////////////////////////////////////////////////////////////////
//======================================================================================//
//								Figures Drawing Functions								//
//======================================================================================//

void GUI::DrawSquare(Point P1, int length, GfxInfo RectGfxInfo, bool selected) const
{
	color DrawingClr;
	if(selected)	
		DrawingClr = UI.HighlightColor; //Figure should be drawn highlighted
	else			
		DrawingClr = RectGfxInfo.DrawClr;
	
	pWind->SetPen(DrawingClr, RectGfxInfo.BorderWdth);	//Set Drawing color & width
	
	drawstyle style;
	if (RectGfxInfo.isFilled)	
	{
		style = FILLED;		
		pWind->SetBrush(RectGfxInfo.FillClr);
	}
	else	
		style = FRAME;
	
	pWind->DrawRectangle(P1.x, P1.y, P1.x +length, P1.y+length, style);
	//pWind->DrawLine(P1.x, P1.y, P1.x + length, P1.y + length, style);

}
void GUI::DrawEllipse(Point P1, int yr,int xr, GfxInfo EllGfxInfo, bool selected) const
{
	color DrawingClr;
	if (selected)
		DrawingClr = UI.HighlightColor; //Figure should be drawn highlighted
	else
		DrawingClr = EllGfxInfo.DrawClr;

	pWind->SetPen(DrawingClr, 3);
	drawstyle style;
	if (EllGfxInfo.isFilled)
	{
		style = FILLED;
		pWind->SetBrush(EllGfxInfo.FillClr);
	}
	else
		style = FRAME;


							
	pWind->DrawEllipse(P1.x - yr, P1.y + xr, P1.x + yr, P1.y - xr, style);





}

void GUI::DrawHexagone(Point points[], GfxInfo RectGfxInfo, bool selected) const
{
	color DrawingClr;
	if (selected)
		DrawingClr = UI.HighlightColor; //Figure should be drawn highlighted
	else
		DrawingClr = RectGfxInfo.DrawClr;

	pWind->SetPen(DrawingClr, RectGfxInfo.BorderWdth);	//Set Drawing color & width

	drawstyle style;
	if (RectGfxInfo.isFilled)
	{
		style = FILLED;
		pWind->SetBrush(RectGfxInfo.FillClr);
	}
	else
		style = FRAME;

	int XPoints2[] = { points[0].x, points[1].x, points[2].x, points[3].x, points[4].x, points[5].x };
	int YPoints2[] = { points[0].y, points[1].y, points[2].y, points[3].y, points[4].y, points[5].y };
	pWind->DrawPolygon(XPoints2, YPoints2, 6, style);
}

//////////////////////////////////////////////////////////////////////////////////////////
GUI::~GUI()
{
	delete pWind;
}

