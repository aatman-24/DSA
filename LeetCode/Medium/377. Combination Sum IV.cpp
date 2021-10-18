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

Question: 377. Combination Sum IV
Topic :Top-Down Bottom-up Pattern= Target Sum, Coin Change
Problems : https://leetcode.com/problems/combination-sum-iv/

==============================> Explanation <=============================================
- Dp variant = Target Sum, Coin Change.

1) Choise Diagram: Target is 4. Answer can be (1, 1, 2), (1, 2, 1), (2, 1, 1) then it is clear indicate
that rathar than starting from the next index we should start from the 0 index. just same
as coin change 1Dp.

2) Base Case: target = 0 then return 1.
              

3) Recurrance Relation:
    
        For(num : nums)
        if(num <= target)
            dp[i] += dp[i-num];
    

- Space optimization we can go for the 1D as you see in Top-Down the current index is only
used for the memo we can replacet the t[][] -> t[] into 1D.
==============================> Apporach and Time Complexity <=============================================

1) Top-Down Pattern=Target Sum, Coin Change
Time: O(N^2)
Space: O(N^2)

2) Bottom-up Pattern= Target Sum, Coin Change
Time: O(N^2)
Space: O(N)

*/


class Solution {

public:
    
    int t[201][1001];
    
    int combinationSum4(int index, int cur, vector<int>&nums) {

        if(cur == 0)
            return 1;

        if(cur < 0)
            return 0;

        if(t[index][cur] != -1)
            return t[index][cur];

        int ways = 0;
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] <= cur) {
                ways += combinationSum4(i, cur-nums[i], nums);
            }
        }

        return t[index][cur] = ways;
    }

    int combinationSum4(vector<int>& nums, int target) {

        memset(t, -1, sizeof(t));

        return combinationSum4(0, target, nums);
    }
};

    
// coin change templates
class Solution {
public:
    int combinationSum4(vector<int>& N, int T) {
        vector<unsigned int> dp(T+1, 0);
        dp[0] = 1;
        for (int i = 1; i <= T; i++)
            for (int num : N)
                if (num <= i) dp[i] += dp[i-num];
        return dp[T];
    }
};