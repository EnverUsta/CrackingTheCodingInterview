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

pair<int, bool> helperMine(TreeNode* root)
{
    bool initLeft = false;
    bool initRight = false;
    pair<int, bool> left;
    pair<int, bool> right;

    if(root->left != nullptr)
    {
        left = helperMine(root->left);
        initLeft = true;
    }
    if(root->right != nullptr)
    {
        right = helperMine(root->right);
        initRight = true;
    }

    // If we detect invalid value in children,
    // return false
    if(initLeft && !left.second)
        return make_pair(-1, false);
    else if(initRight && !right.second)
        return make_pair(-1, false);

    // Control whether everything is okay or not
    if(initLeft && initRight)
    {
        if(left.first <= root->val && right.first >= root->val)
            return make_pair(root->val, true);
        else
            return make_pair(-1, false);
    }
    // when only have left child
    else if(initLeft)
    {
        if(left.first <= root->val)
            return make_pair(root->val, true);
        else
            return make_pair(-1, false);
    }
    // when only have right child
    else if(initRight)
    {
        if(right.first >= root->val)
            return make_pair(root->val, true);
        else
            return make_pair(-1, false);
    }
    // when our node does not have any children
    else
        return make_pair(root->val, true);
}

bool validateBSTMine(TreeNode* root)
{
    auto pair = helperMine(root);
    return pair.second;
}


// This solution makes much more sense :)
bool helper(TreeNode* root, int min, int max)
{
    if(root == nullptr)
        return true;

    if(root->val < min || root->val > max)
        return false;

    return helper(root->left, min, root->val-1) && helper(root->right, root->val+1, max);
}

bool validateBST(TreeNode* root)
{
    int minI = std::numeric_limits<int>::min();
    int maxI = std::numeric_limits<int>::max();

    return helper(root, minI, maxI);
}

int main()
{
    TreeNode* root = new TreeNode(10);
    // root->left = new TreeNode(11);
    root = insertTree(root, 15);
    root = insertTree(root, 5);
    root = insertTree(root, 7);
    root = insertTree(root, 3);
    root = insertTree(root, 12);

    cout << validateBST(root) << '\n';
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