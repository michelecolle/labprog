#include <iostream>
#include <vector>
using namespace std;
int f(int x)
{
    x = x+1;
    return x;
}
void print(vector<double> v)
{
cout << "{";
for (int i = 0; i < v.size(); ++i) {
cout << v[i];
if (i != v.size() - 1)
cout << ", ";
}
cout << "}\n";
}
void printR(vector<double>& v)
{
cout << "ref{";
for (int i = 0; i < v.size(); ++i) {
cout << v[i];
if (i != v.size() - 1)
cout << ", ";
}
cout << "}\n";
}
int main()
{
    int xx = 0;
    cout << f(xx) << '\n';
    cout << xx << '\n';
    int yy = 7;
    cout << f(yy) << '\n';
    cout << yy << '\n';

    vector<double> vd1 (10);
vector<double> vd2(1000000);
// ... riempimento di vd1, vd2, vd3 ...
//print(vd1);
//print(vd2);
//printR(vd1);
//printR(vd2);
    return 0;
}
