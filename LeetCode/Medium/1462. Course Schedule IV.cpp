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

Question: 1462. Course Schedule IV
Topic : Graph, Topo Sort
Problems : https://leetcode.com/problems/course-schedule-iv/
==============================> Explanation <=============================================
- Alwasy check which one is first in topo sort and which one after that so don't confuse.

problem can be solved using floyd warshall also,

because here we just check that i and j the  node is connected or not and trying all the
node as intermidate it can be our result.

a -> b -> c
it is overall 
a->b
a->c
b->c

trying b as intermidate node.


==============================> Apporach and Time Complexity <=============================================


1) Floyd-Warshall:
Time = O(N^3)
Space = O(N^2)


2) Kahn's algorithm:
Time : O(N^2)
Space : O(N^2)
*/

class Solution {
public:
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {

        vector<int> indegree(numCourses, 0);

        vector<int> adjList[numCourses];

        for(auto edge: prerequisites) {
            adjList[edge[0]].push_back(edge[1]);
            indegree[edge[1]]++;
        }

        queue<int> q;
        for(int i = 0; i < numCourses; i++) {
            if(indegree[i] == 0)
                q.push(i);
        }

        // {u: v1, v2} v1 and v2 is prerequisites of u.
        vector<vector<int>> isPre(numCourses, vector<int>(numCourses, 0));

        while(!q.empty()) {

            int node = q.front(); q.pop();
            
            for(auto it: adjList[node]) {

                // If the node is pre-requisites of the it. Then we store the {it: node}.
                // so when {it: node1, node2} indicate that node1 is pre-requisites of the it.
                // so it means that [node1][it] is true not [it][node1].

                // We perform like that reason is that when some other node when "it" is
                // prerequisites of "it2" then we also add all prerequisites of "it"{node1, node2} 
                // into the "it2" also so that's why direct store the value.


                isPre[it][node] = 1;


                // check that if [node][i] means i is prerequisites of node then it also prerequisites of
                // it.
                for(int i = 0; i < numCourses; i++) {
                    if(isPre[node][i] == 1) {
                        isPre[it][i] = 1;
                    }
                }

                indegree[it]--;

                if(indegree[it] == 0) {
                    q.push(it);
                }
            }
        }

        vector<bool> answer(queries.size(), false);
        for(int i = 0; i < answer.size(); i++) {

            // Here we perfrom cross check that, u is prerequisites of v. means 
            // [v][u] is true means u is prerequisites of v.
            if(isPre[queries[i][1]][queries[i][0]]) {
                answer[i] = true;
            }
        }

        return answer;
    }

};




class Solution {
public:
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {

        vector<vector<bool>> connected(numCourses, vector<bool>(numCourses, false));

        for(auto edge: prerequisites) {
            connected[edge[0]][edge[1]] = true;
        }  

        for(int k = 0; k < numCourses; k++) {
            for(int i = 0; i < numCourses; i++) {
                for(int j = 0; j < numCourses; j++) {
                    connected[i][j] = connected[i][j] || connected[i][k] && connected[k][j];
                }
            }
        }

        vector<bool> answer(queries.size());
        for(int i = 0; i < queries.size(); i++) {
            answer[i] = connected[queries[i][0]][queries[i][1]];
        }

        return answer;

    }
};  