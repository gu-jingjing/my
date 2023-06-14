#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>

//LeetCode138. 复制带随机指针的链表
struct Node {
    int val;
    struct Node *next;
    struct Node *random;
};

typedef struct Node Node;
struct Node* copyRandomList(struct Node* head)
{
    Node* cur = head;
    //拷贝结点
    while (cur)
    {
        Node* tmp = (Node*)malloc(sizeof(Node));
        tmp->val = cur->val;
        tmp->next = cur->next;
        cur->next = tmp;

        //迭代
        cur = tmp->next;
    }

    //链接random
    cur = head;
    while (cur)
    {
        if (cur->random == NULL)
        {
            cur->next->random = NULL;
        }
        else
        {
            cur->next->random = cur->random->next;
        }

        //迭代
        cur = cur->next->next;
    }

    //链接新链表，恢复原链表
    Node* NewListHead = NULL;
    Node* NewListTail = NULL;

    cur = head;
    while (cur)
    {
        Node* newnode = cur->next;
        Node* next = newnode->next;

        if (NewListHead == NULL)
        {
            NewListHead = NewListTail = newnode;
        }
        else
        {
            NewListTail->next = newnode;
            NewListTail = newnode;

            cur->next = next;
        }

        //迭代
        cur = next;
    }

    return NewListHead;
}