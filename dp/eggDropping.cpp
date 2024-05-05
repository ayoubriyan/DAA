#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int eggDrop(int n, int k) {
    // Create a 2D table to store results of subproblems
    vector<vector<int>> dp(n + 1, vector<int>(k + 1));

    // Base case: If there is only one egg, we need to try all floors
    for (int i = 1; i <= k; ++i)
        dp[1][i] = i;

    // Consider all cases with 2 or more eggs and j floors
    for (int i = 2; i <= n; ++i) {
        for (int j = 1; j <= k; ++j) {
            dp[i][j] = INT_MAX;
            for (int x = 1; x <= j; ++x) {
                // If egg breaks at floor x, we need to check floors below x
                // If egg doesn't break at floor x, we need to check floors above x
                // Take maximum of both cases and add 1 for current attempt
                int res = 1 + max(dp[i - 1][x - 1], dp[i][j - x]);
                dp[i][j] = min(dp[i][j], res);
            }
        }
    }

    return dp[n][k];
}

int main() {
    int eggs = 1;
    int floors = 10;
    cout << "Minimum number of attempts needed: " << eggDrop(eggs, floors) << endl;
    return 0;
}
