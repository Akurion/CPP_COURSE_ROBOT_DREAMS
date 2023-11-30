#include <iostream>
#include "countnumbers.h"
#include "factorialwithoutrecurs.h"
#include "factorialwithrecurs.h"
#include "naturalnumberswithloop.h"
#include "naturalnumberswithrecur.h"

using namespace std;


int main()
{
    // 1
    int number;

    cout << "Enter the number of values: ";
    cin >> number;

    countnumbers(number);

    cout << endl;

    // 2
    int count, result;

    cout << "Enter number: ";
    cin >> count;

    factorialwithoutrecurs(count);
    factorialwithrecurs(count, result);
    cout << "Factorial with recursion: " << result << endl;

    cout << endl;

   // 3
    int n;
    cout << "Enter count of natural numbers: ";
    cin >> n;
    naturalnumberswithloop(n);
    cout << endl;
    naturalnumberswithrecurdesc(n);
    cout << endl;
    naturalnumberswithrecurasc(n);
    cout << endl;
}


