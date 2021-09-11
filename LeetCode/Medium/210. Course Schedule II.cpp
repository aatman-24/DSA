#include <bits/stdc++.h>
#define ll long long
#define REP(i,n) for(int i = 0; i < n; i++)
#define REP1(i,n) for(int i = 1; i <= n; i++)
#define debug cout << "Ok" << endl;
#define mod 1000000007
#define eps 1e-6

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

Question : 210. Course Schedule II
Topic : Graph, DAG
Problems : https://leetcode.com/problems/course-schedule-ii/
==============================> Explanation <=============================================
Review: 

Striver Video: 8(DFS) and 11(BFS).


Follow Up:

207. Course Schedule

==============================> Edge Case <=============================================

DFS:
1) Time = O(N+E)(AdjList) 
   Space = O(N+E)(AdjList) +  O(N)(Aux) + O(N)(Visited) + O(N)(dfs_visited) 

BFS:

1) Time = O(N+E)(AdjList)
   Space = O(N+E)(AdjList)+ O(N)(Queue) + O(N)(indegree)
*/



class Solution {
public:

    // generate topoSort + check directed graph have cycle or not.
    // if there is cycle topoSort not possible.
    bool dfs(int node, vector<int> &vis, vector<int> &dfs_vis, vector<int> &st, vector<int> adjList[]) {

        vis[node] = 1;
        dfs_vis[node] = 1;

        for(auto it: adjList[node]) {

            if(!vis[it]) {
                if(!dfs(it, vis, dfs_vis, st, adjList))
                    return false;
            }
            else if(dfs_vis[it]) {
                return false;
            }
        }
        
        dfs_vis[node] = 0;
        st.push_back(node);

        return true;
    }


    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {

        // adjList from prerequisites.
        vector<int> adjList[numCourses];
        for(auto it: prerequisites) {
            adjList[it[0]].push_back(it[1]);
        }

        vector<int> vis(numCourses, 0), dfs_vis(numCourses, 0);
        
        // stack but in form of vector. Need to return vector.
        vector<int> st;

        for(int i = 0; i < numCourses; i++) {

            if(!vis[i]) {

                // if cycle topoSort is not possible.
                if(!dfs(i, vis, dfs_vis, st, adjList)) {
                    return vector<int>();
                }
            }

        }

        return st;
    } 
};


// Using BFS. Kahn's Algorithm.
class Solution {
public:

    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {

        // keep track of indegree.
        vector<int> indegree(numCourses, 0);

        // adjList from prerequisites.
        vector<int> adjList[numCourses];
        for(auto it : prerequisites) {
            adjList[it[0]].push_back(it[1]);
            indegree[it[1]]++;
        }


        queue<int> q;

        // push all the node which has no incoming edge.
        for(int i = 0; i < numCourses; i++) {
            if(indegree[i] == 0) q.push(i);
        }

        vector<int> topoOrder;
        
        while(!q.empty()) {

            int node = q.front(); q.pop();
            topoOrder.push_back(node);

            for(auto it: adjList[node]) {
                indegree[it]--;
                if(indegree[it] == 0) {
                    q.push(it);
                }
            }
        }

        // If there is cycle then topoOrder.size() < numCoursers.
        if(topoOrder.size() == numCourses) {
            reverse(topoOrder.begin(), topoOrder.end());
            return topoOrder;
        }

        return vector<int>();
    }
    
};