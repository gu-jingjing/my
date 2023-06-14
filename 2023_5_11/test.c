#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>

//LeetCode138. ���ƴ����ָ�������
struct Node {
    int val;
    struct Node *next;
    struct Node *random;
};

typedef struct Node Node;
struct Node* copyRandomList(struct Node* head)
{
    Node* cur = head;
    //�������
    while (cur)
    {
        Node* tmp = (Node*)malloc(sizeof(Node));
        tmp->val = cur->val;
        tmp->next = cur->next;
        cur->next = tmp;

        //����
        cur = tmp->next;
    }

    //����random
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

        //����
        cur = cur->next->next;
    }

    //�����������ָ�ԭ����
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

        //����
        cur = next;
    }

    return NewListHead;
}