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

Question: 213. House Robber II
Topic : Linear-DP pattern=Fibonaci
Problems : https://leetcode.com/problems/house-robber-ii/

==============================> Explanation <=============================================

Same as, 198. House Robber.. with one additional restriction... can not take both first and last together.

Everything is same...

But subproblem is occured, we perform same algorithm two times...

1) (0 -> N-2) (Last one not included)
2) (1 -> N-1) (First one included)

And take maximum of them.

Reason is that there are total three case for (first and last)

Not Rob first, Not Rob last
Not Rob First, Rob last
Rob First, Not Rob last

Which is covered into two subproblems. 1) Don't Rob last (Rob or not rob first)
                                       2) Don't Rob first (Rob or not rob last)

==============================> Apporach and Time Complexity <=============================================
1) Top-Down + Bottom-UP Linear-DP pattern=Fibonaci:
Time: O(N)
Space: O(N)(Memorization)


*/


// Top-Down (memorization)
class Solution {
public:
    int mostLoot(int n, vector<int>& nums, int t[]) {

        if(n < 0)
            return 0;

        if(t[n] != -1)
            return t[n];

        return t[n] = max(mostLoot(n-1, nums, t), mostLoot(n-2, nums, t) + nums[n]);
    }

    int rob(vector<int>& nums) {

        int n = nums.size();
        if(n == 1)
            return nums[0];

        // first subproblem -> Include the first house and exclude the last house.
        int t[nums.size()];
        memset(t, -1, sizeof(t));
        int firstIncluded = mostLoot(n-2, nums, t);


        // second subproblem -> Include the last house and exclude the first house.
        memset(t, -1, sizeof(t));
        vector<int> num2(nums.begin()+1, nums.end());
        int lastIncluded = mostLoot(num2.size() - 1, num2, t);

        return max(firstIncluded, lastIncluded);
    }
};



// Bottom-up 
class Solution {
public:

    int rob(vector<int>& nums) {

        int n = nums.size();
        if(n == 1)
            return nums[0];

        // first Included and last not included
        int dp1[n+1];       // 0 -> N-1.
        memset(dp1, 0, sizeof(dp1));
        dp1[0] = 0;          // n < 0 -> That time used.     
        dp1[1] = nums[0];    // n == 0 -> That time used.



        // Last Included and first not included
        int dp2[n+2];       // 1 -> N.
        memset(dp2, 0, sizeof(dp2));
        dp2[1] = 0;
        dp2[2] = nums[1];


        for(int i = 2; i < n; i++) {

            dp1[i] = max(dp1[i-1], dp1[i-2]+nums[i-1]);   // Dp Table is 1 based index and nums is 0th based index.
            
            dp2[i+1] = max(dp2[i], dp2[i-1]+nums[i]);
        }

        return max(dp1[n-1], dp2[n]);
    }
};

