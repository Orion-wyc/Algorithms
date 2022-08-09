class Solution {
 public:
  // 下表取
  vector<int> factorial = {1, 1, 2, 6, 24, 120, 720, 5040, 40320, 362880};
  int N = 0;
  string getPermutation(int n, int k) {
    string nums = "";
    for (int i = 1; i <= n; ++i) nums += to_string(i);
    return permute(nums, k);
  }

  string permute(string nums, int k) {
    int n = nums.size();
    if (n == 1) return nums;
    string res = "";
    // 由于是从0开始编号，所以此处需减1
    int idx = (k - 1) / factorial[n - 1];
    cout << idx << nums << endl;
    res += nums.at(idx);
    nums.erase(idx, 1);
    // 问题长度缩小1，更新子问题的k
    res += permute(nums, k - idx * factorial[n - 1]);

    return res;
  }
};