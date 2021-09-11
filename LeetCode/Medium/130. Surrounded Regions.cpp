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

Question: 130. Surrounded Regions
Topic : DFS, Number Of Island
Problems : https://leetcode.com/problems/surrounded-regions/

==============================> Explanation <=============================================
- Count Number Of Island Variant.

Here,

- First Convert all Boundary Island into 'Z'.
- For remaining 'O' which is coverd by all 'X' converted into 'X'.
- And last Convert 'Z' -> 'O' which boundary side Island.

==============================> Apporach and Time Complexity <=============================================

1) DFS Number Of Island:
Time: O(N+E) -> N = m*n, E = 4*m*n -> O(5*m*n) -> O(m*n)
Space: O(m*n)(Aux)

*/

class Solution {
public:
    int xx[4] = {1, 0, -1, 0};
    int yy[4] = {0, 1, 0, -1};

    void dfs(int x, int y, vector<vector<char>> &grid, char changeInto) {
        
        grid[x][y] = changeInto;

        for(int i = 0; i < 4; i++) {
            int x_ = x + xx[i];
            int y_ = y + yy[i];

            if(x_ < 0 || y_ < 0 || x_ >= grid.size() || y_ >= grid[0].size() || grid[x_][y_] != 'O')
                continue;

            dfs(x_, y_, grid, changeInto);
        }
    }


    void solve(vector<vector<char>>& board) {

        int m = board.size(), n = board[0].size();


        // Change All Four Boundary Island Into the 'Z'. Which is fixed
        // Can not change Through the DFS.
        for(int j = 0; j < n; j++) {

            if(board[0][j] == 'O')
                dfs(0, j, board, 'Z');

            if(board[m-1][j] == 'O')
                dfs(m-1, j, board, 'Z');
        }

        for(int i = 0; i < m; i++) {

            if(board[i][0] == 'O')
                dfs(i, 0, board, 'Z');

            if(board[i][n-1] == 'O')
                dfs(i, n-1, board, 'Z');
        }

        // Perform the DFS For remaining 'O'. Which is converted into 'X' after DFS.
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {

                if(board[i][j] == 'O') {
                    dfs(i, j, board, 'X');
                }
            }
        }

        // Now change 'Z' into 'O'.
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(board[i][j] == 'Z')
                    board[i][j] = 'O';
            }
        }

    }
};