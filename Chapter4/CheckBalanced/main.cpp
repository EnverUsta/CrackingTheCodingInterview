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


pair<int, bool> checkBalanced(TreeNode* root)
{
    // recursive exit condition
    if(root == nullptr)
        return make_pair(0, true);

    auto lh = checkBalanced(root->left);
    auto rh = checkBalanced(root->right);

    if(!lh.second || !rh.second)
        return make_pair(-1, false);

    return make_pair(max(lh.first, rh.first) + 1, abs(lh.first - rh.first) <= 1);
}


/*
        10
        /\
      5     20  
     /       \
    3         25


*/
int main()
{
    TreeNode* root = new TreeNode(10);
    root = insertTree(root, 20);
    root = insertTree(root, 5);
    root = insertTree(root, 25);
    root = insertTree(root, 3);
    root = insertTree(root, 35);
    // root = insertTree(root, 45);
    // root = insertTree(root, 55);

    auto result = checkBalanced(root);

    if(!result.second)
        cout << "Your tree is not balanced" << '\n';
    else
        cout << "Your tree is balanced and maximum height is: " << result.first << '\n';
}