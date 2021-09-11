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

Question :785. Is Graph Bipartite?
Topic : Graph, DFS, BFS
Problems : https://leetcode.com/problems/is-graph-bipartite/

==============================> Explanation <=============================================
- Striver Video: (6) and (7).
- Used Color to mark color and also visited or not.
- On greedy manner if once color is assigned then next time it can not change. So if
two neighbor have same color means it is not Bipartite.

==============================> Edge Case <=============================================

DFS:
1) Time = O(N+E)
   Space = O(N)(Aux) + O(N)(color)

BFS:

1) Time = O(N+E)(AdjList)
   Space = O(N)(Queue) + O(N)(color)
*/


// DFS 
class Solution {
public:
    bool dfs(int node, vector<int> &visited, vector<int> &color, vector<vector<int>>& adjList) {

        visited[node] = 1;
        if(color[node] == -1) color[node] = 0;

        for(auto it: adjList[node]) {

            if(!visited[it]) {
                color[it] = 1 - color[node];
                if(!dfs(it, visited, color, adjList))
                    return false;
            }
            else if(color[node] == color[it]) {
                return false;
            }
        }

        return true;
    }


    bool isBipartite(vector<vector<int>>& graph) {

        int N = graph.size();
        vector<int> visited(N, 0), color(N, -1);

        for(int i = 0; i < N; i++) {

            if(!visited[i]) {

                if(!dfs(i, visited, color, graph))
                    return false;
            }


        }
        return true;
    }
};



// BFS
class Solution {
public:
    bool isBipartiteBFS(int src, vector<int> &color, vector<vector<int>>& adjList) {

        queue<int> q;
        q.push(src);

        color[src] = 0;

        while(!q.empty()) {

            int node = q.front(); q.pop();

            for(auto it: adjList[node]) {

                if(color[it] == -1) {
                    color[it] = 1 - color[node];
                    q.push(it);
                }
                else if (color[it] == color[node]){
                    return false;
                }

            }
        }

        return true;
    }



    bool isBipartite(vector<vector<int>>& graph) {

        int N = graph.size();

        vector<int> color(N, -1);

        for(int i = 0; i < N; i++) {

            if(color[i] == -1) {
                if(!isBipartiteBFS(i, color, graph))
                    return false;
            }
        }    

        return true;
    }


};