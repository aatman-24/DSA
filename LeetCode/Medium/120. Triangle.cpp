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

Question: 120. Triangle
Topic :Top-Down Bottom-up Pattern=Multi Dimensions DP
Problems : https://leetcode.com/problems/triangle/

==============================> Explanation <=============================================
- Dp variant = Multi Dimensions DP,

- Here clearly given that either you can choose from [i+1][j] or [i+1][j+1] whatever is minimum.

1) Choise Diagram: We can choose from nextRow,sameColumn or nextRow,column+1 which ever is minimum.

2) Base Case: When curRow >= triangle.size() then we return 0.
              And  curCol >= triangle[curRow].size() then we also return 0.

3) Recurrance Relation:
         dp[i][j] = min(dp[i+1][j], dp[i+1][j+1]) + triangle[i][j].

         i and j represent the curRow and curCol.

- as you see in above relation the current row ith value is depend only on the next row then
we can optimize the space by O(N).

==============================> Apporach and Time Complexity <=============================================

1) Top-Down Bottom-up Pattern=Multi Dimensions DP
Time: O(N^2)
Space: O(N^2)

2) Space Optimization:
Time: O(N^2)
Space: O(N)

*/


// top-down 
class Solution {
public:

    int t[201][201];


    int minimumTotal(int curRow, int curCol, vector<vector<int>> &triangle) {

        // base case. out of boundary return 0.
        if(curRow >= triangle.size() || curCol >= triangle[curRow].size())
            return 0;

        if(t[curRow][curCol] != -1)
            return t[curRow][curCol];

        return t[curRow][curCol] = min(minimumTotal(curRow+1, curCol, triangle), minimumTotal(curRow+1, curCol+1, triangle)) + triangle[curRow][curCol];
    }


    int minimumTotal(vector<vector<int>>& triangle) {

        memset(t, -1, sizeof(t));

        return minimumTotal(0, 0, triangle);
    }
};


class Solution {
public:

    int minimumTotal(vector<vector<int>>& triangle) {

        int n = triangle.size();

        int dp[201][201];
        memset(dp, 0, sizeof(dp));


        // i -> n - 1 to 0.
        // j -> 0 -> m.
        for(int i = n-1; i >= 0; i--) {
            for(int j = 0; j < triangle[i].size(); j++) {
                dp[i][j] = min(dp[i+1][j],dp[i+1][j+1]) + triangle[i][j];
            }
        }

        return dp[0][0];
    }

};



class Solution {
public:

    int minimumTotal(vector<vector<int>>& triangle) {

        int n = triangle.size();

        vector<int> dp(triangle[n-1].size() + 1, 0);

        for(int i = n-1; i >= 0; i--) {

            // here we first till the 0, 1, ... m entry so value is not overwrite. 
            // if overwrite is possible in all the case use the other vector for that.
            for(int j = 0; j < triangle[i].size(); j++) {
                dp[j] = min(dp[j],dp[j+1]) + triangle[i][j];
            }
        }

        return dp[0];
    }
};