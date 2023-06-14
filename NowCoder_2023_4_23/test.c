#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>

//链表中倒数第k个结点
 struct ListNode {
	int val;
	struct ListNode *next;
};


 /**
  *
  * @param pListHead ListNode类
  * @param k int整型
  * @return ListNode类
  */
typedef struct ListNode LTNode;
struct ListNode* FindKthToTail(struct ListNode* pListHead, int k) {
    // write code here
    LTNode* ret = pListHead;
    LTNode* fast = pListHead;
    if (pListHead == NULL)
    {
        return NULL;
    }
    while (k)
    {
        fast = fast->next;
        k--;
        if (fast->next == NULL)
        {
            if (k == 1)
            {
                return ret;
            }
            return NULL;
        }
    }

    while (fast)
    {
        ret = ret->next;
        fast = fast->next;
    }

    return ret;
}