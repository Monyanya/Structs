#pragma once

struct Point 
{
    double x;
    double y;
};

struct CircleF
{
    Point mid;
    double rad;
    double sq;
    double per;
};

struct SquareF
{
    Point corner;
    double length;
    double sq;
    double per;
};