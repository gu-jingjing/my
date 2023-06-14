#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>

//21. 合并两个有序链表
 //Definition for singly-linked list.
 struct ListNode {
     int val;
     struct ListNode *next;
 };


typedef struct ListNode LTNode;
struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2)
{
    if (list1 == NULL)
    {
        return list2;
    }
    if (list2 == NULL)
    {
        return list1;
    }

    LTNode* cur1 = list1;
    LTNode* cur2 = list2;

    LTNode* ret = NULL;
    LTNode* tail = NULL;
    if (cur1->val < cur2->val)
    {
        ret = cur1;
        tail = cur1;
        cur1 = cur1->next;
    }
    else
    {
        ret = cur2;
        tail = cur2;
        cur2 = cur2->next;
    }

    while (cur1 && cur2)
    {
        if (cur1->val < cur2->val)
        {
            tail->next = cur1;
            tail = tail->next;
            cur1 = cur1->next;

        }
        else
        {
            tail->next = cur2;
            tail = tail->next;
            cur2 = cur2->next;
        }
    }

    if (cur1)
    {
        tail->next = cur1;
    }
    if (cur2)
    {
        tail->next = cur2;
    }

    return ret;
}