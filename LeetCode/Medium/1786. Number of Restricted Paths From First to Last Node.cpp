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

Question: 1786. Number of Restricted Paths From First to Last Node
Topic : Graph, Dijkstra
Problems : https://leetcode.com/problems/number-of-restricted-paths-from-first-to-last-node/
==============================> Explanation <=============================================
Simple Dijkstra but calculate the distance from (n -> 1).

1) Peform Dijkstra + DFS(to count ways)

2) Single pass Dijkstra. (Idea from 1976. Number of Ways to Arrive at Destination)

==============================> Apporach and Time Complexity <=============================================

1) Dijkstra + DFS:
Time = O(E*logV + V) + O(V + E)(DFS)
Space = O(N+E)(adjList) + O(N)(way) + O(N)(dist) + O(N)


1) Dijkstra:
Time = O(E*logV + V) 
Space = O(N+E)(adjList) + O(N)(way) + O(N)(dist)

*/

#define mod 1000000007

typedef pair<long,long> ii;


class Solution {
public:

    void dijkstra(int src, vector<ii> adjList[], vector<long> &dist) {

        priority_queue<ii, vector<ii>, greater<ii>> pq;

        pq.push({0, src});
        dist[src] = 0;

        while(!pq.empty()) {

            auto [d, u] = pq.top(); pq.pop();
            
            if(dist[u] < d) continue;

            for(auto it: adjList[u]) {
                
                int v = it.first, wt = it.second;
                      
                if(dist[v] > dist[u] + wt) {
                    
                    dist[v] = dist[u] + wt;
                
                    pq.push({dist[v], v});
                }
            }
        }

    }

    int dfs(int src, vector<long> &dist, vector<long> &ways, vector<ii> adjList[]) {

        if(src == ways.size() - 1) {
            return 1;
        }

        if(ways[src] != -1)
            return ways[src];
        
        int ans = 0;

        for(auto it: adjList[src]) {

 
            if(dist[src] > dist[it.first]) {
                ans =  (ans % mod + dfs(it.first, dist, ways, adjList) % mod) % mod;
            }
        }

        return ways[src] = ans;

    }



    int countRestrictedPaths(int n, vector<vector<int>>& edges) {

        vector<ii> adjList[n+1];
        for(auto edge: edges) {
            adjList[edge[0]].push_back({edge[1], edge[2]});
            adjList[edge[1]].push_back({edge[0], edge[2]});
        }

        vector<long> dist(n+1, LONG_MAX);
        dijkstra(n, adjList,dist);
    
        for(auto it: dist) {
            cout << it << endl;
        }

        vector<long> ways(n+1, -1);
        int x = dfs(1, dist, ways, adjList);
    
        
        return ways[1];
    }
};



#define mod 1000000007

typedef pair<long,long> ii;


class Solution {
public:
    int countRestrictedPaths(int n, vector<vector<int>>& edges) {

        vector<ii> adjList[n+1];
        for(auto edge: edges) {
            adjList[edge[0]].push_back({edge[1], edge[2]});
            adjList[edge[1]].push_back({edge[0], edge[2]});
        }

        vector<long> dist(n+1, LONG_MAX), ways(n+1, 0);
        priority_queue<ii, vector<ii>, greater<ii>> pq;

        pq.push({0, n});
        dist[n] = 0; ways[n] = 1;

        while(!pq.empty()) {

            auto [d, u] = pq.top(); pq.pop();
            
            if(dist[u] < d) continue;

            for(auto it: adjList[u]) {
                
                int v = it.first, wt = it.second;
                      
                if(dist[v] > dist[u] + wt) {
                    
                    dist[v] = dist[u] + wt;
                
                    pq.push({dist[v], v});
                }
                

                // Here you can calculate the way, if dist[v] > dist[u] then  it is possible to
                // to count this path v -> u.
                if(dist[v] > dist[u]) {
                    ways[v] = (ways[v] % mod + ways[u] % mod) % mod;
                }
            }
        }

        return ways[1];
    }
};

