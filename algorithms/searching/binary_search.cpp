#include <algorithm>
#include <array>
#include <iostream>
#include <set>
#include <vector>
using namespace std;

/* 注意搜索区间是[l,R) */
template <typename T1, typename T2>
bool _binary_search(const T1& arr, int l, int r, const T2& target) {
  bool exist = false;
  while (l <= r) { // [l, r]左右均为闭区间，相等时仍有意义
    int mid = l + (r - l) / 2;
    if (arr[mid] == target) {
      exist = true;
      break;
    } else if (arr[mid] > target) {
      r = mid - 1;
    } else {
      l = mid + 1;
    }
  }
  return exist;
}

/* 建议选用lower_bound的写法,接近STL中的实现,注意搜索区间是[l,r) */
template <typename ARRAY, typename T>
int lower_bound(const ARRAY& arr, int l, int r, const T& val) {
  while (l < r) { // [l, r)左闭右开，相等时仍有意义
    int mid = l + (r - l) / 2;
    if (arr[mid] >= val) {
      r = mid;
    } else {
      l = mid + 1;
    }
  }
  return l;
}

/* 如果需要返回下标, 可以在这里处理, 返回值改成int, 不存在时改成 idx=-1 */
template <typename ARRAY, typename T>
bool binary_search(const ARRAY& arr, int l, int r, const T& val) {
  int idx = lower_bound(arr, l, r, val);
  return (idx != r) && !(val < arr[idx]);
}

int main() {
  int len = 10;
  vector<int> arr;
  for (int i = 0; i < len; ++i) {
    arr.push_back(i * 2);
  }
  int arrs[10] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j'};
  array<string, 5> strs = {"hell", "fl", "refal", "asfvsr4c", "Ssdawc"};
  // for (auto s : strs) {
  //   cout << s << endl;
  // }
  sort(strs.begin(), strs.end());
  for (auto s : strs) {
    cout << s << endl;
  }
  pair<int, int> pi{1,2};
  // test cases
  cout << boolalpha << binary_search(arr, 1, len, 3) << endl;
  cout << boolalpha << _binary_search(arr, 1, len - 1, 3) << endl;

  cout << boolalpha << binary_search(arr, 4, len, 3) << endl;
  cout << boolalpha << _binary_search(arr, 4, len - 1, 3) << endl;

  cout << boolalpha << binary_search(arrs, 1, 10, 'j') << endl;
  cout << boolalpha << _binary_search(arrs, 1, 9, 'j') << endl;

  cout << boolalpha << binary_search(arrs, 4, len, 'a') << endl;
  cout << boolalpha << _binary_search(arrs, 4, len - 1, 'a') << endl;

  cout << boolalpha << binary_search(strs, 0, strs.size(), "refal") << endl;
  cout << boolalpha << _binary_search(strs, 0, strs.size() - 1, "refal")
       << endl;

  cout << boolalpha << binary_search(strs, 0, strs.size(), "AAAAA") << endl;
  cout << boolalpha << _binary_search(strs, 0, strs.size() - 1, "AAAAA")
       << endl;

  return 0;
}