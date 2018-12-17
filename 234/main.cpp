#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode *reverse(ListNode *head)
{
    ListNode *prev = nullptr;
    while (head != nullptr) {
        ListNode *next = head->next;
        head->next = prev;
        prev = head;
        head = next;
    }

    return prev;
}

bool isPalindrome(ListNode *head)
{
    ListNode *fast = head, *slow = head;
    while (fast != nullptr && fast->next != nullptr) {
        fast = fast->next->next;
        slow = slow->next;
    }

    if (fast != nullptr) { //odd nodes: let right half smaller
        slow = slow->next;
    }

    slow = reverse(slow);
    fast = head;

    while (slow != nullptr) {
        if (fast->val != slow->val) {
            return false;
        }

        fast = fast->next;
        slow = slow->next;
    }

    return true;
}

int main()
{
    ListNode *node = new ListNode(1);
    node->next = new ListNode(2);
    node->next->next = new ListNode(2);
    node->next->next->next = new ListNode(1);

    cout << isPalindrome(node) << endl;

    return 0;
}
