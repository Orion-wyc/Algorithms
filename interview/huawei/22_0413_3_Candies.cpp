/* 分糖果，题目大意为：给定n个整数，问是否能分为两组，使得两组的数字总和相同
 * 我目前两个思路，一个是回溯 + 剪枝，但是数据范围是100不知道是不是会超时。
 * 第二个是恰好装满物品的01背包问题，参考力扣剑指offer101.分割等和子集。不同的是要求输出路径。
 */

#include <bits/stdc++.h>
using namespace std;

void PrintPath(const vector<int> &nums, const vector<vector<bool>> &dp) {
  int len = dp.size() - 1;
  int target = dp[0].size() - 1;
  vector<bool> vis(len, false);
  int n = len;
  while (target > 0) {
    for (int i = 1; i <= n; ++i) {
      if (dp[i][target] == true) {
        vis[i - 1] = true;
        target -= nums[i - 1];  // 缩减 target 值
        n = i - 1;              // 继续遍历前 i - 1 个数字
        break;
      }
    }
  }
  vector<int> vec_1;
  vector<int> vec_2;
  for (int i = 0; i < len; ++i) {
    if (vis[i]) {
      vec_1.push_back(nums[i]);
    } else {
      vec_2.push_back(nums[i]);
    }
  }
  for (int i = 0; i < vec_1.size() - 1; ++i) cout << vec_1[i] << " ";
  cout << vec_1.back() << endl;
  for (int i = 0; i < vec_2.size() - 1; ++i) cout << vec_2[i] << " ";
  cout << vec_2.back() << endl;
}

void TryPartition(const vector<int> &nums) {
  int total_sum = 0;
  for (int num : nums) total_sum += num;
  // 奇数必然不可分
  if (total_sum & 1) {
    cout << -1 << endl;
    return;
  }

  int target = total_sum / 2;
  int len = nums.size();
  vector<vector<bool>> dp(len + 1, vector<bool>(target + 1, false));
  // 初始化 base-case，空间为 0 必然为 true
  for (int i = 0; i <= len; ++i) dp[i][0] = true;

  for (int i = 1; i <= len; ++i) {
    for (int j = 1; j <= target; ++j) {
      if (j >= nums[i - 1]) {  // 放得下nums[i-1]，可选择放与不放
        dp[i][j] = dp[i - 1][j] || dp[i - 1][j - nums[i - 1]];
      } else {  // 放不下nums[i-1]
        dp[i][j] = dp[i - 1][j];
      }
    }
  }

  cout << boolalpha << dp[len][target] << endl;
  if (dp[len][target]) {
    PrintPath(nums, dp);
  } else {
    cout << -1 << endl;
  }

  // return dp[len][target];
}

int main() {
  vector<int> nums = {1, 4, 4, 5, 5, 7};
  TryPartition(nums);

  return 0;
}