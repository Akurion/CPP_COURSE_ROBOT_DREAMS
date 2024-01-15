#pragma once

#include <iostream>

class Vector2d {
private:
    float x = 0.0f;
    float y = 0.0f;
    static int instanceCount;

public:
    Vector2d(); // default constructor
    Vector2d(float x_val, float y_val); // constructor
    Vector2d& operator=(const Vector2d& other); // assigment operator
    Vector2d operator+(const Vector2d& secondVector) const; // addition operator
    Vector2d operator-(const Vector2d& secondVector) const; // subtraction operator
    friend Vector2d operator+(const Vector2d& leftVector, const Vector2d& rightVector); // friend for addition
    friend Vector2d operator-(const Vector2d& leftVector, const Vector2d& rightVector); // friend for subtraction
    float operator()() const; // operator to compute the magnitude of the vector
    float& operator[](int i); // operator for accessing components by index 
    friend std::ostream& operator<<(std::ostream& os, const Vector2d& vector); // friend for printing
    friend std::istream& operator>>(std::istream& is, Vector2d& vector); // friend for inputting
    static int getInstanceCount(); // static method to count active instances 
    ~Vector2d(); // destructor
};
