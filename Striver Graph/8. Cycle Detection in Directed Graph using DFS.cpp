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
Question : 8. Cycle Detection in Directed Graph using DFS.

/*
==============================> Explanation <=============================================
What is major differnce between the DFS of Directed and Undirected Graph ?

-> So In Un-Directed Graph there is no edge so we can go to any direction witout restriction. But in
Directed Graph there is restriction. 

In directed Graph there is cycle if and only if current DFS call again visit current DFS marked Node.
Otherwise If the Node is visited by someother DFS route then it is not Cycle.


1 -> 2 -> 3 
     |    |
     4 -> 5

2 -> 4 -> 5 -> 3(Visited) (DFS call 1)
2 -> 3 (Already Visited) but it is not cycle. (DFS call 2)

Because both are diffrent DFS call. 

- So handle this issue we used other array which keep track of On call DFS, which node is visited and
backtrack(mark it again 0) if we return from the call.


Time -> O(N+E). Visit all the nodes and Edge.
Space -> O(N+E)(adj List) + O(N)[visited] + O(N)[dfs-call] = O(N+E)

*/


/*
==============================> Edge Case <=============================================

*/

bool checkCycle(int node, vector<int> adjList[], int vis[], int dfsVis[]) {

    vis[node] = 1;

    // Mark the currnet node as on call visited.
    dfsVis[node] = 1;

    for(auto it: adjList[node]) {

        if(!vis[it]) {
            if(checkCycle(it, adjList, vis, dfsVis)) {
                return true;
            }
        }

        // check wheather its neighbour is visited on call or not.
        else if(dfsVis[it] == 1)
            return true;

    }

    // backtrack, mark on call DFS node as unvisited.
    dfsVis[node] = 0;
    return false;
}



bool isCyclic(int N, vector<int> adjList[]) {

    int vis[N], dfsVis[N];
    memset(vis, 0, sizeof(vis));
    memset(dfsVis, 0, sizeof(dfsVis));

    for(int i = 0; i < N; i++) {
        if(!vis[i]) {
            if(checkCycle(i, adjList, vis, dfsVis)) {
                return true;
            }
        }
    }

    return false;
}