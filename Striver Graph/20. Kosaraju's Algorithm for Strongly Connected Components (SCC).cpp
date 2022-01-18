#include <bits/stdc++.h>
#define unsigned long long long long
#define REP(i,n) for(unsigned long long i = 0; i < n; i++)
#define REP1(i,n) for(unsigned long long i = 1; i <= n; i++)
#define debug cout << "Ok" << endl;
#define mod 1000000007

using namespace std;


    
/*
==============================> Description <=============================================
Question : 20. Kosaraju's Algorithm for Strongly Connected Components (SCC)
==============================> Explanation <=============================================

- Strongly Connected Componets(SCC) of graph is set of nodes, if you pick any node then from that set
you can go to all the nodes into the set from that node.

- Idea behind Kosaraju's Algortihm,

= 1 -> 2, For this graph this is not SCC. So How to find SCC ?
-> If we start DFS into reverse order(2 then 1). If we can go 2 to 1 then there is SCC otherwise not.

= 1 -> 2 -> 1 (only 2 node).
-> DFS in Forward = 1 -> 2
-> DFS in Reverse = 2 -> 1.
Means 1 and 2 is in Single SCC.

In short, -> Try DFS from the starting time(normal) and then reverse time(last visit node first) then all
the set which is same in both there are all SCC.


Kosaraju's Algorithm works on the same idea,

1) Sort all nodes in order of finish time. (Topological Sort). (We need That Stack)
2) Take Transpose of Graph. (if node u -> v edge, now v -> u).
3) Perform DFS again on transpose graph, Whatever you get in single path DFS that all are SCC.

Time = O(N+E)(Topo sort) + O(N+E)(Transpose of Graph) + O(N+E)(Reverse Graph DFS) = O(N+E)
Space = O(N+E)(Transpose of Graph) + O(N)(Visited)

Question ?
-> If we reverse the stack and then perfrom DFS on main Graph then it should give the same result ?
-> Answer is no, Reaosn is that after reversing the stack whatever is on top it maybe okay
to start DFS with it. But it neighbour(dfs path) nodes are not okay because it maybe in 
last in stack.

- Follow This algorithm for SCC. 

==============================> Edge Case <=============================================

*/


void dfs(int node, stack<int> &st, int visited[], vector<int> adjList[]) {
    visited[node] = 1;
    for(auto it: adjList[node]) {
        if(!visited[it]) {
            dfs(it, st, visited, adjList);
        }
    }
    st.push(node);
}


void revDFS(int node, int visited[], vector<int> adjListTranspose[]) {
    visited[node] = 1;
    cout << node << ' ';
    for(auto it: adjListTranspose[node]) {
        if(!visited[it]) {
            dfs(it, visited, adjListTranspose);
        }
    }
}


int main() {
    
    // Adjacency List
    int n, m;
    cin >> n >> m;
    vector<int> adjList[n];
    for(int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adjList[u].push_back(v);
    }

    int visited[n] = {0};
    stack<int> st;

    // Topological Sort.
    for(int i = 0; i < n; i++) {
        if(!visited[i]) {
            dfs(i, st, visited, adjList);
        }
    }


    // We have Stack Filled in finishing time manner. (topo stack)
    // Let's first create Transpose of Graph.
    vector<int> adjListTranspose[n];
    for(int i = 0; i < n; i++) {

        // Make all nodes unvisited so that it can be used in next DFS cycle.
        visited[i] = 0;

        for(auto it: adjList[i]) {
            adjListTranspose[it].push_back(i);
        }
    }


    // Perform DFS on Transpose of Graph Using topo Stack. (top of stack has finishing time greater).
    cout << "SCC: " << endl;
    while(!st.empty()) {

        int node = st.top();

        if(!visited[node]) {
            revDFS(node, visited, adjListTranspose);
            cout << endl;
        }
    }
}