#include <algorithm>
#include <iostream>
#include <vector>

int res = 0;

template <typename T>
void merge(std::vector<T> &arr, int low, int mid, int high) {
  int len = high - low + 1;
  std::vector<T> tmp_arr(len); // 这里可以改进以减少开销
  int tmp_idx = 0;
  int left_idx = low;
  int right_idx = mid + 1;
  while (tmp_idx < len) {
    if (left_idx > mid ||
        (right_idx <= high && arr[left_idx] > arr[right_idx])) {
      tmp_arr[tmp_idx++] = arr[right_idx++];
      // 这里可以计算逆序对 
      // res += mid - left_idx + 1;
    } else {
      tmp_arr[tmp_idx++] = arr[left_idx++];
    }
  }
  // std::cout << tmp_arr.size() << " " << tmp_arr.capacity() << std::endl;
  for (int i = 0; i < len; ++i) arr[low + i] = tmp_arr[i];
}

template <typename T>
void merge_sort(std::vector<T> &arr, int low, int high) {
  /* 归并排序递归版本 */
  if (low < high) {
    int mid = low + (high - low) / 2;
    merge_sort(arr, low, mid);
    merge_sort(arr, mid + 1, high);
    merge(arr, low, mid, high);
  }
}

template <typename T>
void merge_sort2(std::vector<T> &arr, int low, int high) {
  /* 归并排序迭代版本 */
  int len = high - low + 1;
  std::vector<T> tmp_arr;
  tmp_arr.reserve(len);
  for (int seg = 1; seg < len; seg += seg) {
    for (int idx = 0; idx < len; idx += seg * 2) {
      int left = idx;
      int mid = std::min(idx + seg, len);
      int right = std::min(idx + seg * 2, len);
      int tmp_idx = left;
      int idx1 = left;
      int idx2 = mid;
      // 归并
      while (idx1 < mid && idx2 < right) {
        tmp_arr[tmp_idx++] =
            (arr[idx1] < arr[idx2]) ? arr[idx1++] : arr[idx2++];
      }
      while (idx1 < mid) tmp_arr[tmp_idx++] = arr[idx1++];
      while (idx2 < high) tmp_arr[tmp_idx++] = arr[idx2++];
    }
    std::swap(arr, tmp_arr);
  }
}

int main() {
  std::vector<int> arr = {9, -1, 2, 5, 2, 8, 111, 7, 9, 123, -1000};
  for (auto n : arr) {
    std::cout << n << " ";
  }
  std::cout << std::endl;
  merge_sort(arr, 0, arr.size() - 1);
  for (auto n : arr) {
    std::cout << n << " ";
  }
  std::cout << std::endl;
  std::cout << res <<std::endl;
  return 0;
}