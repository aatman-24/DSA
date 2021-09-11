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

Question: 1254. Number of Closed Islands
Topic : Graph, DFS, Path Finding
Problems : https://leetcode.com/problems/number-of-closed-islands/

==============================> Explanation <=============================================
- this is simple BFS but problem is that node incoming edge can be red or white or both. When It is
both that time using simple bfs which mark the node is not valid here. 

Because there is other edge also can be visit the same node which is valid.

- Here rathar than marking the single node we have to take care of both possiblity and node
can be marked with red edge or blue edge.

Acutally I create the graph such way that, 

red -> odd 
blue -> even

means if there is node of size n. then we create the 2*n node every node is odd and even.

0       1      2       3        4 5..
0(even) 0(odd) 1(even) 1(even).....

Then we always take care of that, red node have only blue nodes in it and blue node have only
red nodes in its adjList.

- Peform two time BFS start with 0(even) O(odd).
- take care of minDist.

==============================> Apporach and Time Complexity <=============================================

1) BFS:
Time : O(N+E)
Space : O(N+E) + O(N)
*/


class Solution {
public:
    int xx[4] = {1, 0, -1, 0};
    int yy[4] = {0, 1, 0, -1};

    bool isValid(int x, int y, vector<vector<int>> &grid) {
        if(x < 0 || y < 0 || x >= grid.size() || y >= grid[0].size() || grid[x][y] != 0)
            return false;
        return true;
    }

    void dfs(int x, int y, vector<vector<int>> &grid) {

        // Mark as visited.
        grid[x][y] = 2;

        for(int i = 0; i < 4; i++) {

            int x_ = x + xx[i];
            int y_ = y + yy[i];

            if(isValid(x_, y_, grid)) {
                dfs(x_, y_, grid);
            }
        }
    }


    int closedIsland(vector<vector<int>>& grid) {

        int m = grid.size(), n = grid[0].size();


        // Extra, If any of 4 boundary have 0 then we pefrom the dfs from that mark all
        // the island as visited because that can not be our part of solution.
        for(int i = 0; i < m; i++) {
            
            if(grid[i][0] == 0)
                dfs(i, 0, grid);

            if(grid[i][n-1] == 0)
                dfs(i, n-1, grid);
        }

        for(int j = 0; j < n; j++) {
            
            if(grid[0][j] == 0)
                dfs(0, j, grid);

            if(grid[m-1][j] == 0)
                dfs(m-1, j, grid);
        }


        // Normal Count the Island problem.
        int comp = 0;
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j] == 0) {
                    dfs(i, j, grid);
                    comp++;
                }
            }
        }

        return comp;
    }
};