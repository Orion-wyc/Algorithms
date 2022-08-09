#include <iostream>
#include <vector>

template <typename T>
int PartitionArray(std::vector<T> &arr, int low, int high) {
  T key = arr[low];
  while (low < high) {
    while (low < high && arr[high] >= key) --high;
    arr[low] = arr[high];
    while (low < high && arr[low] <= key) ++low;
    arr[high] = arr[low];
  }
  arr[low] = key;

  return low;
}

template <typename T>
void QuickSort(std::vector<T> &arr, int low, int high) {
  if (low < high) {
    int mid = PartitionArray(arr, low, high);
    QuickSort(arr, low, mid - 1);
    QuickSort(arr, mid + 1, high);
  }
}

int main() {
  std::vector<int> arr = {9, -1, 2, 5, 2, 8, 111, 7};
  for (auto n : arr) {
    std::cout << n << " ";
  }
  std::cout << std::endl;
  QuickSort(arr, 0, arr.size() - 1);
  for (auto n : arr) {
    std::cout << n << " ";
  }
  std::cout << std::endl;

  return 0;
}