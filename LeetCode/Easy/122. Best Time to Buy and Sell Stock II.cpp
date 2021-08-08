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

/*
==============================> Description <=============================================

Question : 122. Best Time to Buy and Sell Stock II
Topic : Greedy
Problems : https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/
/*
==============================> Explanation <=============================================
- keep track of low and high price of stock.
- if any day the price is low -> sell the stock and purchase this low price stock.
- If price is greater than low. Then check if maximum price is increases or decrease. If incrase then update the high
price. If it is decrease then sell the stock and puchase on that amount.


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

            // If we found stock in less amount than low. We sell the stock and purchase this low amount stock.
            if(num <= low) {
                if(high != INT_MIN && low != INT_MAX) profit += (high - low);
                low = high = num;
            }
            else {
                // If current value of stock is less than our current high. sell the stock.
                if(num < high) {
                    profit += (high - low);
                    low = high = num;
                }

                // Otherwise keep increase the high.
                else {
                    high = num;
                }
            }
        }

        profit += (high - low);

        return profit;

    }
};