#include <bits/stdc++.h>
#define unsigned long long long long
#define REP(i,n) for(unsigned long long i = 0; i < n; i++)
#define REP1(i,n) for(unsigned long long i = 1; i <= n; i++)
#define debug cout << "Ok" << endl;
#define mod 1000000007

using namespace std;


    
/*
==============================> Description <=============================================
Question : 17. Kruskal's Algorithm



==============================> Explanation <=============================================
- Take the edge which is most suitable(minimum cost) at given time. If it's {source, target}
is not part of single componets.

Time = O(M*logM)(Sorting Edge) + O(M*4*alpha)(Connected Component) = O(M*logM)
Space = O(N)(mst) + O(N)(parent) + O(N)(rank) = O(N)  

==============================> Edge Case <=============================================


*/


struct node {
public:
    int u, v, weight;

    node(int u, int v, int weight)  {
        this->u = u;
        this->v = v;
        this->weight = weight;
    }
}

void union(int u, int v, vector<int> &parent, vector<int> &rank) {

    u = findParent(u);
    v = findParent(v);

    if(rank[u] < rank[v]) {
        parent[u] = v;
    }
    else if(rank[v] < rank[u]) {
        parent[v] = u;
    }
    else {
        parent[v] = u;
        rank[u]++;
    }
}

int findParent(int node, vector<int> &parent) {

    if(node == parent[node])
        return node;

    // return findParent(parent[node]);

    // path compression.
    return parent[node] = findParent(parent[node]);

}


bool comp(node n1, node n2) {
    return n1.weight < n2.weight;
}


int main() {

    int N, m;      // Nodes, Edges
    cint >> N >> m;

    vector<node> edges;
    int u, v, wt;
    for(int i = 0; i < m; i++){
        cin >> u >> v >> wt;
        edges.push_back(node(u,v,wt));
    }
    sort(edges.begin(), edges.end(), comp)


    vector<int> parent(N), rank(N);
    for(int i = 0; i < N; i++)
        parent[i] = i, rank[i] = 0;

    int cost = 0;
    vector<pair<int,int>> mst;
    for(auto it: edges) {
        if(findParent(it.v, parent) != findParent(it.u, parent)) {
            cost += it.weight;
            mst.push_back({it.v, it.u});
            union(it.u, it.v, parent, rank);
        }
    }


    cout << cost << endl;
    for(auto it: mst) cout << it.first << ' ' << it.second << endl;
}


