#include <vector>
#include <queue>
#include <unordered_map>

using namespace std;

class Node
{
public:
    int val;
    vector<Node *> neighbors;
    Node()
    {
        val = 0;
        neighbors = vector<Node *>();
    }
    Node(int _val)
    {
        val = _val;
        neighbors = vector<Node *>();
    }
    Node(int _val, vector<Node *> _neighbors)
    {
        val = _val;
        neighbors = _neighbors;
    }
};

class Solution
{
public:
    Node *cloneGraph(Node *node)
    {
        if (!node)
        {
            return NULL;
        }

        Node *copy = new Node(node->val);
        unordered_map<Node *, Node *> mapping; // key is original node, value is copied node
        mapping[node] = copy;
        queue<Node *> q;
        q.push(node);

        while (!q.empty())
        {
            Node *curr = q.front();
            q.pop();

            for (auto neighbor : curr->neighbors)
            {
                if (mapping.find(neighbor) == mapping.end())
                {
                    mapping[neighbor] = new Node(neighbor->val);
                    q.push(neighbor);
                }
                mapping[curr]->neighbors.push_back(mapping[neighbor]);
            }
        }

        return copy;
    }
};