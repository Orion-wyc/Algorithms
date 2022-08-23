#include <bits/stdc++.h>
using namespace std;

struct Info {
  string filename;
  int prior;
  int cnt;
  bool operator<(const Info &a) const {
    if (cnt == a.cnt)
      return prior < a.prior;
    else
      return cnt > a.cnt;
  }
};

vector<Info> infos;
map<string, int> indices;

// bool cmp(const pair<string, int> &a, const pair<string, int> &b) {
//   return a.second > b.second;
// }

void ProcessInfo(const string &s, int prior) {
  int pos = s.find_last_of('\\');
  // 获取文件名和行号，统一处理为字符串
  string filename = s;
  if (pos != -1) filename = s.substr(pos + 1);

  if (indices.count(filename) > 0) {
    ++infos[indices[filename]].cnt;
  } else {
    indices[filename] = infos.size();
    infos.emplace_back(Info{filename, prior, 1});
  }
}

void PrintInfo() {
  // 按照cnt和出现的先后顺序排序
  sort(infos.begin(), infos.end());

  // 最多八条
  int len = infos.size();
  len = min(8, len);
  for (int i = 0; i < len; ++i) {
    string s = infos[i].filename;
    int cnt = infos[i].cnt;
    // 截取文件名字、获取行号
    int pos = s.find_last_of(' ');
    string filename = s.substr(0, pos);
    if (filename.size() > 16) filename = filename.substr(pos - 16);
    string line = s.substr(pos + 1);
    cout << filename << " " << line << " " << cnt << endl;
  }
}

int main() {
  int prior = 0;
  string s;
  while (getline(cin, s)) {
    ProcessInfo(s, prior);
    ++prior;
  }

  // 输出最终结果，截断操作
  PrintInfo();

  return 0;
}