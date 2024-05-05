#include <iostream>
#include <vector>

using namespace std;

bool subsetSum(const vector<int>& nums, int sum) {
    int n = nums.size();

    // Create a 2D vector to store the subset sum information
    vector<vector<bool>> dp(n + 1, vector<bool>(sum + 1, false));

    // Base case: if the sum is 0, then an empty subset can achieve it
    for (int i = 0; i <= n; ++i) {
        dp[i][0] = true;
    }

    // Fill the dp table
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= sum; ++j) {
            if (nums[i - 1] <= j) {
                dp[i][j] = dp[i - 1][j] || dp[i - 1][j - nums[i - 1]];
            } else {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }

    // Return the value in the bottom-right corner of the dp table
    return dp[n][sum];
}

int main() {
    int n;
    cout << "Enter the number of elements in the set: ";
    cin >> n;

    vector<int> nums(n);
    cout << "Enter the elements of the set: ";
    for (int i = 0; i < n; ++i) {
        cin >> nums[i];
    }

    int sum;
    cout << "Enter the target sum: ";
    cin >> sum;

    if (subsetSum(nums, sum)) {
        cout << "Yes, there exists a subset with the given sum." << endl;
    } else {
        cout << "No, there does not exist a subset with the given sum." << endl;
    }

    return 0;
}
