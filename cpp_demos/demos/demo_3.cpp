#include <algorithm>
#include <iostream>
#include <map>
#include <string>

using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
 public:
  ListNode *deleteNode(ListNode *head, int val) {
    ListNode *hair = new ListNode(0);
    hair->next = head;
    ListNode *pre = hair;
    ListNode *curr = hair->next;
    while (curr != nullptr) {
      if (curr->val == val) break;
      pre = curr;
      curr = curr->next;
    }
    if (curr != nullptr) {
      pre->next = curr->next;
      delete curr;
    }
    return hair->next;
  }
};

// void trim(string &s) { s.erase(remove(s.begin(), s.end(), ' '), s.end()); }

void trim(string &s) {
  int index = 0;
  if (!s.empty()) {
    while ((index = s.find(' ', index)) != string::npos) {
      s.erase(index, 1);
    }
  }
}

int main() {
  ListNode *head = new ListNode(0);
  ListNode *curr = head;
  for (int i = 1; i < 5; ++i) {
    curr->next = new ListNode(i);
    curr = curr->next;
  }
  Solution solve;
  curr = solve.deleteNode(head, 0);
  while (curr != nullptr) {
    cout << curr->val << endl;
    curr = curr->next;
  }

  string s = "   ddd dd d d d d   ";
  cout << s << endl;
  trim(s);
  cout << s << endl;

  map<char, int> mp;
  for (auto c : string("abcdddd")) {
    mp[c]++;
  }
  for (auto p : mp) {
    cout << p.first << " " << p.second << endl;
  }

  return 0;
}
