#include <iostream>
// 1
void bublesort(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = i + 1; j < size; j++)
        {
            if (arr[j] < arr[i])
            {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}
void printarray(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        std::cout << arr[i] << std::endl;
    }
    std::cout << std::endl;
}

// 2
const int ROWS = 5;
const int COLUMNS = 5;

enum class SortingDirection { ByRows, ByColumns };

void customSort(int arr[], int low, int high) {
    if (low < high) {
        int pivot = arr[high];
        int i = low - 1;

        for (int j = low; j <= high - 1; j++) {
            if (arr[j] < pivot) {
                i++;
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }

        int temp = arr[i + 1];
        arr[i + 1] = arr[high];
        arr[high] = temp;

        int partitionIndex = i + 1;

        customSort(arr, low, partitionIndex - 1);
        customSort(arr, partitionIndex + 1, high);
    }
}

void customSortByRows(int arr[ROWS][COLUMNS]) {
    for (int i = 0; i < ROWS; i++) {
        customSort(arr[i], 0, COLUMNS - 1);
    }
}

void customSortByColumns(int arr[ROWS][COLUMNS]) {
    for (int j = 0; j < COLUMNS; j++) {
        int column[ROWS];
        for (int i = 0; i < ROWS; i++) {
            column[i] = arr[i][j];
        }

        customSort(column, 0, ROWS - 1);

        for (int i = 0; i < ROWS; i++) {
            arr[i][j] = column[i];
        }
    }
}

void customSort(int arr[ROWS][COLUMNS], SortingDirection direction) {
    if (direction == SortingDirection::ByRows) {
        customSortByRows(arr);
    }
    else if (direction == SortingDirection::ByColumns) {
        customSortByColumns(arr);
    }
}

void printArray(int arr[ROWS][COLUMNS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLUMNS; j++) {
            std::cout << arr[i][j] << " ";
        }
        std::cout << std::endl;
    }
}


int main()
{
    // 1
    const int SIZE = 10;
    int array[SIZE] = { 10,3,4,5,1,312,451,234,54,10 };

    printarray(array, SIZE);
    bublesort(array, SIZE);
    printarray(array, SIZE);
    std::cout << std::endl;

    // 2
    int arr[ROWS][COLUMNS] = {
    {17, 42, 56, 31, 89},
    {45, 23, 74, 10, 98},
    {65, 38, 12, 77, 51},
    {29, 83, 64, 19, 95},
    {14, 70, 37, 50, 26}
    };

    std::cout << "Original Array:" << std::endl;
    printArray(arr);

    SortingDirection directionByRows = SortingDirection::ByRows;
    customSort(arr, directionByRows);

    std::cout << "\nArray After Sorting By Rows:" << std::endl;
    printArray(arr);

    SortingDirection directionByColumns = SortingDirection::ByColumns;
    customSort(arr, directionByColumns);

    std::cout << "\nArray After Sorting By Columns:" << std::endl;
    printArray(arr);

    // 3

    /*
    bool binarySearch(int arr[], int size, int x)
    {
        int l = 0;
        int r = size - 1;

        while (l <= r) {
            const int m = l + (r - l) / 2;

            if (arr[m] == x)
                return true;

            if (arr[m] < x)
                l = m + 1;
            else
                r = m - 1;
        }

        return false;
    } */

    // time complexity - O(log n) - n розмір масиву
    // space complexity - O(1) - використовується лише 1 кількість змінних додаткового простору

    /*
    int main()
    {
        const int ROWS = 20;
        const int COLUMNS = 30;
        int arr[ROWS][COLUMNS] = {};
        const int toFind = 0;

        //...
        //Code to setup array and value to find 
        //in one way or another
        //..

        for (int i = 0; i < ROWS; i++)
        {
            if (binarySearch(arr[i], COLUMNS, toFind))
            {
                std::cout << "FOUND";
                break;
            }
        }
    }*/

    // time complexity - O(rows * log columns)
    // space complexity - O(1)
}

