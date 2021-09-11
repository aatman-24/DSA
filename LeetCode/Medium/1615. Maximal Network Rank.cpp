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

Question: 1615. Maximal Network Rank
Topic : Graph
Problems : https://leetcode.com/problems/maximal-network-rank/
==============================> Explanation <=============================================
- Finding Outdegree the make the pair of node and find max outdegree sum of both if there is
common edge subtract it.

==============================> Apporach and Time Complexity <=============================================

1) Dijkstra + DFS:
Time = O(E*logV + V) + O(V + E)(DFS)
Space = O(N+E)(adjList) + O(N)(way) + O(N)(dist) + O(N)


1) Dijkstra:
Time = O(E*logV + V) 
Space = O(N+E)(adjList) + O(N)(way) + O(N)(dist)

*/

class Solution {

public:

    int maximalNetworkRank(int n, vector<vector<int>>& roads) {

        vector<int> outdegree(n, 0);
        
        int graph[n][n];
        memset(graph, 0, sizeof(graph));

        for(auto edge: roads) {
            
            graph[edge[0]][edge[1]] = 1;
            graph[edge[1]][edge[0]] = 1;
            
            outdegree[edge[0]]++;
            outdegree[edge[1]]++;
        }

        int ans = 0;

        // Loop all the pairs O(N^2)
        for(int node = 0; node < n; node++) {
            for(int it = node + 1; it < n; it++) {

                    int rank;
                    rank = outdegree[node] + outdegree[it];

                    // If there is common edge subtract it.
                    if(graph[node][it])
                        rank--;

                    ans = max(ans, rank);
                }
            }
        return ans;
    }
};