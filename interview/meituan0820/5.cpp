#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, m;
  cin >> n >> m;
  vector<int> b_arr(n);
  vector<int> a_arr(m);

  for (int i = 0; i < n; ++i) {
    int x;
    cin >> x;
    b_arr[i] = x;
  }
  for (int i = 0; i < m; ++i) {
    int x;
    cin >> x;
    a_arr[i] = x;
  }

  sort(b_arr.begin(), b_arr.end());
  int total = 0;
  for (int i = 0; i < m; ++i) {
    auto it = lower_bound(b_arr.begin(), b_arr.end(), a_arr[i]);
    if (it == b_arr.end()) {
      cout << -1 << endl;
      break;  //好蠢，少了break
    } else {
      total += *it;
    }
  }

  cout << total << endl;

  return 0;
}