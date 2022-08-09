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
void bubble_sort(std::vector<T> &arr) {
  int len = arr.size();
  bool swapped = true;
  while (swapped) {
    swapped = false;
    for (int i = 1; i < len; ++i) {
      if (arr[i] < arr[i - 1]) {
        swapped = true;
        std::swap(arr[i - 1], arr[i]);
      }
    }
  }
}

template <typename T>
void bubble_sort_opt(std::vector<T> &arr) {
  int len = arr.size();
  bool swapped = true;
  while (swapped) {
    swapped = false;
    for (int i = 1; i < len; ++i) {
      if (arr[i] < arr[i - 1]) {
        swapped = true;
        std::swap(arr[i - 1], arr[i]);
      }
    }
    --len;
  }
}

int main() {
  std::vector<int> arr = {4, 7, 1, -9, 7, 3, 5};

  // std::vector<int> arr2(arr);
  // std::nth_element(arr2.begin(), arr2.begin() + 4, arr2.end());
  // copy(arr2.begin(), arr2.end(), std::ostream_iterator<int>(std::cout, " "));

  bubble_sort(arr);
  copy(arr.begin(), arr.end(), std::ostream_iterator<int>(std::cout, " "));
  std::cout << std::endl;

  std::vector<Node> node_arr;

  srand((unsigned int)time(NULL));
  for (int i = 0; i < 5; ++i) {
    int x = rand() % 100;
    int y = rand() % 100;
    node_arr.emplace_back(Node{x, y});
  }
  bubble_sort(node_arr);
  for (auto node : node_arr) {
    std::cout << "(" << node.x << ", " << node.y << ")" << std::endl;
  }

  return 0;
}