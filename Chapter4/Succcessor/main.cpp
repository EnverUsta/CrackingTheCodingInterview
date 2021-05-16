#include <bits/stdc++.h>

using namespace std;

class TreeNode
{
public:
    int val;
    TreeNode *right, *left;

    TreeNode(): val(0), right{nullptr}, left{nullptr} {}
    TreeNode(int _val): val(_val), right{nullptr}, left{nullptr} {}
    TreeNode(int _val, TreeNode* _left, TreeNode* _right): val(0), right{_right}, left{_left} {}
};

TreeNode* insertTree(TreeNode* root, int val);

TreeNode* findSuccessor(TreeNode* root, TreeNode* givenNode)
{
    if(root == nullptr)     return nullptr;

    // Firstly, I am going to check whether there is or not the given node.
    // I am going to use bfs(breadth first search) to find the given node.
    queue<TreeNode*> q;
    q.push(root);

    TreeNode* currNode;
    while(!q.empty())
    {
        currNode = q.front();
        q.pop();
        // We found the given node.
        if(currNode->val == givenNode->val)
            break;

        if(currNode->left != nullptr)
            q.push(currNode->left);
        if(currNode->right != nullptr)
            q.push(currNode->right);
    }
    if(!currNode)   return nullptr;

    // After founding the given node,
    // We need to find the left-most node from the given node's right subtree.
    if(currNode->right != nullptr)
    {
        currNode = currNode->right;
        while(currNode->left != nullptr)
            currNode = currNode->left;
        return currNode;
    }
    else
        return nullptr;
}

int main()
{
    TreeNode* root = new TreeNode(10);
    root = insertTree(root, 20);
    root = insertTree(root, 5);
    root = insertTree(root, 25);
    root = insertTree(root, 3);
    root = insertTree(root, 35);

    TreeNode* successor = findSuccessor(root, root->right);
    if(successor)
        cout << successor->val << '\n';
    else
        cout << "Sorry, Your node does not have a successor node" << '\n';
}

TreeNode* insertTree(TreeNode* root, int val)
{
    // recursive exit condition
    if(root == nullptr)
    {
        return new TreeNode(val);
    }

    if(val < root->val)
        root->left = insertTree(root->left, val);
    else
        root->right = insertTree(root->right, val);

    return root;
}  