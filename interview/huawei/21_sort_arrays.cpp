#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

vector<int> sort_array(vector<int> &arr1, vector<int> &arr2) {
  vector<int> ans;
  vector<int> unseen_nums;
  unordered_map<int, int> cnt_nums;

  for (auto n : arr2) cnt_nums[n] = 0;

  for (auto n : arr1) {
    if (cnt_nums.count(n) > 0) {
      ++cnt_nums[n];
    } else {
      unseen_nums.push_back(n);
    }
  }

  for (auto n : arr2) {
    int cnt = cnt_nums[n];
    while (cnt--) {
      ans.push_back(n);
    }
  }
  sort(unseen_nums.begin(), unseen_nums.end());
  ans.insert(ans.end(), unseen_nums.begin(), unseen_nums.end());

  cout << ans.data() << endl;
  return ans;
}

int main() {
  vector<int> arr1 = {2, 3, 1, 3, 2, 4, 6, 7, 9, 2, 19};
  vector<int> arr2 = {2, 1, 4, 3, 9, 6};
  // 拷贝省略,函数返回值优化移动语义
  vector<int> ans = sort_array(arr1, arr2);
  cout << ans.data() << endl;

  auto print_arr = [](int i) { cout << i << " "; };
  for_each(ans.begin(), ans.end(), print_arr);

  return 0;
}