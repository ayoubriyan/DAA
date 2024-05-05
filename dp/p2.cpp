#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int minDistance(string word1, string word2) {
    int m = word1.length();
    int n = word2.length();

    // Create a 2D vector to store the edit distances
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

    // Initialize the first row and column
    for (int i = 0; i <= m; ++i)
        dp[i][0] = i;
    for (int j = 0; j <= n; ++j)
        dp[0][j] = j;

    // Compute edit distance
    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (word1[i - 1] == word2[j - 1])
                dp[i][j] = dp[i - 1][j - 1];
            else
                dp[i][j] = 1 + min({dp[i - 1][j - 1], dp[i - 1][j], dp[i][j - 1]});
        }
    }

    // Return the edit distance between the two strings
    return dp[m][n];
}

int main() {
    string word1 = "kitten";
    string word2 = "sitting";

    int distance = minDistance(word1, word2);
    cout << "Edit distance between \"" << word1 << "\" and \"" << word2 << "\" is: " << distance << endl;

    return 0;
}
