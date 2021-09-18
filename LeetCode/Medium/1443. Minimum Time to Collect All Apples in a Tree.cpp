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

Question: 1443. Minimum Time to Collect All Apples in a Tree
Topic : Graph, Tree, DFS
Problems : https://leetcode.com/problems/minimum-time-to-collect-all-apples-in-a-tree/
==============================> Explanation <=============================================
Idea is that,

If current node any neighbor contain apple then count that edge 2 times. If it not then
don't count it.

- If node itself is apple or any of child is apple then return true for parent call
else return false.


- If you remove early stop then it is also fine not a problem.

==============================> Apporach and Time Complexity <=============================================

1) DFS: 
Time: O(N+E)(DFS Traversal)
Space: O(N+E)(AdjList) + O(N)(Visited)


*/


class Solution {
public:

    bool dfs(int node, int &apples, vector<int> &visited, vector<int> adjList[], vector<bool>& hasApple, int &ans) {

        bool found = false;
        
        // Node Itself is apples. 
        if(hasApple[node]) {
            apples--;
            found = true;
        }
        
        // Early Stop.
        if(apples == 0)
            return found;
      

        for(auto it: adjList[node]) {

            if(!visited[it]) {
                
                visited[it] = 1;

                if(dfs(it, apples, visited, adjList, hasApple, ans)) {
                    
                    // (both forward and backward egde coutned that's why)
                    ans += 2;

                    // Early Stop.
                    if(apples == 0)
                        return true;

                    // Set as true because its one of child is apple.
                    found = true;
                }
            }
        }


        // Return true when either node itself is apple or any one of it child
        // is apple. Otherwise false.
        return found;
    }





    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {

        int apples = 0, ans = 0;
        for(auto isApple: hasApple) {
            if(isApple) 
                apples++;
        }

        vector<int> adjList[n];
        for(auto edge: edges) {
            adjList[edge[0]].push_back(edge[1]);
            adjList[edge[1]].push_back(edge[0]);
        }

        vector<int> visited(n, 0);
        visited[0] = 1;

        
        dfs(0, apples, visited, adjList, hasApple, ans);

        return ans;
    }
};