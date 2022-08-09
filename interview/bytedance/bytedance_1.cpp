/*
作者：醉里帅梦
链接：https://www.nowcoder.com/discuss/364951?type=post&order=recall&pos=&page=1&ncTraceId=&channel=-1&source_id=search_post_nctrack&gio_id=B072DCC202223B8C4E71BDE0D9A0C047-1645927442372
来源：牛客网
题目描述：
给定m个不重复的字符 [a, b, c, d]，以及一个长度为n的字符串tbcacbdata，
问能否在这个字符串中找到一个长度为m的连续子串，使得这个子串刚好由上面m
个字符组成，顺序无所谓，返回任意满足条件的一个子串的起始位置，未找到返
回-1。比如上面这个例子，acbd，3。 
*/

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
  vector<int> flag(4, -1);
  string s = "tbcacbdata";
  int sum = 0;
  for (int i = 0; i < s.size(); ++i) {
    int idx = s[i] - 'a';
    if (idx >= 4) continue;
    if (flag[idx] == -1) {
      flag[idx] = i;
      ++sum;
    } else {
      if (flag[idx] < i) {
        for (int j = 0; j < 4; ++j) {
          if (flag[j]!=-1 && flag[j] < flag[idx]) {
            flag[j] = -1;
            --sum;
          }
        }
        flag[idx] = i;
      }
    }
    cout << i << sum << endl;
    if (sum == 4) {
      // for (auto a : flag) {
      //   cout << a << " ";
      // }
      cout << *min_element(flag.begin(), flag.end()) << endl;
      break;
    }
  }
  return 0;
}