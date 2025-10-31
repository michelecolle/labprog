#include <iostream>
#include <vector>


class testconst
{
public:
    void SetDataMember(int value);   
    void SetDataMemberNOTPOSSIBLE(int value) const;   
private:
    int dataMember = 0;
};
void testconst::SetDataMember(int value)
{
    dataMember = value;
}
void testconst::SetDataMemberNOTPOSSIBLE(int value) const
{
    dataMember = value; // This line would cause a compilation error
}
int main()
{
    
    std::cout << "=== Lab 03 ===\n";
    // Your lab03 code goes here
    testconst tester;
    std::vector<int> seq = tester.generateSequence(1, 10);
    seq = std::vector<int>(seq.rbegin(), seq.rend()); // Reverse the sequence

    return 0;
}