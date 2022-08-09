#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <iterator>
#include <vector>

struct Node {
  int x;
  int y;
  bool operator<(const Node &node) const {
    if (x == node.x) return y < node.y;
    return x < node.x;
  }
};

template <typename T>
void insertion_sort(std::vector<T> &arr) {
  int len = arr.size();
  for (int i = 1; i < len; ++i) {
    T key = arr[i];
    int idx = i - 1;
    while (idx >= 0 && key < arr[idx]) {
      arr[idx + 1] = arr[idx];
      --idx;
    }
    arr[idx + 1] = key;  //可知arr[idx] <= key, 插入位置为idx + 1
  }
}

int main() {
  std::vector<int> arr = {4, 7, 1, -9, 7, 3, 5};

  insertion_sort(arr);
  copy(arr.begin(), arr.end(), std::ostream_iterator<int>(std::cout, " "));
  std::cout << std::endl;

  std::vector<Node> node_arr;

  // srand((unsigned int)time(NULL));
  srand(123);
  for (int i = 0; i < 5; ++i) {
    int x = rand() % 100;
    int y = rand() % 100;
    node_arr.emplace_back(Node{x, y});
  }
  insertion_sort(node_arr);
  for (auto node : node_arr) {
    std::cout << "(" << node.x << ", " << node.y << ")" << std::endl;
  }

  return 0;
}