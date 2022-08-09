#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

template<typename T>
int _binary_search(const vector<T> &arr, int l, int r, int target) {
  while (l <= r) {
    int mid = l + (r - l) / 2;
    if (arr[mid] > target) {
      r = mid - 1;
    } else if (arr[mid] < target) {
      l = mid + 1;
    } else {
      return mid;
    }
  }
  return -1;
}

void test_case() {
  vector<char> arr = {'a', 'b', 'c', 'd', 'f', 'g', 'h', 'i', 'j', 'k'};
  cout << boolalpha << _binary_search(arr, 0, 9, 'a') << endl;
  cout << boolalpha << _binary_search(arr, 0, 9, 'e') << endl;
  cout << boolalpha << _binary_search(arr, 0, 9, 'k') << endl;
}

int main() {
  test_case();
  return 0;
}