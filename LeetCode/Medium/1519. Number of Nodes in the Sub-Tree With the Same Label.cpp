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

Question: 1519. Number of Nodes in the Sub-Tree With the Same Label
Topic : DFS
Problems : https://leetcode.com/problems/number-of-nodes-in-the-sub-tree-with-the-same-label/
==============================> Explanation <=============================================
- We go to each position and count all the node label into the count[26]. We create
 a spearate array for each node to calculate the frequency.
- After we add all child frequency into the parent count[26] array.
- And each step we store the result into the ans based on label.


==============================> Apporach and Time Complexity <=============================================

1) Brute Force DFS:
Time: O(N)
Space: O(26*N)

*/


class Solution {
public:

    void dfs(int i, int count[], string &labels, vector<int> &ans,vector<int> &visited, vector<int> adjList[]) {
            
        for(auto it: adjList[i]) {

            if(!visited[it]) {

                visited[it] = 1;

                // create new frequency table.
                int cnt1[26] = {0};
                dfs(it, cnt1, labels, ans, visited, adjList);

                // add this frequency into the current frequency table.
                for(int k = 0; k < 26; k++) {
                    count[k] += cnt1[k];
                }
            }    
        }

        // After visiting all its child(subtreess) and itself(++) into the table 
        // and store the value into the answer.
        ans[i] = ++count[labels[i] - 'a'];
    }
    

    vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels) {

        vector<int> ans(n, 0), visited(n, 0);

        vector<int> adjList[n];
        for(auto edge: edges) {
            adjList[edge[0]].push_back(edge[1]);
            adjList[edge[1]].push_back(edge[0]);
        }

        int count[26] = {0};

        visited[0] = 1;
        dfs(0, count, labels, ans, visited, adjList);

        return ans;
    }
};