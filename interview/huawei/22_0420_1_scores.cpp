#include <bits/stdc++.h>
using namespace std;

int ans = 0;
int num = 0;
vector<int> arr;

void solve(int sum, int pos, int cnt) {
  if (sum == num) {
    ++ans;
    return;
  }
  if (cnt >= 3) {
    return;
  }
  if (pos == 25) {
    return;
  }
  solve(sum + arr[pos], pos + 1, cnt);
  solve(sum, pos + 1, cnt + 1);
}

int main() {
  for (int i = 0; i < 10; ++i) arr.push_back(2);
  for (int i = 0; i < 10; ++i) arr.push_back(4);
  for (int i = 0; i < 5; ++i) arr.push_back(8);
  cin >> num;
  solve(0, 0, 0);
  cout << ans << endl;

  return 0;
}
