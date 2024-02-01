#include "DynamicIntArray.h"
#include <iostream>


template<typename Type>
DynamicIntArray<Type>::DynamicIntArray() : arr(nullptr), size(0), capacity(0) {}

template<typename Type>
DynamicIntArray<Type>::DynamicIntArray(std::size_t size) : arr(new Type[size]), size(size), capacity(size) {}

template<typename Type>
DynamicIntArray<Type>::DynamicIntArray(const DynamicIntArray& other) : arr(new Type[other.capacity]), size(other.size), capacity(other.capacity)
{
    for (std::size_t i = 0; i < size; ++i)
    {
        arr[i] = other.arr[i];
    }
}

template<typename Type>
DynamicIntArray<Type>::~DynamicIntArray()
{
    delete[] arr;
}

template<typename Type>
DynamicIntArray<Type>& DynamicIntArray<Type>::operator=(const DynamicIntArray& other)
{
    if (this != &other)
    {
        Type* tempArr = new Type[other.capacity];
        std::copy(other.arr, other.arr + other.size, tempArr);

        delete[] arr;

        arr = tempArr;
        size = other.size;
        capacity = other.capacity;
    }

    return *this;
}

template<typename Type>
Type& DynamicIntArray<Type>::operator[](std::size_t index)
{
    if (index >= size)
    {
        std::cerr << "Index out of bounds!" << std::endl;
        exit(EXIT_FAILURE);
    }

    return arr[index];
}

template<typename Type>
void DynamicIntArray<Type>::setSize(std::size_t newSize)
{
    if (newSize > capacity)
    {
        resize(newSize);
    }

    size = newSize;
}

template<typename Type>
std::size_t DynamicIntArray<Type>::getSize() const
{
    return size;
}

template<typename Type>
void DynamicIntArray<Type>::clear()
{
    delete[] arr;
    arr = nullptr;
    size = 0;
    capacity = 0;
}

template<typename Type>
void DynamicIntArray<Type>::push_back(Type element)
{
    if (size == capacity)
    {
        resize(2 * capacity);
    }

    arr[size++] = element;
}

template<typename Type>
void DynamicIntArray<Type>::resize(std::size_t newCapacity)
{
    Type* newArr = new Type[newCapacity];
    std::copy(arr, arr + size, newArr);
    delete[] arr;
    arr = newArr;
    capacity = newCapacity;
}



template<typename Type>
void DynamicIntArray<Type>::reserve(std::size_t reservedSpace)
{
    if (reservedSpace > capacity)
    {
        resize(reservedSpace);
    }
}

template<typename Type>
std::size_t DynamicIntArray<Type>::getCapacity() const
{
    return capacity;
}

template<typename Type>
void DynamicIntArray<Type>::shrinkToFit()
{
    if (size < capacity)
    {
        resize(size);
    }
}

template<typename Type>
void DynamicIntArray<Type>::pop_back()
{
    if (size > 0)
    {
        --size;
    }
}

template<typename Type>
Type DynamicIntArray<Type>::back() const
{
    if (size > 0)
    {
        return arr[size - 1];
    }
    else
    {
        return Type();
    }
}


int main()
{


    DynamicIntArray<int> myArray;
    myArray.push_back(10);
    myArray.push_back(20);
    myArray.push_back(30);

    for (std::size_t i = 0; i < myArray.getSize(); ++i)
    {
        std::cout << myArray[i] << " ";
    }

    std::cout << std::endl;

    return 0;
}
