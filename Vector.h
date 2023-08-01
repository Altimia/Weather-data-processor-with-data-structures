#ifndef VECTOR_H
#define VECTOR_H

#include <sstream>
#include <string>

template <typename T>
class Vector
{
private:
    T *elements;      // Pointer to the dynamic array
    int capacity;     // Maximum number of elements that can be stored in the vector
    int current_size; // Current number of elements stored in the vector

public:
    // Constructor
    Vector()
    {
        elements = new T[2]; // Allocate memory for 2 elements
        capacity = 2;
        current_size = 0;
    }

    // Copy constructor
    Vector(const Vector &copy)
    {
        elements = new T[copy.capacity]; // Allocate memory for the same number of elements as the copied vector
        capacity = copy.capacity;
        current_size = copy.current_size;
        for (int i = 0; i < current_size; i++)
        {
            elements[i] = copy.elements[i]; // Copy the elements from the copied vector to the new vector
        }
    }

    // Destructor
    ~Vector()
    {
        delete[] elements; // Deallocate the memory used by the dynamic array
    }

    // Add Element
    void PushBack(const T &value)
    {
        if (current_size == capacity)
        {                                  // If the vector is full
            T *temp = new T[2 * capacity]; // Allocate memory for twice the number of elements
            for (int i = 0; i < capacity; i++)
            {
                temp[i] = elements[i]; // Copy the elements from the old array to the new array
            }
            delete[] elements; // Deallocate the memory used by the old array
            capacity *= 2;     // Update the capacity to the new capacity
            elements = temp;   // Update the pointer to the new array
        }
        elements[current_size] = value; // Add the new element to the end of the vector
        current_size++;                 // Increment the current size of the vector
    }

    // Get Index
    T &At(int index)
    {
        if (index >= current_size || index < 0)
        {                                                         // If the index is out of range
            throw std::out_of_range("Vector index out of range"); // Throw an exception
        }
        return elements[index]; // Return the element at the specified index
    }

    // Return Current Size
    int Size() const
    {
        return current_size; // Return the current size of the vector
    }

    // Overload Assignment Operator
    Vector &operator=(const Vector &copy)
    {
        delete[] elements;               // Deallocate the memory used by the old array
        elements = new T[copy.capacity]; // Allocate memory for the same number of elements as the copied vector
        capacity = copy.capacity;
        current_size = copy.current_size;
        for (int i = 0; i < current_size; i++)
        {
            elements[i] = copy.elements[i]; // Copy the elements from the copied vector to the new vector
        }
        return *this; // Return a reference to the current vector
    }

    // Overload Index Operator
    T &operator[](int index)
    {
        if (index >= current_size || index < 0)
        {                                                         // If the index is out of range
            throw std::out_of_range("Vector index out of range"); // Throw an exception
        }
        return elements[index]; // Return the element at the specified index
    }

    const T &operator[](int index) const
    {
        if (index >= current_size || index < 0)
        {                                                         // If the index is out of range
            throw std::out_of_range("Vector index out of range"); // Throw an exception
        }
        return elements[index]; // Return the element at the specified index
    }
};

#endif