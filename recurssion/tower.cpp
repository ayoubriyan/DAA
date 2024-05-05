#include <iostream>
using namespace std;
void step(int start, int end);
void hanoi(int n, int a, int c);
int main()
{
    hanoi(4, 1, 3);


    return 0;
}
void hanoi(int n, int a, int c)
{
    if (n == 1)
    {
        step(a, c);
        
    }
    else
    {
        int b = 6 - (a + c);
        hanoi(n - 1, a, b);
        step(a, c);
        hanoi(n - 1, b, c);
    }
}
void step(int start, int end)
{
    cout << start<<"->" << end<<" ";
}