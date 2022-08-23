// #include <bits/stdc++.h>
// using namespace std;

// void ProcessInputs(const string &input, vector<int> &nums) {
//   stringstream ss(input);
//   string s;
//   while (getline(ss, s, ',')) {
//     nums.push_back(stoi(s));
//   }
// }

// int main() {
//   string s;
//   getline(cin, s);
//   vector<int> nums;
//   ProcessInputs(s, nums);
//   sort(nums.begin(), nums.end());
//   cout << "lenth:  " << 1 << endl;
//   for (int n : nums) {
//     cout << "[" << n << "]" << endl;
//   }
//   return 0;
// }

#include <bits/stdc++.h>
using namespace std;

void ProcessInputs(const string &input, vector<int> &nums) {
  stringstream ss(input);
  string s;
  while (getline(ss, s, ',')) {
    nums.push_back(stoi(s));
  }
}

void ProcessOutput(const vector<vector<int>> &ans) {
  cout << "lenth:  " << ans[0].size() << endl;
  for (auto row : ans) {
    cout << "[";

    for (int i = 0; i < row.size() - 1; ++i) {
      cout << row[i] << ", ";
    }
    cout << row.back() << "]" << endl;
  }
}

bool check(vector<vector<int>> &ans) {
  if (ans[0].size() == 1) return true;
  for (auto row : ans) {
    int d = row[1] - row[0];
    for (int i = 1; i < row.size(); ++i) {
      if (d != row[i] - row[i - 1]) return false;
    }
  }
  return true;
}

void ReorderStudents(vector<int> &nums) {
  // 学生总人数
  int len = nums.size();
  // 学生排序
  sort(nums.begin(), nums.end());
  // 最大的等差
  int max_d = nums.back() - nums.front();
  // 计数
  // map<int, int> num_count;
  // for (int i : nums) ++num_count[i];

  vector<vector<int>> ans;

  // 求约数，可能的K - N组合
  for (int k = 1; k <= len; ++k) {
    if (len % k != 0) continue;
    int n = len / k;
    // 枚举到一组（k,n）
    // 方阵
    for (int i = 0; i < k; ++i) {
      vector<int> path;
      for (int j = 0; j < n; ++j) {
        path.push_back(nums[i * n + j]);
      }
      ans.push_back(path);
    }
    if (check(ans)) {
      break;
    } else {
      ans.clear();
    }
  }
  ProcessOutput(ans);
}

int main() {
  // 读入一行字符串
  string s;
  getline(cin, s);

  // 处理为整型数组
  vector<int> nums;
  ProcessInputs(s, nums);

  // 处理方针
  ReorderStudents(nums);

  return 0;
}
