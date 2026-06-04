#include<iostream>
using namespace std;

  //Definition for a binary tree node.
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
    int calculateDepth(TreeNode* root) {
        if (root == nullptr)
            return 0;

        int lefthight = calculateDepth(root->left) + 1;
        int righthight = calculateDepth(root->right) + 1;


        return lefthight > righthight ? lefthight : righthight;
    }
};

int main()
{

    return 0;
}