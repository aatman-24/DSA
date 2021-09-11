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

Question: 1192. Critical Connections in a Network
Topic : Graph, Tarjan, Bridge in Graph
Problems : https://leetcode.com/problems/critical-connections-in-a-network/


==============================> Explanation <=============================================
- Standard, Tarjan Algorithm for finding the bridge in graph.

==============================> Apporach and Time Complexity <=============================================

1) Tarjan Algorithm:
Time: O(N+E)(Simple DFS)
Space: O(N+E)(Graph) + O(N)(timeOfInsertion, low, visited, Aux)

*/


class Solution {
public:
    vector<vector<int>> ans;

    void dfs(int node, int parent, int timer, vector<int> &timeOfInsertion, vector<int> &low, vector<int> &visited, vector<int> adjList[]) {
        
        visited[node] = 1;

        timeOfInsertion[node] = low[node] = timer;

        timer++;

        for(auto it: adjList[node]) {

            if(it == parent) continue;

            if(!visited[it]) {

                dfs(it, node, timer, timeOfInsertion, low, visited, adjList);

                low[node] = min(low[node], low[it]);

                // It indicate that, it neighbors can not reach any previous(timer is less than current node)
                // node without help of node. So (node -> it) edge break the graph into two parts so it is
                // bridge.
                if(low[it] > timeOfInsertion[node]) {
                    ans.push_back({node, it});
                }
            }
            else{
                // If it is already visited and not parent then, it is already visited first and it timer
                // should also less than current node.
                low[node] = min(low[node], timeOfInsertion[it]);
            }
        }

    }


    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {

        vector<int> adjList[n];
        for(auto edge: connections)  {
            adjList[edge[0]].push_back(edge[1]);
            adjList[edge[1]].push_back(edge[0]);
        }

        vector<int> timeOfInsertion(n, -1), low(n, -1), visited(n, 0);
        int timer = 0;
        dfs(0, -1, timer, timeOfInsertion, low, visited, adjList);
        
        return ans;
    }
};