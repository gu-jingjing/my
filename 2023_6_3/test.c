#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

//KY11 ¶þ²æÊ÷±éÀú
typedef char BTDataType;

typedef struct BinaryTreeNode
{
    BTDataType data;
    struct BinaryTreeNode* left;
    struct BinaryTreeNode* right;
}BTNode;

BTNode* BuyNode(BTDataType x)
{
    BTNode* newnode = (BTNode*)malloc(sizeof(BTNode));
    if (newnode == NULL)
    {
        printf("malloc failed\n");
        return NULL;
    }

    newnode->data = x;
    newnode->left = newnode->right = NULL;
    return newnode;
}

BTNode* CreateBTree(char* s, int* pi)
{
    if (s[*pi] == '#')
    {
        (*pi)++;
        return NULL;
    }

    BTNode* newnode = BuyNode(s[*pi]);
    (*pi)++;

    newnode->left = CreateBTree(s, pi);
    newnode->right = CreateBTree(s, pi);

    return newnode;

}

void InOrder(BTNode* root)
{
    if (root == NULL)
    {
        return;
    }

    InOrder(root->left);
    printf("%c ", root->data);
    InOrder(root->right);

}

int main()
{
    char s[101] = { 0 };
    int k = 0;
    while (scanf("%c", &s[k]) != EOF)
    {
        k++;
    }
    int i = 0;
    BTNode* root = CreateBTree(s, &i);

    InOrder(root);
    printf("\n");

    return 0;
}