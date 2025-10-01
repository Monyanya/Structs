#pragma once
#include "structs.h"

Point InputPoint ();
void OutputPoint (Point&);

CircleF InputCircle ();
CircleF CalcAreaC (CircleF&);
CircleF CalcPerimC (CircleF&);
void OutputCircle (CircleF&);

SquareF InputSquare ();
SquareF CalcAreaS (SquareF&);
SquareF CalcPerimS (SquareF&);
void OutputSquare (SquareF&);

bool PointInCircle (Point&, CircleF&);
bool PointInSquare (Point&, SquareF&);
bool PointOnCircle (Point&, CircleF&);
bool PointOnSquare (Point&, SquareF&);

bool CrossCircles (CircleF&, CircleF&);
bool CrossSquares (SquareF&, SquareF&);
bool CrossCircleSquare (CircleF&, SquareF&);

bool CircleInsideCircle (CircleF&, CircleF&);
bool SquareInsideSquare (SquareF&, SquareF&);
bool SquareInsideCircle (SquareF&, CircleF&);
bool CircleInsideSquare (CircleF&, SquareF&);
