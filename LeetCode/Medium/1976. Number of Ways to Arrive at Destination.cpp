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

Question: 1976. Number of Ways to Arrive at Destination
Topic : Graph, Dijkstra
Problems : https://leetcode.com/problems/number-of-ways-to-arrive-at-destination/
==============================> Explanation <=============================================
- Simple Dijkstra algorithm.
With count the number of way.
==============================> Apporach and Time Complexity <=============================================


1) Dijkstra:
Time = O(E*logV + V) -> (V node added into the pq for every edge + q is not empty)
Space = O(N+E)(adjList) + O(N)(way) + O(N)(dist)

*/

#define mod 1000000007

typedef long long ll;

class Solution {
public:
   int countPaths(int n, vector<vector<int>>& roads) {

        vector<pair<ll,ll>> adjList[n];
        for(auto edge: roads) {
            adjList[edge[0]].push_back({edge[1], edge[2]});
            adjList[edge[1]].push_back({edge[0], edge[2]});
        }

        vector<ll> dist(n, LONG_MAX), ways(n, 0);
        
        priority_queue<pair<ll,ll>, vector<pair<ll,ll>>, greater<pair<ll,ll>>> q;
        q.push({0, 0}); 

        ways[0] = 1; 
        dist[0] = 0;
        
        while(!q.empty()) {

            auto [d, u] = q.top(); q.pop();
            
            if(d > dist[u]) continue; // If you don't perform it will take O(V^3 * logV)

            for(auto [v, time] : adjList[u]) {
                if(dist[v] > dist[u] + time) {
                    dist[v] = (dist[u] + time);

                    // it will go through the u node so both have same way.
                    ways[v] = ways[u];
                    q.push({dist[v], v});
                }

                // differnt path mix the way.
                else if(dist[v] == dist[u] + time) {
                    ways[v] = (ways[v] % mod + ways[u] % mod) % mod;
                }
            }

        }

        return ways[n-1] % mod;
    }
};
