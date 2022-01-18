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
Question : 9. Topological Sort (DFS).

/*
==============================> Explanation <=============================================
Topological Sort:

For the DAG(Directed Acycalic Graph) contain the edge u -> v in graph. Then in Topolocial sort u comes
first and after that v node.

- Why DFS ?

- DFS make the all u -> v for all the adjancent node of u. When the current node(v) does not have any
adjancent node we push into the stack. and return to the previous call where we push the node u into
the stack. 

- In short first v goes to the stack after u. So overall we maintain the order.





Time -> O(N+E). Visit all the nodes and Edge.
Space -> O(N+E)(adj List) + O(N)[visited] + O(N)[stack] = O(N+E)
Auxiliary Space -> O(N) (Recursive call)
*/


/*
==============================> Edge Case <=============================================

*/


void findTopoSort(int node, int[] vis, stack<int> &st, vector<int> adj[]) {

    // Mark the current node as visited.
    vis[node] = 1;

    for(auto it: adjList[node]) {
        if(!vis[it]) {
            findTopoSort(node, vis, st, adj);
        }
    }

    // Push the current node into the stack after the all adjancent node is visited.
    // So Doing this, It gurantee that if there is edge u -> v. First V is push into the stack
    // and after the u node.
    st.push(node);
}


vector<int> topoSort(int N, vector<int> adjList[]) {

    int vis[N];

    // Keep track of topoSort Order. (LIFO)
    stack<int> st;
    memset(vis, 0, sizeof(vis));

    for(int i = 0; i < N; i++) {
        if(!vis[i]) {
            findTopoSort(i, vis, st, adjList) {
        }
    }

    vector<int> topolocialOrder;

    // We emptyt the stack which containt the topological Sort.
    while(!st.empty()) {
        topolocialOrder.push_back(st.top());
        st.pop();
    }
}