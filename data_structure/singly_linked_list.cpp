/* 单链表的实现方式
 */

#include <cassert>
#include <iostream>
using namespace std;

template <typename T = int>
struct ListNode {
  T val;
  ListNode<T> *next;
  ListNode(T v, ListNode<T> *p = nullptr) : val(v), next(p) {}
};

template <typename T = int>
ListNode<T> *FindNode(ListNode<T> *hair, const int pos) {
  // 检查插入位置是否合法
  assert(pos >= 0);

  int idx = 0;
  ListNode<T> *curr = hair;
  while (curr->next != nullptr && idx < pos) {
    curr = curr->next;
    ++idx;
  }
  // 检查插入位置是否越界
  assert(idx == pos);

  return curr;
}

template <typename T = int>
void InsertNode(ListNode<T> *hair, const int pos, const T &val) {
  ListNode<T> *curr = FindNode(hair, pos);

  ListNode<T> *node = new ListNode<T>(val, curr->next);
  curr->next = node;
}

template <typename T = int>
void DeleteNode(ListNode<T> *hair, const int pos) {
  ListNode<T> *pre = FindNode(hair, pos);
  ListNode<T> *tmp = pre->next;
  pre->next = pre->next->next;
  delete tmp;
}

template <typename T = int>
void PrintList(ListNode<T> *hair) {
  ListNode<T> *curr = hair->next;
  while (curr != nullptr) {
    cout << curr->val << " ";
    curr = curr->next;
  }
  cout << endl;
}

void test_case() {
  cout << "Creating a list with 10 ListNodes" << endl;
  ListNode<int> *linklist = new ListNode<int>(0);
  for (int i = 0; i < 10; i++) {
    InsertNode(linklist, 0, i);
  }
  PrintList(linklist);

  // 测试越界
  // InsertNode(linklist, 11, 100);
  // PrintList(linklist);
  InsertNode(linklist, 5, 555);
  PrintList(linklist);

  DeleteNode(linklist, 7);
  PrintList(linklist);

  while (linklist->next != nullptr) {
    DeleteNode(linklist, 0);
  }
  PrintList(linklist);

  delete linklist;
}

int main() {
  test_case();
  return 0;
}