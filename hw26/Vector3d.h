#pragma once

#include <iostream>

class Vector3d {
private:
    float x = 0.0f;
    float y = 0.0f;
    float z = 0.0f;

public:
    Vector3d();  // default constructor
    Vector3d(float x_val, float y_val, float z_val);  // constructor
    float dotProduct(const Vector3d& other) const;  // dot product
    Vector3d negate() const;  // negation
    enum class VectorRelativeState { Identical, coDirected, OppositeDirected, AcuteAngle, ObtuseAngle, RightAngle };
    VectorRelativeState getRelativeState(const Vector3d& other) const;  // relative state
    void scale(float factorX, float factorY, float factorZ);  // scaling
    Vector3d crossProduct(const Vector3d& other) const;  // cross product

    Vector3d operator+(const Vector3d& other) const;
    Vector3d operator-(const Vector3d& other) const;
    Vector3d& operator=(const Vector3d& other);
    float operator()() const;
    float& operator[](int i);
    friend std::ostream& operator<<(std::ostream& os, const Vector3d& vector);
    friend std::istream& operator>>(std::istream& is, Vector3d& vector);
};