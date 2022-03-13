#include "Canvas.h"

int main()
{
	Canvas canvas(25, 25);
    //canvas.SetPoint(5, 15, '&');
    //canvas.DrawLine(10, 10, 11, 20, '$');
    //canvas.FillRect(5, 5, 7, 20, '!');
    //canvas.DrawRect(5, 5, 7, 20, '?');
    canvas.FillCircle(10, 10, 4, '#');
	canvas.DrawCircle(10, 10, 4, '*');
    canvas.Print();
    //canvas.Clear();
}