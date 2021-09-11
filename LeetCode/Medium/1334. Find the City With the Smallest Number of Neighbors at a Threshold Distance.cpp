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

Question: 1334. Find the City With the Smallest Number of Neighbors at a Threshold Distance
Topic : Graph, shortest path
Problems : https://leetcode.com/problems/find-the-city-with-the-smallest-number-of-neighbors-at-a-threshold-distance/

==============================> Explanation <=============================================
- Simple Floyd warshall.

possible:

- dijkstra
- bellman
- floyd warshall

==============================> Apporach and Time Complexity <=============================================

1) Floyd Warshall:
Time : O(N^3)
Space : O(N^2)
*/

    class Solution {
public:


int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {

    vector<vector<int>> dist(n, vector<int>(n, 10001));

    for(auto edge: edges) {
        dist[edge[0]][edge[1]] = dist[edge[1]][edge[0]] = edge[2];
    } 

    for(int i = 0; i < n; i++) {
        dist[i][i] = 0;
    }

    for(int k = 0; k < n; k++) {
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                    dist[i][j] =  min(dist[i][j], dist[i][k] + dist[k][j]);            
                }
            }
        }




    int res = 0;
    int min_count = n;
    
    for(int i = 0; i < n; i++) {

        int count = 0;
        for(int j = 0; j < n; j++) {
            if(dist[i][j] <= distanceThreshold)
                count++;
        }

        if(count <= min_count) {
            min_count = count;
            res = i;
        }
    }


    return res;
}
};