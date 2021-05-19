#include <bits/stdc++.h>

using namespace std;

class TreeNode
{
public:
    int val;
    TreeNode *left, *right;

    TreeNode(): val{0}, left{nullptr}, right{nullptr} 
    {}
    TreeNode(int _val) : val{_val}, left{nullptr}, right{nullptr}
    {}
    TreeNode(int _val, TreeNode* _left) : val{val}, left{_left}, right{nullptr}
    {}
    TreeNode(int _val, TreeNode* _left, TreeNode* _right) : val{val}, left{_left}, right{_right}
    {}
};

bool covers(TreeNode* root, TreeNode* p)
{
    if(root == nullptr) return false;

    if(root == p)   return true;

    return covers(root->left, p) || covers(root->right, p);
}

TreeNode* commonAncestorHelper(TreeNode* root, TreeNode* p, TreeNode* q)
{
    if(root == nullptr || root == p || root == q)
        return root;

    bool isPLeft = covers(root->left, p);
    bool isQLeft = covers(root->left, q);

    TreeNode* childSide;
    if(isPLeft && isQLeft)
        childSide = root->left;
    else if(!isPLeft && !isQLeft)
        childSide = root->right;
    else
        return root;
    
    commonAncestorHelper(childSide, p, q);
}

TreeNode* commonAncestor(TreeNode* root, TreeNode* p, TreeNode* q)
{
    if(!covers(root, p) && !covers(root, q))    
        return nullptr;
    
    commonAncestorHelper(root, p, q);
}

TreeNode* insertTree(TreeNode* root, int val);

int main()
{
    TreeNode* root = new TreeNode(6);
    root = insertTree(root, 2);
    root = insertTree(root, 3);
    root = insertTree(root, 4);
    root = insertTree(root, 5);
    root = insertTree(root, 8);
    root = insertTree(root, 10);
    root = insertTree(root, 9);
    root = insertTree(root, 11);

    TreeNode* p = root->right->right->right;
    TreeNode* q = root->right->right->left;

    TreeNode* result = commonAncestor(root, p, q);
    cout << result->val << '\n';
}

TreeNode* insertTree(TreeNode* root, int val)
{
    // recursive exit condition
    if(root == nullptr)
        return new TreeNode(val);

    if(val < root->val)
        root->left = insertTree(root->left, val);
    else
        root->right = insertTree(root->right, val);

    return root;
}