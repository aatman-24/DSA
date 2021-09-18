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

Question: 1034. Coloring A Border
Topic : DFS, BFS
Problems : https://leetcode.com/problems/coloring-a-border/
==============================> Explanation <=============================================
- Here I solved Using BFS

-> Simple Ideas is that visit the entire component of grid[x][y] color and start with(x, y) only.
-> The boundary of component is either,
    -> It is first row, col or last row, col.
    -> Or Either Any of neighbors is different(Means from diffrent component).

Just simple simulate this problem just like Number of Island.


-> It can be solved using DFS:
--- Need a mechanism such that, already visited node does not visit more than one time or
explore more than one time. (For this either use 2D vector or second way is to manipulate
this value by changing into the negative value).
--- After that Check the negative value is coverd by all negative value then it should not
be boundary. So change it with original value.
--- and remaining is boundary so change into given color.


I found that BFS is easy compare to DFS.

==============================> Apporach and Time Complexity <=============================================

1) DFS:
Time: O(N*M)
Space: O(N*M)(Aux)

2) BFS:
Time: O(N*M)
Space: O(N*M)(Queue)

*/


class Solution {
public:

int xx[4] = {1, 0, -1, 0};
int yy[4] = {0, 1, 0, -1};

    void colorComponent(int row, int col, vector<vector<int>> &grid, vector<vector<int>> &ans, int color) {

        int m = grid.size(), n = grid[0].size();
        int targetComp = grid[row][col];

        queue<pair<int,int>> q;
        q.push({row, col});

        while(!q.empty()) {
            
            int size = q.size();

            for(int j = 0; j < size; j++) {

                auto [x, y] = q.front(); q.pop();

                for(int i = 0; i < 4; i++) {

                    int x_ = x + xx[i];
                    int y_ = y + yy[i];

                    // If this condition is not true it means that currnet
                    // (x, y) is boundary.
                    if(x_ < 0 || y_ < 0 || x_ >= m || y_ >= n || grid[x_][y_] != targetComp) {
                        ans[x][y] = color;
                        continue;
                    }

                    // Already visited so skip it.
                    if(ans[x_][y_] > 0)
                        continue;

                    // Otherwise put (x_, y_) into the queue to explore the component further.
                    q.push({x_, y_});
                }

                // After exploring the four direction, If (x, y) is not boundary
                // then set the given grid[x][y] value.
                if(ans[x][y] == 0) {
                    ans[x][y] = grid[x][y];
                }
        
            }
        }

    }


    vector<vector<int>> colorBorder(vector<vector<int>>& grid, int row, int col, int color) {

        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> ans(m, vector<int>(n, 0));

        colorComponent(row, col, grid, ans, color);

        // put the remaining value as it is.
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(ans[i][j] == 0) {
                    ans[i][j] = grid[i][j];
                }
            }
        }
        
        
        return ans;
    }
};