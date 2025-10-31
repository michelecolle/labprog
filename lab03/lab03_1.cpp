#include <iostream>
#include <vector>


void f()
{
    int n[10];
    int* p = &n[5];
    int ctr = -5;
    while (ctr < 5)
    {
        p[ctr] = 11*(ctr+5);
        ++ctr;  
    }
    for (int i = 0; i < 10; ++i)
        std::cout << "n[" << i << "] = " << n[i] << "\n";
    std::cout << "\n";
}
void f_illegal(int target)
{
    std::cout << "f_illegal for: " << target << "\n";

    int n[10];
    n[target] = 42; // illegal if target < -5 or target > 4
    std::cout << "n[" << target<< "] = " << n[target] << "\n";
}

int main()
{
    f();
    f_illegal(7); 
    f_illegal(2); 
    f_illegal(-1); 
    f_illegal(-1); 
    f_illegal(-1); 
    f_illegal(-1); 
    f_illegal(10); 
    f_illegal(11); 
    f_illegal(12); 
    f_illegal(500000); 
    return 0;
}