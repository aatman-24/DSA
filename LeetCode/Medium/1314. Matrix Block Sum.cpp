#include <bits/stdc++.h>
#define ll long long
#define REP(i,n) for(int i = 0; i < n; i++)
#define REP1(i,n) for(int i = 1; i <= n; i++)
#define debug cout << "Ok" << endl;
#define mod 1000000007

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

Question : 1314. Matrix Block Sum
Topic : DP, Kadane
Problems : https://leetcode.com/problems/matrix-block-sum/
*/


// Time Complexity - O(N*M). Using Kadane's.
class Solution {
public:
    vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int k) {
        int n = mat.size();
        int m = mat[0].size();
        vvi ans(n, vi(m,0));


        REP(i,n) REP(j,m) {
            if(i > 0) mat[i][j] += mat[i-1][j];
            if(j > 0) mat[i][j] += mat[i][j-1];
            if(i > 0 && j > 0) mat[i][j] -= mat[i-1][j-1];
        }



        REP(i,n) {
            REP(j,m) {

             int row1 = max(0, i-k);
             int col1 = max(0, j-k);
             int row2 = min(i+k, n-1);
             int col2 = min(j+k, m-1);


            int subMatSum = mat[row2][col2];
            if(row1 > 0) subMatSum -= mat[row1-1][col2];
            if(col1 > 0) subMatSum -= mat[row2][col1-1];
            if(row1 > 0 && col1 > 0) subMatSum += mat[row1-1][col1-1]; 

             ans[i][j] = subMatSum;


            }
        }
        return ans;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */