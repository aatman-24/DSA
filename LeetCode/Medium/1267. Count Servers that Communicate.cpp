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

Question: 1267. Count Servers that Communicate
Topic : Logic, Matrix
Problems : https://leetcode.com/problems/count-servers-that-communicate/


==============================> Explanation <=============================================
- Very simple just need to way the mark the indices so that we can know that is there any element
in given row or column. (1st solution) using extra row and column perform that.


2) Interesting....
- Here We Only check one thing at a time. Means if we checking for row wise first then checking 
column wise next time. 

And each time we keep track of previouse (x, y) which is 1 so we can mark it as 2 with current(x, y).

And last count all the 2.

==============================> Apporach and Time Complexity <=============================================

1) Matrix:
Time: O(N*M)
Space: O(min(N, M))


2) Matrix with Optimization:
Time:O(N*M)
Space:O(1)

*/


class Solution {
public:
    
    int countServers(vector<vector<int>>& grid) {

        int m = grid.size(), n = grid[0].size();

        vector<int> row(m, 0), col(n, 0);

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                    if(grid[i][j]) {
                        row[i]++;
                        col[j]++;
                    }
            }
        }

        int count = 0;
        
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j]) {
                    if(row[i] > 1 || col[j] > 1) {
                        count++;
                    }
                }
            }
        }

        return count;
    }
};




class Solution {
public:
    
    int countServers(vector<vector<int>>& grid)  {

        int m = grid.size(), n = grid[0].size();

        for(int i = 0; i < m; i++) {
            
            int prev_x = -1, prev_y = -1;

            for(int j = 0; j < n; j++) {

                if(grid[i][j]) {
                    if(prev_x == -1 && prev_y == -1) {
                        prev_x = i, prev_y = j;
                    }
                    else {
                        grid[i][j] = 2;
                        grid[prev_x][prev_y] = 2;
                    }
                }
            }
        }

        for(int j = 0; j < n; j++) {
            
            int prev_x = -1, prev_y = -1;

            for(int i = 0; i < m; i++) {

                if(grid[i][j]) {
                    if(prev_x == -1 && prev_y == -1) {
                        prev_x = i, prev_y = j;
                    }
                    else {
                        grid[i][j] = 2;
                        grid[prev_x][prev_y] = 2;
                    }
                }
            }
        }

        int count = 0;
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j] == 2) {
                    count++;
                }
            }
        }


        return count;
    }
};