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

Question: 1971. Find if Path Exists in Graph
Topic : Graph, DFS, BFS, Union-Find.
Problems : https://leetcode.com/problems/find-if-path-exists-in-graph/

==============================> Explanation <=============================================
- Can be solved Using DFS, BFS and Union-Find also.

==============================> Apporach and Time Complexity <=============================================

1) DFS
Time: O(N+E)
Space: O(N+E) + O(N)

*/


class Solution {
public:
    bool dfs(int src, int target, vector<int> &visited, vector<int> adjList[]) {
        visited[src] = 1;

        if(src == target)
            return true;

        for(auto it: adjList[src]) {
            if(!visited[it]) {
                if(dfs(it, target, visited, adjList))
                    return true;
            }
        }

        return false;
    }

    bool validPath(int n, vector<vector<int>>& edges, int start, int end) {
        vector<int> adjList[n];
        for(auto edge: edges) {
            adjList[edge[0]].push_back(edge[1]);
            adjList[edge[1]].push_back(edge[0]);
        }
        vector<int> visited(n, 0);
        return dfs(start, end, visited, adjList);
    }
};