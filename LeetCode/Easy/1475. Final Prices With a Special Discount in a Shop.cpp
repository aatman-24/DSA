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

Question : 1475. Final Prices With a Special Discount in a Shop
Topic : Monotone  stack
Problems : https://leetcode.com/problems/final-prices-with-a-special-discount-in-a-shop/
pattern : 1 Monotone stack

/*
==============================> Edge Case <=============================================

*/


/*
==============================> Explanation <=============================================

*/

class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        int n = prices.size();
        vector<int> ans(prices);
        stack<int> st;

        for(int i = 0; i < n; i++) {
            while(!st.empty() && prices[st.top()] >= prices[i]) {
                int j = st.top(); st.pop();
                ans[j] -= prices[i];
            }
            st.push(i);
        }

        return ans;
    }

};