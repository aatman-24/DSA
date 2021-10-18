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

Question: 740. Delete and Earn
Topic : Linear-DP Pattern=HouseRobber, Coin Change
Problems : https://leetcode.com/problems/delete-and-earn/

==============================> Explanation <=============================================
1) Idea is clear that, either we took the current element or don't. 
- We sort the elements reason is we can keep track of all deleted element on one side only.. Here
we sort increasing order and start from the right side.. so we need to delete the nums[i]+1 elements.
We took the decision based on left side and delete(skip) the nums[i]-1.
- Second is that, we took the number curr = nums[i] then we take all the copies of that number as profit.

So Two condition, Either take it(all the copies) or don't take it. If we take it then we go to the index
where number is less than num[i]-1 and if we don't take it then we jump to the (i-1)(prev numbers).

- same as coin change or knapsack either we take it or don't take it but if we take it then there are action
which we need to peform.


2) House Robber:
- create array count[MAX] and we store the count[i] = {frequency of i * i} at ith index.
- then simple House robber don't take the neighbors element if we take the current one with (i-2) elements.
- or take the adjacent then don't take current one.

dp[i] = max(dp[i-1], dp[i-2]*arr[i]);


1) Choise Diagram: If we are at current index i in the array. Then LIS[i] is the maximum among all,
                   numbers arr[j] such that, It can be extend all the LIS for which nums[j][1] < nums[i][0].
                   So that, reason LIS[i] = LIS[j] + 1. nums[j] < nums[i]. j can be (0 -> i).

2) Base Case: LIS[i] = 1. Every number itself is LIS.

3) Recurrence Relation: 
                    for j = 0 -> i,
                        if(nums[j][1] < nums[i][0])
                            LIS[I] = max(LIS[i], LIS[j]+1)


==============================> Apporach and Time Complexity <=============================================
M = 10000

1) Top-Down + Bottom-UP Linear-DP Pattern=LIS, Standard
Time: O(N^2)
Space: O(N)(Memorization)

2) Pattern=House Robber Top-Down+Bottom-up:
Time: O(M)
Space: O(M)

2) House_Robber Two state:
Time: O(M) -> M = 10000
Space: O(1)

*/



// Top-Down
class Solution {
public:

    int deleteAndEarn(int index, vector<int> &nums, int t[]) {
    
        if(index == -1)
            return 0;

        if(t[index] != -1)
            return t[index];

        // Take the current one and its duplicates.
        int earned = nums[index];
        int skip = index - 1;
        while(skip >= 0 && nums[index] == nums[skip]) {
            earned += nums[skip];
            skip--;
        }
    
        // While the number is num[index]-1 then we skip all of this numbers.
        // pick the current nums[i] and delete all the num[i] - 1.
        while(skip < nums.size() && nums[index] - 1 == nums[skip])
            skip--;

        // And add other Point we earned by starting from the skip.
        earned += deleteAndEarn(skip, nums, t);


        // Don't take the current one and jump to the next.
        int skipped = deleteAndEarn(index-1, nums, t);

        return t[index] = max(earned, skipped);
    }



    int deleteAndEarn(vector<int>& nums) {

        sort(nums.begin(), nums.end());

        int t[nums.size()+1];
        memset(t, -1, sizeof(t));

        return deleteAndEarn(nums.size()-1, nums, t);

    }
};


// Bottom-up
class Solution {

public:


    int deleteAndEarn(vector<int>& nums) {

        int n = nums.size();

        sort(nums.begin(), nums.end());

        int dp[nums.size()+1];
        dp[0] = 0;


        // nums[i-1] is 1 based index.
        for(int i = 1; i <= n; i++)  {

            int earned = nums[i-1];
            int j = i - 1;

            // add all the duplicates.
            while(j >= 1 && nums[j-1] == nums[i-1]) {
                earned += nums[j-1];
                j--;
            }

            // skip the next number until if number is nums[i] - 1 
            while(j >= 1 && nums[i-1]-1 == nums[j-1])
                j--;

            // Take the current one with + (valid previous number) Or don't take the current one.
            // valid previous means number should not be nums[i]-1 or nums[i]+1.
            dp[i] = max(dp[i-1], dp[j] + earned);
        }

        return dp[n];
    }
};



// House Robber Top-Down.
class Solution {
public:

    int MAX = 10003;

    int deleteAndEarn(int idx, int count[], int t[]) {
        
        if(idx <= 0)
            return 0;

        if(t[idx] != -1)
            return t[idx];

        // Either take the current element and (i-2) element or don't take the current one then jump to
        // the previous.
        return t[idx] = max(deleteAndEarn(idx-1, count, t), deleteAndEarn(idx-2, count, t) + count[idx]);
    }

    int deleteAndEarn(vector<int>& nums) {

        // count the frequency of value. If 3 comes 3 times then count[3] = 9.
        int count[MAX];
        memset(count, 0, sizeof(count));

        for(int num: nums) {
            count[num] += num;
        }

        int t[MAX];
        memset(t, -1, sizeof(t));
        
        return deleteAndEarn(MAX-1, count, t);    
    }
};



// House Robber Bottom-up.
class Solution {
public:

int MAX = 10003;

int deleteAndEarn(vector<int>& nums) {

    int arr[MAX];
    memset(arr, 0, sizeof(arr));

    for(int num: nums) {
        arr[num] += num;
    }

    int dp[MAX];
    memset(dp, 0, sizeof(dp));
    dp[0] = 0;
    dp[1] = arr[1];

    for(int i = 2; i < MAX; i++) {
            
        // Same as previous. Either take it current(i) with (i-2) or 
        // don't take the current one took value from previous (i-1).
        dp[i] = max(dp[i-1] , dp[i-2] + arr[i]);
    }

    return dp[MAX-1];
}
};



// 2 State. Just compare with above one.
class Solution {
public:

int MAX = 10003;

int deleteAndEarn(vector<int>& nums) {

    int arr[MAX];
    memset(arr, 0, sizeof(arr));

    for(int num: nums) {
        arr[num] += num;
    }

    int dp[MAX];
    memset(dp, 0, sizeof(dp));
    int prev2 = arr[0];
    int prev1 = arr[1];
    
    for(int i = 2; i < MAX; i++) {
            
        // Same as previous. Either take it current(i) with (i-2) or 
        // don't take the current one took value from previous (i-1).
        dp[i] = max(prev1 , prev2 + arr[i]);
        prev2 = prev1;
        prev1 = dp[i];
    }

    return prev1;
}
};
