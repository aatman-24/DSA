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

Question : 1351. Count Negative Numbers in a Sorted Matrix
Topic : Logic.
Problems : https://leetcode.com/problems/count-negative-numbers-in-a-sorted-matrix/

==============================> Explanation <=============================================

Time -> O(N + M). Because we traverse only one time entire columns for all the rows.

Check the second solution using binary search.

*/


/*
==============================> Edge Case <=============================================


*/

class Solution {
public:

    // Find the index from the right of row where element is not negative. AFter that
    // in second row you don't need to check backward from that column because all are negative_number
    // as given in problems. 

    // In short, all negative elements are in staircase where stair is either same width or 
    // width is increase.
    int countNegatives(vector<vector<int>>& grid) {

        int n = grid.size(), m = grid[0].size();
        
        int row = 0, col = m - 1;
        int negative_number = 0;


        while(row < n) {

            while(col >= 0 && grid[row][col] < 0) col--;

            negative_number += (m - col - 1);

            row++;
        }

        return negative_number;
    }
};


class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int ans(0);
        
        // Brute Force: O(mn) - check if negative
        for (const vector<int>& row: grid)
            for (const int& i: row)
                if (i < 0) ans++;
        return ans;
        
        // Binary Search: O(m lg(n)) or equivalently O(n lg(m)) - look for break point of each row / column
        for (const vector<int>& row: grid)
            ans += upper_bound(row.rbegin(), row.rend(), -1) - row.rbegin();
        return ans;
        
        // Search Break Points: O(m + n) - traverse from upper right to lower left
        int m(grid.size()), n(grid[0].size()), r(0), c(n - 1);
        while (r < m) {
            while (c >= 0 && grid[r][c] < 0) c--;
            ans += n - c - 1;
            r++;
        }
        return ans;
    }
};