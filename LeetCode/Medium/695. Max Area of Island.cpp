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

Question: 695. Max Area of Island
Topic : Graph, DFS, Matrix, Path Finding
Problems : https://leetcode.com/problems/max-area-of-island/
==============================> Explanation <=============================================
Traverse all Four Direction and It is valid Move then extend DFS until valid move possible.

==============================> Apporach and Time Complexity <=============================================


1) DFS + Visited:

Time = O(N^2) 
Space = O(N^2)(Visited) + O(N^2)(Aux) 

2) DFS:
Time = O(N^2)
Space = O(N^2)(Aux)(In Worst Case)


*/

class Solution {
public:

    int xx[4] = {1, 0, -1, 0};
    int yy[4] = {0, 1,  0, -1};

    bool isValid(int x, int y, vector<vector<int>> &grid, vector<vector<int>> &visited) {
        if(x < 0 || y < 0 || x >= grid.size() || y >= grid[0].size() || grid[x][y] != 1 || visited[x][y] == 1)
            return false;
        return true;
    }

    int dfs(int x, int y, vector<vector<int>>& grid, vector<vector<int>> &visited) {

        visited[x][y] = 1;
        
        int area = 1;
        for(int i = 0; i < 4; i++) {

            int x_ = x + xx[i];
            int y_ = y + yy[i];

            if(isValid(x_, y_, grid, visited)) {
                area += dfs(x_, y_, grid, visited);    
            }
        }

        return area;
    }


    int maxAreaOfIsland(vector<vector<int>>& grid) {

        int m = grid.size(), n = grid[0].size();

        vector<vector<int>> visited(m, vector<int>(n, 0));

        int max_area = 0;

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(visited[i][j] == 0 && grid[i][j] == 1) {
                    int area = dfs(i, j, grid, visited);
                    if(area > max_area)
                        max_area = area;
                }
            }
        }

        return max_area;
    }
};




class Solution {

public:
    int xx[4] = {1, 0, -1, 0};
    int yy[4] = {0, 1,  0, -1};

    bool isValid(int x, int y, vector<vector<int>> &grid, vector<vector<int>> &visited) {
        if(x < 0 || y < 0 || x >= grid.size() || y >= grid[0].size() || grid[x][y] != 1)
            return false;
        return true;
    }

    int dfs(int x, int y, vector<vector<int>>& grid, vector<vector<int>> &visited) {

        grid[x][y] = 0;
        
        int area = 1;

        for(int i = 0; i < 4; i++) {

            int x_ = x + xx[i];
            int y_ = y + yy[i];

            if(isValid(x_, y_, grid)) {
                area += dfs(x_, y_, grid);    
            }
        }

        return area;
    }


    int maxAreaOfIsland(vector<vector<int>>& grid) {

        int m = grid.size(), n = grid[0].size();

        int max_area = 0;

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j] == 1) {
                    int area = dfs(i, j, grid);
                    if(area > max_area)
                        max_area = area;
                }
            }
        }

        return max_area;
    }
};