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

Question: 1129. Shortest Path with Alternating Colors
Topic : Graph, BFS, Heap
Problems : https://leetcode.com/problems/shortest-path-with-alternating-colors/

==============================> Explanation <=============================================
- this is simple BFS but problem is that node incoming edge can be red or white or both. When It is
both that time using simple bfs which mark the node is not valid here. 

Because there is other edge also can be visit the same node which is valid.

- Here rathar than marking the single node we have to take care of both possiblity and node
can be marked with red edge or blue edge.

Acutally I create the graph such way that, 

red -> odd 
blue -> even

means if there is node of size n. then we create the 2*n node every node is odd and even.

0       1      2       3        4 5..
0(even) 0(odd) 1(even) 1(even).....

Then we always take care of that, red node have only blue nodes in it and blue node have only
red nodes in its adjList.

- Peform two time BFS start with 0(even) O(odd).
- take care of minDist.

==============================> Apporach and Time Complexity <=============================================

1) BFS:
Time : O(N+E)
Space : O(N+E) + O(N)
*/


class Solution {
    
public:
    
    vector<vector<int>> graph;

    void buildGraph(int n, vector<vector<int>> red_edges, vector<vector<int>> blue_edges) {

        graph.assign(2*n, vector<int>());

        // red_edge -> odd(node) -> even(node)
        for(auto edge: red_edges) {
            graph[2*edge[0] + 1].push_back(2*edge[1]+0);
        }

        // blue_edge -> even(node) -> odd(node).
        for(auto edge: blue_edges) {
            graph[2*edge[0] + 0].push_back(2*edge[1]+1);
        }

    }

    void bfs(int n, int startNode, vector<int> &dist) {

        queue<int> q;
        q.push(startNode);

        vector<int> visited(2*n, 0);
        visited[startNode] = 1;

        // keep count of level.
        int count = 0;

        while(!q.empty()) {

            int size = q.size();
            
            for(int i = 0; i < size; i++) {
                
                int node = q.front(); q.pop();

                // if the dist is minimum for the (node/2) update it.
                dist[node/2] = min(dist[node/2], count);

                for(auto it: graph[node]) {
                    if(!visited[it]) {
                        visited[it] = 1;
                        q.push(it);
                    }
                }

            }

            count++;
        }
    }



    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& red_edges, vector<vector<int>>& blue_edges) {

        buildGraph(n, red_edges, blue_edges);

        vector<int> dist(n, INT_MAX);

        bfs(n, 0, dist);
        bfs(n, 1, dist);

        for(int i = 0; i < n; i++) {
            if(dist[i] == INT_MAX) {
                dist[i] = -1;
            }
        }

        return dist;
    }
};