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

Question : 304. Range Sum Query 2D - Immutable
Topic : DP, Kadane
Problems : https://leetcode.com/problems/range-sum-query-2d-immutable/
*/


// Time Complexity - O(N*M). Using Kadane's.
class NumMatrix {
public:
    vvi mat;
    NumMatrix(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        
        mat.assign(n,vi(m,0));
        for(int i = 0; i < n; i++) for(int j = 0; j < m; j++) mat[i][j] = matrix[i][j];
        
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(i > 0) mat[i][j] += mat[i-1][j];
                if(j > 0) mat[i][j] += mat[i][j-1];
                if(i > 0 && j > 0) mat[i][j] -= mat[i-1][j-1];
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        int subMatSum = mat[row2][col2];
        if(row1 > 0) subMatSum -= mat[row1-1][col2];
        if(col1 > 0) subMatSum -= mat[row2][col1-1];
        if(row1 > 0 && col1 > 0) subMatSum += mat[row1-1][col1-1]; 
        return subMatSum;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */