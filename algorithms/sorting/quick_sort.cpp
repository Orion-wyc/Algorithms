#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <iterator>
#include <vector>

struct Node {
  int x;
  int y;
  bool operator<=(const Node &node) const {
    if (x == node.x) return y <= node.y;
    return x <= node.x;
  }
  bool operator>=(const Node &node) const { return node <= *this; }
};

template <typename T>
int partition(std::vector<T> &arr, int low, int high) {
  T key = arr[low];
  while (low < high) {
    // 先处理右侧，注意和key比较的等号，可以少交换
    while (low < high && arr[high] >= key) --high;
    arr[low] = arr[high];
    // 处理左侧，同上
    while (low < high && arr[low] <= key) ++low;
    arr[high] = arr[low];
  }
  arr[low] = key;

  return low;
}

template <typename T>
void quick_sort(std::vector<T> &arr, int low, int high) {
  if (low < high) {
    int idx = partition(arr, low, high);
    quick_sort(arr, low, idx - 1);
    quick_sort(arr, idx + 1, high);
  }
}

int main() {
  std::vector<int> arr = {4, 7, 1, -9, 7, 3, 5};
  quick_sort(arr, 0, arr.size() - 1);
  copy(arr.begin(), arr.end(), std::ostream_iterator<int>(std::cout, " "));
  std::cout << std::endl;

  std::vector<Node> node_arr;

  srand((unsigned int)time(NULL));
  for (int i = 0; i < 30; ++i) {
    int x = rand() % 10;
    int y = rand() % 10;
    node_arr.emplace_back(Node{x, y});
  }
  quick_sort(node_arr, 0, node_arr.size() - 1);
  for (auto node : node_arr) {
    std::cout << "(" << node.x << ", " << node.y << ")" << std::endl;
  }

  return 0;
}