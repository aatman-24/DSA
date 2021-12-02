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

Question: 1039. Minimum Score Triangulation of Polygon
Topic : Top-Down Bottom-up Pattern=MultidimesionalDP
Problems : https://leetcode.com/problems/minimum-score-triangulation-of-polygon/

==============================> Explanation <=============================================

- Dp variant = IntervalDP, MCM Version.

- Same to same of MCM.

1) Choise Diagram: 
- Fixed One of the Side of Polygon(i, j)[Or Either Two points] and choose the Third Point K between [i, j]
So, [i, j, k] points make one triangle... which cost A[i] * A[j] * A[k] and add the cost of remaining
[i, k] + [k, j] triangulation cost.

2) Base Case: N < 2 [(j - i < 2)] return 0.
              
3) Recurrance Relation:
            
    for(int k = i + 1; k < j; k++) {        // Notice here, k should be between (i, j).
        dp[i][j] = min(dp[i][j], dp[i][k] + arr[i] * arr[k] * arr[j] + dp[k][j]);
    }
        
==============================> Apporach and Time Complexity <=============================================

1) Top-Down Bottom-up Pattern=IntervalDP
Time: O(N^2)
Space: O(N^2)

*/

class Solution {
public:
    int t[51][51];

    int minScoreTriangulation(int i, int j, vector<int> &arr) {
        
        // need three point to make triangle.
        if(j - i < 2)
            return 0;
        
        if(t[i][j] != -1)
            return t[i][j];

        int res = INT_MAX;
        for(int k = i + 1; k < j; k++) {
            res = min(res, minScoreTriangulation(i, k, arr) + arr[i] * arr[k] * arr[j] + minScoreTriangulation(k, j, arr));
        }

        return t[i][j] = res;
    }

    int minScoreTriangulation(vector<int>& values) {

        memset(t, -1, sizeof(t));

        return minScoreTriangulation(0, values.size()-1, values);

    }
};


class Solution {
public:
    
    int minScoreTriangulation(vector<int>& arr) {

        int N = arr.size();

        int dp[N][N];
        memset(dp, 0, sizeof(dp));


        for(int len = 2; len < N; len++) {          // I just copied the template of the IntervalDP.

            for(int i = 0; i + len < N; i++) {

                int j = i + len;

                int res = INT_MAX;

                for(int k = i + 1; k < j; k++) {

                    res = min(res, dp[i][k] + arr[i] * arr[k] * arr[j] + dp[k][j]);     // And change this one.
                }       

                dp[i][j] = res;
            }
        }

        return dp[0][N-1];    
    }
};