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

Question: 417. Pacific Atlantic Water Flow
Topic : Path Finding, DFS, BFS, Island
Problems : https://leetcode.com/problems/pacific-atlantic-water-flow/


==============================> Explanation <=============================================
- Number of Island copy. But we perform two time (DFS|BFS). One time for pacific water flow
and second time Atlantic water flow with boundary only.

==============================> Apporach and Time Complexity <=============================================

1) DFS Island:
Time: O(M*N)
Space: O(M*N)(pacific) + O(M*N)(atlantic) + O(M*N)(Aux)


2) BFS Island:
Time: O(M*N)
Space: O(M*N)(pacific) + O(M*N)(atlantic) + O(M*N)(Queue)

*/

class Solution {
public:
    int xx[4] = {1, 0, -1, 0};
    int yy[4] = {0, 1, 0, -1};

    bool isValid(int x_, int y_, int x, int y, vector<vector<int>> &grid, vector<vector<int>> &mat) {
        if(x_ < 0 || y_ < 0 || x_ >= grid.size() || y_ >= grid[0].size() || mat[x_][y_] == 1)
            return false;
        return grid[x_][y_] >= grid[x][y];
    }

    void dfs(int x, int y, vector<vector<int>> &grid, vector<vector<int>> &mat) {
        mat[x][y] = 1;
        for(int i = 0; i < 4; i++) {
            int x_ = x + xx[i];
            int y_ = y + yy[i];

            // we don't visit the cell already visited.
            if(isValid(x_, y_, x, y, grid, mat)) {
                dfs(x_, y_, grid, mat);
            }
        }
    }


    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {

        int m = heights.size(), n = heights[0].size();

        vector<vector<int>> pacific(m, vector<int>(n, 0));
        vector<vector<int>> atlantic(m, vector<int>(n, 0));

        // 0th row
        for(int j = 0; j < n; j++) {
            if(pacific[0][j] == 0) {
                dfs(0, j, heights, pacific);
            }
        }

        // 0th col
        for(int i = 0; i < m; i++) {
            if(pacific[i][0] == 0) {
                dfs(i, 0, heights, pacific);
            }
        }

        
        // m-1th row
        for(int j = 0; j < n; j++) {
            if(atlantic[m-1][j] == 0) {
                dfs(m-1, j, heights, atlantic);
            }
        }


        // n-1th col
        for(int i = 0; i < m; i++) {
            if(atlantic[i][n-1] == 0) {
                dfs(i, n-1, heights, atlantic);
            }
        }

        vector<vector<int>> ans;
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(atlantic[i][j] && pacific[i][j]) {
                    ans.push_back({i, j});
                }
            }
        }

        return ans;
    }
};



class Solution {
public:
        
    int xx[4] = {1, 0, -1, 0};
    int yy[4] = {0, 1, 0, -1};

    bool isValid(int x_, int y_, int x, int y, vector<vector<int>> &grid, vector<vector<int>> &mat) {
        if(x_ < 0 || y_ < 0 || x_ >= grid.size() || y_ >= grid[0].size() || mat[x_][y_] == 1)
            return false;
        return grid[x_][y_] >= grid[x][y];
    }


    void bfs(queue<pair<int,int>> q, vector<vector<int>> &atlantic, vector<vector<int>> &grid) {
        while(!q.empty()) {
            auto [x, y] = q.front(); q.pop();


            // we don't visit the cell already visited.
            if(atlantic[x][y] == 1)
                continue;
            
            atlantic[x][y] = 1;
            for(int i = 0; i < 4; i++) {
                int x_ = x + xx[i];
                int y_ = y + yy[i];
                if(isValid(x_, y_, x, y, grid, atlantic)) {
                    q.push({x_, y_});
                }
            }
        }
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {

        int m = heights.size(), n = heights[0].size();

        vector<vector<int>> pacific(m, vector<int>(n, 0));
        vector<vector<int>> atlantic(m, vector<int>(n, 0));

        queue<pair<int,int>> pacQ, atlQ;

        for(int j = 0; j < n; j++) {
            pacQ.push({0, j});
            atlQ.push({m-1, j});
        }

        for(int i = 0; i < m; i++) {
            pacQ.push({i, 0});
            atlQ.push({i, n-1});
        }

        bfs(pacQ, pacific, heights);
        bfs(atlQ, atlantic, heights);

        vector<vector<int>> ans;
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(atlantic[i][j] && pacific[i][j]) {
                    ans.push_back({i, j});
                }
            }
        }

        return ans;
    }
};