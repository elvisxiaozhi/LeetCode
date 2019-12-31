#include <iostream>
#include <vector>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

bool hasCycle(ListNode *head)
{
    if (head == nullptr || head->next == nullptr) {
        return false;
    }

    ListNode *slow = head;
    ListNode *fast = head->next;
    while (slow != fast) {
        if (fast == nullptr || fast->next == nullptr) {
            return false;
        }

        slow = slow->next;
        fast = fast->next->next;
    }

    return true;
}

ListNode *detectCycle_1(ListNode *head)
{
    if (head == nullptr)
        return nullptr;

    ListNode *slow = head;
    ListNode *fast = head;

    while (fast != nullptr && fast->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast)
            break;
    }

    if (fast == nullptr || fast->next == nullptr)
        return nullptr;

    slow = head;
    while (slow != fast) {
        slow = slow->next;
        fast = fast->next;
    }

    return slow;
}

ListNode *detectCycle(ListNode *head)
{
    vector<ListNode *> node;

    while (head != nullptr) {
        node.push_back(head);
        head = head->next;
        const auto it = find(node.begin(), node.end(), head);
        if (it != node.end())
            return head;
    }

    return nullptr;
}

int main()
{
    ListNode *node = new ListNode(3);
    node->next = new ListNode(2);
    node->next->next = new ListNode(0);
    node->next->next->next = new ListNode(-4);
    node->next->next->next->next = node->next;

    cout << hasCycle(node) << endl;

    return 0;
}
