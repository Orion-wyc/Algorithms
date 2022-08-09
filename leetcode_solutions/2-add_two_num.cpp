
// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* res = new ListNode();
        ListNode* p1 = l1;
        ListNode* p2 = l2;
        ListNode* curr=res;
        int carry = 0;
        while ((p1 != nullptr) && (p2!=nullptr)) {
            int sum = p1->val + p2->val + carry;
            carry = sum / 10;
            curr->next =  new ListNode(sum % 10);
            curr = curr->next;
            p1 = p1->next;
            p2 = p2->next;
        }
        while (p1 != nullptr) {
            int sum = p1->val + carry;
            carry = sum / 10;
            curr->next =  new ListNode(sum % 10);
            curr = curr->next;
            p1 = p1->next;
        }
        while (p2!=nullptr) {
            int sum = p2->val + carry;
            carry = sum / 10;
            curr->next =  new ListNode(sum % 10);
            curr = curr->next;
            p2 = p2->next;
        }
        // 最后的进位容易遗忘
        if (carry == 1) {
            curr->next = new ListNode(carry);
        }

        return res->next;
    }
};