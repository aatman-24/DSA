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

Question: 1361. Validate Binary Tree Nodes
Topic : Graph, Tree, DFS, Union-Find
Problems : https://leetcode.com/problems/validate-binary-tree-nodes/
==============================> Explanation <=============================================
Tree can be valid,

- form single tree.
- And every node must be visited once.


1) Try to solve problem using Graph.
- DFS + Union-Find.

--> We perform the DFS with starting node(root) and check if all the node visited once or not. If
any node is visited more than one time we return false.


But Question is how to find the root node ?

--> If we start the wrong root node(suppose leaf of the tree) we can not visit all the nodes in tree
which is obvious.

--> So For that we used Union-Find. Which return the root node If the Given tree is valid if tree
 is not valid then it does not matter from where we start.

2) Try to solve problem using Tree.

- We find the indegree of every node.
- All the node except(root node) must have indegree[i] == 1. And for that root node it should be zero.
So we got the root of the tree using this logic.
- After that we count total number of node starting with root node if it is equal to the given N.
then it is valid otherwise not. Here In this step we check given tree is single or not. Because
all nodes except the root node has indegree once means we can reach all the node but need to check
weahter in single DFS or not.


==============================> Apporach and Time Complexity <=============================================


1) Graph:

Time = O(N+E)(Peforming DFS) + O(N)(Union Find)
Space = O(N+E)(adjList) + O(N)(visited) + O(N)(parent) 

2) Tree:
Time = O(N)
Space = O(N)(Indegree) + O(N)(Aux)


*/

class Solution {
public:
    
    int findParent(int u, vector<int> &parent) {
        if(parent[u] == u)
            return u;
        return parent[u] = findParent(parent[u], parent);
    }

    void union_(int u, int v, vector<int> &parent) {
        u = findParent(u, parent);
        v = findParent(v, parent);
        if(u != v)
            parent[v] = u;
    }


    int findRoot(int n, vector<int> adjList[]) {
        
        vector<int> parent(n);
        
        for(int i = 0; i < n; i++)
            parent[i] = i;

        for(int u = 0; u < n; u++) {
            for(int i = 0; i < adjList[u].size(); i++) {
                int v = adjList[u][i];
                if(v != -1) {
                    // cout << u << ' ' << v << endl;
                    union_(u, v, parent);
                }
            }
        }

        return findParent(0, parent);
    }
        
    bool dfs(int src, vector<int> &visited, vector<int> adjList[]) {

        if(src == -1) return true;

        visited[src] = 1;

        for(auto it: adjList[src]) {
                
            if(it == -1) continue;
            
            if(visited[it]) return false;

            if(!dfs(it, visited, adjList))
                return false;
        }

        return true;    
    }


        
    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {

        vector<int> adjList[n];
        for(int i = 0; i < leftChild.size(); i++) {
            adjList[i].push_back(leftChild[i]);
            adjList[i].push_back(rightChild[i]);
        }

        vector<int> visited(n, 0);
        int root = findRoot(n, adjList);
        
        if(!dfs(root, visited, adjList))
            return false;

        for(int i = 0; i < n; i++)
            if(!visited[i])
                return false;

        return true;
    }
};





class Solution {
public:
        
    int countNode(vector<int> &leftChild, vector<int> &rightChild, int root) {
        if(root == -1)
            return 0;
        return countNode(leftChild, rightChild, leftChild[root]) + countNode(leftChild, rightChild, rightChild[root]) + 1;
    }

    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {

        vector<int> indegree(n, 0);

        for(int i = 0; i < leftChild.size(); i++) {

            // all the node must have indegree equal to 1 except root node.
            if(leftChild[i] != -1 && ++indegree[leftChild[i]] > 1)
                return false;

            if(rightChild[i] != -1 && ++indegree[rightChild[i]] > 1)
                return false;
        }

        // find the root node.
        int root = -1;
        for(int i = 0; i < n; i++) {

            if(indegree[i] == 0){

                // second root occur which is not valid.
                if(root != -1) 
                    return false;

                root = i;  
            }
        }


        // no root found.
        if(root == -1) return false;

        int totalNode = countNode(leftChild, rightChild, root);

        return totalNode == n;
    }
};