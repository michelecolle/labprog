#include <iostream>

int main() {
    std::cout << "Test memory leak" << std::endl;
    int* leak = new int[1000000]; // Allocating memory without deallocation
    std::cout << "Allocated memory for 1,000,000 integers." << std::endl;
    // Intentionally not deleting the allocated memory to simulate a memory leak 
    return 0;
}