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

Question:  799. Champagne Tower
Topic :Top-Down Bottom-up Pattern= MultiDimesional DP
Problems : https://leetcode.com/problems/champagne-tower/

==============================> Explanation <=============================================

- Dp variant = MultiDimesional DP.


- Here, dp[i][j] represent how much water is filled in the glass jth in ith row.


1) Choise Diagram: We can fill the (i, j) water from (i-1, j-1) and (i-1, j) glasses.
                   total water we can got from that glasses is,

                    (glass(i-1, j-1) - 1) / 2
                    (glass(i-1, j) - 1) / 2

                    - Remaining half water from both the glass.

2) Base Case: i = 0 && j = 0, we poured all the water into the (0,0) glass.
              i < 0 ||  j < 0 || j > i -> No water we got from the above state so return 0.
              
3) Recurrance Relation:
    
        dp[i][j] = max((dp[i-1][j-1] - 1 / 2), 0)  + max((dp[i-1][j] - 1 / 2), 0)

- Space optimization is possible because we just using the previous (i-1) information.

==============================> Apporach and Time Complexity <=============================================

1) Top-Down Bottom-up Pattern=MultiDimesional DP
Time: O(N^2)
Space: O(N^2)

2) Space Optimization Bottom-up Pattern= MultiDimesional DP
Time: O(N^2)
Space: O(N)

*/


class Solution {
public:

    double t[101][101];

    double champagneTowerSolve(int i, int j, int poured) {

        // base case. 
        if(i == 0 && j == 0)
            return poured;

        if(i < 0 || j < 0 || j > i)
            return 0;
        
        if(t[i][j] != -1)
            return t[i][j];

        // if and only water is poured from the above glass. Otherwise take 0.
        double left = max((champagneTowerSolve(i-1, j-1, poured) - 1)/2, 0);
        double right = max((champagneTowerSolve(i-1, j, poured) - 1)/2, 0);
        
        return t[i][j] = left + right;
    }

    double champagneTower(int poured, int query_row, int query_glass) {

        for(int i = 0; i <= query_row; i++) {
            for(int j = 0; j <= i; j++) {
                t[i][j] = -1;
            }
        }

        double water = champagneTowerSolve(query_row, query_glass, poured);

        return (water > 1) ? 1 : water;
    }
};



class Solution {
public:

    double champagneTower(int poured, int query_row, int query_glass) {

        double dp[101][101] = {0.0};

        // base case
        dp[0][0] = poured;

        for(int i = 1; i <= query_row; i++) {
            
            for(int j = 0; j <= i; j++) {

                if(j-1 >= 0) dp[i][j] += max((dp[i-1][j-1] - 1) / 2 , 0.0);
                dp[i][j] += max((dp[i-1][j]-1)/2, 0.0); 
            
            }
        }

        double water = dp[query_row][query_glass];

        return (water > 1) ? 1 : water;
    }
};


class Solution {
public:

    double champagneTower(int poured, int query_row, int query_glass) {

        vector<double> dp(101, 0.0);
        dp[0] = poured;

        for(int i = 1; i <= query_row; i++) {
            

            // store the current row value here.
            vector<double> copy_dp(101, 0.0);

            for(int j = 0; j <= i; j++) {

                if(j-1 >= 0) copy_dp[j] += max((dp[j-1] - 1) / 2 , 0.0);
                copy_dp[j] += max((dp[j]-1)/2, 0.0); 
            
            }

            // swap the row
            dp = copy_dp;
        }

        double water = dp[query_glass];

        return (water > 1) ? 1 : water;
    }
};
