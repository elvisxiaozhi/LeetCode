#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

void printNode(ListNode *node)
{
    if (node == nullptr)
        return;

    cout << node->val << endl;
    printNode(node->next);
}

void deleteNode(struct ListNode *node)
{
    node->val = node->next->val;
    node->next = node->next->next;
}

void deleteNode1(struct ListNode *node)
{
    ListNode *prev = nullptr;
    while (node->next != nullptr) {
        node->val = node->next->val;
        prev = node;
        node = node->next;
    }

    delete node;
    prev->next = nullptr;
}

int main()
{
    ListNode *node = new ListNode(4);
    node->next = new ListNode(5);
    node->next->next = new ListNode(1);
    node->next->next->next = new ListNode(9);

    deleteNode(node->next);

    printNode(node);

    return 0;
}
