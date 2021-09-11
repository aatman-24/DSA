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

Question: 802. Find Eventual Safe States
Topic : Graph, TopoSort, DFS, Cycle Detection
Problems : https://leetcode.com/problems/find-eventual-safe-states/
==============================> Explanation <=============================================

Idea is that -> Any node don't have any cycle from any of its neighbor then and only it is safe.

- 1)

Intuition is that, all the node whose outdegree is zero is directly into the solution. 

- Now we have to find the node i such that, after removing edge (i, j) (j is safe node which has
out degree zero.) outdegree[i] become zero then it is also safe node.

- So Doing above step, we need find such node i we used topological sort. But we use the 
reverse of graph which become indegree for that graph.

- For current graph it become outdegree. I named outdegree here so don't confuse it is just
indegree of reverse of graph. 

All the node whose outdegree[i] == 0 become our solution.(indegree[i] == 0 for reverse of graph).


2) DFS cycle Detection in Directed Graph Variant
- Modify such that all the neighbor node does not have any cycle then and only we add into answer.





==============================> Apporach and Time Complexity <=============================================

1) Topological Sort:

Time = O(N+E)
Space = O(N+E)(Reverse Graph) + O(N) (Queue) + O(N)(Outdegree)

           
2) Cycle Detection in Directed Graph Variant :

Time: O(N + E)
Space: O(N)(Visited) + O(N)(Aux) + O(dfsVisited)

*/

class Solution {
public:

    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {

        int n = graph.size();

        vector<int> outDegree(n,0);

        vector<int> reverseGraph[n];

        for(int i = 0; i < graph.size(); i++) {
            for(auto it : graph[i]) {
                reverseGraph[it].push_back(i);
                outDegree[i]++;
            }
        }


        queue<int> q;
        for(int i = 0; i < n; i++)
            if(outDegree[i] == 0)
                q.push(i);


        vector<int> ans;
        while(!q.empty()) {

            int node = q.front(); q.pop();
            ans.push_back(node);

            for(auto it: reverseGraph[node]) {
                outDegree[it]--;
                if(outDegree[it] == 0) {
                    q.push(it);
                }
            }
        }

        sort(ans.begin(), ans.end());

        return ans;
    }
};



class Solution {
public:
    bool hasLoop(int src, vector<int> &visited, vector<int> &dfsVisited, vector<vector<int>> &adjList, vector<int> &ans) {

        visited[src] = 1;
        dfsVisited[src] = 1; 

        for(auto it: adjList[src]) {

            if(!visited[it]) {

                if(hasLoop(it, visited, dfsVisited, adjList, ans)) {
                    return true;
                }
            }
            else if(dfsVisited[it]) {
                return true;
            }
        }

        ans.push_back(src);
        dfsVisited[src] = 0;

        return false;
    }

    vector<int> eventualSafeNodes(vector<vector<int>>& adjList) {

        vector<int> ans;
        vector<int> visited(adjList.size(), 0), dfsVisited(adjList.size(), 0);

        for(int i = 0; i < adjList.size(); i++) {

            if(visited[i] == 0) {
                hasLoop(i, visited, dfsVisited, adjList, ans);
            }

        }

        sort(ans.begin(), ans.end());
        return ans;
    }
};


