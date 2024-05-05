#include<iostream>
using namespace std;
int ack(int x,int y);
int main()
{
int result=ack(2,0);
cout<<result;
return 0;
}


int ack(int m, int n) {
    if (m == 0) {
        return n + 1;
    } else if (m > 0 && n == 0) {
        return ack(m - 1, 1);
    } else if (m > 0 && n > 0) {
        return ack(m - 1, ack(m, n - 1));
    }
    return 0; // Handle invalid input
}