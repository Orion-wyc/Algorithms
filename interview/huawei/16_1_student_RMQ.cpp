#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

void update_score(vector<int>& arr, int idx, int val) { arr[idx] = val; }

int get_max(const vector<int>& arr, int l, int r) {
  return *max_element(arr.begin() + l, arr.begin() + r + 1);
}

int main() {
  int N, M;
  cin >> N >> M;
  vector<int> scores;
  for (int i = 0; i < N; ++i) {
    int x;
    cin >> x;
    scores.push_back(x);
  }
  for (int i = 0; i < M; ++i) {
    char op;
    int a;
    int b;
    cin >> op >> a >> b;
    if (op == 'U') {
      update_score(scores, a - 1, b);
    } else if (op == 'Q') {
      cout << get_max(scores, min(a, b) - 1, max(a, b) - 1) << endl;
    }
  }
  return 0;
}
