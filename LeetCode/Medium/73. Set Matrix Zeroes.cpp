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
d
/*
==============================> Description <=============================================

Question : 73. Set Matrix Zeroes
Topic : Matrix, hashing
Problems : https://leetcode.com/problems/set-matrix-zeroes/

==============================> Explanation <=============================================
Solving using O(NM) or O(N+M) extra Space it is easy. means directly we can use
other array to spcify wheather the element is at any row or at any column 0 or not.


But how to do inplace ?

- Logic is same. But here rathar than using extra array for row and column. We use the
first row and first column for that.

- So what about first row and first column in matrix ?
- for that we use two variable which indicate the zero or not into first row and first
column after that we can use it.

- And at last if we fill the matrix with zero. If row or column have zero.


*/


/*
==============================> Edge Case <=============================================


*/

class Solution {

public:

    void setZeroes(vector<vector<int>>& matrix) {

        int m = matrix.size(), n = matrix[0].size();


        bool firstRow = false;
        bool firstCol = false;

        // check for 0th column.
        for(int i = 0; i < m; i++) {
            if(matrix[i][0] == 0) {
                firstCol = true;
                break;
            }
        }

        // check for 0th row.
        for(int i = 0; i < n; i++) {
            if(matrix[0][i] == 0) {
                firstRow = true;
                break;
            }
        }

        // check for other ith and jth indices. if it is zero then make the
        // 0th row and 0th column respective of them zero.
        for(int i = 1; i < m; i++) {
            for(int j = 1; j < n; j++) {
                if(matrix[i][j] == 0) {
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }

        // Done Checking. Make it zero if needed.




        // If any time matrix[i][j] is fill up by zero if corresponding row and column
        // are zero. 
        for(int i = 1; i < m; i++) {
            for(int j = 1; j < n; j++) {
                if(matrix[i][0] == 0 || matrix[0][j] == 0) {
                    matrix[i][j] = 0;
                }
            }
        }

        // for the first col 
        if(firstCol) {
            for(int i = 0; i < m; i++) {
                matrix[i][0] = 0;
            } 
        }

        // for the first row.
        if(firstRow) {
            for(int i = 0; i < n; i++) {
                matrix[0][i] = 0;
            }
        }
    }
};