#include <algorithm>
#include <iostream>
#include <vector>

template <typename T>
void shell_sort(std::vector<T> &arr, int low, int high) {
  int len = high - low + 1;
  for (int step_size = len >> 1; step_size > 0; step_size >>= 1) {
    for (int i = step_size; i < len; ++i) {
      for (int j = i; j >= step_size && arr[j] < arr[j - step_size];
           j -= step_size) {
        std::swap(arr[j], arr[j - step_size]);
      }
    }
  }
}

int main() {
  std::vector<int> arr = {9, -1, 2, 5, 2, 8, 111, 7, 9, 123, -1000};
  for (auto n : arr) {
    std::cout << n << " ";
  }
  std::cout << std::endl;
  shell_sort(arr, 0, arr.size() - 1);
  for (auto n : arr) {
    std::cout << n << " ";
  }
  std::cout << std::endl;

  return 0;
}