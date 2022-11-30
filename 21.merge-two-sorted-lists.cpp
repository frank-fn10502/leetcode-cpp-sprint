/*
 * @lc app=leetcode id=21 lang=cpp
 *
 * [21] Merge Two Sorted Lists
 */

// @lc code=start
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

class Solution
{
public:
    ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
    {
        ListNode *nextNode, *first, *current;
        first = (list1->val <= list2->val ? list1 : list2);
        current = first;

        do
        {
            if (list1 == nullptr)
            {
                nextNode = list2;
                list2 = list2->next;
            }
            else if (list2 == nullptr)
            {
                nextNode = list1;
                list1 = list1->next;
            }
            else if (list1->val <= list2->val)
            {
                nextNode = list1;
                list1 = list1->next;
            }
            else
            {
                nextNode = list2;
                list2 = list2->next;
            }

            if (nextNode == nullptr)
                break;
            current->next = nextNode;
            current = current->next;
        } while (true);

        return first;
    }
};
// @lc code=end
