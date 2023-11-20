#include <iostream>

enum class Month {
    January = 1,

    February,
    March,
    April,
    May,
    June,
    July,
    August,
    September,
    October,
    November,
    December
};

enum class Season {
    Winter,
    Spring,
    Summer,
    Autumn
};

bool isAngleValid(int angle)
{
    return (angle > 0 && angle < 180);
}


int main()
{
    // 1
    int a, b, c;

    std::cout << "Enter number A: " << std::endl;
    std::cin >> a;
    std::cout << "Enter number B: " << std::endl;
    std::cin >> b;
    std::cout << "Enter number C: " << std::endl;
    std::cin >> c;

    int maxnum = a;

    if (b > maxnum)
    {
        maxnum = b;
    }
    if (c > maxnum)
    {
        maxnum = c;
    }
    std::cout << "Max number is: " << maxnum << std::endl;

    // 2

    std::cout << "" << std::endl;

    double number1, number2;

    std::cout << "Enter number1: " << std::endl;
    std::cin >> number1;
    std::cout << "Enter number2: " << std::endl;
    std::cin >> number2;

    double minimum = (number1 < number2) ? number1 : number2;

    std::cout << "Minimum is: " << minimum << std::endl;

    // 3

    std::cout << "" << std::endl;

    int numbertocheck;

    std::cout << "Enter number: " << std::endl;
    std::cin >> numbertocheck;

    if (numbertocheck % 5 == 0 && numbertocheck % 11 == 0)
    {
        std::cout << "Number is divided by 5 and 11" << std::endl;
    }
    else
    {
        std::cout << "Number is not divided by 5 and 11" << std::endl;
    }

    // 4

    std::cout << "" << std::endl;

    int angle1, angle2, angle3, sumangle;

    std::cout << "Enter angle1: " << std::endl;
    std::cin >> angle1;
    std::cout << "Enter angle2: " << std::endl;
    std::cin >> angle2;
    std::cout << "Enter angle3: " << std::endl;
    std::cin >> angle3;

    sumangle = angle1 + angle2 + angle3;


    if (sumangle == 180 && isAngleValid(angle1) && isAngleValid(angle2) && isAngleValid(angle3))
    {
        std::cout << "That angles can make triangle." << std::endl;
    }
    else
    {
        std::cout << "That angles can't make triangle" << std::endl;
    }

    // 5

    std::cout << "" << std::endl;

    int monthnumber;
    std::cout << "Enter month number (1-12): " << std::endl;
    std::cin >> monthnumber;

    if (monthnumber > 12 && monthnumber < 1)
        std::cout << "Number must be 1-12";

    switch (static_cast<Month>(monthnumber))
    {
    case Month::January:
        std::cout << "January" << std::endl;
        break;
    case Month::February:
        std::cout << "February" << std::endl;
        break;
    case Month::March:
        std::cout << "March" << std::endl;
        break;
    case Month::April:
        std::cout << "April" << std::endl;
        break;
    case Month::May:
        std::cout << "May" << std::endl;
        break;
    case Month::June:
        std::cout << "June" << std::endl;
        break;
    case Month::July:
        std::cout << "July" << std::endl;
        break;
    case Month::August:
        std::cout << "August" << std::endl;
        break;
    case Month::September:
        std::cout << "September" << std::endl;
        break;
    case Month::October:
        std::cout << "October" << std::endl;
        break;
    case Month::November:
        std::cout << "November" << std::endl;
        break;
    case Month::December:
        std::cout << "December" << std::endl;
        break;
    default:
        std::cout << "Wrong month number" << std::endl;
        break;
    }

    // 6

    std::cout << "" << std::endl;

    int monthnumber2;
    std::cout << "Enter month number (1-12): " << std::endl;
    std::cin >> monthnumber2;
    switch (monthnumber2)
    {
    case 1:
    case 2:
    case 12:
        std::cout << "Winter" << std::endl;
        break;
    case 3:
    case 4:
    case 5:
        std::cout << "Spring" << std::endl;
        break;
    case 6:
    case 7:
    case 8:
        std::cout << "Summer" << std::endl;
        break;
    case 9:
    case 10:
    case 11:
        std::cout << "Autumn" << std::endl;
        break;
    }
}