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

Question: 1895. Largest Magic Square
Topic : prefixSum
Problems : https://leetcode.com/problems/largest-magic-square/

==============================> Explanation <=============================================
- Take four seperate, prefix sum row, col, leftdiagonal, rightDiagonal
- start from k = min(n, m) to k >= 2 for any k if we found matrix return that k.

Rathar than taking four prefix sum, we can calculate for left and right diagonal while running. which reduce
the cost and add time.

==============================> Apporach and Time Complexity <=============================================
1) Prefix Sum with Two Matrix:
Time: O(K^2 * N*M)
Space: O(M*N) 

2) Prefix sum with Four Matrix:
Time: O(K * M * N)
Space: O(M*N)

*/


class Solution {
public:
    
    int m, n;
    vector<vector<int>> preRow, preCol;

    int largestMagicSquare(vector<vector<int>>& grid) {


        m = grid.size(), n = grid[0].size();


        // preRow Extra Column is added 0th col
        // preCol Extra Row is added. 0th row
        preRow.assign(m, vector<int>(n+1, 0)); preCol.assign(m+1, vector<int>(n, 0));
       
        // Row Prefix
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                preRow[i][j+1] = preRow[i][j] + grid[i][j];
            }
        }

        // Column prefix
        for(int j = 0; j < n; j++) {
            for(int i = 0; i < m; i++) {
                preCol[i+1][j] = preCol[i][j] + grid[i][j];
            }
        }

        // max length of k is min(n,m)
        for(int k = min(n, m); k > 1; k--) {
            if(test(grid, k))
                return k;
        }

        return 1;
    }



    bool test(vector<vector<int>> &grid, int k) {

        // At Every Valid (r, c) we try to make K*K matrix.
        for(int r = 0; r + k - 1 < m; r++) {

            for(int c = 0; c + k - 1 < n; c++) {

                // Calculate the distance of diag and antidiag for current k.
                int diag = 0, antidiag = 0;

                for(int d = 0; d < k; d++) {
                    diag += grid[r+d][c+d];
                    antidiag += grid[r+d][c+k-1-d];
                }


                bool match = diag == antidiag;

                for(int nr = r; nr < r + k && match; nr++)
                    match = diag == getSumRow(nr, c, c + k - 1);    // inclusive

                for(int nc = c; nc < c + k && match; nc++) 
                    match = diag == getSumCol(r, nc, r + k - 1);    // inclusive

                if(match)
                    return true;
            }
        }

        return false;
    }


    int getSumRow(int r, int c1, int c2) {

        // +1 because of preRow is added one more column. If we don't add then for the 0th column we have 
        // to write condition which is complex.
        return preRow[r][c2+1] - preRow[r][c1]; 
    }


    int getSumCol(int r1, int c, int r2) {
        // +1 add more row is added in the preCol.
        return preCol[r2+1][c]- preCol[r1][c] ;
    }

};
