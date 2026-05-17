#include<iostream>
using namespace std;
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;

    Node() {}

    Node(int _val) {
        val = _val;
        left = NULL;
        right = NULL;
    }

    Node(int _val, Node* _left, Node* _right) {
        val = _val;
        left = _left;
        right = _right;
    }
};

class Solution {
public:
    void InOrderConvert(Node* cur, Node*& prev)
    {
        if (cur == nullptr)
            return;
        InOrderConvert(cur->left, prev);

        cur->left = prev;
        if (prev)
            prev->right = cur;
        prev = cur;
        InOrderConvert(cur->right, prev);
    }
    Node* treeToDoublyList(Node* root) {
        if (root == nullptr)
        {
            return root;
        }
        Node* prev = nullptr;
        InOrderConvert(root, prev);

        //找到最小节点，进行链接
        Node* head = root;
        while (head->left)
        {
            head = head->left;
        }
        head->left = prev;
        prev->right = head;
        return head;
    }

};

int main()
{

    return 0;
}