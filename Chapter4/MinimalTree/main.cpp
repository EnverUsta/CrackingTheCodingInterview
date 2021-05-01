#include <bits/stdc++.h>

using namespace std;

/*
    Q.  Given a sorted(increasing order) array with unique integer elements, write an algorithm
        to create a binary search tree with minimal height.

    Examples:
    array[] = {3, 5, 7, 10, 12}

    optimal solution:
            10
        /      \
       5         12
     /  \       /
   3      7   10

    bst: (normal adding)
                    3
                       \
                           5
                              \ 
                                7
                                  \
                                    10
                                        \
                                          12


    What if we start from middle
                     7
                  /      \
                5          10
            /                  \
        3                        12



    {3, 5, 6, 7, 10, 12, 15}

    Adding: 7, 5, 3, 6, 12, 10, 15

             7
            / \
          5     12
         / \    / \
         3   6 10  15
*/

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

void inOrderTraversal(TreeNode* root)
{
    if(root == nullptr)
        return;
    
    inOrderTraversal(root->left);
    cout << root->val << '\n';
    inOrderTraversal(root->right);
}

TreeNode* minimalTree(const vector<int>& vec, int lo, int hi)
{
    //exit recursion
    if(lo > hi)
        return nullptr;

    int mid{lo + (hi-lo)/2};

    TreeNode* newNode = new TreeNode();
    newNode->val = vec[mid];
    newNode->left = minimalTree(vec, lo, mid-1);
    newNode->right = minimalTree(vec, mid+1, hi);

    return newNode;
}

int main()
{
    vector<int> vec{0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int lo{0}, hi = vec.size()-1;
    TreeNode* root = minimalTree(vec, lo, hi);
    inOrderTraversal(root);
}