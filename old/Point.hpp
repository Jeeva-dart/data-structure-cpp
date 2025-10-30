#ifndef POINT_H
#define POINT_H
#include<iostream>
#include<compare>
using namespace std;
class Point {
    private:
        short z = 0;
    public:
        short x = 0;
        short y = 0;
        Point() = default;
        Point(short x, short y);
        bool operator==(const Point& other) const;
        Point getPoints();
        void setPoints(short x, short y);
        strong_ordering operator<=>(const Point& point);
        Point operator+(const Point& point) const;
        Point operator+(short num) const;
        Point& operator+=(const Point& point);
        Point& operator++();
        Point operator++(int);
        friend ostream& operator<<(ostream& stream, Point& point);
    };
    
istream& operator>>(istream& stream, Point& point);
ostream& operator<<(ostream& stream, Point& point);
    
#endif