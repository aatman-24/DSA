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

Question: 1547. Minimum Cost to Cut a Stick
Topic : Top-Down Bottom-up Pattern=IntervalDP
Problems : https://leetcode.com/problems/minimum-cost-to-cut-a-stick/

==============================> Explanation <=============================================
You must have to cut at given points. But you can choose any order to cut. 

1) Brute Force: O(N*N!)   -> Order -> Permutation -> And count the cost.


Dp variant = IntervalDP.

1) Choise Diagram: 

We first sort the given cuts array so it is easy to keep track of cut points in sequence(0->N).
We try cut at given every points and got the cost for the left and right side stick and add into that
cost and choose minimum. 

But here we needs to keep track of leftBoundary and rightBoundary reason is cost is calculated based on
that.

We have two options:

1) Include left and right boundary into the function signature -> First Method (I Codeded)

2) Include (0, N) into the cuts. But don't cut at this poins. (Which is good and also follow template of
IntervalDP).

2) Base Case: (rightBoundary - leftBoundary) <= 1 return 0. We can not cut into this smaller region.
              
3) Recurrance Relation:

   dp[i][j] = max(dp[i][j], dp[i][k] + arr[j]-arr[i] + dp[k][j]);
             
dp[i][j] -> Given the minimum cost by cutting the all the points of cuts array between [i, j] index(included).           



How to set left and right boundary ?

- You got idea using pen and paper only.


==============================> Apporach and Time Complexity <=============================================

1) Top-Down Bottom-up Pattern=IntervalDP
Time: O(N^2)
Space: O(N^2)

*/

class Solution {
public:

    int t[101][101];

    int minCost(int i, int j, int left, int right, vector<int> &cuts) {

        if(i > j || left >= right)
            return 0;

        if(t[i][j] != -1)
            return t[i][j];

        int cost = INT_MAX;
        for(int k = i; k <= j; k++) {

            // see the new left and right boundary.
          cost = min(cost, minCost(i, k-1, left, cuts[k], cuts) + (right - left) + minCost(k+1, j, cuts[k], right, cuts)); 
        }

        return t[i][j] = cost;
    }


    int minCost(int n, vector<int>& cuts) {

        sort(cuts.begin(), cuts.end());
        memset(t, -1, sizeof(t));

        return minCost(0, cuts.size()-1, 0, n, cuts);
    }
};


class Solution {
public:

    int t[103][103];

    int minCost(int i, int j, vector<int> &cuts) {

        if(j - i <= 1)
            return 0;

        if(t[i][j] != -1)
            return t[i][j];

        int cost = INT_MAX;
        for(int k = i+1; k < j; k++) {
            // see the new left and right boundary.
          cost = min(cost, minCost(i, k, cuts) + (cuts[j] - cuts[i]) + minCost(k, j, cuts)); 
        }

        return t[i][j] = cost;
    }


    int minCost(int n, vector<int>& cuts) {

        cuts.push_back(0);
        cuts.push_back(n);
        sort(cuts.begin(), cuts.end());
        
        memset(t, -1, sizeof(t));

        return minCost(0, cuts.size()-1, cuts);
    }
};



class Solution {
public:

       int minCost(int n, vector<int>& cuts) {

        cuts.push_back(0);
        cuts.push_back(n);
        sort(cuts.begin(), cuts.end());

        int N = cuts.size();
           
        int dp[N+1][N+1];
        memset(dp, 0, sizeof(dp));
    
        for(int len = 2; len < N; len++) {              // check from the base case j - i <= 1. start len = 2.

            for(int i = 0; i + len < N; i++) {          // we add boundary (0, n) so we don't cut there that's why
                
                int j = i + len;

                dp[i][j] = INT_MAX;
                
                for(int k = i + 1; k < j; k++) {        // always check here your boundary is working well or not.

                    dp[i][j] = min(dp[i][j], dp[i][k] + cuts[j] - cuts[i] + dp[k][j]);
                }
            }

        }

        return dp[0][N-1];
    }
};