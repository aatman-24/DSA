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
Question : 5. Cycle Detection using BFS.

/*
==============================> Explanation <=============================================
- When we visit the current node, adjancent node and it is already visited by someother
node rathar than parent we found the cycle.

- Here we keep track of previous(parent) node into the queue.

Time -> O(N+E). Visit all the nodes and Edge.
Space -> O(N+E)(adj List) + O(N)[visited array] + O(N) [queue] = O(N+E)

*/


/*
==============================> Edge Case <=============================================

*/


bool checkForCycle(int node, int V, vector<int> &visited, vector<int> adjList[]) {

    // Create queue for BFS. Here, <node, parent_node>
    queue<pair<int,int>> q;

    // Mark the first node where BFS start as visited and push into the queue.
    visited[node] = 1;
    q.push({node, -1});

    while(!q.empty()) {

        int node = q.front().first;
        int parent = q.front().second;
        q.pop();

        for(auto it : adjList[node]) {

            // If not visited. Visit it and add into the queue.
            if(!visited[it]) {

                // Here is Change from DFS.
                visited[it] = 1;
                q.push({it, node});
            }
            // While adjancent node of current node, is already visited and this is not 
            // parent means we found the cycle.
            else if(parent != it)
                return true;
        }
    }

    return false;
}

bool isCycle(int V, vector<int> adjList[]) {

    vector<int> vis(V+1,0);

    for(int i = 1; i <= V; i++) {

        if(!vis[i]) {
            if(checkForCycle(i, V, vis, adjList))
                return true;
        }

    }

    return false;
}