#include "Vector3d.h"
#include <cmath>

Vector3d::Vector3d() : x(0.0f), y(0.0f), z(0.0f) {}

Vector3d::Vector3d(float x_val, float y_val, float z_val) : x(x_val), y(y_val), z(z_val) {}

float Vector3d::dotProduct(const Vector3d& other) const {
    return x * other.x + y * other.y + z * other.z;
}

Vector3d Vector3d::negate() const {
    return Vector3d(-x, -y, -z);
}

Vector3d::VectorRelativeState Vector3d::getRelativeState(const Vector3d& other) const {


    return VectorRelativeState::Identical;  
}

void Vector3d::scale(float factorX, float factorY, float factorZ) {
    x *= factorX;
    y *= factorY;
    z *= factorZ;
}

Vector3d Vector3d::crossProduct(const Vector3d& other) const {


    return Vector3d();  
}


Vector3d Vector3d::operator+(const Vector3d& other) const {
    return Vector3d(x + other.x, y + other.y, z + other.z);
}

Vector3d Vector3d::operator-(const Vector3d& other) const {
    return Vector3d(x - other.x, y - other.y, z - other.z);
}

Vector3d& Vector3d::operator=(const Vector3d& other) {
    if (this != &other) {
        x = other.x;
        y = other.y;
        z = other.z;
    }
    return *this;
}

float Vector3d::operator()() const {
    return std::sqrt(x * x + y * y + z * z);
}

float& Vector3d::operator[](int i) {
    if (i == 0) {
        return x;
    }
    else if (i == 1) {
        return y;
    }
    else if (i == 2) {
        return z;
    }
    else {
        throw std::out_of_range("Index out of range");
    }
}

std::ostream& operator<<(std::ostream& os, const Vector3d& vector) {
    os << "{" << vector.x << "; " << vector.y << "; " << vector.z << "}";
    return os;
}

std::istream& operator>>(std::istream& is, Vector3d& vector) {
    is >> vector.x >> vector.y >> vector.z;
    return is;
}