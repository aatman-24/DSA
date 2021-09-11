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

Question: 1319. Number of Operations to Make Network Connected
Topic : Graph, Union-Find
Problems : https://leetcode.com/problems/number-of-operations-to-make-network-connected/

==============================> Explanation <=============================================
- Count the number of component in the graph.
If component is N then N - 1 edge needed.

- Check extra edge by, parent[i] == parent[j] then, i -> j is the extra edge.

Compare, needed <= extra_edge return needed.
else return -1.


==============================> Apporach and Time Complexity <=============================================

1) DFS with Extra Visited Array:
Time : O(N^2)
Space : O(N^2) + O(N^2)(Aux)

1) DFS:
Time: O(N^2)
Space: O(N^2)(Aux)

*/

class Solution {
public:

    int findParent(int u, int parent[]) {
        if(parent[u] == u)
            return u;
        return parent[u] = findParent(parent[u], parent);
    }

    int union_(int u, int v, int parent[]) {

        u = findParent(u, parent);
        v = findParent(v, parent);

        if(u != v) {
            parent[v] = u;
            return 0;
        }

        return 1;
    }


    int makeConnected(int n, vector<vector<int>>& connections) {

        int parent[n];
        for(int i = 0; i < n; i++) parent[i] = i;


        int extra_edge = 0;
        for(auto edge: connections) {
            extra_edge += union_(edge[0], edge[1], parent);
        }

        int need_edge = 0;
        for(int i = 0; i < n; i++) {
            if(parent[i] == i)
                need_edge++;
        }

        // main component should be not counted.
        need_edge--;

        if(extra_edge >= need_edge)
            return need_edge;

        return -1;
    }
};  