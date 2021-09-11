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

Question: 684. Redundant Connection
Topic : Graph, DFS, UNION-FIND
Problems : https://leetcode.com/problems/redundant-connection/
==============================> Explanation <=============================================
- Idea is that,

Start make the graph using given edge. But when single component have two node u and v. And
if current edge is u -> v or v -> u means it is extra it already in single connected
component then why you need to add that edge ? (So this edge can be your answer).

- Find the last such edge in your graph.


Answer Edge: Edge which is join two node from single component is your answer. 



How to find it is from single component or not ?
- Check both parent is same or not.




==============================> Apporach and Time Complexity <=============================================

1) DFS : Peform DFS For edges.size() times. Every time perform edge[i] is not added into 
the graph. If you visit all the Node it means edge[i] is extra edge.

Time = O(M * (N + E)) ; M = edges.size(), N+E = DFS for AdjList.
Space = O(N+E)(AdJList) + O(N)(Aux)

2) UNION - FIND:
Time = O(M * 4 * alpah);    M = Given edges 
Space = O(M);            

*/


class Solution {

public:

    /* Union - Find */

    int parent[1001], rank[1001];


    void makeSet(int n) {

        for(int i = 1; i <= 1000; i++) {
            parent[i] = i;
            rank[i] = 0;
        }
    }


    int findParent(int node) {
        if(node == parent[node])
            return node;

        return parent[node] = findParent(parent[node]);
    }

        
     void union_(int u, int v, int &src, int &tar) {

        int uParent = findParent(u);
        int vParent = findParent(v);

        // Here What mean of uParent == vParent ?
        // -> If both Parent are same it means it is already a part of single connected 
        // componets. Given (u, v) is extra edge because already u and v are connected. 

        if(uParent == vParent) {
            src = u, tar = v;
        }

        if(rank[uParent] < rank[vParent]) {
            parent[uParent] = vParent;
        }
        else if(rank[vParent] < rank[uParent]) {
            parent[vParent] = uParent;
        }
        else {
            parent[vParent] = uParent;
            rank[uParent]++;
        }

    }

    /* ------ */


    vector<int> findRedundantConnection(vector<vector<int>>& edges) {

        makeSet(1001);
        
        // Resulatant edge.
        int src, tar;

        for(int i = 0; i < edges.size(); i++) {
            union_(edges[i][0], edges[i][1], src, tar);
        }

        vector<int> edge = {src, tar};

        return edge;
    }
};