#include<bits/stdc++.h>

using namespace std;

class GraphNode
{
public:
    char val;
    vector<GraphNode*> neighbors;

    GraphNode() : val{'0'}, neighbors{vector<GraphNode*>()}
    {}
    GraphNode(char _val) : val{_val}, neighbors{vector<GraphNode*>()}
    {}
    GraphNode(char _val, vector<GraphNode*> _neighbors) : val{_val}, neighbors{_neighbors}
    {}
};

void insert(GraphNode* node1, GraphNode* node2);
vector<GraphNode*> createGraph(vector<char> projects, vector<pair<char, char>> dependencies);
GraphNode* findNode(vector<GraphNode*> nodes, char val);

void helper(GraphNode* start, vector<bool> &isVisited, vector<char> &resultOrder)
{
    for(auto node : start->neighbors)
    {
        if(!isVisited[node->val - 'a'])
        {
            isVisited[node->val - 'a'] = true;
            helper(node, isVisited, resultOrder);
            resultOrder.push_back(node->val);
        }
       
    }

   if(!isVisited[start->val - 'a'])
   {
        resultOrder.push_back(start->val);
        isVisited[start->val - 'a'] = true;
   }
}

vector<char> buildOrder(vector<GraphNode*> nodes)
{
    vector<bool> isVisited(nodes.size()+1, false);
    vector<char> resultOrder;
    for(auto node : nodes)
        helper(node, isVisited, resultOrder);
    return resultOrder;
}

int main()
{
    vector<GraphNode*> nodes;
    vector<char> projects = {'a', 'b', 'c', 'd', 'e', 'f'};
    vector<pair<char, char>> dependencies = {{'a', 'd'}, {'f', 'b'}, {'b', 'd'}, {'f', 'a'}, {'d', 'c'}};

    nodes = createGraph(projects, dependencies);
    auto result = buildOrder(nodes);
    for(auto ch : result)
        cout << ch << '\n';
}

vector<GraphNode*> createGraph(vector<char> projects, vector<pair<char, char>> dependencies)
{
    vector<GraphNode*> resultGraph;
    for(auto ch : projects)
        resultGraph.push_back(new GraphNode(ch));

    for(int i = 0; i < dependencies.size(); i++)
    {
        GraphNode* node1 = findNode(resultGraph, dependencies[i].first);
        GraphNode* node2 = findNode(resultGraph, dependencies[i].second);
        insert(node2, node1);
    }

    return resultGraph;
}

GraphNode* findNode(vector<GraphNode*> nodes, char val)
{
    for(auto node : nodes)
        if(node->val == val)
            return node;
}

void insert(GraphNode* node1, GraphNode* node2)
{
    node1->neighbors.push_back(node2);
}