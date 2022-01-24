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

Question : 53. Maximum Subarray
Topic : Array, DP, Cadene-DP
Problems : https://leetcode.com/problems/maximum-subarray/

==============================> Explanation <=============================================

- Pure Cadene-DP Algorithm.

==============================> Apporach and Time Complexity <=============================================

1) Cadene-DP
Time: O(N)
Space: O(1)

*/

class Solution {
public:
    int maxSubArray(vector<int>& arr) {
        
        int n = (int)arr.size();
        int ans = INT_MIN, sum = 0;   // either use ans = arr[0]. but not 0.

        for(auto it : arr) {
            sum += it;
            ans = max(ans, sum);
            if(sum < 0) sum = 0;
        }

        return ans;
    }
};
