#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

//144. 二叉树的前序遍历
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};


int BTreeSize(struct TreeNode* root)
{
    return root == NULL ? 0 : 1 + BTreeSize(root->left) + BTreeSize(root->right);
}

void PreOrder(struct TreeNode* root, int* ret, int* pi)
{
    if (root == NULL)
    {
        return;
    }

    ret[*pi] = root->val;
    (*pi)++;
    PreOrder(root->left, ret, pi);
    PreOrder(root->right, ret, pi);
}

int* preorderTraversal(struct TreeNode* root, int* returnSize)
{
    int size = BTreeSize(root);
    *returnSize = size;

    int* ret = (int*)malloc(sizeof(int) * size);
    int i = 0;

    PreOrder(root, ret, &i);
    return ret;
}

//226. 翻转二叉树
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
void InvertTree(struct TreeNode* root)
{
    if (root == NULL)
    {
        return;
    }

    struct TreeNode* tmp = root->left;
    root->left = root->right;
    root->right = tmp;

    if (root->left)
    {
        InvertTree(root->left);
    }

    if (root->right)
    {
        InvertTree(root->right);
    }

}

struct TreeNode* invertTree(struct TreeNode* root)
{
    InvertTree(root);
    return root;

}

//101. 对称二叉树
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

bool issym(struct TreeNode* rootleft, struct TreeNode* rootright)
{
    if (rootleft == NULL && rootright == NULL)
    {
        return true;
    }

    if (rootleft == NULL || rootright == NULL)
    {
        return false;
    }
    if (rootleft->val != rootright->val)
    {
        return false;
    }
    return issym(rootleft->left, rootright->right)
        && issym(rootleft->right, rootright->left);
}

bool isSymmetric(struct TreeNode* root)
{
    if (root == NULL)
    {
        return true;
    }
    return issym(root->left, root->right);

}

//572. 另一棵树的子树
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

bool IsSubTree(struct TreeNode* root, struct TreeNode* subRoot)
{

    if (IsSameTree(root, subRoot))
    {
        return true;
    }
    if (root == NULL)
    {
        return false;
    }

    return IsSubTree(root->left, subRoot)
        || IsSubTree(root->right, subRoot);
}

bool isSubtree(struct TreeNode* root, struct TreeNode* subRoot)
{
    return IsSubTree(root, subRoot);
}


//110. 平衡二叉树
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

int BTreeHeight(struct TreeNode* root)
{
    if (root == NULL)
    {
        return 0;
    }
    if (root->left == NULL && root->right == NULL)
    {
        return 1;
    }

    int leftheight = BTreeHeight(root->left);
    int rightheight = BTreeHeight(root->right);

    return leftheight > rightheight ? 1 + leftheight : 1 + rightheight;
}

bool IsBalanced(struct TreeNode* root)
{
    if (root == NULL)
    {
        return true;
    }

    int leftsize = BTreeHeight(root->left);
    int rightsize = BTreeHeight(root->right);
    int num = leftsize > rightsize ? leftsize - rightsize :
        rightsize - leftsize;


    if (num > 1)
    {
        return false;
    }
    return IsBalanced(root->left)
        && IsBalanced(root->right);
}

bool isBalanced(struct TreeNode* root)
{
    return IsBalanced(root);
}


