#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  string s = "";
  cin >> s;
  vector<string> ans;
  for (int i = 0; i < n; ++i) {
    int low = i * 9;
    char op = s[low];
    string curr = s.substr(low + 1, 8);
    if (op == '0') {
      reverse(curr.begin(), curr.end());
    }
    ans.push_back(curr);
  }
  // output
  for (int i = 0; i < ans.size() - 1; ++i) {
    cout << ans[i] << " ";
  }
  cout << ans.back() << endl;
  return 0;
}