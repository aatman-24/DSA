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

Question:  1027. Longest Arithmetic Subsequence
Topic : Bottom-UP Pattern=LIS
Problems : https://leetcode.com/problems/longest-arithmetic-subsequence/

==============================> Explanation <=============================================
- Dp variant = LIS version, 

- First idea comes into the mind that, if we are at the current ith index then we need to check
all the index [0, i-1] which we can extend.

- diff = num[i] - nums[j]

- diff can be between [-500, 500] -> (500, 0), (0, 500)

- We can only extend the dp[j][diff]. If it is 0 then we start with 2.(Base case)


Use Unordered_map<int,int> dp[N]:

- dp[i]{[d] -> L}-> Indicate that for the number nums[i] with d difference have  L length.

But it give TLE. Due to O(N^3) Space. 


Use Vector as dp, dp[N][1001]:

- Now, We already know that diff can be -500 for that reason we add offset(500) to every
diff so it always positive and use the same logic.


1) Choise Diagram: -> for the current num[i], extend the series with any number num[j]  0 <= j < i
                      with given diff = nums[i] - nums[j].

2) Base Case: N = 2, return 2.
              
3) Recurrance Relation:
    
        for(int i = 0; i < N; i++)
            for(int j = 0; j < i; j++)
                diff = nums[i] - nums[j]
                dp[i][diff] = (dp[j][diff] != 0) ? dp[j][diff] + 1 : 2


- Try to perform Bottom-Up direct in LIS. It is very easy compare to Top-Down.

==============================> Apporach and Time Complexity <=============================================

1) Bottom-UP Pattern=LIS
Time: O(N^2)
Space: O(N^3)

1) Bottom-UP Pattern=LIS Space Optimization
Time: O(N^2)
Space: O(N^2)


*/



class Solution {
public:
    int longestArithSeqLength(vector<int>& nums) {

        int N = nums.size();
        
        // {diff->length}
        // dp[i] -> ending at ith index with {diff -> length}
        unordered_map<int,int> dp[N];

        int ans = 2;

        for(int i = 0; i < N; i++) {

            for(int j = 0; j < i; j++) {

                int d = nums[i] - nums[j];

                // check with same difference at the jth index can we extend or not.
                dp[i][d] = dp[j].count(d) ? dp[j][d] + 1: 2;

                ans = max(ans, dp[i][d]);
            }
        }

        return ans;
    }

};



class Solution {
public:

    int longestArithSeqLength(vector<int>& nums) {

        int N = nums.size();
        
        int dp[N][1001];
        memset(dp, 0, sizeof(dp));

        int ans = 2;

        for(int i = 0; i < N; i++) {

            for(int j = 0; j < i; j++) {

                int d = nums[i] - nums[j] + 500;

                // check with same difference at the jth index can we extend or not.
                dp[i][d] = (dp[j][d] != 0) ? dp[j][d] + 1: 2;

                ans = max(ans, dp[i][d]);
            }
        }

        return ans;
    }

};