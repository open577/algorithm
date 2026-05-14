#include<iostream>
using namespace std;


 struct TreeNode {
     int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };
 
 class Solution {
 public:
     /*bool Isintree(TreeNode* root, TreeNode* cur)
     {
         if (root == nullptr)
             return false;

         if (root == cur)
         {
             return true;

         }

         return Isintree(root->left, cur) ||
             Isintree(root->right, cur);*/

     bool Isintree(TreeNode* root, TreeNode* x)
     {
         if (root == nullptr)
             return false;
         return root == x
             || Isintree(root->left, x)
             || Isintree(root->right, x);
     }
     TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {

         if (root == nullptr)
         {
             return nullptr;
         }

         if (p == root || q == root)
         {
             return root;
         }

         bool pinleft, pinright, qinleft, qinright;

         pinleft = Isintree(root->left, p);
         pinright = !pinleft;

         qinleft = Isintree(root->left, q);
         qinright = !qinleft;

         if ((pinleft && qinright) || (pinright && qinleft))
         {
             return root;
         }

         else if (pinleft && qinleft)
         {
             return lowestCommonAncestor(root->left, p, q);
         }

         else
             return lowestCommonAncestor(root->right, p, q);

     }
 };
 int main()
 {

     return 0;
 }
