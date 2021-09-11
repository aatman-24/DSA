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

Question: 1905. Count Sub Islands
Topic : DFS, BFS, Number of Island.
Problems : https://leetcode.com/problems/combinations/

==============================> Explanation <=============================================
Variant of Find the Number of Island.

Here, 

- We perform the DFS on grid2 to eliminate the island which contain the (i, j) cell which is 1 into
the grid2 and 0 into the grid1.

- After doing this, simple count the number of island into the grid2.

- If grid2 is sub-island of grid1 then it should not contain any extra Island(grid1 -> 0 && grid -> 1). So
First task is turn off that all cell in grid2. 


Performing the STEP-1 gurantee that all cell (i,j) can not be part of solution is set to 0. Very logical
that if grid2 has 1 and grid1 has 0 means grid2 cell can not be part of sub-island of grid1. 



==============================> Apporach and Time Complexity <=============================================

1) Number of Island:
Time: O(N^2)
Space: O(N^2)(Aux)

*/

class Solution {
public:

    int xx[4] = {1, 0, -1, 0};
    int yy[4] = {0, 1, 0, -1};

    void dfs(int x, int y, vector<vector<int>> &grid, int changeInto) {
        grid[x][y] = changeInto;
        
        for(int i = 0; i < 4; i++) {
            
            int x_ = x + xx[i];
            int y_ = y + yy[i];
            
            if(x_ < 0 || y_ < 0 || x_ >= grid.size() || y_ >= grid[0].size() || grid[x_][y_] != 1)
                continue;
            
            dfs(x_, y_, grid, changeInto);
        }
    }


    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {

        int m = grid1.size(), n = grid1[0].size();

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(grid2[i][j] == 1 && grid1[i][j] == 0) {
                    dfs(i, j, grid2, 0);
                }
            }
        }



        int count = 0;
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(grid2[i][j] == 1) {
                    count++;
                    dfs(i, j, grid2, 2);
                }
            }
        }

        return count;
    }
};