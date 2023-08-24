#include <iostream>

using namespace std;

struct ListNode
{
public:
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution
{
public:
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2)
    {
        ListNode *head;
        ListNode *cur;     // current pointer of the merged ("1st") list
        ListNode *cur_run; // current running pointer of the "2nd" list
        ListNode *tmp;
        if ((!l1) || (!l2))
            return l1 ? l1 : l2;
        if (l1->val <= l2->val) // use cur and cur_run instead of l1 and l2
        {
            cur = l1;
            cur_run = l2;
        }
        else
        {
            cur = l2;
            cur_run = l1;
        }
        head = cur;

        while (cur_run != nullptr)
        {
            if ((cur->next != nullptr) && (cur->next->val <= cur_run->val))
            {
                cur = cur->next;
            }
            else // if cur_run->val is smaller than the cur->next->val
            {
                if (cur_run->val >= cur->val)
                {
                    tmp = cur_run->next;
                    cur_run->next = cur->next;
                    cur->next = cur_run;
                    cur = cur->next;
                    cur_run = tmp;
                }
                else
                {
                    cur = cur->next;
                }
            }
        }
        return head;
    }
};

void printList(ListNode *l)
{
    while (l != nullptr)
    {
        cout << l->val << " -> ";
        l = l->next;
    }
    cout << endl;
}

int main(int argc, char const *argv[])
{
    ListNode l11(1);
    ListNode l12(2);
    ListNode l13(4);

    ListNode l21(1);
    ListNode l22(3);
    ListNode l23(4);

    l11.next = &l12;
    l12.next = &l13;
    l13.next = nullptr;

    l21.next = &l22;
    l22.next = &l23;
    l23.next = nullptr;

    Solution MySolution;

    printList(MySolution.mergeTwoLists(&l11, &l21));

    return 0;
}
