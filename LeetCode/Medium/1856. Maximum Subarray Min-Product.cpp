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

Question : 1856. Maximum Subarray Min-Product
Topic : Stack
Problems : https://leetcode.com/problems/maximum-subarray-min-product/

/*
==============================> Edge Case <=============================================
2] solution: i == n.size() when all elements are coverd and all are in incresing order for that.


IN both soultion prefix sum is handled differntly.
*/


/*
==============================> Explanation <=============================================
Apporach is same for both solution. for maximum the sum we expand both side until we 
found element which is smaller than current element. and every time current element will be 
our minimum element for subarray.


for sum we used prefix sum.
*/


#include <bits/stdc++.h>
#define ll long long
#define REP(i,n) for(int i = 0; i < n; i++)
#define REP1(i,n) for(int i = 1; i <= n; i++)
#define debug cout << "Ok" << endl;
#define mod 1000000007

class Solution {
public:

    ll getSum(ll presum[], int left, int right) {
        return presum[right+1] - presum[left];
    }

    // O(N) - O(N) [stack + sum prefix + boundary identify first]
    int maxSumMinProduct(vector<int>& nums) {

        int n = nums.size();

        int left_bound[n], right_bound[n];
        memset(left_bound, 0, sizeof(left_bound));
        memset(left_bound, 0, sizeof(right_bound));

        stack<int> st;
        for(int i = 0; i < n; i++) {
            while(!st.empty() && nums[st.top()] >= nums[i]) st.pop();
            if(!st.empty()) {
                left_bound[i] = st.top() + 1;
            }   
            else {
                left_bound[i] = 0;
            }
            st.push(i);
        }

        while(!st.empty()) st.pop();

        for(int i = n-1; i >= 0; i--) {
            while(!st.empty() && nums[st.top()] >= nums[i]) st.pop();
            if(!st.empty()) {
                right_bound[i] = st.top() - 1;
            }   
            else {
                right_bound[i] = n-1;
            }
            st.push(i);
        }


        ll prefix_sum[n+1];
        memset(prefix_sum, 0, sizeof(prefix_sum));

        //stored at (i+1)th index.
        for(int i = 0; i < n; i++) {
            prefix_sum[i+1] = prefix_sum[i] + nums[i];
        }

        ll maxProduct = 0;
        for(int i = 0; i < n; i++) {
            maxProduct = max(maxProduct, getSum(prefix_sum, left_bound[i], right_bound[i]) * nums[i]);
        }

        return int(maxProduct % mod);
    }


    // O(N) - O(N) [stack + sum prefix + boundary identify at run time]
    int maxSumMinProduct(vector<int>& n) {
    
        vector<ll> prefix_sum(n.size() + 1);
        stack<int> st;

        for(int i = 0; i < n.size(); i++)
            prefix_sum[i+1] = prefix_sum[i] + n[i];

        ll maxProduct = 0;
        for(int i = 0; i <= n.size(); i++) {
            while(!st.empty() && (i == n.size() || n[st.top()] >= n[i])) {
                int j = st.top();
                st.pop();
                maxProduct = max(maxProduct, (prefix_sum[i] - prefix_sum[st.empty() ? 0 : st.top() + 1]) * n[j]);
            }
            st.push(i);
        }

        return int(maxProduct % mod);
    }
};