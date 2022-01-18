#include <bits/stdc++.h>
#define ll long long
#define REP(i,n) for(int i = 0; i < n; i++)
#define REP1(i,n) for(int i = 1; i <= n; i++)
#define debug cout << "Ok" << endl;
#define mod 1000000007

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
Question : 4. Cycle Detection using DFS.

/*
==============================> Explanation <=============================================
Cycle Detection Using DFS -> Once we found the cycle we return true, don't traverse more.

Time -> O(N+E). Visit all the nodes and Edge.
Space -> O(N+E)(adj List) + O(N)[visited array] = O(N+E)

*/


/*
==============================> Edge Case <=============================================

*/

bool checkForCycle(int node, int parent, vector<int> &vis, vector<int> adjList[]) {

    // Mark the current node as visited.
    vis[node] = 1;

    // Visit All the neighbour node of current node.
    for(auto it: adjList[node]) {

        // If it is not visited.
        if(!vis[it]){
            if(checkForCycle(it, node, vis, adjList))
                return true;
        }
        // If it is visited and not the previou(parent) node. Means there is cycle already visited
        // Nodes comes again and it is not node where we come from the current node.
        else if(it != parent)
            return true;

    }

    // Not Found.
    return false;
}


bool isCycle(int V, vector<int> adjList[]) {

    vector<int> vis(V+1,0);

    for(int i = 1; i <= V; i++) {

        if(!vis[i]) {
            if(checkForCycle(i, -1, vis, adjList))
                return true;
        }

    }

    return false;
}