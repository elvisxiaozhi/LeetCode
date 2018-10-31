#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

void printNode(ListNode *node)
{
    if (node == nullptr) {
        return;
    }

    cout << node->val << endl;

    printNode(node->next);
}

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2)
{
    ListNode *node = new ListNode(0);
    ListNode *p = l1;
    ListNode *q = l2;
    ListNode *curr = node;

    int carry = 0;
    while (p != nullptr || q != nullptr) {
        int x = (p != nullptr) ? p->val : 0;
        int y = (q != nullptr) ? q->val : 0;
        int sum = carry + x + y;
        carry = sum / 10;
        curr->next = new ListNode(sum % 10);
        curr = curr->next;
        if (p != nullptr) p = p->next;
        if (q != nullptr) q = q->next;
    }

    if (carry > 0) {
        curr->next = new ListNode(carry);
    }

    return curr;
}

int main()
{
    ListNode *node1 = new ListNode(5);
//    node1->next = new ListNode(4);
//    node1->next->next = new ListNode(3);

    ListNode *node2 = new ListNode(5);
//    node2->next = new ListNode(6);
//    node2->next->next = new ListNode(4);

    ListNode *node3 = addTwoNumbers(node1, node2);

    printNode(node3);

    return 0;
}
