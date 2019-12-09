/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
#include<bits/stdc++.h>
using namespace std;
void mirrorBT(TreeNode* root){
    if(root==NULL)
        return;
    mirrorBT(root->left);
    mirrorBT(root->right);
    TreeNode* temp = root->left;
    root->left = root->right;
    root->right = temp;
}
int isIdentical(TreeNode* a,TreeNode* b){
    if(a==NULL && b==NULL)
        return true;
    if(a!=NULL && b!=NULL){
        return a->val==b->val && isIdentical(a->left,b->left) && isIdentical(a->right,b->right);
    }
    return false;
}
int Solution::isSymmetric(TreeNode* A){
    TreeNode* mirror = A;
    mirrorBT(mirror);
    return isIdentical(A,mirror);
}
