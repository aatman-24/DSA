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

Question : 52. N-Queens II
Topic : Recursion, Backtracking, Branch and Bound
Problems : https://leetcode.com/problems/n-queens-ii/

==============================> Explanation <=============================================
- N queen Using brach and bound.

==============================> Edge Case <=============================================

Branch And Bound.
Time = O(2^N^2) -> Every Node has M possiblity.
Space = O(N)(aux) + O(2*N)(diagonal array)

Extra Space For row_ds or cols_ds array which store the position of fixed variable.
Time = O(N * 2^N^2)
Space = O(N)(aux) + O(N)(array)



*/


// Branch and Bound.
class Solution {
public:

    void backtrack(int col, vector<vector<int>> &board,vector<int> &row_ds, vector<int> &leftDiagonal, vector<int> &rightDiagonal,int &count) {
        
        if(col == board.size()) {
            count++;
            return;
        }

        for(int row = 0; row < board.size(); row++) {

            // if(isValid(board, row, col)) {

            if(row_ds[row] == 0 && leftDiagonal[board.size() - 1 + col - row] == 0 && rightDiagonal[row+col]==0) {

                board[row][col] = 1;
                row_ds[row] = leftDiagonal[board.size() - 1 + col - row] = rightDiagonal[row+col] = 1;

                backtrack(col+1, board, row_ds, leftDiagonal, rightDiagonal, count);
                
                row_ds[row] = leftDiagonal[board.size() - 1 + col - row] = rightDiagonal[row+col] = 0;
                board[row][col] = 0;
            }
        }
    }


    int totalNQueens(int n) {

        vector<vector<int>> board(n, vector<int>(n,0));
        vector<int> row(n,0), leftDiagonal(2*n-1), rightDiagonal(2*n-1);
        int count = 0;
        backtrack(0, board, row, leftDiagonal, rightDiagonal, count);
        return count;
    }
};



// Fixed Column. Function Argument.
// For loop Row.
// Whatever is fixed it opposite(here row) array needs to check validity.
// row_ds[c] return the row in which queen is placed into the c row.
class Solution {
public:

      bool isValid(int row, int col, vector<int> row_ds) {

        for(int c = 0; c < col; c++) {

            if(row_ds[c] == row || abs(row_ds[c] - row) == abs(col - c))
                return false;
        }

        return true;
    }



    void backtrack(int col, vector<vector<int>> &board,vector<int> &row_ds, int &count) {
        
        if(col == board.size()) {
            count++;
            return;
        }

        for(int row = 0; row < board.size(); row++) {

            if(isValid(row, col, row_ds)) {

                int tmp = row_ds[col];
                board[row][col] = 1;
                row_ds[col] = row;

                backtrack(col+1, board, row_ds, count);
                
                row_ds[col] = tmp;
                board[row][col] = 0;
            }
        }
    }


    int totalNQueens(int n) {

        vector<vector<int>> board(n, vector<int>(n,0));

        // row[col] -> row. Return in ith column which row contain queen.
        vector<int> row(n, 0);
        int count = 0;
        backtrack(0, board, row, count);
        return count;
    }
};



// Fixed Row. Function Argument.
// For loop Column.
// Whatever is fixed it opposite(here col) array needs to check validity.
// cols_ds[r] return the column in which queen is placed into the r row.
class Solution {
public:

    bool isValid(int row, int col, vector<int> cols_ds) {

        for(int r = 0; r < row; r++) {

            // cols_ds[r] == col means it check that in rth row which column contain queen is same with col or not.
            // abs(r - row) == abs(cols_ds[r] - col) -> It check diagonal
            if(cols_ds[r] == col || abs(r - row) == abs(cols_ds[r] - col))
                return false;
        }

        return true;
    }



    void backtrack(int row, vector<vector<int>> &board, vector<int> &cols_ds, int &count) {
        
        if(row == board.size()) {
            count++;
            return;
        }

        for(int col = 0; col < board.size(); col++) {

            if(isValid(row, col, cols_ds)) {

                int previous_col = cols_ds[row];
                board[row][col] = 1;
                cols_ds[row] = col;

                backtrack(row+1, board, cols_ds, count);
                
                cols_ds[row] = previous_col;
                board[row][col] = 0;
            }
        }
    }



    int totalNQueens(int n) {

        vector<vector<int>> board(n, vector<int>(n,0));
        vector<int> cols(n, 0);
        int count = 0;
        backtrack(0, board, cols, count);
        return count;
    }
};