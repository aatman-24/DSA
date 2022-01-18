#include <bits/stdc++.h>
#define unsigned long long long long
#define REP(i,n) for(unsigned long long i = 0; i < n; i++)
#define REP1(i,n) for(unsigned long long i = 1; i <= n; i++)
#define debug cout << "Ok" << endl;
#define mod 1000000007

using namespace std;



/*
==============================> Description <=============================================
Question : 12. Shortest Path in Undirected Graph with Unit Weights.

/*
==============================> Explanation <=============================================
- Weight is not given then take 1 as weight.

- BFS + Greedy.

Why BFS Work ?
- We start with src node and BFS gurantee that it always visit the nearest node first then and only
farest node. It is level order. So If intermidatory node distance is already set by algorithm
then that node can be intermidatory for other node to calculate distance.


Time -> O(N+E). Visit all the nodes and Edge.
Space -> O(N+E)(adj List) + O(N)[distance] + O(N)[queue] = O(N)

*/


/*
==============================> Edge Case <=============================================

*/




void BFS(vector<int> adjList[], int N, int src) {

    // Distance Array and set with  maximum distance.
    int dist[N];
    for(int i = 0; i < N; i++) dist[i] = INT_MAX;

    // set source node dist as zero.
    dist[src] = 0;
    
    // Queue for BFS.
    queue<int> q;
    q.push(src);

    while(!q.empty()) {

        int node = q.front(); q.pop();

        // For every adjacent node of current node.
        for(auto it: adjList[node]) {

            // If distance of current it node is less using current node as intermidate node then set
            // distance using node as intermidatory.

            // Relaxing the distance.
            if(dist[node] + 1 < dist[it]) {
                dist[it] = dist[node] + 1;
                q.push(it);
            }

        }
    }


    for(int i = 0; i < N; i++)
        cout << dist[i] << ' ';

    cout << endl;
}