#include <iostream>

const int ROWS = 4;
const int COLS = 4;

// 1
bool linearfind(int arr[ROWS][COLS], int toFind) {
    for (int i = 0; i < ROWS; ++i) {
        for (int j = 0; j < COLS; ++j) {
            if (arr[i][j] == toFind) {
                return true;
            }
        }
    }

    return false;
}

// 2
bool binarySearch(int arr[], int size, int toFind) {
    int left = 0;
    int right = size - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] == toFind) {
            return true; 
        }
        else if (arr[mid] < toFind) {
            left = mid + 1;
        }
        else {
            right = mid - 1;
        }
    }

    return false; 
}

// 3
enum class SortingDirection {
    ascending,
    descending
};


bool isSorted(const int* arr, int size, SortingDirection direction) {
    if (size <= 1) {
        return true; 
    }

    if (direction == SortingDirection::ascending) {
        for (int i = 1; i < size; ++i) {
            if (arr[i - 1] > arr[i]) {
                return false; 
            }
        }
    }
    else if (direction == SortingDirection::descending) {
        for (int i = 1; i < size; ++i) {
            if (arr[i - 1] < arr[i]) {
                return false; 
            }
        }
    }
    else {
        return false;
    }

    return true; 
}

bool find(int arr_2d[ROWS][COLS], int toFind) {
    for (int i = 0; i < ROWS; ++i) {
        
        if (binarySearch(arr_2d[i], COLS, toFind)) {
            return true;
        }
    }

    return false; 
}

// 4.1

void traverseArrayClockwise(int arr[ROWS][COLS]) {
    for (int col = COLS - 1; col >= 0; --col) {
        for (int row = 0; row < ROWS; ++row) {
            std::cout << "col" << col + 1 << " row" << row + 1 << " -> ";
        }
    }
}

// 4.2
void traverseArrayClockwiseFromBottomLeft(int arr[ROWS][COLS]) {
    for (int i = ROWS - 1; i >= 0; --i) {
        if (i % 2 == 0) {
            for (int j = COLS - 1; j >= 0; --j) {
                std::cout << "row" << i + 1 << " col" << j + 1 << " -> ";
            }
        }
        else {
            for (int j = 0; j < COLS; ++j) {
                std::cout << "row" << i + 1 << " col" << j + 1 << " -> ";
            }
        }
    }

    std::cout << std::endl;
}

int main() {
    // 1

    int myArray[ROWS][COLS] = { {1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}, {13, 14, 15, 16} };

    int toFind;
    std::cout << "Enter element to found: " << std::endl;
    std::cin >> toFind;

    if (linearfind(myArray, toFind)) {
        std::cout << "Element was founded" << std::endl;
    }
    else {
        std::cout << "Not founded" << std::endl;
    }
    
    std::cout << std::endl;

    // 2
    // не розібрався в умові, там ж те саме що і в першому коді, можливо малось на увазі бінарний пошук

    if (find(myArray, toFind)) {
        std::cout << "Element was founded " << std::endl;
    }
    else {
        std::cout << "Not founded: " << std::endl;
    }
    
    std::cout << std::endl;

    // 3
    const int size = 5;
    int ascendingArray[size] = { 1, 2, 3, 4, 5 };
    int descendingArray[size] = { 5, 4, 3, 2, 1 };
    int unsortedArray[size] = { 3, 1, 5, 2, 4 };

    if (isSorted(ascendingArray, size, SortingDirection::ascending)) {
        std::cout << "Array ascending\n";
    }
    else {
        std::cout << "Array not ascending\n";
    }

    if (isSorted(descendingArray, size, SortingDirection::descending)) {
        std::cout << "Array descending\n";
    }
    else {
        std::cout << "Array not descending\n";
    }

    if (isSorted(unsortedArray, size, SortingDirection::ascending)) {
        std::cout << "Array ascending\n";
    }
    else {
        std::cout << "Array not ascending\n";
    }

    std::cout << std::endl;

    // 4

    traverseArrayClockwise(myArray);
    std::cout << std::endl;
    traverseArrayClockwiseFromBottomLeft(myArray);
    std::cout << std::endl;
}