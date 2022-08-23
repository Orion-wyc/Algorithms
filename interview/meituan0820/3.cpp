#include <bits/stdc++.h>
using namespace std;

double solve(const vector<int> &probs, const vector<int> &scores, int m) {
  int n = probs.size();
  double total = 0.0;
  // <score, probs>
  vector<pair<int, int>> sp_vec;
  for (int i = 0; i < n; ++i) {
    if (probs[i] == 100) {
      total += scores[i] * 1.0;
      continue;
    }
    sp_vec.emplace_back(pair<int, int>(scores[i], probs[i]));
  }

  auto cmp = [](const pair<int, int> &a, const pair<int, int> &b) {
    int s1 = a.first * (100 - a.second);
    int s2 = b.first * (100 - b.second);
    if (s1 == s2) {
      if (a.first == b.first) {
        return a.second < b.second;
      } else {
        return a.first > b.first;
      }
    } else {
      return s1 > s2;
    };
  };
  sort(sp_vec.begin(), sp_vec.end(), cmp);
  // for (auto p : sp_vec) {
  //   cout << p.first << " " << p.second << endl;
  // }
  for (int i = 0; i < m; ++i) {
    total += sp_vec[i].first * 1.0;
  }
  for (int i = m; i < n; ++i) {
    total += sp_vec[i].first * sp_vec[i].second / 100.0;
  }

  return total;
}

int main() {
  int n, m;
  cin >> n >> m;

  vector<int> probs(n);
  vector<int> scores(n);

  for (int i = 0; i < n; ++i) {
    int x;
    cin >> x;
    probs[i] = x;
  }

  for (int i = 0; i < n; ++i) {
    int x;
    cin >> x;
    scores[i] = x;
  }

  printf("%.2f\n", solve(probs, scores, m));

  return 0;
}