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

Question : 37. Sudoku Solver
Topic : Recursion, Backtracking, Branch and Bound
Problems : https://leetcode.com/problems/sudoku-solver/

==============================> Explanation <=============================================


==============================> Edge Case <=============================================

Time = O(9 * 9^N^2) -> (1-9) possiblity for all empty blocks. We can calculate only for empty blocks.
                        so N^2 block with 9 possiblity. And every empty block take O(9) to check 
                        valid or not.
Space = O(N)(aux)

*/

class Solution {
public:
    
    
bool isValid(vector<vector<char>> &board, int row, int col, char num) {

    for(int i = 0; i < board.size(); i++) {

        if(board[i][col] == num)
            return false;

        if(board[row][i] == num)
            return false;

        if(board[3 * (row/3) + (i/3)][3 * (col/3) + (i%3)] == num)
            return false;
    }

    return true;
}



    bool solve(vector<vector<char>> &board) {

        for(int row = 0; row < board.size(); row++) {

            for(int col = 0; col < board[0].size(); col++) {

                if(board[row][col] == '.') {

                    for(char num = '1'; num <= '9'; num++) {

                        if(isValid(board, row, col, num)) {

                            board[row][col] = num;
                                
                            if(solve(board) == true) {
                                return true;
                            }

                            board[row][col] = '.';
                        }

                    }  

                    return false;
                }
            }
        }
         
        return true;
    }




     void solveSudoku(vector<vector<char>> &board) {
        solve(board);
     }


};