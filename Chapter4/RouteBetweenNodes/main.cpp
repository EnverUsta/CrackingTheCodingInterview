#include <bits/stdc++.h>

using namespace std;

/*
    Q.  Given a directed graph, design an algorithm to find out whether there is a route
        between two nodes.
*/

// Let's assume directed graph
class Node
{
public:
    int val;
    vector<Node*> neighbors;

    Node() : val{0}, neighbors{vector<Node*>()}
    {}
    Node(int _val) : val{_val}, neighbors{vector<Node*>()}
    {}
    Node(int _val, vector<Node*> _neighbors) : val{_val}, neighbors{_neighbors}
    {}
};

void insert(Node* a, Node* b)
{
    a->neighbors.push_back(b);
}


// These dfs and bfs algoritms are just reminders.
// Yes, sometimes I forget their implementations :(
void dfs(Node* start, vector<bool>& visited)
{
    if(start == nullptr)    return;
    
    visited[start->val] = true;
    cout << start->val << '\n';
    for(auto node : start->neighbors)
    {
        if(visited[node->val] == false)
            dfs(node, visited);
    }
}

void bfs(Node* start, vector<bool> visited)
{
    queue<Node*> q;
    q.push(start);
    visited[start->val] = true;

    while(!q.empty())
    {
        Node* currNode = q.front();
        q.pop();
        cout << currNode->val << '\n';

        for(auto node : currNode->neighbors)
        {
            if(visited[node->val] == false)
            {
                q.push(node);
                visited[node->val] = true;
            }
        }
    }
}


bool routeBetweenNodes(Node* a, Node* b)
{
    vector<bool> visited(4, false);
    queue<Node*> q;
    q.push(a);
    visited[a->val] = true;

    while(!q.empty())
    {
        auto currNode = q.front();
        q.pop();
        
        for(auto node : currNode->neighbors)
        {
            if(node == b)
                return true;
            if(!visited[node->val])
            {
                q.push(node);
                visited[node->val] = true;
            }
        }
    }

    return false;
}


int main()
{
    Node* a = new Node(1);
    Node* b = new Node(2);
    Node* c = new Node(3);
    Node* d = new Node(4);
    int numberOfNodes = 4;
    vector<bool> visited(numberOfNodes+1, false);

    insert(a, b);
    insert(a, c);
    insert(b, c);
    insert(c, a);

    cout << "DFS: " << '\n';
    dfs(a, visited);

    visited.assign(numberOfNodes+1, false);
    cout << "BFS: " << '\n';
    bfs(a, visited);


    cout << "Route Between Nodes:" << '\n';
    if(routeBetweenNodes(a, b))
        cout << "There is a root between " << a->val << " and " << b->val << '\n';
    else
        cout << "There is no root" << '\n';
}