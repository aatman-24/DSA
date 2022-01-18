#include <bits/stdc++.h>
#define unsigned long long long long
#define REP(i,n) for(unsigned long long i = 0; i < n; i++)
#define REP1(i,n) for(unsigned long long i = 1; i <= n; i++)
#define debug cout << "Ok" << endl;
#define mod 1000000007

using namespace std;



/*
==============================> Description <=============================================
Question : 14. Dijkstra's Algorithm | Shortest Path in Undirected Graphs
/*
==============================> Explanation <=============================================
- We already see the Undirected Unit weight graph SSSP problem.

but when given edge weight and find SSSP use Dijkstra's...

It greedy apporach. It always makes decision which is most optimize at given instant of time.


Time -> O(N+E) * logN(pq push opreation) = O(N logN)
Space -> O(N)[distance] + O(N)[pq] = O(N)

*/


/*
==============================> Edge Case <=============================================

*/

    
// Dijkstra's algorithm
void shortestPath(int src, int N, vector<pair<int,int>> adjList[]) {

    // minimum pq.
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>> pq;

    // distance array.
    vector<int> distTo(N+1, INT_MAX);

    // set the source distance as zero.
    distTo[source] = 0;

    // push the source node {dist, node}.
    pq.push(make_pair(0, source));


    while(!pq.empty()) {

        // pop out the best minimum distance at time.
        int dist = pq.top().first;
        int prev = pq.top().second;
        pq.pop();

        // visit all its neighbour node.
        for(auto it: adjList[prev]) {

            int next_node = it.first;
            int weight = it.second;

            // Distance Relaxing...
            if(distTo[next_node] > distTo[prev] + weight) {
                distTo[next_node] = distTo[prev] + weight;

                // push into the pq with updated distance so it can be intermidatory for other node.
                pq.push(make_pair(distTo[next_node], next_node));
            }

        }
    }

    // print the distance vector.
    for(int i = 1 ; i <= N; i++)
        cout << distTo[i] << ' ';

    cout << endl;
}