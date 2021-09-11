#include <bits/stdc++.h>
#define ll long long
#define REP(i,n) for(int i = 0; i < n; i++)
#define REP1(i,n) for(int i = 1; i <= n; i++)
#define debug cout << "Ok" << endl;
#define mod 1000000007
#define eps 1e-6

using namespace std;


typedef pair<ll,ll> ii;
typedef vector<ii> vii;
typedef map<char,int> mci;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<vi> vvi;
typedef map<int,int> mii;


/*
==============================> Description <=============================================

Question : 133. Clone Graph
Topic : 2-D matrix Path
Problems : https://leetcode.com/problems/clone-graph/
==============================> Explanation <=============================================


==============================> Edge Case <=============================================

DFS:
1) Time = O(N+E) (AdjList)
   Space = O(N)(Aux) + O(N)(Hashing)

BFS:

1) Time = O(N+E) (AdjList)
   Space = O(N)(Queue) + O(N)(Hashing)
*/


class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};


// DFS
class Solution {
public:
    
    Node* cloneGraph(Node* node, vector<Node*> &visited) {

        if(node == nullptr) return node;
        
        // make new node of given node.
        Node* node_copy = new Node(node->val);

        // put into the hash.
        visited[node->val] = node_copy;


        for(auto it: node->neighbors) {
            
            // if it neighbor is not visited yet.
            if(visited[it->val] == nullptr) {

                // create it neighbor node first.
                Node* neighbor_it = cloneGraph(it, visited);
                
            }

            // then push it newly created neighbor into adjlist of current copy node.
            node_copy->neighbors.push_back(visited[it->val]);    
        }
            
        return node_copy;
    }

    // DFS
    Node* cloneGraph(Node* node) {

        // used vector<Node*> for hashing because maximum node is 100.
        vector<Node*> visited(101, nullptr);

        return cloneGraph(node, visited);
    }
};



// DFS using map.
class Solution {
public:

    Node* cloneGraph(Node* node) {

        if (!node) {
            return NULL;
        }

        if (copies.find(node) == copies.end()) {
            copies[node] = new Node(node -> val, {});
            for (Node* neighbor : node -> neighbors) {
                copies[node] -> neighbors.push_back(cloneGraph(neighbor));
            }
        }
        return copies[node];
    }
private:
    unordered_map<Node*, Node*> copies;
};


// BFS using map + queue.
class Solution {
public:

    Node* cloneGraph(Node* node) {
        
        if (!node) {
            return NULL;
        }

        copies[node] = new Node(node -> val);

        // For BFS create Queue of Original Node.
        queue<Node*> q;
        q.push(node);


        
        while (!q.empty()) {
            
            Node* cur = q.front();
            q.pop();

            for (Node* neighbor : cur -> neighbors) {

                if (copies.find(neighbor) == copies.end()) {
                    copies[neighbor] = new Node(neighbor -> val, {});
                    q.push(neighbor);
                }

                // new_node -> neighbours.push_back(new_neighbors)
                // push back its neighbor which is created above.
                copies[cur] -> neighbors.push_back(copies[neighbor]);
            }
        }
        return copy;
    }
private:
    unordered_map<Node*, Node*> copies;
};


