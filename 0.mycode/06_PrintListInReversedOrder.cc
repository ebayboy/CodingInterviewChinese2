
#include <iostream>
#include <stack>
#include <vector>

using namespace std;

/*
题目：
从尾到头打印链表
输入一个链表的头节点，从尾到头反过来打印出每个节点的值。链表节点定义如下：
*/

/*
解题思路：
将链表存储到栈中， 之后遍历栈将结果存储到vector中，打印vector
*/

/*
    1. statck use
*/
struct ListNode
{
    int val;
    struct ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

/* head -> p1 -> p2 -> p3 -> p4 -> ... */
vector<int> ReverseList(ListNode *head)
{
    vector<int> res;
    ListNode *p;

    std::stack<ListNode> ps;

    for (p = head; p != nullptr; p = p->next)
    {
        ps.push(p->val);
    }

    while (!ps.empty())
    {
        res.push_back(ps.top().val);
        ps.pop();
    }

    return res;
}

void deleteList(ListNode *head)
{
    ListNode *p, *pnode;
    /*              head   
    /* head -> p1 -> p2 -> p3 -> p4 -> ... */
    /*              head  */
    pnode = head->next;
    while (pnode != nullptr)
    {
        p = pnode;
        pnode = p->next;
        cout << "delete:" << p->val << endl;
        delete p;
    }
}

int main(int argc, const char **argv)
{
    ListNode *head, *tail;
    ListNode *p;

    head = tail = new ListNode(-1);
    cout << "head.val:" << head->val << endl;

    for (size_t i = 0; i < 5; i++)
    {
        p = new ListNode(i);
        tail->next = p;
        tail = tail->next;
    }

    vector<int> res = ReverseList(head);

    for (auto v : res)
    {
        cout << "v:" << v << endl;
    }

    //delete mem
    deleteList(head);
    delete head;

    return 0;
}