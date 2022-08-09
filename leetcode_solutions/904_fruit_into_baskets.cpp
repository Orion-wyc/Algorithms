class Solution {
 public:
  int totalFruit(vector<int>& fruits) {
    int len = fruits.size();
    unordered_set<int> cache;
    int res = 0;
    int l = 0;
    int r = 0;
    while (r < len) {
      cache.insert(fruits[r]);  // 添加一种水果
      if (cache.size() <= 2) {  // 水果种类未超出限制则到下一颗树
        ++r;
      } else {
        // 水果种类超过2，从当前类型r开始向左，最近的和（r, r - 1）不同的水果
        int k = r - 1;
        while (fruits[k] == fruits[r - 1]) {
          --k;
        }
        cache.erase(fruits[k]);  // 从采摘篮子中去除这个“第三类”水果
        l = k + 1;
      }
      // cout << l << " " << r << endl;
      res = max(res, r - l);
    }
    return res;
  }
};