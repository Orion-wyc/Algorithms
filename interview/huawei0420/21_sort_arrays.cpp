#include <bits/stdc++.h>
using namespace std;

void ReorderArray(vector<int> &arr1, const vector<int> &arr2) {
  unordered_map<int, int> num_count;
  vector<int> unseen_nums;
  for (int n : arr2) num_count.emplace(n, 0);
  for (int n : arr1) {
    if (num_count.find(n) != num_count.end()) {
      ++num_count[n];
    } else {
      unseen_nums.push_back(n);
    }
  }
  sort(unseen_nums.begin(), unseen_nums.end());
  arr1.clear();

  for (int n : arr2) {
    arr1.insert(arr1.end(), num_count[n], n);
  }
  arr1.insert(arr1.end(), unseen_nums.begin(), unseen_nums.end());
}

int main() {
  vector<int> arr1 = {2, 3, 1, 3, 4, 6, 7, 9, 2, 19};
  vector<int> arr2 = {2, 1, 4, 3, 9, 6};

  ReorderArray(arr1, arr2);

  for (int n : arr1) {
    cout << n << " ";
  }
  
  return 0;
}