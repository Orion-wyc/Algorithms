#include <algorithm>
#include <iostream>
#include <vector>

template <typename T>
void sift_down(std::vector<T> &arr, int low, int high) {
  int parent = low;
  int child = parent * 2 + 1;
  while (child <= high) {
    if (child + 1 <= high && arr[child] > arr[child + 1]) {
      ++child;
    }
    if (arr[parent] <= arr[child]) {
      break;
    } else {
      std::swap(arr[parent], arr[child]);
      parent = child;
      child = parent * 2 + 1;
    }
  }
}

template <typename T>
void heap_sort(std::vector<T> &arr) {
  int len = arr.size();
  // 建堆
  for (int i = len / 2 - 1; i >= 0; --i) sift_down(arr, i, len - 1);
  // 排序, 将堆顶元素与第i个元素 (当前堆的最后一个) 交换位置
  for (int i = len - 1; i > 0; --i) {
    std::swap(arr[0], arr[i]);
    sift_down(arr, 0, i - 1);
  }
}

int main() {
  // a test case
  std::vector<int> arr = {9, -1, 2, 5, 2, 8, 111, 7, 9, 123, -1000};
  for (auto n : arr) {
    std::cout << n << " ";
  }
  std::cout << std::endl;
  heap_sort(arr);
  for (auto n : arr) {
    std::cout << n << " ";
  }
  std::cout << std::endl;

  return 0;
}