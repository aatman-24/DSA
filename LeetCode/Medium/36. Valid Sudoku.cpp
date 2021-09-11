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

Question : 36. Valid Sudoku
Topic : Sudoku
Problems : https://leetcode.com/problems/valid-sudoku/
==============================> Explanation <=============================================


==============================> Edge Case <=============================================

1) Time = O(9 * N^2)
   Space = O(1)

1) Time = O(N^2)
   Space = O(N)
*/



class Solution {
public:
    bool isValid(vector<vector<char>>& board, int row, int col) {

        char num = board[row][col];

        for(int i = 0; i < 9; i++) {

            if(i != col && board[row][i] == num)
                return false;

            if(i != row && board[i][col] == num)
                return false;

            if((3*(row/3) + (i/3)) != row &&  (3*(col/3)+(i%3)) != col && board[3*(row/3) + (i/3)][3*(col/3)+(i%3)] == num)
                return false;
        }

        return true;

    }


    bool isValidSudoku(vector<vector<char>>& board) {

        for(int row = 0; row < board.size(); row++) {
            for(int col = 0; col < board.size(); col++) {

                if(board[row][col] != '.') {
                    if(!isValid(board, row, col)) {
                        return false;
                    }
                }
            }
        }

        return true;
    }
};



// Using Hashing.
class Solution
{
public:
    bool isValidSudoku(vector<vector<char> > &board)
    {
        int used1[9][9] = {0}, used2[9][9] = {0}, used3[9][9] = {0};
        
        for(int i = 0; i < board.size(); ++ i)
            for(int j = 0; j < board[i].size(); ++ j)
                if(board[i][j] != '.')
                {
                    int num = board[i][j] - '0' - 1, k = i / 3 * 3 + j / 3;
                    if(used1[i][num] || used2[j][num] || used3[k][num])
                        return false;
                    used1[i][num] = used2[j][num] = used3[k][num] = 1;
                }
        
        return true;
    }
};

// k = i / 3 * 3 + j / 3
// 0  0  0 | 1  1  1 | 2  2  2
// 0  0  0 | 1  1  1 | 2  2  2
// 0  0  0 | 1  1  1 | 2  2  2
// --------+---------+---------
// 3  3  3 | 4  4  4 | 5  5  5
// 3  3  3 | 4  4  4 | 5  5  5
// 3  3  3 | 4  4  4 | 5  5  5
// --------+----------+--------
// 6  6  6 | 7  7  7 | 8  8  8
// 6  6  6 | 7  7  7 | 8  8  8
// 6  6  6 | 7  7  7 | 8  8  8