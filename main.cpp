#include <iostream>
#include "func.h"

int main () {
    std::cout << "Введите координаты точки: ";
    Point p = InputPoint();
    OutputPoint(p);

    std::cout << "Введите координаты центра круга: ";
    CircleF c0 = InputCircle();
    CalcAreaC(c0);
    CalcPerimC(c0);
    OutputCircle(c0);

    std::cout << "Введите координаты верхнего левого угла квадрата: ";
    SquareF s0 = InputSquare();
    CalcAreaS(s0);
    CalcPerimS(s0);
    OutputSquare(s0);

    std::cout << "Точка строго внутри круга? " << (PointInCircle(p, c0) ? "Да" : "Нет") << "\n";
    std::cout << "Точка строго на окружности? " << (PointOnCircle(p, c0) ? "Да" : "Нет") << "\n";
    std::cout << "Точка строго внутри квадрата? " << (PointInSquare(p, s0) ? "Да" : "Нет") << "\n";
    std::cout << "Точка строго на границе квадрата? " << (PointOnSquare(p, s0) ? "Да" : "Нет") << "\n";

    std::cout << "\nПересечение двух кругов\n";
    CircleF c1 = InputCircle();
    CalcAreaC(c1); CalcPerimC(c1);
    CircleF c2 = InputCircle();
    CalcAreaC(c2); CalcPerimC(c2);
    std::cout << "Пересекаются два круга? " << (CrossCircles(c1, c2) ? "Да" : "Нет") << "\n";

    std::cout << "\nПересечение двух квадратов\n";
    SquareF s1 = InputSquare();
    CalcAreaS(s1); CalcPerimS(s1);
    SquareF s2 = InputSquare();
    CalcAreaS(s2); CalcPerimS(s2);
    std::cout << "Пересекаются два квадрата? " << (CrossSquares(s1, s2) ? "Да" : "Нет") << "\n";

    std::cout << "\nПересечение круга и квадрата\n";
    CircleF c3 = InputCircle();
    CalcAreaC(c3); CalcPerimC(c3);
    SquareF s3 = InputSquare();
    CalcAreaS(s3); CalcPerimS(s3);
    std::cout << "Пересекаются круг и квадрат? " << (CrossCircleSquare(c3, s3) ? "Да" : "Нет") << "\n";

    std::cout << "\nПринадлежность: круг внутри круга\n";
    CircleF ci1 = InputCircle();
    CalcAreaC(ci1); CalcPerimC(ci1);
    CircleF ci2 = InputCircle();
    CalcAreaC(ci2); CalcPerimC(ci2);
    std::cout << "Первый круг строго внутри второго? " << (CircleInsideCircle(ci1, ci2) ? "Да" : "Нет") << "\n";

    std::cout << "\nПринадлежность: квадрат внутри квадрата\n";
    SquareF si1 = InputSquare();
    CalcAreaS(si1); CalcPerimS(si1);
    SquareF si2 = InputSquare();
    CalcAreaS(si2); CalcPerimS(si2);
    std::cout << "Первый квадрат строго внутри второго? " << (SquareInsideSquare(si1, si2) ? "Да" : "Нет") << "\n";

    std::cout << "\nПринадлежность: квадрат внутри круга\n";
    SquareF si3 = InputSquare();
    CalcAreaS(si3); CalcPerimS(si3);
    CircleF co = InputCircle();
    CalcAreaC(co); CalcPerimC(co);
    std::cout << "Квадрат строго внутри круга? " << (SquareInsideCircle(si3, co) ? "Да" : "Нет") << "\n";

    std::cout << "\nПринадлежность: круг внутри квадрата\n";
    CircleF ci3 = InputCircle();
    CalcAreaC(ci3); CalcPerimC(ci3);
    SquareF so = InputSquare();
    CalcAreaS(so); CalcPerimS(so);
    std::cout << "Круг строго внутри квадрата? " << (CircleInsideSquare(ci3, so) ? "Да" : "Нет") << "\n";

    return 0;
}