#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
//牛客 CM11 链表分割

struct ListNode {
    int val;
    struct ListNode*next;
    ListNode(int x) : val(x), next(NULL) {}
};
class Partition {
public:
    ListNode* partition(ListNode* pHead, int x) {
        // write code here
        struct ListNode* rhead = (struct ListNode*)malloc(sizeof(struct ListNode));

        struct ListNode* listl = NULL;
        struct ListNode* tails = NULL;
        struct ListNode* taill = NULL;

        struct ListNode* cur = pHead;
        if (cur == NULL)
        {
            return NULL;
        }

        while (cur)
        {
            struct ListNode* next = cur->next;
            if (cur->val < x)
            {
                if (tails)
                {
                    tails->next = cur;
                    tails = cur;
                }
                else
                {
                    rhead->next = cur;
                    tails = cur;
                }
            }
            else
            {
                if (listl)
                {
                    taill->next = cur;
                    taill = cur;
                }
                else
                {
                    listl = cur;
                    taill = cur;
                }

            }
            cur = next;
        }

        if (taill)
        {
            taill->next = NULL;
        }
        if (tails == NULL)
        {
            free(rhead);
            rhead = NULL;
            return listl;
        }
        tails->next = listl;
        struct ListNode* del = rhead;
        rhead = rhead->next;

        free(del);
        del = NULL;

        return rhead;

    }
};

//牛客 OR36 链表的回文结构

struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
class PalindromeList {
public:
    void ReverseList(ListNode** phead)
    {
        ListNode* cur = *phead;
        ListNode* rhead = *phead;
        cur = cur->next;
        rhead->next = NULL;

        while (cur)
        {
            ListNode* next = cur->next;
            cur->next = rhead;
            rhead = cur;
            cur = next;
        }

        *phead = rhead;
    }
    bool chkPalindrome(ListNode* phead) {
        // write code here
        ListNode* cur = phead;

        ListNode* fast = phead;
        ListNode* slow = phead;
        int flag = 0;
        while (fast)
        {
            flag++;
            fast = fast->next;
            if (flag % 2 == 0)
            {
                slow = slow->next;
            }
        }

        ReverseList(&slow);

        ListNode* begin = phead;
        while (slow)
        {
            if (begin->val != slow->val)
            {
                return false;
            }
            slow = slow->next;
            begin = begin->next;
        }

        return true;
    }
};

//力扣 160. 相交链表

//Definition for singly-linked list.
 struct ListNode {
     int val;
     struct ListNode *next;
};

typedef struct ListNode LTNode;
struct ListNode* getIntersectionNode(struct ListNode* headA, struct ListNode* headB)
{
    LTNode* curA = headA;
    LTNode* curB = headB;

    while (curA)
    {
        while (curB)
        {
            if (curA == curB)
            {
                return curB;
            }
            curB = curB->next;
        }
        curB = headB;
        curA = curA->next;
    }
    return NULL;

}