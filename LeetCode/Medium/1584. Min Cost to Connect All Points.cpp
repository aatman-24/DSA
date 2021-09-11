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

Question: 1584. Min Cost to Connect All Points
Topic : Prims, Kruskal, MST
Problems : https://leetcode.com/problems/min-cost-to-connect-all-points/

==============================> Explanation <=============================================
- Graph Creation + Finding MST.

Finding MST can be possible using (PRIMS + Krushkal) Both.

For N Points -> E = N^2 Edge possible.

Can be solved using prims also.



==============================> Apporach and Time Complexity <=============================================

1) Kruskal Algorithm:
Time: O(K * logE) -> K number of edge popped before we reach all the nodes. 
Space: O(E)(Aux)

*/



class Solution {
public:
    
    int parent[1001];

    int findParent(int u) {
        if(parent[u] == u)
            return u;
        return parent[u] = findParent(parent[u]);
    }

    void union_(int u, int v) {
        u = findParent(u);
        v = findParent(v);
        if(u != v) {
            parent[v] = u;
        }
    }

    int getDistance(int i, int j, vector<vector<int>> &points) {
        return abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1]);
    }

    int minCostConnectPoints(vector<vector<int>>& points) {

        int n = points.size();
        
        for(int i = 0; i < n; i++)
            parent[i] = i;
        
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;

        for(int i = 0; i < points.size(); i++) {
            for(int j = i + 1; j < points.size(); j++) {
                pq.push({getDistance(i, j, points), i, j});
            }
        }

        int V = 0, mst = 0;

        while(V != n - 1) {

            auto it = pq.top(); pq.pop();
            int d = it[0], u = it[1], v = it[2];

            int parentOfU = findParent(u);
            int parentOfV = findParent(v);

            if(parentOfU != parentOfV) {
                            
                union_(u, v);
                mst += d;
                V++;
            }
            
            
        }

        return mst;
    }
};