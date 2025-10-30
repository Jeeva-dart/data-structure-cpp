#include "Point.hpp"

bool Point::operator==(const Point& other) const {
    return x == other.x && y == other.y;
}

Point Point::getPoints() {
    return Point(x, y);
}

void Point::setPoints(short pointX, short pointY) {
    this->x = pointX;
    this->y = pointY;
}

Point::Point(short pointX, short pointY) : x{pointX}, y{pointY} {};


strong_ordering Point::operator<=>(const Point& point) {
    return this->x <=> point.x;
}

Point Point::operator+(const Point& point) const {
    return Point(this->x + point.x, this->y + point.y);
}

Point Point::operator+(short num) const {
    return Point(this->x + num, this->y + num);
}

Point& Point::operator+=(const Point& point) {
    this->x += point.x;
    this->y += point.y;
    return *this;
}

Point& Point::operator++() {
    this->x++;
    this->y++;
    return *this;
}

Point Point::operator++(int) {
    Point copy = *this;
    operator++();
    return copy;
}

istream& operator>>(istream& stream, Point& point) {
    cout << "Enter x: ";
    stream >> point.x;
    cout << "Enter y: ";
    stream >> point.y;
    return stream;
};

ostream& operator<<(ostream& stream, Point& point) {
    stream << '(' << point.x << ',' << point.y << ',' << point.z << ')' << endl;
    return stream;
};