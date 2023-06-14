#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>


//104. 二叉树的最大深度

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

int maxDepth(struct TreeNode* root) {
    if (root == NULL)
    {
        return 0;
    }

    int leftheight = maxDepth(root->left);
    int rightheight = maxDepth(root->right);

    return leftheight > rightheight ? leftheight + 1 : rightheight + 1;

}

//100. 相同的树
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
bool IsSameTree(struct TreeNode* p, struct TreeNode* q)
{
    if (p == NULL && q == NULL)
    {
        return true;
    }

    if (p == NULL || q == NULL)
    {
        return false;
    }

    if (p->val != q->val)
    {
        return false;
    }

    return IsSameTree(p->left, q->left)
        && IsSameTree(p->right, q->right);
}

bool isSameTree(struct TreeNode* p, struct TreeNode* q) {
    return IsSameTree(p, q);

}

//965. 单值二叉树
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */


bool isUnivalTree(struct TreeNode* root) {
    if (root == NULL)
    {
        return true;
    }

    if (root->left && root->val != root->left->val)
    {
        return false;
    }
    if (root->right && root->val != root->right->val)
    {
        return false;
    }

    return isUnivalTree(root->left)
        && isUnivalTree(root->right);

}