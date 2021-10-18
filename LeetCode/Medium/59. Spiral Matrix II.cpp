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

Question : 59. Spiral Matrix II
Topic : matrix
Problems : https://leetcode.com/problems/spiral-matrix-ii/

==============================> Explanation <=============================================

- Parent: 54. Spiral Matrix

Ideas comes from here.... (left to right or right to left inclusive)
and (up to down) or (down to up) exclusive.


==============================> Apporach and Time Complexity <=============================================

1) Visiting matrix in spiral way :
Time: O(N^2)
Space: O(1)


*/

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {

        vector<vector<int>> matrix(n, vector<int>(n,0));

        int left = 0, up = 0, right = n - 1, down = n-1;
        int count = 1;

        while(count <= n * n) {
        
            for(int i = left; i <= right && count <= n * n; i++)
                matrix[up][i] = count++; 

            for(int j = up + 1; j <= down-1 && count <= n * n; j++)
                matrix[j][right] = count++;

            for(int i = right; i >= left && count <= n * n; i--)
                matrix[down][i] = count++;

            for(int j = down-1; j >= up+1 && count <= n * n; j--)
                matrix[j][left] = count++;
            
            left++; right--; up++; down--;

        }

        return matrix;
    }
};