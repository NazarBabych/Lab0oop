#ifndef GEO_H
#define GEO_H
#include <vector>

struct Point {
    double x, y;
};

struct Triangle {
    Point A, B, C;
};

extern Triangle triangle;
extern std::vector<Point> points;
extern double twiceArea;

void Points();
void ABCDEFG();
void Perevirka();
void Geron();

#endif