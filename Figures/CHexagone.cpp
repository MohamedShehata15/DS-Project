#include "CHexagone.h"
#include <iostream>
#include "Helpers.h"

CHexagone::CHexagone(Point _points[], GfxInfo FigureGfxInfo) :CFigure(FigureGfxInfo)
{
    for (int i = 0; i < 6; i++) {
        points[i] = _points[i];
    }
}

void CHexagone::DrawMe(GUI* pGUI)
{
    //Call Output::DrawRect to draw a Square on the screen	
    pGUI->DrawHexagone(points, FigGfxInfo, Selected);
}
bool CHexagone::PointInFigure(int x, int y)
{
    Point p;
    p.x = x;
    p.y = y;
    // Create a point for line segment from p to infinite 
    Point extreme = { 10000, y };

    // Count intersections of the above line with sides of polygon 
    int count = 0, i = 0;
    do
    {
        int next = (i + 1) % 6;

        // Check if the line segment from 'p' to 'extreme' intersects 
        // with the line segment from 'polygon[i]' to 'polygon[next]' 
        if (Helpers::doIntersect(points[i], points[next], p, extreme))
        {
            // If the point 'p' is collinear with line segment 'i-next', 
            // then check if it lies on segment. If it lies, return true, 
            // otherwise false 
            if (Helpers::orientation(points[i], p, points[next]) == 0)
                return Helpers::onSegment(points[i], p, points[next]);

            count++;
        }
        i = next;
    } while (i != 0);

    // Return true if count is odd, false otherwise 
    return count & 1; // Same as (count%2 == 1) 
}

string CHexagone::GetShapeInfo()
{
    return "In Process";
}