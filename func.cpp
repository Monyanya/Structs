#include <iostream>
#include "func.h"
#include <cmath>

Point InputPoint () {
    Point p{};
    std::cin >> p.x >> p.y;    
    return p;
}

void OutputPoint (Point& p) {
    std::cout << "Координаты точки: (" << p.x << "; " << p.y << ")" << std::endl;
}

CircleF InputCircle () {
    CircleF c{};
    std::cin >> c.mid.x >> c.mid.y;
    std::cout << "Введите радиус круга: ";
    std::cin >> c.rad;
    return c;
}

void OutputCircle (CircleF& c) {
    std::cout << "Координаты центра: (" << c.mid.x << "; " << c.mid.y << ")\n"
              << "Радиус: " << c.rad << "\n"
              << "Площадь: " << c.sq << "\n"
              << "Длина окружности: " << c.per << "\n";
}

CircleF CalcAreaC (CircleF& c) {
    c.sq = M_PI * c.rad * c.rad;
    return c;
}

CircleF CalcPerimC (CircleF& c) {
    c.per = 2 * M_PI * c.rad;
    return c;
}

SquareF InputSquare() {
    SquareF s{};
    std::cin >> s.corner.x >> s.corner.y;
    std::cout << "Введите длину стороны квадрата: ";
    std::cin >> s.length;
    return s;
}

SquareF CalcAreaS (SquareF& s) {
    s.sq = s.length * s.length;
    return s;
}

SquareF CalcPerimS (SquareF& s) {
    s.per = s.length * 4;
    return s;
}

void OutputSquare (SquareF& s) {
    std::cout << "Координаты верхнего левого угла: (" << s.corner.x << "; " << s.corner.y << ")\n"
              << "Длина стороны: " << s.length << "\n"
              << "Площадь: " << s.sq << "\n"
              << "Периметр: " << s.per << "\n";
}

bool PointInCircle(Point& p, CircleF& c) {
    double dx = p.x - c.mid.x;
    double dy = p.y - c.mid.y;
    return dx*dx + dy*dy < c.rad * c.rad;
}

bool PointInSquare(Point& p, SquareF& s) {
    double left = s.corner.x;
    double right = s.corner.x + s.length;
    double top = s.corner.y;
    double bottom = s.corner.y - s.length;
    return (p.x > left) && (p.x < right) && (p.y > bottom) && (p.y < top);
}

bool PointOnCircle(Point& p, CircleF& c) {
    double dx = p.x - c.mid.x;
    double dy = p.y - c.mid.y;
    return dx*dx + dy*dy == c.rad * c.rad;
}

bool PointOnSquare(Point& p, SquareF& s) {
    double left = s.corner.x;
    double right = s.corner.x + s.length;
    double top = s.corner.y;
    double bottom = s.corner.y - s.length;

    bool on_left   = (p.x == left)  && (p.y >= bottom) && (p.y <= top);
    bool on_right  = (p.x == right) && (p.y >= bottom) && (p.y <= top);
    bool on_top    = (p.y == top)   && (p.x >= left)   && (p.x <= right);
    bool on_bottom = (p.y == bottom)&& (p.x >= left)   && (p.x <= right);

    if ((p.x > left) && (p.x < right) && (p.y > bottom) && (p.y < top)) return false;
    return on_left || on_right || on_top || on_bottom;
}

bool CrossCircles(CircleF& a, CircleF& b) {
    double dx = a.mid.x - b.mid.x;
    double dy = a.mid.y - b.mid.y;
    double d = std::sqrt(dx*dx + dy*dy);
    double rsum = a.rad + b.rad;
    double rdiff = std::abs(a.rad - b.rad);
    return (d <= rsum) && (d >= rdiff);
}

