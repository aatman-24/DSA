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

Question : 1004. Max Consecutive Ones III
Topic : Two pointer
Problems : https://leetcode.com/problems/max-consecutive-ones-iii/submissions/
*/


class Solution {
public:

    int longestOnes(vector<int>& nums, int k) {

        int i = 0,j = 0;
        int ans = 0;
        while(i < nums.size() && j < nums.size()) {

            while(j < nums.size() && (k > 0 || nums[j] == 1)) {
                if(nums[j] == 0) k--;
                j++;
            }
            ans = max(ans, j-i);
            if(nums[i] == 0) k++;
            i++;
        }
        return ans;
    }

};