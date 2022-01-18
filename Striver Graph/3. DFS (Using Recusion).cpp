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
Question : 3. DFS(Using Recusion)

/*
==============================> Explanation <=============================================
DFS -> Visit upto the Depth.

Time -> O(N+E) + O(N+E) = O(N+E). Visit all the nodes and Edge.
Space -> O(N+E)(adj List) + O(N)[visited array] = O(N+E)
*/


/*
==============================> Edge Case <=============================================

*/



void dfs(int node, vector<int> adj[], vector<int> &vis, vector<int> &dfsOrder) {

    // push back the current node into the dfsorder. mark the node as visited.
    dfsOrder.push_back(node);
    vis[node] = 1;

    // Visit the adjancent node but into the depth so call every time dfs for every
    // adjancent node.
    for(auto it: adj[node]) {
        if(!vis[it]) {
            dfd(it, adj, vis, dfsOrder);
        }
    }
}




/*
@param: adj[] -> Adjancency List.
@param: V -> Number of Nodes.
@return: bfs -> Vector of node.
*/

vector<int> dfsOfGraph(int V, vector<int> adj[]) {

    vector<int> dfsOrder;
    vector<int> vis(V+1, 0);

    // For multiple Components in Graph.
    for(int i = 1; i <= V; i++) {

        // If ith node is not visited.
        if(!vis[i]) {
            dfd(i, adj, vis, dfsOrder);
        }

    }

    return dfsOrder;
}











