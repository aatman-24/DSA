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
Question : 10. Topological Sort (BFS) | Kahn's Algorithm.

/*
==============================> Explanation <=============================================
Topological Sort:

For the DAG(Directed Acycalic Graph) contain the edge u -> v in graph. Then in Topolocial sort u comes
first and after that v node.

- Why It Works?

- So when Indrgree is 0. Means It can become u. (for u -> v). Current node did not have any dependency.
- So we can add that node into the topologicalOrder.



Time -> O(N+E). Visit all the nodes and Edge.
Space -> O(N+E)(adj List) + O(N)[indegree] + O(N)[queue] = O(N+E)
Auxiliary Space -> O(N) (Recursive call)

*/


/*
==============================> Edge Case <=============================================

*/


vector<int> topoSort(int N, vector<int> adjList[]) {

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

    vector<int> topoLogicalOrder;

    while(!q.empty()) {

        int node = q.front();
        q.pop();

        topoLogicalOrder.push_back(node);

        // For current node u remove all the edge with its neighbour means decreae the indegree
        // for neighbour node.
        for(auto it: adjList[node]) {
            indegree[it]--;

            // If it is zero add into the queue.
            if(indegree[it] == 0)
                q.push(it);
        }
    }



    return topoLogicalOrder;
}