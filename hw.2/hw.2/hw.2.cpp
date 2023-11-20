#include <iostream>
#include <iomanip>


enum class WeekDay {
    Monday = 1,
    Tuesday,
    Wednesday,
    Thursday,
    Friday,
    Saturday,
    Sunday
};


int main()
{
    setlocale(LC_ALL, "ru");
    // 2.1
    int a, b, temp;
    std::cout << "залупа number A: " << std::endl;
    std::cin >> a;
    std::cout << "Enter number B: " << std::endl;
    std::cin >> b;
    temp = a;
    a = b;
    b = temp;
    std::cout << "Number A: " << a << std::endl << "Number B: " << b << std::endl;
    
    // 2.2

    std::cout << std::endl;

    double myDouble = 123.456;
    std::cout << "Double variable: " << myDouble << std::endl;
    int myInt = static_cast<int>(myDouble);
    std::cout << "Integer variable: " << myInt << std::endl;
    std::cout << std::right << std::setw(20) << std::setfill('$') << myDouble << std::endl;


    // 2.3

    std::cout << std::endl;

    double myDouble2 = 12345.6789;

    std::cout << "Standard format:" << std::endl;
    std::cout << "2 decimal places: " << std::fixed << std::setprecision(2) << myDouble2 << std::endl;
    std::cout << "5 decimal places: " << std::fixed << std::setprecision(5) << myDouble2 << std::endl;
    std::cout << "10 decimal places: " << std::fixed << std::setprecision(10) << myDouble2 << std::endl;

    std::cout << "e-notation:" << std::endl;
    std::cout << "2 decimal places: " << std::scientific << std::setprecision(2) << myDouble2 << std::endl;
    std::cout << "5 decimal places: " << std::scientific << std::setprecision(5) << myDouble2 << std::endl;
    std::cout << "10 decimal places: " << std::scientific << std::setprecision(10) << myDouble2 << std::endl;

    // 2.4

    std::cout << std::endl;

    WeekDay today = WeekDay::Wednesday;

    int numericValue = static_cast<int>(today);
    std::cout << "Today is the " << static_cast<int>(today) << "-th day of the week." << std::endl;

    // 2.5

    std::cout << std::endl;

    int number;

    std::cout << "Enter a number: ";
    std::cin >> number;

    bool boolValue = static_cast<bool>(number);

    std::cout << "Bool value: " << std::boolalpha << boolValue << std::endl;


}
