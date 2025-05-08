#include "geo.h"
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

Triangle triangle;
std::vector<Point> points;
double area = 0.0;
double twiceArea = 0.0;
double a = 0, b = 0, c = 0;
double distance(const Point &A, const Point &B) {
    return std::sqrt((A.x - B.x)*(A.x - B.x) + (A.y - B.y)*(A.y - B.y));
}

double crossProduct(const Point &A, const Point &B, const Point &P) {
    return (B.x - A.x) * (P.y - A.y) - (B.y - A.y) * (P.x - A.x);
}

double heronArea(const Point &A, const Point &B, const Point &C) {
    double a = distance(B, C);
    double b = distance(A, C);
    double c = distance(A, B);
    double s = (a + b + c) / 2.0;
    return std::sqrt(s * (s - a) * (s - b) * (s - c));
}

void Points() {
    std::cout << "Enter the coordinates of the triangle (3 points):\n";
    std::cout << "A (x y): ";
    std::cin >> triangle.A.x >> triangle.A.y;
    std::cout << "B (x y): ";
    std::cin >> triangle.B.x >> triangle.B.y;
    std::cout << "C (x y): ";
    std::cin >> triangle.C.x >> triangle.C.y;

    int n;
    std::cout << "How many points do you want to check? ";
    std::cin >> n;
    points.resize(n);

    for (int i = 0; i < n; ++i) {
        std::cout << "points " << i + 1 << " (x y): ";
        std::cin >> points[i].x >> points[i].y;
    }
}

void ABCDEFG() {
    a = distance(triangle.B, triangle.C);
    b = distance(triangle.C, triangle.A);
    c = distance(triangle.A, triangle.B);

    double s = (a + b + c) / 2.0;
    area = std::sqrt(s * (s - a) * (s - b) * (s - c));
    twiceArea = 2 * area;

}

void Geron()
{
    for (size_t i = 0; i < points.size(); ++i)
    {
        const Point &P = points[i];
        std::cout << "points " << i + 1 << " (" << P.x << ", " << P.y << "): ";
        if (area == heronArea(P, triangle.A, triangle.B) + heronArea(P, triangle.B, triangle.C) + heronArea(P, triangle.C, triangle.A))
        {
            if (heronArea(P, triangle.A, triangle.B) == 0 || heronArea(P, triangle.B, triangle.C) ==0 || heronArea(P, triangle.C, triangle.A) == 0)
            {
                std::cout << "on the triangle\n";
            }
            else
            {
                std::cout << "inside the triangle\n";
            }
        }
        else
        {
            std::cout << "outside the triangle\n";
        }


    }
}
void Perevirka() {
    if (twiceArea == 0) {
        std::cout << "The triangle is degenerate (all points on a straight line).\n";
        for (size_t i = 0; i < points.size(); ++i) {
            const Point &P = points[i];
            double cp = crossProduct(triangle.A, triangle.B, P);

            std::cout << "points " << i + 1 << " (" << P.x << ", " << P.y << "): ";
            if (cp == 0) {
                std::cout << "lies on the line of the triangle\n";
            } else {
                std::cout << "does not lie on the line of the triangle\n";
            }
        }
        return;
    }

    for (size_t i = 0; i < points.size(); ++i) {
        const Point &P = points[i];
        double cp1 = crossProduct(triangle.A, triangle.B, P);
        double cp2 = crossProduct(triangle.B, triangle.C, P);
        double cp3 = crossProduct(triangle.C, triangle.A, P);

        bool has_pos = (cp1 > 0) || (cp2 > 0) || (cp3 > 0);
        bool has_neg = (cp1 < 0) || (cp2 < 0) || (cp3 < 0);

        std::cout << "Point " << i + 1 << " (" << P.x << ", " << P.y << "): ";

        if (cp1 == 0 || cp2 == 0 || cp3 == 0) {
            bool Na =
                (cp1 == 0 && P.x >= std::min(triangle.A.x, triangle.B.x) && P.x <= std::max(triangle.A.x, triangle.B.x) &&
                             P.y >= std::min(triangle.A.y, triangle.B.y) && P.y <= std::max(triangle.A.y, triangle.B.y)) ||
                (cp2 == 0 && P.x >= std::min(triangle.B.x, triangle.C.x) && P.x <= std::max(triangle.B.x, triangle.C.x) &&
                             P.y >= std::min(triangle.B.y, triangle.C.y) && P.y <= std::max(triangle.B.y, triangle.C.y)) ||
                (cp3 == 0 && P.x >= std::min(triangle.C.x, triangle.A.x) && P.x <= std::max(triangle.C.x, triangle.A.x) &&
                             P.y >= std::min(triangle.C.y, triangle.A.y) && P.y <= std::max(triangle.C.y, triangle.A.y));

            if (Na) {
                std::cout << "lies on the side of the triangle\n";
            } else {
                std::cout << "lies on the line of the triangle, but outside it\n";
            }
        } else if (!has_pos || !has_neg) {
            std::cout << "inside the triangle\n";
        } else {
            std::cout << "outside the triangle\n";
        }
    }
}