#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* reverseList(ListNode* head)
{
    if (head == NULL || head->next == NULL) return head;
    ListNode *p = reverseList(head->next);
    head->next->next = head;
    head->next = NULL;
    return p;
}

ListNode *reverseList1(ListNode *head)
{
    ListNode *prev = NULL;
    ListNode *curr = head;
    while (curr != NULL) {
        ListNode *nextTemp = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nextTemp;
    }
    return prev;
}

void printTreeNode(ListNode *node)
{
    if (!node) {
        return;
    }
    else {
        cout << node->val << endl;
    }

    if (node->next) {
        printTreeNode(node->next);
    }
}

int main()
{
    ListNode *node = new ListNode(1);
    node->next = new ListNode(2);
    node->next->next = new ListNode(3);
    node->next->next->next = new ListNode(4);
    node->next->next->next->next = new ListNode(5);

    ListNode *node2 = reverseList1(node);
    printTreeNode(node2);

    return 0;
}
