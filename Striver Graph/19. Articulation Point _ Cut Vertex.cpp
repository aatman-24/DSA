#include <bits/stdc++.h>
#define unsigned long long long long
#define REP(i,n) for(unsigned long long i = 0; i < n; i++)
#define REP1(i,n) for(unsigned long long i = 1; i <= n; i++)
#define debug cout << "Ok" << endl;
#define mod 1000000007

using namespace std;


    
/*
==============================> Description <=============================================
Question : 19. Articulation Point _ Cut Vertex
==============================> Explanation <=============================================

Articulation Point in the graph,

When Perform the DFS, If node is current node and its adjacent node is it. Then current node
become the articulation point if its adjacent node it can not reach the prvious node of
current node (without going through the current node) that mean current node is articulation
point. (Except the root).

    - if low[adjacentNode] >= timeOfInsertion[node] && parent == -1 (Except root)
            node is articulation point.

    - And for the root. (if root have individual child more than one) then root is
    articulation point.




What is differce between Bridges and articulation point into condition ?
- In Bridge,

    low[adjacentNode] > timeOfInsertion[node]

- In Articulation Point,
    
    low[adjacentNode] >= timeOfInsertion[node] (check equal sign)


Why ?

- So in bridge the adjacent node can reach to the previous node of current node, or to
the current node then it is okay. (node -> adjacent) edge is not used but some other edge
is used to reach to the node or previous node.

- but in the articulation point, if adjacent node reach to the previous node without using
current node so it must be less than timeOfinsertion of current node. If 
low[adjacentNode] == timeOfInsertion[node]. It mean that adjancentNode can reach only to
the node. so if node is removed then can also graph is divided into parts. That's why
equal sign.

Perform DFS.

Time = O(N+E)(DFS)
Space = O(N)(insertionTime) + O(N)(low) + O(N)(visited) + O(N)(Aux) + O(N)(isArticulation) = O(N)

==============================> Edge Case <=============================================


*/

void dfs(int node, int parent, int &timer, vector<int> &timeOfInsertion, vector<int>& low, vector<int> &isArticulationPoint, vector<int>& visited) {

    // mark the current node as visited.
    visited[node] = 1;

    // timeofInsertion and low of current node is atleast timer.
    timeOfInsertion[node] = low[node] = timer;

    // Increase the timer.
    timer++;

    // count the individual child.
    int count = 0;

    // For all its adjacentNode.
    for(auto it: adjList[node]) {

        // Don't go to the parent again.
        if(it == parent) continue;

        if(!visited[it]) {

            dfs(it, node, timer, timeOfInsertion, low, visited);

            count++;
            
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

            if(low[it] >= timeOfInsertion[node] && parent != -1) {
                isArticulationPoint[node] = 1;
            }
        }   
        else {

            // when the it is already visited that means it adjancent is already visited
            // so it containt the lowest value which is timeOfInsertion[it].

            low[node] = min(low[node], timeOfInsertion[it]);
        }
    }

    if(parent == -1 && child > 1) {
        isArticulationPoint[node] = 1;
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

    // For the DFS.
    vector<int> visited(N, 0);
    
    // Hashing of Articulation point.
    vector<int> isArticulationPoint(N,0);

    int timer = 0;

    for(int i = 0; i < N; i++) {

        if(!visited[i]) {
            dfs(node, -1, timer, timeOfInsertion, low, isArticulationPoint, visited);
        }
    }


    for(int i = 0; i < N; i++){
        if(isArticulationPoint(i)) {
            cout << i << endl;
        }
    }

    return 0;
}