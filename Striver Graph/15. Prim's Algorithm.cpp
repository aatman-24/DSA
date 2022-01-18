#include <bits/stdc++.h>
#define unsigned long long long long
#define REP(i,n) for(unsigned long long i = 0; i < n; i++)
#define REP1(i,n) for(unsigned long long i = 1; i <= n; i++)
#define debug cout << "Ok" << endl;
#define mod 1000000007

using namespace std;



/*
==============================> Description <=============================================
Question : 15. Prim's Algorithm
/*
==============================> Explanation <=============================================
- we select the edge which target node is not selected yet and the weight of that edge is
minimal compare to possible edge.
*/


/*
==============================> Edge Case <=============================================

*/


// O(N^2) - O(N). 
void primsMST(int src, vector<pair<int,int>> adjList[], int N) {

    // Keep track of Parent.
    int parent[N];

    // Keep track of distance.
    int key[N];

    // Keep track of node is part of MST or not.
    int mstSet[N];

    // Summation of MST Path.
    int mstPathSum = 0;

    for(int i = 0; i < N; i++)
        key[i] = INT_MAX, mstSet[i] = false, parent[i] = -1;

    // Src node distance is zero and it parent is also -1.  
    key[src] = 0;
    parent[src] = -1;

    // total N node and N-1 edge.
    for(int count = 0; count < N-1; count++) {

        int u, min_dist = INT_MAX;

        for(int v = 0; v < N; v++)
            if(mstSet[v] == false && key[v] < min_dist)
                min_dist = key[v], u = v;


        mstSet[u] = v;
        mstPathSum += min_dist;

        for(auto it: adjList[u]) {
            int v = it.first;
            int weight = it.second;

            if(mstSet[v] == false && weight < key[v])
                parent[v] = u; key[v] = weight;
        }

    }


    for(int i = 1; i < N; i++)
        cout << parent[i] << " - " << i << "\n";
    
    return 0;
}

// Optimized. Using Heap Data Structure we can efficently derive the min_dist node.
// O((N+E) + N*logN) - O(N).
void primsMST(int src, vector<pair<int,int>> adjList[], int N) {

    // Keep track of Parent.
    int parent[N];

    // Keep track of distance.
    int key[N];

    // Keep track of node is part of MST or not.
    int mstSet[N];

    // Summation of MST Path.
    int mstPathSum = 0;

    for(int i = 0; i < N; i++)
        key[i] = INT_MAX, mstSet[i] = false, parent[i] = -1;

    // minimum priority queue.
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>> > pq;

    // Src node distance is zero and it parent is also -1.  
    key[src] = 0;
    parent[src] = -1;
    pq.push({0, src});    // {weight, node}


    // total N node and N-1 edge. // N
    for(int count = 0; count < N-1; count++) {

        int u = pq.top().second;
        int min_dist = pq.top().first;
        pq.pop();               // logN



        mstSet[u] = v;
        mstPathSum += min_dist;

        for(auto it: adjList[u]) {      // (N + E)
            int v = it.first;
            int weight = it.second;

            if(mstSet[v] == false && weight < key[v]){
                parent[v] = u; key[v] = weight;
                pq.push({key[v], v});
            }
        }

    }


    for(int i = 1; i < N; i++)
        cout << parent[i] << " - " << i << "\n";
    
    return 0;
}