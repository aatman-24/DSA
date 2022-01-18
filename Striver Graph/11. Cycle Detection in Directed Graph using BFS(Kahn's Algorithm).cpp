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
Question : 11. Cycle Detection in Directed Graph using BFS(Kahn's Algorithm).

/*
==============================> Explanation <=============================================
Topological Sort:

For the DAG(Directed Acycalic Graph) contain the edge u -> v in graph. Then in Topolocial sort u comes
first and after that v node.

- So we know that Kahn's Algorithm for finding the Topological Sort it works For the DAG graph. So we
use this logic.

-What we do is we try to find the Topo sort for the Given Graph. And keep track of visited Node(marked node)
which is added into the topologicalSortOrder. 

-So it is clear that if there is Cycle into the graph then all nodes is not going to added into the
topologicalSortOrder because all the node which is in cycle its indegree never became zero so never
push into the queue.

- So if it visit all node means there is no cycle otherwise there is cycle.

Looks like we used Contradicition.





Time -> O(N+E). Visit all the nodes and Edge.
Space -> O(N+E)(adj List) + O(N)[indegree] + O(N)[queue] = O(N+E)
Auxiliary Space -> O(N) (Recursive call)

*/


/*
==============================> Edge Case <=============================================

*/

bool isCyclic(int N, vector<int> adjList[]) {

    queue<int> q;

    // Contains the Indegree Of Node.
    vector<int> indegree(N, 0);

    // Count the Indegree of Node.
    for(int i = 0; i < N; i++) {
        for(auto it: adjList[i]) {
            indegree[i]++;
        }
    }

    // Put all the Node whose Indegree is zero.
    for(int i = 0; i < N; i++) {
        if(indegree[i] == 0)
            q.push(i);
    }

    int cnt = 0;

    while(!q.empty()) {

        int node = q.front();
        q.pop();

        topoLogicalOrder.push_back(node);

        // Keep Visited Node.
        cnt++;

        // For current node u remove all the edge with its neighbour means decreae the indegree
        // for neighbour node.
        for(auto it: adjList[node]) {
            indegree[it]--;

            // If it is zero add into the queue.
            if(indegree[it] == 0)
                q.push(it);
        }
    }

    if(cnt == N)
        return true;

    return false;

}