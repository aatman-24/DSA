#include <bits/stdc++.h>
#define unsigned long long long long
#define REP(i,n) for(unsigned long long i = 0; i < n; i++)
#define REP1(i,n) for(unsigned long long i = 1; i <= n; i++)
#define debug cout << "Ok" << endl;
#define mod 1000000007

using namespace std;


    
/*
==============================> Description <=============================================
Question : Bellman Ford Algorithm | Detect Negative Weight Cycle in Graphs
==============================> Explanation <=============================================

Why Bellman Ford Algorithm For SSSP, When there is already Dijkstra ?
- Dijkstras's Algorithm find SSSP if and only if there is no negative cycle. If there is
then it fails.
 
1 ->(-1) 2 ->(-1) -> 1.

- It update distance every time due to negative edge. Which result into TLE.


So Finding SSSP and Checking Negative Weight Cycle can be peformed using Bellman.

Single Edge: (u, v) -> weight

Edge Relaxation: 
    
    if dist[u] + weight < dist[v]:
        dist[v] = dist[u] + weight


Algorithm:

- Perform Edge Relaxation (N-1) times.
- After (N-1) Edge Relaxation you got the SSSP for given source vertex.

Checking Negative Edge Cycle,
- After that peform one more time, if dist array change then there is negative weight cycle.

- Else:
    print(Dist Array).


Why (N-1) times?
- If there is N nodes, then the longest path contain the (N-1) edge. So in worst case
parsing the minimum weight take (N-1) cycle.

dist = [0, INF, INF, INF]

1st Cycle
1 ->(1) -> 2 ->(7) -> 3 ->(8) -> 4.
dist = [0, 1, INF, INF]

2nd Cycle
dist = [0, 1, 8, INF]

3rd Cycle (N-1) Cycle.
dist = [0, 1, 8, 16]

If After in 4th Cycle. If still dist is change then there is negative cycle due to that
dist is minimized.


- Or you can also think in second approach..
- (Except Source Node) (N-1) node can be intermidatory node in worst case and every time
edge relaxation performed just like above example...

(first 1 be intermidatory), then 2, then 3. (N-1) node.


Finally In short,

- perform the Edge Relaxation in N-1 Times.
- Peform one more time if dist array change then there is cycle. If not print the dist array as SSSP.




Time = O(E * (N-1)) [PS: Not best as Dijkstra O(N*logE)]
Space = O(N)(Dist)



==============================> Edge Case <=============================================

*/


class node {

public:

    int u, v, weight;

    node(int u, int v, int wt) {
        this->u = u;
        this->v = v;
        this ->weight = wt;
    }
};



int main() {
    
    // Adjacency List
    int n, m;
    cin >> n >> m;
    vector<node> edges[n];
    for(int i = 0; i < m; i++) {
        int u, v, wt;
        cin >> u >> v >> wt;
        edges.push_back(node(u, v, wt));
    }

    int src; cin >> src;

    int inf = 1000000; // don't take it as INT_MAX. Overflow occur in future if you used it.
    vector<int> dist(n, inf);

    dist[src] = 0;

    // Here only N-1 Time. Check two time don't mistake here.
    for(int i = 1; i <= n-1; i++) {
        for(auto it: edges) {
            if(dist[it.u] + it.weight < dist[it.v]) {
                dist[it.v] = dist[it.u] + it.weight;
            }
        }
    }


    // check one more time. Checking negative edge cycle.
    bool flag = true;
    for(auto it: edges) {
        if(dist[it.u] + it.weight < dist[it.v]) {
            dist[it.v] = dist[it.u] + it.weight;
            flat = false;
        }
    }

    // print sssp.
    if(flag) {
        for(int i = 0; i < n; i++) {
            cout << dist[i] << ' ';
        }
    }   
    else {
        cout << "Negative Edge Cycle" << endl;
    }

    return 0;
}