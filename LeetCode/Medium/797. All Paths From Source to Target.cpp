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

Question: 797. All Paths From Source to Target
Topic : Graph, DFS, BACKTRACKING
Problems : https://leetcode.com/problems/all-paths-from-source-to-target/
==============================> Explanation <=============================================
- DFS with Backtracking.
Visit all possible way and check at last wheather we reach at the end node or not.


==============================> Apporach and Time Complexity <=============================================

1) DFS:

Time = O(2^(N-2)) -> For (N-1)(Except SRC and Target) node, Either we add it or not into the current path.
Space = O(N)(Aux) + O(N)(To store current path)

           

*/


class Solution {
public:
    
    
    vector<vector<int>> ans;


    void dfs(int src, vector<int> &visited, vector<int> &path, vector<vector<int>>& graph) {


        visited[src] = 1;
        path.push_back(src);

        for(auto it: graph[src]) {

            if(visited[it] == 0) {
                dfs(it, visited, path, graph);
            }
        }

        if(src == graph.size() - 1) {
            ans.push_back(path);
        }

        
        visited[src] = 0;
        path.pop_back();
    }


    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {

        int N = graph.size();

        vector<int> visited(N,0);

        vector<int> path;

        dfs(0, visited, path, graph);

        return ans;
    }
};