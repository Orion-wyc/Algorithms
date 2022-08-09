#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <numeric>
#include <functional>
using namespace std;

struct Node {
  int x;
  int y;
  Node(int x, int y) : x(x), y(y) {}
  bool operator<(const Node a) const { return x > a.x; }
};

int main() {
  vector<Node> nodes;
  for (int i = 2; i < 7; ++i) {
    // nodes.push_back(Node(i, 2 * i));
    nodes.emplace_back(i, 2 * i);
  }
  for (Node a : nodes) {
    cout << a.x << " " << a.y << endl;
  }
  sort(nodes.begin(), nodes.end());

  for (Node a : nodes) {
    cout << a.x << " " << a.y << endl;
  }

  auto cmp = [](const std::pair<int, int> &l, const std::pair<int, int> &r) {
    return l.second < r.second;
  };
  std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>,
                      decltype(cmp)>
      pq(cmp);
  cout << boolalpha << binary_search(nodes.begin(), nodes.end(), Node{3, 6})
       << endl;

  vector<int> src = {1, 2, 3, 4, 5}, dst;
  // 求解src中元素的前缀和，dst[i] = src[0] + ... + src[i]
  // back_inserter 函数作用在 dst 容器上，提供一个迭代器
  partial_sum(src.begin(), src.begin() + 5, back_inserter(dst));
  for (unsigned int i = 0; i < dst.size(); i++) cout << dst[i] << " ";

  return 0;
}