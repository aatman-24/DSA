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

Question: 200. Number of Islands
Topic : Graph, Path Finding, DFS
Problems : https://leetcode.com/problems/number-of-islands/

==============================> Explanation <=============================================
- DFS For Path Finding Pattern.

'1' -> land
'0' -> Water
'2' -> Visited

==============================> Apporach and Time Complexity <=============================================

1) DFS with Extra Visited Array:
Time : O(N^2)
Space : O(N^2) + O(N^2)(Aux)

1) DFS:
Time: O(N^2)
Space: O(N^2)(Aux)

*/

class Solution {
public:
    
    int xx[4] = {1, 0, -1, 0};
    int yy[4] = {0, 1, 0, -1};

    bool isValid(int x, int y, vector<vector<char>> &grid) {
        if(x < 0 || y < 0 || x >= grid.size() || y >= grid[0].size() || grid[x][y] != '1')
            return false;
        return true;
    }

    void dfs(int x, int y, vector<vector<char>> &grid) {

        grid[x][y] = '2';

        for(int i = 0; i < 4; i++) {
         
            int x_ = x + xx[i];
            int y_ = y + yy[i];
         
            if(isValid(x_, y_, grid)) {
                dfs(x_, y_, grid);
            }
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        int island = 0;
        for(int i = 0; i < grid.size(); i++) {
            for(int j = 0; j < grid[0].size(); j++) {
                if(grid[i][j] == '1') {
                    dfs(i, j, grid);
                    island++;
                }
            }
        }
        return island;
    }
};