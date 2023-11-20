#include <iostream>
#include <iomanip>

int main()
{
    // 1
    int rawseconds = 0;
    int hour, seconds, minutes;

    std::cout << "Enter how much seconds did you spend: " << std::endl;
    std::cin >> rawseconds;

    minutes = (rawseconds % 3600) / 60;
    seconds = rawseconds % 60;

    hour = rawseconds / 3600;

    std::cout << "You spend: " << hour << " hours " << minutes << " minutes " << seconds << " seconds.";

    std::cout << std::endl;

    // 2
    double a, b, c, sum, prod, average;
  
    bool less, bigger;
    std::cout << std::endl << "Enter number A: " << std::endl;
    std::cin >> a;
    std::cout << "Enter number B: " << std::endl;
    std::cin >> b;
    std::cout << "Enter number C: " << std::endl;
    std::cin >> c;

    sum = a + b + c;
    prod = a * b * c;
    average = (a + b + c) / 3;
    less = a < b;
    
    bigger = b > c;

    std::cout << "Sum: " << sum << " Prod: " << prod << " Arithmetic Mean: " << average << std::endl;
    std::cout << "a < b? " << std::boolalpha << less << std::endl << "b > c? " << std::boolalpha << bigger << std::endl;

    std::cout << std::endl;

    // 3
    bool lessThan, equal, moreThan, lessOrEqual;
    double d, e;

    std::cout << "Enter number D: " << std::endl;
    std::cin >> d;
    std::cout << "Enter number E: " << std::endl;
    std::cin >> e;

    lessThan = d < e;
    equal = d == e;
    moreThan = d > e;
    lessOrEqual = d <= e;
    std::cout << "d < e? " << std::boolalpha << lessThan << std::endl << "d == e? " << std::boolalpha << equal << std::endl << "d > e? " << std::boolalpha << moreThan << std::endl << "d <= e? " << std::boolalpha << lessOrEqual << std::endl;

    std::cout << std::endl;

    // 4
    double width, height, square, perimetr;

    std::cout << "Enter rectangle's width: " << std::endl;
    std::cin >> width;
    std::cout << "Enter rectangle's height: " << std::endl;
    std::cin >> height;

    square = width * height;
    perimetr = (2 * width) + (2 * height);

    std::cout << "Rectangle's Square: " << square << std::endl;
    std::cout << "Recntagle's Perimetr: " << perimetr << std::endl;

    std::cout << std::endl;

    // 5
    double radius, square2, circumference;
    const double pi = 3.14;

    std::cout << "Enter radius: " << std::endl;
    std::cin >> radius;

    circumference = 2 * pi * radius;
    square2 = pi * (radius * radius);

    std::cout << "Circumference: " << circumference << std::endl;
    std::cout << "Square: " << square2 << std::endl;


}
