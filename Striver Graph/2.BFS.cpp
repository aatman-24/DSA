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
Question : 2.BFS

/*
==============================> Explanation <=============================================
BFS -> Visit all the adjancent node first.

Time -> O(N+E) + O(N+E) = O(N+E). Visit all the nodes and Edge.
Space -> O(N+E)(adj List) + O(N)[visited array] + O(N)[queue] = O(N+E)
*/


/*
==============================> Edge Case <=============================================

*/


/*
@param: adj[] -> Adjancency List.
@param: V -> Number of Nodes.
@return: bfs -> Vector of node.
*/
vector<int> bfsOfGraph(vector<int> adj[], int V) {

    // Keep track of BFS.
    vector<int> bfs;

    // Mark all the nodes as unvisited.
    vector<int> vis(V+1, 0);

    // Start from every node. For Disconnect Components.
    for(int i = 1; i <= V; i++) {

        // If ith node is not visited then and only start from there.
        if(!vis[i]) {

            // Create Queue. And the current ith node and mark as visited.
            queue<int> q;
            q.push(i);
            vis[i] = 1;

            while(!q.empty()) {
                
                // Pop the front node.
                int node = q.front()
                q.pop();
                bfs.push_back(node);

                // Add its adjancent node. And mark as visited.
                for(auto it: adj[node]) {
                    q.push(it);
                    vis[it] = 1;
                }


            }

        }
    }

    // return bfs.
    return bfs;
}