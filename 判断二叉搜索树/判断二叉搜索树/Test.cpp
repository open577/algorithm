#include<iostream>
using namespace std;
//*
// * Definition for a binary tree node.
  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };
 
class Solution {
public:
    //前序遍历
    TreeNode* parent = nullptr;
    bool isValidBST(TreeNode* root) {

        //地柜结束条件
        if (root == nullptr)
            return true;

        //递归检查左子树
        if (!isValidBST(root->left))
            return false;

        if (parent != nullptr && root->val <= parent->val)
            return false;

        parent = root;
        return isValidBST(root->right);

    }
};

int main()
{

    return 0;
}