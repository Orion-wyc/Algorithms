#include <algorithm>
#include <iostream>
#include <vector>

// 假设只有10个桶
const int NUM_BUCKETS = 10;

template <typename T = int>
void _insertion_sort(std::vector<T> &arr) {
  int len = arr.size();
  if (len <= 1) return;
  for (int i = 1; i < len; ++i) {
    for (int j = i; j >= 1 && arr[j] < arr[j - 1]; --j) {
      std::swap(arr[j], arr[j - 1]);
    }
  }
}

template <typename T = int>
void bucket_sort(std::vector<T> &arr, int low, int high) {
  // 元素分桶
  std::vector<std::vector<T>> buckets(NUM_BUCKETS, std::vector<T>{});
  for (auto n : arr) {
    int idx = n / NUM_BUCKETS;
    buckets.at(idx).push_back(n);
  }

  // 桶内排序, 同时合并结果
  int k = 0;
  for (int i = 0; i < NUM_BUCKETS; ++i) {
    _insertion_sort(buckets.at(i));
    for (auto n : buckets.at(i)) {
      arr[k++] = n;
    }
  }
}

int main() {
  // 默认所有数字在[0,99]范围内
  std::vector<int> arr = {9, 2, 5, 69, 80, 99, 71, 9, 12, 33, 48};
  for (auto n : arr) {
    std::cout << n << " ";
  }
  std::cout << std::endl;
  bucket_sort(arr, 0, arr.size() - 1);
  for (auto n : arr) {
    std::cout << n << " ";
  }
  std::cout << std::endl;

  return 0;
}