#include <iostream>
#include "swapfunc.h"
#include "calculatesum.h"
#include "findelement.h"

int main()
{
    // 1
    int a = 5, b = 10;
    swapbyref(a, b);
    swapbypoint(&a, &b);
    
    std::cout << std::endl;

    // 2
    const int SIZE = 10;
    double sum = 0;
    const double array[SIZE] = { 11.3, 11.5, 12.0, 9.3, 5.4, 4.6, 3.7, 2.5, 1.1 };

    if (calculateSum(array, SIZE, sum))
        std::cout << "Sum: " << sum << std::endl;
    else
        std::cout << "Can't sum your array, size must be higher than 0" << std::endl;

    std::cout << std::endl;

    //3 
    int elem = 10;
    int array1[SIZE] = { 11, 10, 12, 13, 14, 15, 16, 17, 18, 19 };
    if (find(array1, SIZE, elem))
        std::cout << "Element was founded" << std::endl;
    else
        std::cout << "Element wasn't founded" << std::endl;
    

}