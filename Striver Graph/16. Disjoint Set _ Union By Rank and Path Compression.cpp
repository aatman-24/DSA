#include <bits/stdc++.h>
#define unsigned long long long long
#define REP(i,n) for(unsigned long long i = 0; i < n; i++)
#define REP1(i,n) for(unsigned long long i = 1; i <= n; i++)
#define debug cout << "Ok" << endl;
#define mod 1000000007

using namespace std;



/*
==============================> Description <=============================================
Question : 16. Disjoint Set _ Union By Rank and Path Compression



==============================> Explanation <=============================================

Time = O(4*alpha) = O(4) = Constant. (proven)
Space = O(N)

==============================> Edge Case <=============================================


*/



int parent[10000];
int rank[10000];

void makeSet(int n) {
    for(int i = 1; i <= n; i++)
        parent[i] = i, rank[i] = 0;
}

int findParent(int node) {
    if(node == parent[node])
        return node;

    // return findParent(parent[node]);

    // path compression.
    return parent[node] = findParent(parent[node]);

}

void union(int u, int v) {

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

int main() {

    int n;      // n components
    
    makeSet(n);

    int m; cin >> m;
    while(m--) {
        int u, v;
        union(u,v);
    }

    if(findParent(2) != findParent(3)) {
        cout << "Differnt Components" << endl;
    }
    else {
        cout << "Same" << endl;
    }

}


