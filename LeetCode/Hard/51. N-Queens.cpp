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

Question : 51. N-Queens
Topic : Recursion, Backtracking, Brach and bound
Problems : https://leetcode.com/problems/n-queens/

==============================> Explanation <=============================================
- N queen Using brach and bound.

==============================> Edge Case <=============================================

Time = O(2^N^2) -> Every Node has M possiblity.
Space = O(N)(aux) + O(2*N)(diagonal array)


*/


class Solution {
public:

    void solve(int col, vector<string> &board, vector<vector<string>> &ans, vector<int> &leftRow,vector<int> &leftDiagonal,vector<int> &rightDiagonal, int n) {
        if(col == n) {
            ans.push_back(board);
            return;
        }

        for(int row = 0; row < n; row++) {
            
            if(leftRow[row] == 0 && leftDiagonal[row+col] == 0 && rightDiagonal[n-1+col-row] == 0) {

                board[row][col] = 'Q';
                leftRow[row] = leftDiagonal[row+col] = rightDiagonal[n-1+col-row] = 1;

                solve(col+1, board, ans, leftRow, leftDiagonal, rightDiagonal, n);

                board[row][col] = '.';
                leftRow[row] = leftDiagonal[row+col] = rightDiagonal[n-1+col-row] = 0;
            }
        }
    }


    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
       
        vector<string> board(n);
        string s(n, '.');
        for(int i = 0; i < n; i++) board[i] = s;

        vector<int> leftRow(n, 0), leftDiagonal(2*n-1, 0), rightDiagonal(2*n-1,0);
        solve(0, board, ans, leftRow, leftDiagonal, rightDiagonal, n);
        return ans;
    }
};