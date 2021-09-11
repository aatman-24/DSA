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

Question : 207. Course Schedule
Topic : Graph, DAG
Problems : https://leetcode.com/problems/course-schedule/
==============================> Explanation <=============================================
Review: 

Striver Video: 8(DFS) and 11(BFS).

==============================> Edge Case <=============================================

DFS:
1) Time = O(N+E)(AdjList) 
   Space = O(N+E)(AdjList) +  O(N)(Aux) + O(N)(Visited) + O(N)(dfs_visited)

BFS:

1) Time = O(N+E)(AdjList)
   Space = O(N+E)(AdjList)+ O(N)(Queue) + O(N)(indegree)
*/

// Direct Graph Cycle Detection using DFS.
class Solution {
public:
    bool dfs(int node, vector<int> &visited, vector<int> &dfs_visited, vector<int> adjList[]) {

        visited[node] = 1;
        
        dfs_visited[node] = 1;

        for(auto it: adjList[node]) {

            if(!visited[it]) {
                if(!dfs(it, visited, dfs_visited, adjList))
                    return false;
            }
            else if (dfs_visited[it]) {
                return false;
            }
        }

        // unmark return from dfs.
        dfs_visited[node] = 0;

        return true;
    }


    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {

        // adjList from prerequisites.
        vector<int> adjList[numCourses];
        for(int i = 0; i < prerequisites.size(); i++) {
            adjList[prerequisites[i][0]].push_back(prerequisites[i][1]);
        }

        // visited -> mark all visited node.
        // dfs_visited -> mark and unmark visited node from dfs.
        vector<int> visited(numCourses,0), dfs_visited(numCourses, 0);

        // dfs for directed graph.
        for(int i = 0; i < prerequisites.size(); i++) {

            int src = prerequisites[i][0];

            if(!visited[src]) {
                if(!dfs(src, visited, dfs_visited, adjList)) 
                    return false;
            }

        }

        return true;
    }
};


// Direct Graph Cycle Detection using BFS(Kah's Algorithm|Toposort).
class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {

        // adjList from prerequisites and count indegree of node.
        vector<int> adjList[numCourses];
        vector<int> indegree(numCourses, 0);
        for(auto it: prerequisites) {
            adjList[it[0]].push_back(it[1]);
            indegree[it[1]]++;
        }

        // q for kahn's algorithm.
        queue<int> q;

        // add all node which has no incoming edge.
        for(int i = 0; i < numCourses; i++) {
            if(indegree[i] == 0) q.push(i);
        }

        // count total course possible.
        int takenCourse = 0;

        while(!q.empty()) {
            
            int node = q.front(); q.pop();
            takenCourse++;
            
            // decrease indegree of it neighbors.
            for(auto it: adjList[node]) {
                indegree[it]--;
                if(indegree[it] == 0) {
                    q.push(it);
                }
            }
        }

        // if there is no cycle then all course been coutned.
        return takenCourse == numCourses;
    }
};



