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

Question : 289. Game of Life
Topic : Matrix, Logic
Problems : https://leetcode.com/problems/game-of-life/

==============================> Explanation <=============================================

- We need to find a way using that we can keep track of both previous and current state. Extra memory is not allowed
so only one way is possible by changing the value.

Brute Force: O(N*M) using Extra space


Inplace,

[current, next]
00 -> 2 
01 -> 3
10 -> 4
11 -> 5

We just update the value according to the mapping and rules given problem.

And last, we replace values [2,4] -> 0 and [3, 5] -> 1.

==============================> Apporach and Time Complexity <=============================================

1) Matrix, Logic
Time: O(N*M)
Space: O(1)

*/

class Solution {

public:

    // 8 directions.
    int xx[8] = {1, 1, 0, -1, -1, -1, 0, 1};
    int yy[8] = {0, 1, 1, 1, 0, -1, -1, -1};

    void gameOfLife(vector<vector<int>>& board) {
    
        int N = board.size(), M = board[0].size();

        for(int i = 0; i < N; i++) {
            
            for(int j = 0; j < M; j++) {

                int count = 0;

                for(int k = 0; k < 8; k++) {

                    int x = xx[k] + i;
                    int y = yy[k] + j;

                    if(x < 0 || y < 0 || x >= N || y >= M)
                        continue;

                    // board[x][y] == 1, (x, y) is not visited.. active cell.
                    // visited..
                    // 4 -> (10) (live -> dead)
                    // 5 -> (11) (live -> live)
                    if(board[x][y] == 1 || board[x][y] == 4 || board[x][y] == 5)
                        count++;
                }

                // current cell is live.
                if(board[i][j]) {

                    // keep live. (1 -> 1)
                    if(count == 2 || count == 3) {
                        board[i][j] = 5;
                    }
                    // dead (1 -> 0)
                    else {
                        board[i][j] = 4;
                    }

                }
                // current cell is dead.
                else {
                    // become live. (0 -> 1)
                    if(count == 3) {
                        board[i][j] = 3;
                    }
                    // dead. (0 -> 0)
                    else {
                        board[i][j] = 2;
                    }
                }

            }
        }


        // update value.
        // 2, 4 -> 0.
        // 3, 5 -> 1.
        for(int i = 0; i < N; i++) {
            for(int j = 0; j < M; j++) {
                if(board[i][j] == 2 || board[i][j] == 4) {
                    board[i][j] = 0;
                }
                else {
                    board[i][j] = 1;
                }
            }
        }

    }
};