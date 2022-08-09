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
void selection_sort(std::vector<T> &arr) {
  int len = arr.size();
  for (int i = 0; i < len; ++i) {
    int idx = i;
    for (int j = i + 1; j < len; ++j) {
      if (arr[j] < arr[idx]) idx = j;
    }
    std::swap(arr[i], arr[idx]);
  }
}

int main() {
  std::vector<int> arr = {4, 7, 1, -9, 7, 3, 5};

  selection_sort(arr);
  copy(arr.begin(), arr.end(), std::ostream_iterator<int>(std::cout, " "));
  std::cout << std::endl;

  std::vector<Node> node_arr;

  srand((unsigned int)time(NULL));
  for (int i = 0; i < 5; ++i) {
    int x = rand() % 100;
    int y = rand() % 100;
    node_arr.emplace_back(Node{x, y});
  }
  selection_sort(node_arr);
  for (auto node : node_arr) {
    std::cout << "(" << node.x << ", " << node.y << ")" << std::endl;
  }

  return 0;
}