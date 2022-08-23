#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  string A;
  string B;
  cin >> A;
  cin >> B;

  string ans(n * 2, 'a');
  for (int i = 0; i < 2 * n; ++i) {
    if (i % 2 == 0) {
      ans[i] = A[i / 2];
    } else {
      ans[i] = B[i / 2]
    }
  }
  return ans;
}