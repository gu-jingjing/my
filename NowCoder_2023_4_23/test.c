#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>

//�����е�����k�����
 struct ListNode {
	int val;
	struct ListNode *next;
};


 /**
  *
  * @param pListHead ListNode��
  * @param k int����
  * @return ListNode��
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