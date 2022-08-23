#include <bits/stdc++.h>
using namespace std;

string ExtractTime(const string &input) {
  stringstream ss(input);
  string seg = "";
  while (getline(ss, seg, '/')) {
    // if (VerifyTime(seg)) {
    if (seg.size() == 19) { // 不检查合法性？
      break;
    }
  }
  return seg;
}

struct TimeItem {
  string timestamp;
  string raw_string;

  TimeItem(string input) : raw_string(input) {
    timestamp = ExtractTime(input);
  };

  bool operator<(const TimeItem &rhs) const {
    if (timestamp == rhs.timestamp) {
      if (raw_string.size() == rhs.raw_string.size()) {
        raw_string < rhs.raw_string;
      } else {
        return raw_string.size() < rhs.raw_string.size();
      }
    }
    return timestamp < rhs.timestamp;
  }
};


void SortTimeItems(const unordered_set<string> &time_set) {
  // 构造TimeItem数组
  vector<TimeItem> arr;
  for (auto s : time_set) {
    arr.push_back(TimeItem(s));
  }
  sort(arr.begin(), arr.end());
  // 排序
  for (auto s : arr) {
    cout << s.raw_string << endl;
  }
}


int main() {
  int n;
  cin >> n;
  unordered_set<string> time_set;
  // 第一次遍历先去重
  for (int i = 0; i < n; ++i) {
    string input;
    cin >> input;
    time_set.insert(input);
  }

  SortTimeItems(time_set);

  return 0;
}
