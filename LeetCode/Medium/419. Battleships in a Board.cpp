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

Question: 419. Battleships in a Board
Topic : DFS, Number of Island
Problems : https://leetcode.com/problems/battleships-in-a-board/

==============================> Explanation <=============================================
Solution-1:
- Performing simple DFS(same as number of island) and count component.

Solution-2:
- We only count starting cell of Battleship. Starting cell is which top-left cell 
    - which is not '.'
    - have not left side 'x'.
    - have not upper side 'x'.
    - and must be 'x'. 

==============================> Apporach and Time Complexity <=============================================

1) DFS:
Time: O(N+E) N=(M*N), E = (4*M*N) -> O(M*N+4*M*N) -> O(5*M*N) -> O(M*N) 
Space: O(M*N)(Aux)

2) Single Pass:
Time:O(M*N)
Space:O(1)

*/



class Solution {
public:
    int xx[4] = {1, 0, -1, 0};
    int yy[4] = {0, 1, 0, -1};

    void dfs(int x, int y, vector<vector<char>> &grid) {
        grid[x][y] = '.';
        for(int i = 0; i < 4; i++) {
            int x_ = x + xx[i];
            int y_ = y + yy[i];

            if(x_ < 0 || y_ < 0 || x_ >= grid.size() || y_ >= grid[0].size() || grid[x_][y_] != 'X')
                continue;

            dfs(x_, y_, grid);
        }
    }

    int countBattleships(vector<vector<char>>& board) {
        int count = 0;
        for(int i = 0; i < board.size(); i++) {
            for(int j = 0; j < board[0].size(); j++) {
                if(board[i][j] == 'X') {
                    count++;
                    dfs(i, j, board);
                }
            }
        }
        return count;
    }
};



class Solution {
public:
    int countBattleships(vector<vector<char>>& board) {

        int m = board.size(), n = board[0].size();
        int count = 0;

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(board[i][j] == '.') continue;
                if(i > 0 && board[i-1][j] == 'X') continue;
                if(j > 0 && board[i][j-1] == 'X') continue;
                count++;
            }
        }

        return count;
    }
};