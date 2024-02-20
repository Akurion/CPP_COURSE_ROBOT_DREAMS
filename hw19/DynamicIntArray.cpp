#include "DynamicIntArray.h"
#include <iostream>

//default c-tor
DynamicIntArray::DynamicIntArray() : arr(nullptr), size(0), capacity(0) {}

//c-tor with size
DynamicIntArray::DynamicIntArray(std::size_t size) : arr(new int[size]), size(size), capacity(size) {}

//copy c-tor
DynamicIntArray::DynamicIntArray(const DynamicIntArray& other) : arr(new int[other.capacity]), size(other.size), capacity(other.capacity)
{
    for (std::size_t i = 0; i < size; ++i)
    {
        arr[i] = other.arr[i];
    }
}

//free allocated memory
DynamicIntArray::~DynamicIntArray()
{
    delete[] arr;
}

DynamicIntArray& DynamicIntArray::operator=(const DynamicIntArray& other)
{
    if (this != &other)
    {
        // Create a temporary array to avoid memory leaks in case of an exception
        int* tempArr = new int[other.capacity];

        // Copy elements from the other array
        for (std::size_t i = 0; i < other.size; ++i)
        {
            tempArr[i] = other.arr[i];
        }

        // Delete old array
        delete[] arr;

        // Update the pointers and size
        arr = tempArr;
        size = other.size;
        capacity = other.capacity;
    }

    return *this;
}

int& DynamicIntArray::operator[](std::size_t index)
{
    if (index >= size)
    {
        // Handle index out of bounds
        // This could be further improved by throwing an exception
        std::cerr << "Index out of bounds!" << std::endl;
        exit(EXIT_FAILURE);
    }

    return arr[index];
}

void DynamicIntArray::setSize(std::size_t newSize)
{
    if (newSize > capacity)
    {
        // Resize the array if needed
        resize(newSize);
    }

    size = newSize;
}

std::size_t DynamicIntArray::getSize() const
{
    return size;
}

void DynamicIntArray::clear()
{
    delete[] arr;
    arr = nullptr;
    size = 0;
    capacity = 0;
}

void DynamicIntArray::push_back(int element)
{
    // Check if there is enough space, resize if needed
    if (size == capacity)
    {
        resize(2 * capacity); // Double the capacity
    }

    // Add the new element at the end
    arr[size++] = element;
}

void DynamicIntArray::resize(std::size_t newCapacity)
{
    int* newArr = new int[newCapacity];

    // Copy old elements to the new array
    for (std::size_t i = 0; i < size; ++i)
    {
        newArr[i] = arr[i];
    }

    // Delete old array
    delete[] arr;

    // Update the pointers and capacity
    arr = newArr;
    capacity = newCapacity;
}
