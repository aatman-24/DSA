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

Question : 463. Island Perimeter
Topic : BFS, pattern = Number of Island
Problems : https://leetcode.com/problems/island-perimeter/

==============================> Explanation <=============================================

What is perimeter ?

- If any time we hit any boundary(either the matrix boundary or island boundary) then this edge counted as perimiter.

==============================> Apporach and Time Complexity <=============================================

1) BFS, pattern = Number of Island
Time: O(N^2)
Space: O(1)


*/


class Solution {
public:

    int xx[4] = {1, 0, -1, 0};
    int yy[4] = {0, 1, 0, -1};

    int solve(vector<vector<int>> &grid, int x, int y) {

        int perimeter = 0;

        // mark the current cell as visited.
        grid[x][y] = 2;

        for(int i = 0; i < 4; i++) {

            int x_ = x + xx[i];
            int y_ = y + yy[i];

            // out of boundary, increment the perimeter.
            if(x_ < 0 || y_ < 0 || x_ >= grid.size() || y_ >= grid[0].size()) {
                perimeter++;
            }
            // boundary of island, increment the perimeter.
            else if(grid[x_][y_] == 0) {
                perimeter++;
            }
            // already visited cell, skip it.
            else if(grid[x_][y_] == 2) {
                continue;
            }
            else
                perimeter += solve(grid, x_, y_);
        }

        return perimeter;
    }


    int islandPerimeter(vector<vector<int>>& grid) {
        
        // find the island
        int startX = -1, startY = -1;

        for(int i = 0; i < grid.size(); i++) {
            for(int j = 0; j < grid[0].size(); j++) {
                if(grid[i][j]) {
                    startX = i; startY = j;
                    break;
                }
            }
            if(startX != -1)
                break;
        }


        int perimeter =  solve(grid, startX, startY);  

        return perimeter;
    }
};