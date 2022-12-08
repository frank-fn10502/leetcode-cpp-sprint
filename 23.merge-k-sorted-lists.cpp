/*
 * @lc app=leetcode id=23 lang=cpp
 *
 * [23] Merge k Sorted Lists
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
#include <bits/stdc++.h>
using namespace std;
// struct ListNode
// {
//     int val;
//     ListNode *next;
//     ListNode() : val(0), next(nullptr) {}
//     ListNode(int x) : val(x), next(nullptr) {}
//     ListNode(int x, ListNode *next) : val(x), next(next) {}
// };

class Solution
{
public:
    ListNode *mergeKLists(vector<ListNode *> &lists)
    {
        if (lists.size() == 0)
            return {};
        if (lists.size() == 1)
            return lists[0];

        ListNode *list1 = nullptr, *list2 = nullptr,
                 *result = nullptr,
                 *current = nullptr;
        for (int i = 0; i < lists.size(); i++)
        {
            if (result == nullptr)
            {
                result = lists[i];
                continue;
            }
            if (lists[i] == nullptr)
                continue;
            list1 = result;                                     //集合的 list
            list2 = lists[i];                                   // 下一個 List
            result = (list1->val < list2->val ? list1 : list2); // 最小的起始為新的 head
            current = nullptr;
            while (list1 != nullptr && list2 != nullptr)
            {
                if (list1->val < list2->val)
                {
                    if (current == nullptr)
                        current = list1;
                    else
                    {

                        current->next = list1;
                        current = current->next;
                    }
                    list1 = list1->next;
                }
                else
                {
                    if (current == nullptr)
                        current = list2;
                    else
                    {
                        current->next = list2;
                        current = current->next;
                    }
                    list2 = list2->next;
                }
            }
            if (list1 != nullptr)
                current->next = list1;
            else if (list2 != nullptr)
                current->next = list2;
        }
        return result;
    }
};
// @lc code=end
