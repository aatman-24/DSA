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

Question: 416. Partition Equal Subset Sum
Topic : Linear-DP Pattern=TargetSum, BoundedKnapsack
Problems : hhttps://leetcode.com/problems/partition-equal-subset-sum/

==============================> Explanation <=============================================

Idea is from, (Target Sum, Bounded Knapsack, Aditya Verma)

- Using 2-state is direct. We need two subset so we find the one subset of sum/2.

=>> Choice Diagram -> Either we include the element or don't include it.
                    if(num <= N)
                        t[i][N] = solve(i-1, N - num)(#Move to the next and take current element) || solve(i-1, N)
                    else:
                        t[i][N] = solve(i-1, N) (#Move to the next element don' take current one).

==> Base Case -> Target = 0, Return True.
                 index = 0, Target != 0, Return False, Out of element. Need more element.

==> Recurrance Relation: 
            
            if(num <= N)
                t[i][N] = solve(i-1, N - num) || solve(i-1, N)
            else:
                t[i][N] = solve(i-1, N)


Space Optimization: 

But Still we can optimize the space here,

1) As you can see our t[i][N] is always dependent on the previous row (i-1)th row. So we can only use
O(2N) space by using prev and current rows.

2) Second oberservation is that, decision of t[i][j] is taken in the column range from (0 -> j) only
because t[i-1][j] or t[i-1][j-num] both column is <= j. So using single O(N) array by traversing the
from right -> left we can do this.

Notice... t[i][j] decision is not affect by any column >= j in previous row. While filling the entry from
          right to left.

          But filling the entry from the left -> right, every entry t[i][j] is affected by the column <= j.
          which is not accepted because entry is going to be overwritten.

https://leetcode.com/problems/partition-equal-subset-sum/discuss/90592/01-knapsack-detailed-explanation/241664


Linear DP:

It is concept of Space optimization.... 

// from left to right means dp[i][j] = dp[i][j-nums[i-1]])  (Same element can be used more than one time)
// form right to left means dp[i][j] = dp[i-1][j-nums[i-1]] (Same element can not be used more than one time)

Why Right to left ?

Let's see the what is result if doing into the left to right ?

nums = [1, 2, 5], Target = 4.

First Phase,    0 1 2 3 4           nums[i-1] = 1, and j = [1, 4]

                T T F F F
                T T T F F
                T T T T F
                T T T T T    (As you can see result is true, while OG is false)
                             Because already filled up(or taken) is spreading in whole array.
                             left side directly affect the result of right side array.
                             nums[i-1] = 1 is used total 4 times here.


Now see right to left,

nums = [1, 2, 5], Target = 4.

First Phase,    0 1 2 3 4           nums[i-1] = 1, and j = [1, 4]
                T F F F F.
                T F F F.F
                T F F.F F
                T T.F F F           (See here only 1st element is updated which is right and all other remain
                                     Same as False.) and right side of array does not affect or pariticipate
                                     in decision for the left part.

Second Phase,  0 1 2 3 4            nums[i-1] = 2 and j = [1, 4]. Yes 2 is used 2 times here, But
               T T F F F.           as you can see it is used in different combination not same index 
               T T F T.F            is used more than one time.
               T T T.T.F

Third Phase,   0 1 2 3 4            nums[i-1] = 5 which is not less that 4. So end...

Ans = False Dp[4] is F.

As you see if element is not used more than one time then fill the entry from the right to left else
fill the entry from left to right.


==============================> Apporach and Time Complexity <=============================================
1) Top-Down + Bottom-UP Linear-DP Pattern=TargetSum, Bounded Knapsack:
Time: O(N)
Space: O(N)(Memorization)

1) Linear Space:
Time: O(N)
Space: O(1)
*/



// Top-Down
class Solution {
public:
        
    int canPartition(int index, int N, vector<int>& nums, vector<vector<int>> &t) {

        // Target 0 then return true.
        if(N == 0)
            return true;

        // No more element return false.
        if(index <= 0)
            return N == 0;

        if(t[index][N] != -1)
            return t[index][N];

        if(nums[index-1] <= N) {
            t[index][N] = canPartition(index-1, N-nums[index-1], nums, t) || canPartition(index-1, N, nums, t);
        }
        else {
            t[index][N] = canPartition(index-1, N, nums, t);
        }

        return t[index][N];
    } 


    bool canPartition(vector<int>& nums) {

        int target = 0;
        for(int num: nums)
            target += num;

        if(target % 2 == 1) return false;

        target /= 2;

        vector<vector<int>> t(nums.size()+1, vector<int>(target+1, -1));

        return (bool)canPartition(nums.size() - 1, target, nums, t);
    }

};


// Bottom-up
class Solution {
public:

    bool canPartition(vector<int>& nums) {

        int target = 0;
        for(int num: nums)
            target += num;

        if(target % 2 == 1) return false;

        target /= 2;

        int m = nums.size(), n = target;

        int dp[m+1][n+1];
        memset(dp, 0, sizeof(dp));


        // base condition

        // Without having any value you can not make sum j.
        for(int j = 1; j <= n; j++) dp[0][j] = 0;

        // For sum = 0, no need of any element.
        for(int i = 0; i <= m; i++) dp[i][0] = 1;
        

        for(int i = 1; i <= m; i++) {
            
            for(int j = 1; j <= n; j++) {
                
                if(nums[i-1] <= j) {
                    dp[i][j] = dp[i-1][j-nums[i-1]] || dp[i-1][j];
                }
                
                else {
                    dp[i][j] = dp[i-1][j];
                }
            }
        }

        return (bool)dp[m][n];
    }
};






// Top-Down Linear
class Solution {
public:
    
    int canPartition(int index, int N, vector<int>& nums, vector<int> &t) {

        if(N == 0)
            return true;

        if(index <= 0 || N < 0)
            return false;

        if(t[N] != -1)
            return t[N];

        if(nums[index-1] <= N) {
            t[N] = canPartition(index-1, N-nums[index-1], nums, t) || canPartition(index-1, N, nums, t);
        }
        else {
            t[N] = canPartition(index-1, N, nums, t);
        }

        return t[N];
    } 


    bool canPartition(vector<int>& nums) {

        int target = 0;
        for(int num: nums)
            target += num;

        if(target % 2 == 1) return false;

        target /= 2;

        vector<int> t(target+1, -1);

        return (bool)canPartition(nums.size() - 1, target, nums, t);
    }

};



// Bottom-up Linear
class Solution {
public:


bool canPartition(vector<int>& nums) {


    int target = 0;
    for(int num: nums)
        target += num;

    if(target % 2 == 1) return false;
    target /= 2;


    int m = nums.size(), n = target;
    vector<int> dp(n+1, 0);

    // Base
    dp[0] = 1;

    for(int i = 1; i <= m; i++) {

        // start from j -> (Target -> Zero.)
        for(int j = n; j >= 0; j--) {

            if(nums[i-1] <= j) {
                dp[j] = dp[j] || dp[j-nums[i-1]];
            }
        }
    }

    return (bool)dp[n];
}

};