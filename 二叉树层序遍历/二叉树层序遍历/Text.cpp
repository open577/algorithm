#include<iostream>
#include<queue>
#include<vector>
using namespace std;

 struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
    
};


class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> vv;
        //根为空
        if (root == nullptr)
        {
            return vv;
        }
        //根不为空

        queue<TreeNode*> Node;
        int LevelSize = 1;
        Node.push(root);
        while (!Node.empty())
        {
            vector<int> v;
            while (LevelSize--)
            {
                TreeNode* front = Node.front();
                v.push_back(front->val);
                Node.pop();

                if (front->left)
                {
                    Node.push(front->left);
                }

                if (front->right)
                {
                    Node.push(front->right);
                }
            }
            LevelSize = Node.size();
            vv.push_back(v);
        }
        return vv;
    }
};
int main()
{

    return 0;
}