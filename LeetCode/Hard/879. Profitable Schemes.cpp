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

Question: 879. Profitable Schemes
Topic :Top-Down Pattern=Bounded Knapsack
Problems : https://leetcode.com/problems/profitable-schemes/

==============================> Explanation <=============================================
- Dp variant = Bounded Knapsack,

- Take it don't take it.

- Space Optimization is possible, because only previous(idx-1) 2D matrix is needed.

==============================> Apporach and Time Complexity <=============================================

1) Top-Down Pattern=Bounded Knapsack
Time: O(n * N * minProfit)
Space: O(n * N * minProfit)

*/



#define mod 1000000007


class Solution {
public:
    
    int t[101][101][101];

    long profitableSchemes(int idx, int n, int minProfit, vector<int>& group, vector<int>& profit) {
        
        if(idx == 0)
            return (minProfit <= 0) ? 1 : 0;


        // Here we stored previously at 0th index for negative value so we used that one.
        if(t[idx][n][max(0, minProfit)] != -1)
            return t[idx][n][max(0, minProfit)];

        long best = 0;
        if(group[idx-1] <= n) {
            best = (profitableSchemes(idx-1, n - group[idx-1], minProfit-profit[idx-1], group, profit) +
            profitableSchemes(idx-1, n, minProfit, group, profit)) ;
        }
        else {
            best = profitableSchemes(idx-1, n, minProfit, group, profit);
        }

        // we don't store the negative minProfit at negative index, rathar than use the 
        // 0th index for that.
        return t[idx][n][max(0, minProfit)] = best % mod;

    }

    int profitableSchemes(int n, int minProfit, vector<int>& group, vector<int>& profit) {

        memset(t, -1, sizeof(t));

        return profitableSchemes(group.size(), n, minProfit, group, profit);
    }
};