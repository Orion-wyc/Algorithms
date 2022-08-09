// 求最小滑动窗口的例子

class Solution {
 public:
  const int kINF = numeric_limits<int>::max();
  string minWindow(string s, string t) {
    // s 字符串中字符数量必须不少于 t 中字符数量
    if (s.size() < t.size()) return "";

    unordered_map<char, int> cache;
    for (char c : t) ++cache[c];

    int cnt = t.size();  // t中需要的字符总数
    int l = 0;           // 滑动窗口左边界
    int r = 0;           // 滑动窗口右边界
    int res = kINF;      // 最小窗口长度
    int res_l = 0;       // 最小窗口的左端点
    while (r < s.size()) {
      // 若当前字符出现在 t 中，则更新计数
      if (cache.count(s[r]) > 0) {
        // 当前字符还缺少时才减少所需字符的计数, 确保滑动窗口中的字符能满足 t,
        // 避免出现有多个 t 中其他字符但是并不包含所有种类字符的情况（e.g.,
        // "bba", "ba"）
        if (cache[s[r]] > 0) --cnt;
        --cache[s[r]];  // 否则，只更新map
      }
      // 更新右边界(开区间)
      ++r;
      // cnt == 0时恰好满足，循环退出时代表当前窗口压缩完毕，需要继续更新右边界
      while (cnt == 0) {
        // 更新区间长度和答案的左边界
        if (res > r - l) {
          res = r - l;
          res_l = l;
        }
        // 如果左边界的字符在 t 中，则更新计数，否则
        if (cache.count(s[l]) > 0) {
          if (cache[s[l]] == 0) ++cnt;
          ++cache[s[l]];
        }
        // 直接更新滑动窗口左边界
        ++l;
      }
    }
    if (res == kINF) res = 0;

    return s.substr(res_l, res);
  }
};