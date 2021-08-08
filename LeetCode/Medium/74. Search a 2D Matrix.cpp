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

Question : 74. Search a 2D Matrix
Topic : Binary Search
Problems : https://leetcode.com/problems/search-a-2d-matrix/

==============================> Explanation <=============================================



*/


/*
==============================> Edge Case <=============================================


*/

class Solution {
public:


    bool findTarget(vector<int> &A, int target) {

        int l = 0, h = A.size() - 1;
        while(l <= h) {

            int md = (l + h) >> 1;

            if(A[md] == target)
                return true;
            else if( A[md] < target)
                l = mid + 1;
            else
                h = mid - 1;
        }

        return false;

    }

    // Apply the BS to row by row and check the target elememt.

    // Time complexity = O(N * logM)
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
     
        for(auto row: matrix) {
            if(findTarget(row, target))
                return true;
        }
        return false;   
    }



    // Count all matrix as single row and apply the binary search.

    // How to find the element row and column.
    // if there are total m column into the matrix.
    // current_row = md / m
    // currnet_col = md % m

    // Time complexity = log(M*N)
    bool searchMatrix(vector<vector<int>>& matrix, int target) {

        int m = matrix.size(), n = matrix[0].size();
        int l = 0, h = (m * n - 1);

        while(l <= h) {

            int md = (l + h) >> 1;

            if(matrix[md/n][md%n] == target)
                return true;
            else if(matrix[md/n][md%n] < target)
                l = md + 1;
            else
                h = md - 1;
        }

        return false;
    }
};