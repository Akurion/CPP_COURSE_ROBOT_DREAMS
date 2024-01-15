#include "Vector2d.h"
#include <cmath>
#include <iostream>

int Vector2d::instanceCount = 0;

Vector2d::Vector2d() : x(0.0f), y(0.0f) {
    instanceCount++;
}

Vector2d::Vector2d(float x_val, float y_val) : x(x_val), y(y_val) {
    instanceCount++;
}

Vector2d& Vector2d::operator=(const Vector2d& other) {
    if (this != &other) {
        x = other.x;
        y = other.y;
    }
    return *this;
}

Vector2d Vector2d::operator+(const Vector2d& secondVector) const {
    return Vector2d(x + secondVector.x, y + secondVector.y);
}

Vector2d Vector2d::operator-(const Vector2d& secondVector) const {
    return Vector2d(x - secondVector.x, y - secondVector.y);
}

Vector2d operator+(const Vector2d& leftVector, const Vector2d& rightVector) {
    return Vector2d(leftVector.x + rightVector.x, leftVector.y + rightVector.y);
}

Vector2d operator-(const Vector2d& leftVector, const Vector2d& rightVector) {
    return Vector2d(leftVector.x - rightVector.x, leftVector.y - rightVector.y);
}

float Vector2d::operator()() const {
    return std::sqrt(x * x + y * y);
}

float& Vector2d::operator[](int i) {
    if (i == 0) {
        return x;
    }
    else if (i == 1) {
        return y;
    }
    else {
        throw std::out_of_range("Index out of range");
    }
}

std::ostream& operator<<(std::ostream& os, const Vector2d& vector) {
    os << "{" << vector.x << "; " << vector.y << "}";
    return os;
}

std::istream& operator>>(std::istream& is, Vector2d& vector) {
    is >> vector.x >> vector.y;
    return is;
}

int Vector2d::getInstanceCount() {
    return instanceCount;
}

Vector2d::~Vector2d() {
    instanceCount--;
}


int main()
{

    Vector2d testVec{ 1.2, 5.6 };
    std::cout << testVec << std::endl;


    Vector2d inputVec;
    std::cout << "Enter vector (format: x y): ";
    std::cin >> inputVec;
    std::cout << "You entered: " << inputVec << std::endl;


    std::cout << "Number of active instances: " << Vector2d::getInstanceCount() << std::endl;

    return 0;
}