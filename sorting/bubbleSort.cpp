#include <iostream>
using namespace std;

int main()
{

    int A[4] = {19,18,20,24};
    int temp;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (A[j] > A[j + 1])
            {
                temp = A[j];
                A[j] = A[j + 1];
                A[j + 1] = temp;
            }
        }
    }

    for (int j = 0; j < 4; j++)
    {
        cout << A[j]<<" ";
    }
}
