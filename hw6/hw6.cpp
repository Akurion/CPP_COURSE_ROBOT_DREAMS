#include <iostream>

using namespace std;

int main()
{
    // 1
    int a1, d, f, result;

    cout << "Enter a: " << endl;
    cin >> a1;
    cout << "Enter d: " << endl;
    cin >> d;
    cout << "Enter f: " << endl;
    cin >> f;
    cout << endl;

    for (int i = 0; i < f; i++) {
        result = a1 + i * d;
        cout << result << std::endl;
    }

    cout << endl;

    // 2
    int n;
    cout << "Enter n: " << endl;
    cin >> n;
    if (n < 0)
    {
        cout << "number must be higher or equal 0" << endl;
    }
    else 
    {
        int a = 0, b = 1, next;
        for (int i = 2; i <= n; i++)
        {
            next = a + b;

            a = b;
            b = next;
        }
        cout << "Fibonacci number: " << n << " is: " << b << endl;
    }

    cout << endl;

    // 3
    int number;
    int factorial = 1;
    cout << "Enter your number: " << endl;
    cin >> number;
    if (number < 0)
    {
        cout << "Number must be higher than 0" << endl;
    }
    else
    {
        for (int i = 1; i <= number; ++i)
        {
            factorial *= i;
        }
        cout << factorial << endl;
    }

    cout << endl;

    // 4
    int size;
    cout << "Enter size: " << endl;
    cin >> size;

    cout << "A: " << endl;
    for (int i = size; i > 0; i--) {
        for (int j = 0; j < i; j++) {
            std::cout << "*";
        }
        std::cout << std::endl;
    }
    
    cout << endl;
    cout << "B: " << endl;
    for (int i = 1; i <= size; i++) {
        for (int j = 0; j < i; j++) {
            std::cout << "*";
        }
        std::cout << std::endl;
    }

    cout << endl;
    cout << "C: " << endl;
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            std::cout << "*";
        }
        std::cout << std::endl;
    }


    cout << endl;
    cout << "D: " << endl;
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < i; j++) {
            std::cout << " ";
        }
        for (int j = 0; j < size; j++) {
            std::cout << "*";
        }
        std::cout << std::endl;
    }

    cout << endl;
    cout << "E: " << endl;
    for (int i = 0; i < size; i++) {
        for (int j = 0; j <= i; j++) {
            std::cout << (j % 2);
        }
        std::cout << std::endl;
    }

    cout << endl;

    // 5
    char symbol;
    int sum = 0;

    
    while (true)
    {
        cout << endl;
        cout << "Enter char: " << endl;
        cin >> symbol;

        if (symbol == '.')
        {
            cout << "Program stop" << endl;
            break;
        }

        if (islower(symbol))
        {
            char uppersymbol = toupper(symbol);
            {
                cout << "Upper symbol: " << uppersymbol << endl;
            }
        }
        else if (isdigit(symbol))
        {
            int value = symbol - '0';
            sum += value;
            cout << "Sum: " << sum << endl;
        }
        else
        {
            cout << "that symbol doesn't work." << endl;
        }
    }

}
