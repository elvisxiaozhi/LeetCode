#include <iostream>

using namespace std;

struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
};

ListNode* mergeTwoLists(ListNode* l1, ListNode* l2)
{
    if(l1 == NULL) {
        return l2;
    }
    if(l2 == NULL) {
        return l1;
    }

    if(l1->val < l2->val) {
        l1->next = mergeTwoLists(l1->next, l2);
        return l1;
    }
    else {
        l2->next = mergeTwoLists(l1, l2->next);
        return l2;
    }
}

int main()
{    
    ListNode *head1 = new ListNode(1);
    head1->next = new ListNode(3);
    head1->next->next = new ListNode(5);

    ListNode *head2 = new ListNode(0);
    head2->next = new ListNode(2);
    head2->next->next = new ListNode(4);

    ListNode *mergedHead = mergeTwoLists(head1, head2);

    while(mergedHead != NULL) {
        cout << mergedHead->val << endl;
        mergedHead = mergedHead->next;
    }

    return 0;
}
