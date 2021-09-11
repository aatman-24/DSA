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

Question: 1466. Reorder Routes to Make All Paths Lead to the City Zero
Topic : Graph
Problems : https://leetcode.com/problems/reorder-routes-to-make-all-paths-lead-to-the-city-zero/    
==============================> Explanation <=============================================
- Finding Outdegree the make the pair of node and find max outdegree sum of both if there is
common edge subtract it.

==============================> Apporach and Time Complexity <=============================================

1) BFS Without Cycle(Given Problem):
Time = O(N+E)(BFS)
Space = O(N+E)

Can be solved using DFS also.

2) BFS With Cycle:
Time = O(N+E) (Performed DFS of level 1 and then BFS if it is not visited)
              (If you think what overall peformed is visit all the node which take O(N+E)).
Space = O(N+E)

*/

class Solution {
public:
    int minReorder(int n, vector<vector<int>>& connections) {

        // adjList (node, edge_wt) for parent -> child(1)(direct) and child -> parent(0)(reverse).
        vector<pair<int,int>> adjList[n];
        for(auto edge: connections) {
            adjList[edge[0]].push_back({edge[1], 1});
            adjList[edge[1]].push_back({edge[0], 0});
        }

        vector<bool> visited(n, false);

        queue<pair<int,int>> q;
        q.push({0, 0});

        int change = 0;

        while(!q.empty()) {
            
            auto [node, wt] = q.front(); q.pop();
            visited[node] = true;
            change += wt;

            for(auto it: adjList[node]) {
                if(!visited[it.first]) {
                    q.push(it);
                }
            }
        }

        return change;
    }

};


class Solution {
public:

    void bfs(int src, vector<bool> &visited, vector<int> adjList[]) {

        queue<int> q;
        q.push(src);

        while(!q.empty()) {
            int node = q.front(); q.pop();
            visited[node] = true;
            for(auto it: adjList[node]) {
                if(!visited[it]) {
                    q.push(it);
                }
            }
        }
       
    }

    int minReorder(int n, vector<vector<int>>& connections) {

        // Make both graph.
        vector<int> graph[n], rgraph[n];

        for(auto edge: connections) {
            graph[edge[0]].push_back(edge[1]);
            rgraph[edge[1]].push_back(edge[0]);
        }


        vector<bool> visited(n, false);
            
        // Peform BFS which mark all the node whose come to the zero initialy.
        bfs(0, visited, rgraph);
       
        int count = 0;

        // Node for each node check that if its adjacent is not visited yet. count it
        // (reverse the edge) and pefrom BFS from that node so all the node which can come to 
        // that node are visited. 
        for(int i = 0; i < n; i++) {
            for(auto it: graph[i]) {
                if(!visited[it]) {
                    count++;
                    bfs(it, visited, rgraph);
                }
            }
        }

        return count;
    }
};