#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int minOperationsToN(int n) {
    vector<int> minOps(n + 1, 0);

    for (int i = 2; i <= n; ++i) {
        minOps[i] = INT_MAX;

        if (i % 2 == 0)
            minOps[i] = min(minOps[i], minOps[i / 2] + 1);
        if (i % 3 == 0)
            minOps[i] = min(minOps[i], minOps[i / 3] + 1);

        minOps[i] = min(minOps[i], minOps[i - 1] + 1);
    }

    return minOps[n];
}

int main() {
    int n = 10;
    cout << "Minimum number of operations to reach " << n << ": " << minOperationsToN(n) << endl;
    return 0;
}
