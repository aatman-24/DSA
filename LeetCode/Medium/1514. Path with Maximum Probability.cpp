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

Question: 1514. Path with Maximum Probability
Topic : Graph, BFS, Heap
Problems : https://leetcode.com/problems/path-with-maximum-probability/ted/

==============================> Explanation <=============================================
- Visit all the node as BFS manner but the high probablity node visit first then low.


==============================> Apporach and Time Complexity <=============================================

1) BFS + Heap:
Time : O(E * log E)
Space : O(N+E) + O(N)

*/


class Solution {

    public:
    
    double maxProbability(int n, vector<vector<int>>& edge, vector<double>& succProb, int start, int end) {

        // Create a Graph.
        vector<pair<int,double>> adjList[n];    
        for(int i = 0; i < edge.size(); i++) {
            adjList[edge[i][0]].push_back({edge[i][1], succProb[i]});
            adjList[edge[i][1]].push_back({edge[i][0], succProb[i]});
        }


        // Visited Array.
        vector<int> visited(n, 0);

        // PQ to store the <proba, node>. Max Heap.
        priority_queue<pair<double,int>, vector<pair<double,int>>> pq;

        // Push the start node into pq.
        pq.push({1.0, start});

        while(!pq.empty()) {

            // Get the node which has more probality.
            auto pn = pq.top(); pq.pop();

            // mark as visited.
            visited[pn.second] = 1;

            // If it is end return the probablity.
            if(pn.second == end) {
                return pn.first;
            }

            // Visit its adjacent node and into the heap by mulitiplying current probablity * its own probablity.
            for(auto it: adjList[pn.second]) {
                if(!visited[it.first]) {
                    pq.push({pn.first * it.second, it.first});
                }
            }
        }

        return 0.0;
    }
};