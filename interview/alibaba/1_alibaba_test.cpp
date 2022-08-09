/*
 给出一个正整数 N 和长度 L ，找出一段长度大于等于 L 的连续非负整数，
 他们的和恰好为 N 。答案可能有多个，我我们需要找出长度最小的那个。
 1 <= N <= 10^9, 2 <= L <= 100.
 */

#include <iostream>
using namespace std;

int main() {
  int N;
  int L;
  cin >> N >> L;
  long long x = 0;
  long long y = L;
  bool flag = false;
  do {
    x = N / y - (y - 1) / 2;
    long long check_sum = y * y + (2 * x - 1) * y - 2 * N;
    if (check_sum == 0 && x >= 0) {
      flag = true;
      break;
    }
    ++y;
  } while (y <= 100);
  if (flag) {
    for (int i = 0; i < y; ++i) {
      cout << x + i;
      if (i != y - 1) cout << " ";
    }
  } else {
    cout << "No";
  }
  return 0;
}