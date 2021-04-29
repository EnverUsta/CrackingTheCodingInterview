#include <bits/stdc++.h>

using namespace std;

/*
    Q. write code to remove duplicates from an unsorted linked list.
       How would you solve if a temporary buffer is not allowed.
*/

class ListNode
{
public:
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int v) : val{v}, next{nullptr} {}
    ListNode(int v, ListNode* next) : val{v}, next{next} {}
};

ListNode* tail = nullptr;

// O(1)
void insert(ListNode* l1, int data)
{
    if(l1 == nullptr)
    {
        l1 = new ListNode(data);
        tail = l1;
    }
    else
    {
        if(tail == nullptr)
            tail = l1;
        
        tail->next = new ListNode(data);
        tail = tail->next;
        
   }
}   

void print(ListNode* l1)
{
    ListNode *iter = l1;
    while(iter != nullptr)
    {
        cout << iter->val << '\n';
        iter = iter->next;
    }
}

// time-complexity: O(n)
// space-complexity: O(n)
void removeDups(ListNode* l1)
{
    if(l1 == nullptr)
        return;

    unordered_set<int> set;
    ListNode* prev = l1;
    ListNode* curr = l1->next;

    // 1 -> 1 -> 1 -> 3 -> 5 -> 3 =>>>  (prev)1->(curr)3->5->3
    // set = {1, }
    set.insert(prev->val);
    while(curr != nullptr)
    {
        // Element has already been added
        // If this is the case, we should delete this element.
        if(set.find(curr->val) != set.end())
        {
            ListNode* willBeDeleted = curr;
            curr = curr->next;
            delete willBeDeleted;
            prev->next = curr;
        }

        // everything is going normal
        else
        {
            set.insert(curr->val);
            prev = curr;
            curr = curr->next;
        }
    }
}

int main()
{
    // 10(l1) -> nullptr
    ListNode* l1 = new ListNode(10); 
    insert(l1, 10);
    insert(l1, 20);
    insert(l1, 20);
    insert(l1, 30);
    insert(l1, 40);
    insert(l1, 50);

    cout << "Before duplicates: " << '\n';
    print(l1);
    removeDups(l1);
    cout << "\n After Duplicates: " << '\n';
    print(l1);
}
