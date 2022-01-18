#include <bits/stdc++.h>
#define unsigned long long long long
#define REP(i,n) for(unsigned long long i = 0; i < n; i++)
#define REP1(i,n) for(unsigned long long i = 1; i <= n; i++)
#define debug cout << "Ok" << endl;
#define mod 1000000007

using namespace std;


    
/*
==============================> Description <=============================================
Question : 18 Bridges in Graph _ Cut Edge
==============================> Explanation <=============================================

Brideges Found in the Graph...

When the current node adjacent node can not reach to any previous of current node without
using (node -> it) edge.

so we checking that,

    low[it] > timeofInsertion[node]. (Bridge)


    low[it] indicate what is minimum timer node can be reach by it(node).
    timeOfInsertion[node] -> insertion time of node. 

Perform DFS.

Time = O(N+E)(DFS)
Space = O(N)(insertionTime) + O(N)(low) + O(N)(visited) + O(N)(Aux) = O(N)

==============================> Edge Case <=============================================


*/

void dfs(int node, int parent, int &timer, vector<int> &timeOfInsertion, vector<int>& low, vector<int>& visited) {

    // mark the current node as visited.
    visited[node] = 1;

    // timeofInsertion and low of current node is atleast timer.
    timeOfInsertion[node] = low[node] = timer;

    // Increase the timer.
    timer++;

    // For all its adjacentNode.
    for(auto it: adjList[node]) {

        // Don't go to the parent again.
        if(it == parent) continue;

        if(!visited[it]) {

            dfs(it, node, timer, timeOfInsertion, low, visited);
            
            // low[node] is minimum of low of current node and its adjancent node.
            low[node] = min(low[node], low[it]);

            // First of all current node is comes first into the dfs and after its adjacent node.
            // So if low[it] > timeOfInsertion[node] that means its adjancent node have no 
            // any other way (except node -> it) to go into the above graph. It means disconneting
            // this edge form the cycle. (bridge)

            // if (low[it] < timeOfInsertion[node]) mean its adjacent node it have the way
            // instead of the (node -> it) to go into above graph then and only it
            // contains low[it] < timeOfInsertion[node].

            // if(low[it] == timeOfInsertion[node]) current node is starting node of any dfs 
            // cycle.

            if(low[it] > timeOfInsertion[node]) {
                cout << node << " " << it << endl;
            }
        }   
        else {

            // when the it is already visited that means it adjancent is already visited
            // so it containt the lowest value which is timeOfInsertion[it].

            low[node] = min(low[node], timeOfInsertion[it]);
        }
    }



}



int main() {

    int N, M;
    cin >> N >> M;
    vector<int> adjList[N];
    for(int i = 0; i < M; i++){
        int u, v;
        cin >> u >> v;
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }


    // Time Of Insertion mean when the node is visited.
    vector<int> timeOfInsertion(N, -1);

    // What is lowest time node can be reach by the ith node.
    vector<int> low(N, -1);


    vector<int> visited(N, 0);
    int timer = 0;

    for(int i = 0; i < N; i++) {

        if(!visited[i]) {
            dfs(node, -1, timer, timeOfInsertion, low, visited);
        }
    }

    return 0;
}