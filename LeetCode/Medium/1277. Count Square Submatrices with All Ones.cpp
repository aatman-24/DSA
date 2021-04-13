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

Question : 1277. Count Square Submatrices with All Ones
Topic : DP, Kadane's Algorithm.
Problems : https://leetcode.com/problems/count-square-submatrices-with-all-ones/
*/


// Time Complexity - O(N*M*min(N,M)). Using Accumlation Sum, Kadane's Algorithm.
class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        int cnt = 0;

        for(int i = 0; i < n; i++) {
            for(int j = 0;j < m; j++) {
                if(i > 0) matrix[i][j] += matrix[i-1][j];
                if(j > 0) matrix[i][j] += matrix[i][j-1];
                if(i > 0 && j > 0) matrix[i][j] -= matrix[i-1][j-1];
            }
        }

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                for(int k = i, l = j; k < n && l < m; k++, l++) {
                    if(matrix[i][j] == 0) continue;
                    int subMatSum = matrix[k][l];
                    if(i > 0) subMatSum -= matrix[i-1][l];
                    if(j > 0) subMatSum -= matrix[k][j-1];
                    if(i > 0 && j > 0) subMatSum += matrix[i-1][j-1]; 
                    if(floor(sqrt(subMatSum)) == (k-i+1)) cnt++;
                }
            }

        }

        return cnt;
    }
};

// Time Complexity - O(N*M). Using DP.
class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();

        int cnt = 0;

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(matrix[i][j] == 1) {

                    if(i == 0 || j == 0) {
                        cnt++;
                    }
                    else {
                        int formedSquare =  min({matrix[i-1][j], matrix[i][j-1], matrix[i-1][j-1]}) + 1;
                        cnt += formedSquare;
                        matrix[i][j] = formedSquare;
                    }
                }
            }
        }

        return cnt;
    }
};