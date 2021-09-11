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

Question: 547. Number of Provinces
Topic : Graph, DFS, Connected Components.
Problems : https://leetcode.com/problems/number-of-provinces/

==============================> Explanation <=============================================
16 number.

==============================> Apporach and Time Complexity <=============================================

1) DFS:
Time = O(N^2)(DFS)
Space = O(N)(Aux)


2) Union-Find 
Time = O(alpha* N^2) -> Alpha for union find which is near to O(4). 
Space = O(200) -> Rank and Parent Array.
*/


// Using DFS.
class Solution {
public:


    void dfs(int node, vector<vector<int>>& isConnected) {
    
        for(int i = 0; i < isConnected.size(); i++) {

            if(i != node && isConnected[node][i] == 1) {

                // Delete the reverse edge i -> node. So from ith node it don't come to the current node again.
                isConnected[node][i] = 0;
                isConnected[i][node] = 0;

                dfs(i, isConnected);
            }
        }

        // Mark the current node as visited. So we don't check it again.
        isConnected[node][0] = -1;
    }


    int findCircleNum(vector<vector<int>>& isConnected) {

        int N = isConnected.size();
        int countComp = 0;

        for(int i = 0; i < N; i++) {

            if(isConnected[i][0] != -1) {
                
                countComp++;

                dfs(i, isConnected);
            }
        }
        
        return countComp;

    }

};


// Using Union-Find.

class Solution {

public:
    
    int parent[201], rank[201];


    void makeSet(int n) {
        
        for(int i = 1; i <= n; i++) {
            parent[i] = i;
            rank[i] = 0;
        }
    }


    int findParent(int node) {

        if(node == parent[node]) {
            return node;
        }

        // path compression.
        return parent[node] = findParent(parent[node]);
    }


    void union_f(int u, int v) {

        u = findParent(u);
        v = findParent(v);

        if(rank[u] < rank[v]) {
            parent[u] = v;
        }

        else if(rank[v] < rank[u]) {
            parent[v] = u;
        }
        
        else {
            parent[v] = u;
            rank[u]++;
        }   
    }


    int findCircleNum(vector<vector<int>>& isConnected) {

        int comp = 0;
        
        makeSet(isConnected.size());
      
        for(int i = 1; i <= isConnected.size(); i++) {
            for(int j = 1; j <= isConnected.size(); j++) {
                if(i != j && isConnected[i-1][j-1] == 1)
                    union_f(i, j);
            }
        }

       for(int j = 1; j <= isConnected.size(); j++) {   
           
            if(parent[j] == j){
              comp++;  
            }
        }

        return comp;
    }
};