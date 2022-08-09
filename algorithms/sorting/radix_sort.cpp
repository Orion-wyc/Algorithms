/* 基数排序
 * 假设所有数都是非负的整数, 关键字的排序使用计数排序 countint_sort
 */

#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>

void counting_sort(std::vector<unsigned int> &arr, unsigned int mod) {
  int len = arr.size();
  std::vector<unsigned int> cnt(10, 0);
  std::vector<unsigned int> tmp_arr(len, 0);
  // 计数
  for (auto n : arr) {
    ++cnt[(n / mod) % 10];
  }
  // 求cnt前缀和
  for (int i = 1; i < cnt.size(); ++i) {
    cnt[i] += cnt[i - 1];
  }
  // 自右向左排序
  for (int i = len - 1; i >= 0; --i) {
    int key = (arr[i] / mod) % 10;
    tmp_arr[cnt[key] - 1] = arr[i];
    --cnt[key];
  }
  arr = tmp_arr;
}

void radix_sort(std::vector<unsigned int> &arr) {
  unsigned int max_num = *std::max_element(arr.begin(), arr.end());
  // 取出最大的数用于判断关键字数量，按关键字(0-9)排序，其余较短数字缺位补0
  // 此处关键字比较顺序是从个位开始，向高位比较
  for (unsigned int mod = 1; max_num / mod > 0; mod *= 10) {
    counting_sort(arr, mod);
  }
}

int main() {
  std::vector<unsigned int> arr = {53,  3,  542, 748, 14, 214,
                                   154, 14, 63,  616, 589};
  radix_sort(arr);
  std::copy(arr.begin(), arr.end(),
            std::ostream_iterator<unsigned int>(std::cout, " "));
  return 0;
}