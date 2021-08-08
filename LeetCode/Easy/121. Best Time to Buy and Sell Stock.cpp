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
d
/*
==============================> Description <=============================================

Question : 121. Best Time to Buy and Sell Stock
Topic : Greedy
Problems : https://leetcode.com/problems/best-time-to-buy-and-sell-stock/
/*
==============================> Explanation <=============================================
- Just need to buy and sell once.

- keep track of low and high price whenever we found the maximum (high - low). we purchase it.
- But when we found current price is less than low. We make low = high = price. So high value comes after the
low price day.


Series of Buy and Sell Stock:

121. Best Time to Buy and Sell Stock
122. Best Time to Buy and Sell Stock II


Time = O(N)
Space = O(1)
*/


/*
==============================> Edge Case <=============================================


*/


class Solution {
public:

    int maxProfit(vector<int>& prices) {

        int profit = 0;
        int low = INT_MAX, high = INT_MIN;

        for(int num: prices) {

            if(num < low) {
                low = high = num;
            }
            else if(num > low) {
                high = num;
            }

            profit = max(profit, high-low);
        }

        return profit;
    }

};