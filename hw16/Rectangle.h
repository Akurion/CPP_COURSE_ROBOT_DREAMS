#pragma once

class Rectangle
{
private:
	float lenght;
	float height;

public:
	Rectangle() : lenght(0.0f), height(0.0f) {} // constructor
	Rectangle(float l, float h) : lenght(l), height(h) {}

	float getArea() const {
		return lenght * height;
	}

	float getPerimeter() const {
		return 2 * (lenght * height);
	}
	~Rectangle(); // destructor
};