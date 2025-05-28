#pragma once

struct Point{
    float x;
    float y;
};

struct Triangle{
    Point a, b, c;
};

Triangle read_triangle();
void print_t(Triangle);

Point read_point();
void point_point(Point);