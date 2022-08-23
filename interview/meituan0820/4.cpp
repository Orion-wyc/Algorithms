#include <bits/stdc++.h>
using namespace std;

// int getSum(const vector<int> &arr) {
//   int sum = 0;
//   for (int n : arr) {
//     sum += abs(n);
//   }
//   return sum;
// }

int solve(const vector<int> &arr1, const vector<int> &arr2) {
  int n = arr1.size();
  int m = arr2.size();
  vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
  for (int i = 1; i <= n; ++i) dp[i][0] = abs(arr1[i - 1]) + dp[i - 1][0];
  for (int j = 1; j <= m; ++j) dp[0][j] = abs(arr2[j - 1]) + dp[0][j - 1];

  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      if (arr1[i - 1] == arr2[j - 1]) {
        dp[i][j] = dp[i - 1][j - 1];
      } else {
        dp[i][j] = min(dp[i - 1][j] + abs(arr1[i - 1]),
                       min(dp[i][j - 1] + abs(arr2[j - 1]),
                           dp[i - 1][j - 1] + abs(arr1[i - 1] - arr2[j - 1])));
      }
    }
  }

  // for (int i = 0; i <= n; ++i) {
  //   for (int j = 0; j <= m; ++j) {
  //     cout << dp[i][j] << " ";
  //   }
  //   cout << endl;
  // }
  return dp[n][m];
}

int main() {
  int n, m;
  cin >> n >> m;
  vector<int> arr1(n);
  vector<int> arr2(m);
  for (int i = 0; i < n; ++i) {
    int x;
    cin >> x;
    arr1[i] = x;
  }
  for (int i = 0; i < m; ++i) {
    int x;
    cin >> x;
    arr2[i] = x;
  }
  cout << solve(arr1, arr2) << endl;
  return 0;
}