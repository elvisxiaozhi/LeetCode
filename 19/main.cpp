#include <iostream>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode *makeNode(ListNode *node, vector<int> mVec, int index)
{
    if (index == mVec.size()) {
        return node;
    }

    node->next = new ListNode(mVec[index]);
    makeNode(node->next, mVec, ++index);

    return node;
}

vector<int> returnNodeVec(ListNode *node)
{
    vector<int> res;
    queue<ListNode *> q;
    q.push(node);
    ListNode *curr = node;

    while (!q.empty()) {
        curr = q.front()->next;
        res.push_back(q.front()->val);
        q.pop();

        if (curr != nullptr) {
            q.push(curr);
        }
    }

    return res;
}

ListNode* removeNthFromEnd(ListNode* head, int n)
{
    vector<int> mVec = returnNodeVec(head);
    mVec.erase(mVec.begin() + mVec.size() - n);

    if (mVec.empty())
        return nullptr;

    ListNode *res = new ListNode(mVec[0]);
    makeNode(res, mVec, 1);
    return res;
}

void printNode(ListNode *node)
{
    if (node == nullptr)
        return;

    cout << node->val << endl;

    printNode(node->next);
}

int main()
{
    vector<int> mVec = {1, 2, 3, 4, 5};
    ListNode *node = new ListNode(1);
    makeNode(node, mVec, 1);
    returnNodeVec(node);
    ListNode *res = removeNthFromEnd(node, 2);
    printNode(res);

    return 0;
}
