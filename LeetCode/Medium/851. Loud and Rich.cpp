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

Question: 851. Loud and Rich
Topic : Graph, Directed DFS
Problems : https://leetcode.com/problems/loud-and-rich//
==============================> Explanation <=============================================
Idea is that,

If answer[x] = y, then find all the node which has more money than x -> find the node whose
quiteness is lowest.

1) So first create a graph adjList such that a -> [] give all the node which has higher value than
a.

2) Find smallest Quiteness using Directed dfs.


One thing notice that, I don't used dfsVisited[] for Directed Graph DFS. Reason is that in question
given that there is no node such that, a is greater than b and b is greater than a such condition
hold. That means there is no cycle. That's why only visited[] is used.




==============================> Apporach and Time Complexity <=============================================

1) Directed Graph DFS with Optimization:

Time = O(N+E)
Space = O(N)(Visited) + O(N)(Aux)

*/


class Solution {
public:

    int dfs(int src, vector<int> &visited, vector<int> adjList[], vector<int> &quiet, vector<int> &ans) {

        // Mark src node as visited.
        visited[src] = 1;

        // All nodes has maximum Quiteness itself.
        int min_QIndex = src;

        for(auto it: adjList[src]) {
            
            int index;

            // If it is not visited, then find it quiteness first 
            // which can be part of making decision for current node.
            if(!visited[it]) {
                index = dfs(it, visited, adjList, quiet, ans);
            }
            // If it is already visited then we directly take it that value. (Optimization).
            else
                index = ans[it];
            
            // Take which ever is small.
            if(quiet[min_QIndex] > quiet[index])
                    min_QIndex = index; 

        }

        // put into value.
        ans[src] = min_QIndex;

        // Return min_QIndex so that it can be part in decision of parent quiteness.
        return min_QIndex;
    }



    vector<int> loudAndRich(vector<vector<int>>& richer, vector<int>& quiet) {

        int n = quiet.size();

        // Create a Graph.
        vector<int> adjList[n+1];


        // If [a, b] given a has more money than b. Then we make edge b -> a. 
        // So at last if b -> [n1, n2] it indicate that all the nodes n1, n2 has more money
        // than b. So when we find more money nodes then we just need to traverse the graph.
        for(auto edge: richer) {
            adjList[edge[1]].push_back(edge[0]);
        }

        vector<int> visited(n, 0), ans(n, 0);

        for(int i = 0; i < n; i++) {
            if(visited[i] == 0)
                int k = dfs(i, visited, adjList, quiet, ans);
        }

        return ans;
    }
};