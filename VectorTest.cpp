#include <iostream>
#include "Vector.h"

int main()
{
    // Test default constructor
    Vector<int> v1;
    std::cout << "v1 size: " << v1.Size() << std::endl; // Expected output: v1 size: 0

    // Test push back
    v1.PushBack(1);
    v1.PushBack(2);
    v1.PushBack(3);
    std::cout << "v1 size: " << v1.Size() << std::endl; // Expected output: v1 size: 3

    // Test copy constructor
    Vector<int> v2(v1);
    std::cout << "v2 size: " << v2.Size() << std::endl; // Expected output: v2 size: 3

    // Test assignment operator
    Vector<int> v3;
    v3 = v1;
    std::cout << "v3 size: " << v3.Size() << std::endl; // Expected output: v3 size: 3

    // Test index operator
    std::cout << "v1[0]: " << v1[0] << std::endl; // Expected output: v1[0]: 1
    std::cout << "v1[1]: " << v1[1] << std::endl; // Expected output: v1[1]: 2
    std::cout << "v1[2]: " << v1[2] << std::endl; // Expected output: v1[2]: 3

    // Test at method
    std::cout << "v1.At(0): " << v1.At(0) << std::endl; // Expected output: v1.At(0): 1
    std::cout << "v1.At(1): " << v1.At(1) << std::endl; // Expected output: v1.At(1): 2
    std::cout << "v1.At(2): " << v1.At(2) << std::endl; // Expected output: v1.At(2): 3

    // Test out of range exception
    try
    {
        std::cout << "v1[3]: " << v1[3] << std::endl;
    }
    catch (std::out_of_range &e)
    {
        std::cout << "Exception caught: " << e.what() << std::endl; // Expected output: Exception caught: Vector index out of range
    }

    return 0;
}