#include <iostream>
#include "Vector2d.h"
#include "Vector3d.h"

int main()
{
    Vector2d testVec{ 1.2, 5.6 };
    std::cout << "Test Vector: " << testVec << std::endl;

    Vector2d inputVec;
    std::cout << "Enter vector (format: x y): ";
    std::cin >> inputVec;
    std::cout << "You entered: " << inputVec << std::endl;

    std::cout << "Magnitude of testVec: " << testVec() << std::endl;

    Vector2d copyVec = testVec;
    std::cout << "Copied Vector: " << copyVec << std::endl;

    Vector2d sumVec = testVec.operator+(inputVec);
    std::cout << "Sum of Vectors: " << sumVec << std::endl;

    Vector2d diffVec = testVec.operator-(inputVec);
    std::cout << "Difference of Vectors: " << diffVec << std::endl;

    std::cout << "Number of active instances: " << testVec.getInstanceCount() << std::endl;

    Vector3d vec1(1.0f, 2.0f, 3.0f);
    Vector3d vec2(4.0f, 5.0f, 6.0f);


    std::cout << "Vector1: " << vec1 << std::endl;
    std::cout << "Vector2: " << vec2 << std::endl;

    float dotProductResult = vec1.dotProduct(vec2);
    std::cout << "Dot Product: " << dotProductResult << std::endl;

    Vector3d negatedVector = vec1.negate();
    std::cout << "Negated Vector: " << negatedVector << std::endl;

    Vector3d::VectorRelativeState relativeState = vec1.getRelativeState(vec2);
    std::cout << "Relative State: " << static_cast<int>(relativeState) << std::endl;

    vec1.scale(2.0f, 2.0f, 2.0f);
    std::cout << "Scaled Vector1: " << vec1 << std::endl;

    Vector3d crossProductResult = vec1.crossProduct(vec2);
    std::cout << "Cross Product: " << crossProductResult << std::endl;

    return 0;
}
