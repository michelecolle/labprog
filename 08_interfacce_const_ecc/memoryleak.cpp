#include <iostream>

int main() {
    std::cout << "Test memory leak" << std::endl;
    int* leak = new int[1000000]; // Allocating memory without deallocation
    std::cout << "Allocated memory for 1,000,000 integers." << std::endl;
    // Intentionally not deleting the allocated memory to simulate a memory leak 
    
    delete[] leak; // Uncomment this line to prevent memory leak
    leak = nullptr; // Avoid dangling pointer

    //ora mostro come la shallow copuy possa creare problemi
    int* array1 = new int[10];
    //int* array3 = new int[30];
    int* array3 = array1; // Shallow copy qua memory leak!!!!!
    delete[] array1; // Deleting array1 leaves array3 dangling
    array1 = nullptr;
    std::cout << "array1 deleted, array3 is now a dangling pointer." << std::endl;
    //delete[] array3; // questo causa un crash (segmentation fault)
    array3 = nullptr;
    std::cout << "array1 deleted, array3 is now a dangling pointer." << std::endl;
    //in pratica ho un memory leak impossiblile da eliminare.
    return 0;
}
//memory leak check:
/*
nella cartella del main con il suo cmakelists.txt
eseguire:

cmake -S . -B build-asan -DCMAKE_BUILD_TYPE=Debug -DCMAKE_CXX_FLAGS="-fsanitize=address -fno-omit-frame-pointer"
cmake --build build-asan

poi eseguire il programma con:
asanrun build-asan/memoryleak
NB: asanrun é un alias in ~/.bashrc
alias asanrun='ASAN_OPTIONS=detect_leaks=1:leak_check_at_exit=1'

*/