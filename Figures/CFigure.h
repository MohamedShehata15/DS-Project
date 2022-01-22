#ifndef CFIGURE_H
#define CFIGURE_H

#include "..\defs.h"
#include "..\GUI\GUI.h"

//Base class for all figures
class CFigure
{
protected:
	int ID;		//Each figure has an ID
	bool Selected;	//true if the figure is selected.
	GfxInfo FigGfxInfo;	//Figure graphis info
	static int squareNum, ellipseNum, hexNum;
	/// Add more parameters if needed.

public:
	CFigure(GfxInfo FigureGfxInfo);
	/*virtual void increase() = 0;
	virtual void decrease() = 0;*/
	virtual int GetNumber()const = 0;
	virtual void upload(ifstream &file) = 0;
	virtual void saveFigure(ofstream &file) = 0;


	void SetSelected(bool );	//select/unselect the figure
	bool IsSelected() const;	//check whether fig is selected

	virtual void DrawMe(GUI*) const  = 0 ;		//Draw the figure
	
	void ChngDrawClr(color Dclr);	//changes the figure's drawing color
	void ChngFillClr(color Fclr);	//changes the figure's filling color

	int GetNumOfSquares()const;
	int GetNumOfEllipses()const;
	int GetNumOfHexagons()const;


	/// <summary>
	/// a function that a takes a point and determine if it's within the shape area
	/// </summary>
	/// <param name="int x"></param>
	/// <param name="int y"></param>
	/// <returns>true if the point within the area and false if not</returns>
	virtual bool isWithinArea(int, int) = 0; 

	virtual void Resize(GUI*, float) = 0;	//Resize the figure
	virtual CFigure* GetCopy() = 0;
	///The following functions should be supported by the figure class
	///It should be overridden by each inherited figure

	///Decide the parameters that you should pass to each function	
	virtual color GetCurrentColor()const;
	bool IsFilled()const;

	//virtual void Rotate() = 0;	//Rotate the figure

	//virtual void Move() = 0;		//Move the figure

	//virtual void Save(ofstream &OutFile) = 0;	//Save the figure parameters to the file
	//virtual void Load(ifstream &Infile) = 0;	//Load the figure parameters to the file
	
	// 08-01-2022 Output ?????? we don't need this parameter -->>>!!!
	//virtual void PrintInfo(Output* pOut) = 0;	//print all figure info on the status bar
	


	virtual void PrintInfo(GUI*) = 0;	//print all figure info on the status bar
};

#endif