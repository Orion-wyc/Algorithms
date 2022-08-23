#include <bits/stdc++.h>
using namespace std;

// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;
#include <bits/stdc++.h>

string solution(string &S) {
  // write your code in C++ (C++14 (g++ 6.2.0))
  // [0, 1, ...,9] 数字计数
  vector<int> num_count(10, 0);
  for (char c : S) {
    ++num_count[c - '0'];
  }
  // 所有数字个数除以2
  bool zero_flag = true;
  string left = "";
  for (int i = 9; i >= 0; --i) {
    int n = num_count[i] / 2;
    if (n > 0) {
      if (i > 0) zero_flag = false;
      left.insert(left.end(), n, '0' + i);
    }
    num_count[i] %= 2;
  }

  string mid = "";
  for (int i = 9; i >= 0; --i) {
    if (num_count[i] > 0) {
      mid.push_back('0' + i);
      break;
    }
  }

  if (zero_flag) {
    if (!mid.empty())
      return mid;
    else
      return "0";
  }

  string right = left.substr(0, left.size());
  reverse(right.begin(), right.end());
  return left + mid + right;
}

int main() {
  vector<string> cases = {
      "0",
      "000",
      "00900",
      "39878",
      "54321",
      "00100",
      "1",
      "19910",
  };

  for (auto S : cases) {
    cout << solution(S) << endl;
  }
  return 0;
}