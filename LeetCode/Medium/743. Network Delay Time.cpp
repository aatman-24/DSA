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

Question: 743. Network Delay Time
Topic : Graph, Dijskra, BellmanFord
Problems : https://leetcode.com/problems/network-delay-time/
==============================> Explanation <=============================================
- DFS with Backtracking.
Visit all possible way and check at last wheather we reach at the end node or not.


==============================> Apporach and Time Complexity <=============================================

1) BellmanFord:

Time = O(N*E)
Space = O(N) (dist array)

           
2) Dijkstra:

Time: O(N + E) * O(logN) = O(E * logN)
Space: O(N + E)(adj) + O(N)(dist array)

*/


// Belleman-Ford Algorithm
class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int N, int K) {
        vector<int> dist(N + 1, INT_MAX);
        dist[K] = 0;
        for (int i = 0; i < N; i++) {
            for (vector<int> e : times) {
                int u = e[0], v = e[1], w = e[2];
                if (dist[u] != INT_MAX && dist[v] > dist[u] + w) {
                    dist[v] = dist[u] + w;
                }
            }
        }

        int maxwait = 0;
        for (int i = 1; i <= N; i++)
            maxwait = max(maxwait, dist[i]);
        return maxwait == INT_MAX ? -1 : maxwait;
    }
};



// Dijkstra algorithm.
class Solution {
public:

    int networkDelayTime(vector<vector<int>>& times, int n, int k) {

        vector<pair<int,int>> adjList[n+1];

        for(vector<int> edge: times) {
            adjList[edge[0]].push_back({edge[1], edge[2]});
        }

        // Priority Queue.
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;

        // Dist Matrix.
        int distTo[n+1];

        // Set distance maximum.
        for(int i = 1; i <= n; i++) distTo[i] = INT_MAX;

        // Set Src node distance 0.
        distTo[k] = 0;

        // put a pair into priority queue.
        pq.push({0, k});



        while(!pq.empty()) {

            // Best Node At Given Instance of Time.
            int best_node = pq.top().second;
            pq.pop();

            // Visit all its neighbor and perform edge relaxing.
            for(auto it: adjList[best_node]) {     // O(E)

                if(distTo[it.first] > distTo[best_node] + it.second) {
                    distTo[it.first] = distTo[best_node] + it.second;
                
                    // Put into the queue.
                    pq.push({distTo[it.first], it.first}); // O(logV) -> O(E * logV)
                }
            }
        }

        int maximum_time = 0;
        for(int i = 1; i <= n; i++) {
            maximum_time = max(maximum_time, distTo[i]);
        }

        return maximum_time == INT_MAX ? -1 : maximum_time;
    }
};


