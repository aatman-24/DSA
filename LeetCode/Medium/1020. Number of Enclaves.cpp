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

Question: 1020. Number of Enclaves
Topic : DFS
Problems : https://leetcode.com/problems/number-of-enclaves/


==============================> Explanation <=============================================
- simple path finding dfs.

-First Visit all the boundary and make all the component as 0 so it is not counted because that
all are the cell which can walking off the boundary.

- After count reamining land. which is the answer.

Can be solved using BFS. Does not matter both are same in time and space.


==============================> Apporach and Time Complexity <=============================================

1) DFS:
Time: O(N*M)
Space: O(N*M)(IN worst case).

*/


class Solution {
public:
    int xx[4] = {1, 0, -1, 0};
    int yy[4] = {0, 1, 0, -1};

    bool isValid(int x, int y, vector<vector<int>> &grid) {
        if(x < 0 || y < 0 || x >= grid.size() || y >= grid[0].size() || grid[x][y] != 1)
            return false;
        return true;
    }

    void dfs(int x, int y, vector<vector<int>> &grid) {
        grid[x][y] = 0;
        for(int i = 0; i < 4; i++) {
            int x_ = x + xx[i];
            int y_ = y + yy[i];
            if(isValid(x_, y_, grid)) {
                dfs(x_, y_, grid);
            }
        }
    }

    int numEnclaves(vector<vector<int>>& grid) {

        int m = grid.size(), n = grid[0].size();

        for(int i = 0; i < m; i++) {
            if(grid[i][0] == 1)
                dfs(i, 0, grid);

            if(grid[i][n-1] == 1)
                dfs(i, n-1, grid);
        }

        for(int j = 0; j < n; j++) {
            if(grid[0][j] == 1)
                dfs(0, j, grid);

            if(grid[m-1][j] == 1)
                dfs(m-1, j, grid);
        }


        // count remaining land.
        int count = 0;
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j] == 1)
                    count++;
            }
        }

        return count;
    }  
};