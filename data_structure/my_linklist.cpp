class MyLinkedList {
 public:
  MyLinkedList() {
    hair = new ListNode(0);
    tail = hair;
    length = 0;
  }

  int get(int index);
  void addAtHead(int val);
  void addAtTail(int val);
  void addAtIndex(int index, int val);
  void deleteAtIndex(int index);

 private:
  struct ListNode {
    int val;
    ListNode *next;
    ListNode(int v = 0, ListNode *p = nullptr) : val(v), next(p) {}
  };

  ListNode *hair;
  ListNode *tail;
  int length;

  ListNode *findNode(int index);
};

int MyLinkedList::get(int index) {
  if (index < 0 || index >= length) return -1;
  ListNode *pre = findNode(index);
  return pre->next->val;
}

void MyLinkedList::addAtHead(int val) {
  ListNode *node = new ListNode(val, hair->next);
  hair->next = node;
  // 当链表为空时，需要更新tail指针
  if (tail == hair) tail = hair->next;
  ++length;
}

void MyLinkedList::addAtTail(int val) {
  ListNode *node = new ListNode(val, tail->next);
  tail->next = node;
  tail = node;
  ++length;
}

void MyLinkedList::addAtIndex(int index, int val) {
  if (index == length) {
    addAtTail(val);
  } else if (index <= 0) {
    addAtHead(val);
  } else if (index > 0 && index < length) {
    ListNode *pre = findNode(index);
    ListNode *node = new ListNode(val, pre->next);
    pre->next = node;
    ++length;
  }
}

void MyLinkedList::deleteAtIndex(int index) {
  if (index < 0 || index >= length) return;
  ListNode *pre = findNode(index);
  ListNode *tmp = pre->next;
  pre->next = pre->next->next;
  // 如果删除的节点是尾节点，则需要更新尾指针
  if (tail == tmp) tail = pre;
  --length;
  delete tmp;
}

// ListNode定义在类内部，需要使用类名获取
MyLinkedList::ListNode *MyLinkedList::findNode(int index) {
  // 确保输入的index合法
  int cnt = 0;
  ListNode *curr = hair;
  while (cnt < index) {
    curr = curr->next;
    ++cnt;
  }
  return curr;
}

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */

// int main() {
//   return 0;
// }