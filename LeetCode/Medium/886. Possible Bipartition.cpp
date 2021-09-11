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

Question :886. Possible Bipartition
Topic : Graph, DFS, BFS, Toposort
Problems : https://leetcode.com/problems/possible-bipartition/

==============================> Explanation <=============================================
Graph is Bipartite or Not ?

- Can be solved using DFS and BFS.
Here I used DFS.


==============================> Apporach and Time Complexity <=============================================

1) DFS Bipartition:
Time = O(N+E)(AdjList)
Space = O(N)(Aux) + O(N)(color)

*/


class Solution {
public:
    bool isBipartite(int node, vector<int> adjList[], vector<int> &color) {

        if(color[node] == -1) color[node] = 0;

        for(auto it: adjList[node]) {

            if(color[it] == -1) {
                color[it] = 1 - color[node];
                if(!isBipartite(it, adjList, color))
                    return false;
            }
            else if(color[node] == color[it]) {
                return false;
            }
        }

        return true;
    }

    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {

        vector<int> adjList[n+1];

        for(auto edge: dislikes) {
            adjList[edge[0]].push_back(edge[1]);
            adjList[edge[1]].push_back(edge[0]);
        }

        vector<int> color(n+1,-1);

        for(int i = 1; i <= n; i++) {

            if(color[i] == -1) {

                if(!isBipartite(i, adjList, color)) {
                    return false;
                }  
            }

        }
        return true;
    }
};