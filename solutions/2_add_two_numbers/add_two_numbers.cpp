/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

#include <iostream>

using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class Solution
{
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        ListNode temp_list(0);
        ListNode *result_list = &temp_list;
        int rest = 0;

        while (l1 || l2 || rest)
        {
            if (l1 != nullptr)
            {
                rest += l1->val;
                l1 = l1->next;
            }
            if (l2 != nullptr)
            {
                rest += l2->val;
                l2 = l2->next;
            }
            result_list->next = new ListNode(rest % 10);
            rest /= 10;
            result_list = result_list->next;
        }
        return temp_list.next;
    }
};

void printList(ListNode *l)
{
    while (l != nullptr)
    {
        cout << l->val << endl;
        l = l->next;
    }
}

int main(int argc, char const *argv[])
{
    Solution MySolution;

    ListNode l1(1);
    ListNode l2(2);
    l1.next = &l2;

    ListNode l31(3, &l1);
    printList(&l31);

    ListNode *l_sum = MySolution.addTwoNumbers(&l31, &l1);

    printList(l_sum);

    return 0;
}
