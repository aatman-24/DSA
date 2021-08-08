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

Question : 1695. Maximum Erasure Value
Topic : Two pointer
Problems : https://leetcode.com/problems/maximum-erasure-value/
*/


class Solution {
public:

    int maximumUniqueSubarray(vector<int>& nums) {

        vi mark(10001, -1);
        
        int lft=0, rht=0, ans=0, cursum = 0;

        while(rht < nums.size()) {

            if(mark[nums[rht]] == -1) {
                cursum += nums[rht];
                mark[nums[rht]] = 0;
                rht++;  

            }
            else {
                ans = max(ans, cursum);
                while(lft < nums.size() && nums[lft] !=  nums[rht]) {
                    cursum -= nums[lft];
                    mark[nums[lft]] = -1;
                    lft++;
                }
                cursum -= nums[lft];
                mark[nums[lft]] = -1;
                lft++;      
            }
            ans = max(ans, cursum);
        }
        return ans;

    }
};