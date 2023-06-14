#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
//203. 移除链表元素
 //Definition for singly-linked list.
 struct ListNode {
     int val;
     struct ListNode *next;
 };
 
typedef struct ListNode LTNode;

struct ListNode* removeElements(struct ListNode* head, int val)
{
    LTNode* newhead = NULL;
    LTNode* tail = newhead;
    LTNode* cur = head;
    while (cur)
    {
        if (cur->val != val)
        {
            if (newhead == NULL)
            {
                newhead = cur;
                tail = cur;
                cur = cur->next;
            }
            else
            {
                tail->next = cur;
                tail = tail->next;
                cur = cur->next;
            }
        }
        else
        {
            cur = cur->next;
        }
    }
    if (tail)
    {
        tail->next = NULL;
    }
    return newhead;
}


//206. 反转链表
 //Definition for singly-linked list.
 struct ListNode {
     int val;
     struct ListNode *next;
 };
typedef struct ListNode LTNode;
struct ListNode* reverseList(struct ListNode* head)
{
    if (head == NULL || head->next == NULL)
    {
        return head;
    }

    LTNode* cur = head;
    LTNode* newhead = head->next;
    LTNode* tail = newhead->next;

    while (tail)
    {
        head->next = tail;
        newhead->next = cur;

        cur = newhead;
        newhead = tail;
        tail = tail->next;

    }
    head->next = tail;
    newhead->next = cur;
    return newhead;
}

//876. 链表的中间结点
 //definition for singly-linked list.
 struct listnode 
 {
    int val;
    struct listnode *next;
 };
typedef struct ListNode LTNode;
struct ListNode* middleNode(struct ListNode* head)
{
    LTNode* fast = head;
    LTNode* slow = head;
    int flag = 0;
    while (fast)
    {
        fast = fast->next;
        flag++;
        if (flag % 2 == 0)
        {
            slow = slow->next;
        }
    }
    return slow;
}

