#include<iostream>
using namespace std;


 /** Definition for a binary tree node.*/
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
    int TreeHight(TreeNode* root)
    {
        if (root == nullptr)
        {
            return 0;
        }

        return max(TreeHight(root->left), TreeHight(root->right)) + 1;
    }
    bool isBalanced(TreeNode* root) {
        if (root == nullptr)
            return true;

        int lefthight = TreeHight(root->left);
        int rightheight = TreeHight(root->right);

        if (abs(lefthight - rightheight) > 1)
            return false;

        return isBalanced(root->left) && isBalanced(root->right);
    }
};

int main()
{

    return 0;
}