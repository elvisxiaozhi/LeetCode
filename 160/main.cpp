#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
{
    if(!headA || !headB)
        return nullptr;

    ListNode *A = headA;
    ListNode *B = headB;
    int aLength = 0, bLength = 0;

    while (A) {
        A = A->next;
        ++aLength;
    }
    while (B) {
        B = B->next;
        ++bLength;
    }

    A = headA, B = headB;

    if (aLength > bLength) {
        int len = aLength - bLength;
        while (len--) {
            headA = headA->next;
        }
    }
    else if (aLength < bLength) {
        int len = bLength - aLength;
        while (len--) {
            headB = headB->next;
        }
    }

    while (headA != nullptr && headB != nullptr) {
        if (headA == headB) {
            return headA;
        }
        headA = headA->next;
        headB = headB->next;
    }

    return nullptr;
}

int main()
{
    ListNode *node1 = new ListNode(4);
    node1->next = new ListNode(1);
    node1->next->next = new ListNode(8);
    node1->next->next->next = new ListNode(4);

    ListNode *node2 = new ListNode(5);
    node2->next = new ListNode(0);
    node2->next->next = new ListNode(1);
    node2->next->next->next = new ListNode(8);
    node2->next->next->next->next = new ListNode(4);

    return 0;
}