bool CrossSquares(SquareF& s1, SquareF& s2) {
    double a_left = s1.corner.x;
    double a_right = s1.corner.x + s1.length;
    double a_top = s1.corner.y;
    double a_bottom = s1.corner.y - s1.length;

    double b_left = s2.corner.x;
    double b_right = s2.corner.x + s2.length;
    double b_top = s2.corner.y;
    double b_bottom = s2.corner.y - s2.length;

    if (a_right < b_left || b_right < a_left || a_top < b_bottom || b_top < a_bottom)
        return false;

    bool a_in_b = (a_left > b_left) && (a_right < b_right) && (a_bottom > b_bottom) && (a_top < b_top);
    bool b_in_a = (b_left > a_left) && (b_right < a_right) && (b_bottom > a_bottom) && (b_top < a_top);
    if (a_in_b || b_in_a) return false;

    return true;
}

bool CrossCircleSquare(CircleF& c, SquareF& s) {
    double left = s.corner.x;
    double right = s.corner.x + s.length;
    double top = s.corner.y;
    double bottom = s.corner.y - s.length;

    bool cx_in = (c.mid.x >= left) && (c.mid.x <= right);
    bool cy_in = (c.mid.y >= bottom) && (c.mid.y <= top);

    if (cx_in && cy_in) {
        double d_left   = c.mid.x - left;
        double d_right  = right - c.mid.x;
        double d_top    = top - c.mid.y;
        double d_bottom = c.mid.y - bottom;
        double min_edge = std::min(std::min(d_left, d_right), std::min(d_top, d_bottom));
        return c.rad >= min_edge;
    } else {
        double dx = 0.0;
        if (c.mid.x < left) dx = left - c.mid.x;
        else if (c.mid.x > right) dx = c.mid.x - right;

        double dy = 0.0;
        if (c.mid.y < bottom) dy = bottom - c.mid.y;
        else if (c.mid.y > top) dy = c.mid.y - top;

        double dist = std::sqrt(dx*dx + dy*dy);
        return dist <= c.rad;
    }
}

bool CircleInsideCircle(CircleF& a, CircleF& b) {
    double dx = a.mid.x - b.mid.x;
    double dy = a.mid.y - b.mid.y;
    double d = std::sqrt(dx*dx + dy*dy);
    return d + a.rad < b.rad;
}

bool SquareInsideSquare(SquareF& s1, SquareF& s2) {
    double a_left = s1.corner.x;
    double a_right = s1.corner.x + s1.length;
    double a_top = s1.corner.y;
    double a_bottom = s1.corner.y - s1.length;

    double b_left = s2.corner.x;
    double b_right = s2.corner.x + s2.length;
    double b_top = s2.corner.y;
    double b_bottom = s2.corner.y - s2.length;

    return (a_left > b_left) && (a_right < b_right) && (a_bottom > b_bottom) && (a_top < b_top);
}

bool SquareInsideCircle(SquareF& s, CircleF& c) {
    double left = s.corner.x;
    double right = s.corner.x + s.length;
    double top = s.corner.y;
    double bottom = s.corner.y - s.length;

    double dx, dy;

    dx = left - c.mid.x;  dy = top - c.mid.y;
    if (!(dx*dx + dy*dy < c.rad * c.rad)) return false;

    dx = right - c.mid.x; dy = top - c.mid.y;
    if (!(dx*dx + dy*dy < c.rad * c.rad)) return false;

    dx = left - c.mid.x;  dy = bottom - c.mid.y;
    if (!(dx*dx + dy*dy < c.rad * c.rad)) return false;

    dx = right - c.mid.x; dy = bottom - c.mid.y;
    if (!(dx*dx + dy*dy < c.rad * c.rad)) return false;

    return true;
}

bool CircleInsideSquare(CircleF& c, SquareF& s) {
    double left = s.corner.x;
    double right = s.corner.x + s.length;
    double top = s.corner.y;
    double bottom = s.corner.y - s.length;

    return (c.mid.x - c.rad > left)  &&
           (c.mid.x + c.rad < right) &&
           (c.mid.y + c.rad < top)   &&
           (c.mid.y - c.rad > bottom);
}