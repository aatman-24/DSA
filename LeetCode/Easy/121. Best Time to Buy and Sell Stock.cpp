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
Topic : Greedy, DP=Pattern=BuySellStock, Kadane
Problems : https://leetcode.com/problems/best-time-to-buy-and-sell-stock/
/*
==============================> Explanation <=============================================
Greedy Apporach:

- Just need to buy and sell once. For sell the stock you must buy the stocks. Easy Equation buy in low price
and sell into the high price.
- keep track of low and high price whenever we found the maximum (high - low). we purchase it.
- But when we found current price is less than low. We make low = high = price. So high value comes after the
low price day.


1) Regular Question:

Dynamic Programming:

- Equation is same buy in low price and sell it into the higher price and make max profit.

How DP ?

- Suppose at current ith day, We want to sell it then we need to know what is minimum price we can puchase it
before the selling....

- So Idea is clear we need to know(keep track of) best day to puchase the stock...

So Here DP is in term of buying the sell in minimum price. We need to keep track of minimum price.

Choice Diagram: dp[i] = min(stock[i], dp[i-1])

Base Case: dp[0] = stock[0] -> Directly buy the stock on the first day.

Recurrance Relation: 
1) dp[i] = min(stock[i], dp[i-1])
2) maxProfit = max(maxProfit, stock[i] - dp[i-1]) -> current Day Stock Price - (from all previous day minimum stock price we need to buy)




2) Twisted Question:

Dynamic Programming Kadane Algorithm: 

- In Regular Question Stock price of the every day is given, But in case of that the difference of the 
day's price is given then How to solve ?

{1, 7, 4, 11} -> {0, 6, -3, 7}

Then It become the max subarray Sum problem. How ?


0  -> d1 - d1
6  -> d2 - d1
-3 -> d3 - d2
7  -> d4 - d3

We need to find subarray, either (d4-d1) or (d4-d2) or (d3-d1) in general [a, b] 
which indicate that, purchase the stock at b day and sell it at A day which given maximum profit.

Then we already know how to find maximum subarray sum -> use Kadane Algortihm.

We can covert this problem into that by taking the differnce check 3rd solution:



Series of Buy and Sell Stock:

121. Best Time to Buy and Sell Stock
122. Best Time to Buy and Sell Stock II

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


class Solution {
public:
    int maxProfit(vector<int>& prices) {

        // keep track of minimum price to buy a stock.
        vector<int> dp(prices.size(), 0);

        // base
        // Not have any choice must buy the stock on 0th day.
        dp[0] = prices[0];          

        int maxProfit = 0;
        for(int i = 1; i < prices.size(); i++) {
            maxProfit = max(maxProfit, prices[i] - dp[i-1]);
            dp[i] = min(dp[i-1], prices[i]);
        }

        return maxProfit;
    }
};



class Solution {
public:
    int maxProfit(vector<int>& prices) {

        int maxProfit = 0, curSum = 0;

        for(int i = 1; i < prices.size(); i++) {
            
            curSum += prices[i] - prices[i-1];
            curSum = max(0, curSum);        // never drop the curSum to negative Value.
            
            maxProfit = max(maxProfit, curSum);
        }

        return maxProfit;
    }
};