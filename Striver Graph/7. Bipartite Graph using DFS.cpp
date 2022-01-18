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
Question : 7. Bipartite Graph using DFS.

/*
==============================> Explanation <=============================================
Bipartite Graph: Using Two color if you colored the graph, such that no adjacent Node have
same color then it is called Bipartite Graph.


- LOGIC -> If graph contain the cycle and its length is odd it means your graph can not 
be Bipartite Graph. 

       -> If there is no cycle or length is even the graph is Bipartite Graph.

- Check on GFG more.



Time -> O(N+E). Visit all the nodes and Edge.
Space -> O(N+E)(adj List) + O(N)[color array] = O(N+E)

*/


/*
==============================> Edge Case <=============================================

*/

bool bipartiteDfs(int node, vector<int> adjList, int color[]) {

    if(color[node] == -1) color[node] = 1;

    for(auto it: adjList[src]) {

        // If adjacent Node is not colored yet.
        if(color[it] == -1) {

            // color with oppsite color of current node.
            color[it] = 1 - color[node];

            if(!bipartiteDfs(it, adjList, color))
                return false;
        }

        // If it is already colored and color is same with current node. Means Grpah 
        // cannot be Bipartite.
        else if(color[it] == color[node]) {
            return false;
        }

    }

    return true;
}


bool checkBipartite(vector<int> adjList[], int n) {

    int color[n];

    memset(color, -1, sizeof(color));

    for(int i = 0; i < n; i++) {

        if(color[i] == -1) {

            if(!bipartiteDfs(i, adj, color))
                return false;
        }
    }

    return true;
}



int main() {

    int n, m;
    cin >> n >> m;

    vector<int> adjList[n];

    for(int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }

    if(checkBipartite(adjList, n)) {
        cout << "YES" << endl;
    }
    else {
        cout << "NO" << endl;
    }

}