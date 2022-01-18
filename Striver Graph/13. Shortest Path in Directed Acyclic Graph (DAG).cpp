#include <bits/stdc++.h>
#define unsigned long long long long
#define REP(i,n) for(unsigned long long i = 0; i < n; i++)
#define REP1(i,n) for(unsigned long long i = 1; i <= n; i++)
#define debug cout << "Ok" << endl;
#define mod 1000000007

using namespace std;



/*
==============================> Description <=============================================
Question : 13. Shortest Path in Directed Acyclic Graph (DAG).

/*
==============================> Explanation <=============================================
- this algorithm only work for the DAG Graph.

STEP 1: Find topsort. Stack is needed from here.
STEP 2: Using stack perform distance relaxing.


Why It works ?
- Toposort visit all the node which does not have any other node dependency. So by doing that we find 
all the nodes which can be reach by from the source node. And node which can not reach by the source node
is popped from the stack first and after that source is popped.

- And once any node distance is calculated(it is not INT_MAX) then we can use this node as intermidatory
for others once. The node which is not reached by the source node distance is INT_MAX so it can never
used as intermidatory node. 

Time -> O(N+E)(Topo sort) + O(N+E)(Distance Relaxing). Visit all the nodes and Edge.
Space -> O(N)[distance] + O(N)[stack] + O(N)[Visited]= O(N)
Auxiliary Space -> True.

*/


/*
==============================> Edge Case <=============================================

*/

    

// pair<int,int> = {neighbour_node, edge_weight}
void findTopoSort(int node, int vis[], stack<int> &st, vector<pair<int,int>> adjList[]) {

    // Mark the current node as visited.
    vis[node] = 1;

    for(auto it: adjList[node]) {

        // If its neighbour is not visited.
        if(!vis[it.first]) {
            findTopoSort(it.first, vis, st, adjList);
        }
    } 

    // add into stack after all its adjancent node inserted into the stack.
    st.push(node);

}




void shortestPath(int src, int N, vector<pair<int,int>> adjList[]) {

    // Find the toposort. So we can use its stack for finding the shortest path.
    int vis[N] = {0};
    stack<int> st;
    for(int i = 0; i < N; i++)
        if(!vis[i])
            findTopoSort(i, vis, st, adjList)



    // Finding the shortest path using that stack.
    int dist[N];
    for(int i = 0; i < N; i++) dist[i] = INT_MAX;

    // source node distance zero.
    dist[src] = 0;

    while(!st.empty()) {

        int node = st.top(); st.pop();

        // If current node is already visited first then and only it can be intermidatory node for others.
        if(dist[node] != INT_MAX){

            for(auto it: adjList[node]) {

                // distance relaxing.
                if(dist[node] + it.second < dist[it.first])
                    dist[it.first] = dist[node] + it.second;
            }   
        }



    }

    // print the distance.
    for(int i = 0; i < N; i++)
        cout << dist[i] << ' ';

}