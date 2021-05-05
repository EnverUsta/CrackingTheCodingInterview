#include <bits/stdc++.h>

using namespace std;

/*
    Q. List of Depths.
        Given a binary tree, design an algorithm which creates a linked list of all the nodes 
        at each depth (e.g. If you have a tree with depth D, you'll have D linked lists).
*/

class TreeNode
{
public:
    int val;
    TreeNode *right, *left;

    TreeNode(): val(0), right{nullptr}, left{nullptr} {}
    TreeNode(int _val): val(_val), right{nullptr}, left{nullptr} {}
    TreeNode(int _val, TreeNode* _left, TreeNode* _right): val(0), right{_right}, left{_left} {}
};

class ListNode
{
public:
    int val;
    ListNode* next;

    ListNode(): val{0}, next{nullptr} {}
    ListNode(int _val): val{_val}, next{nullptr} {}
    ListNode(int _val, ListNode* _next): val{_val}, next{_next} {}
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


void insert(ListNode** root, int val)
{
    ListNode* temp = new ListNode(val);
    temp->next = *root;
    *root = temp;
}

vector<ListNode*> listOfDepths(TreeNode* root)
{
    vector<ListNode*> result;
    queue<TreeNode*> q;
    q.push(root);

    int count{1};
    int depth{0};
    while(!q.empty())
    {
        TreeNode* extracted = q.front();
        q.pop();

        if(result.size() <= depth)
            result.push_back(new ListNode(extracted->val));
        else
            insert(&result[depth], extracted->val);

        if(extracted->left != nullptr)
            q.push(extracted->left);
        if(extracted->right != nullptr)
            q.push(extracted->right);

        count--;
        if(count == 0)
        {
            depth++;
            count = q.size();
        }
    }

    return result;
}

void printList(ListNode* root)
{
    ListNode* iter = root;

    while(iter != nullptr)
    {
        cout << iter->val << '\n';
        iter = iter->next;
    }
}

int main()
{
    TreeNode* root = new TreeNode(10);
    root = insertTree(root, 33);
    root = insertTree(root, 11);
    root = insertTree(root, 2);
    root = insertTree(root, 101);
    root = insertTree(root, 102);

    ListNode* l_root = new ListNode(10);
    insert(&l_root, 20);
    insert(&l_root, 30);


    vector<ListNode*> returnedList = listOfDepths(root);

    int depth{0};
    for(auto list : returnedList)
    {
        cout << "depth " << depth << ":" << '\n';
        printList(list);
        depth++;
    }

    delete[] root;
    delete[] l_root;
}
