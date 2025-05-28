#include <iostream>
#include "triangle.h"
using namespace std;

Triangle read_triangle(){
    Triangle t;
    cout << "Enter point 1: " << endl;
    t.a = read_point();
    cout << "Enter point 2: " << endl;
    t.b = read_point();
    cout << "Enter point 3: " << endl;
    t.c = read_point();
}
Point read_point(){
    Point p;
    cout << "Enter x, y";
    cin >> p.x >> p.y;
    return p;
}
void print_t(Triangle t){
    cout << "Triangle point: ";
    point_point(t.a);
    cout << "\nTriangle point: ";
    point_point(t.b);
    cout << "\nTriangle point: ";
    point_point(t.c);
}
void point_point(Point tri){
    cout << "x = " << tri.x << "\ny = " << tri.y;
}