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

Question: 376. Wiggle Subsequence
Topic : Linear-DP Pattern=LIS
Problems : https://leetcode.com/problems/wiggle-subsequence/

==============================> Explanation <=============================================

Idea is that,

we use two array,

endAtPositive[] -> Which keep track of longest wiggle sequence which end at the positive diffence. 
endAtNegative[] -> Which keep track of longest wiggle sequence which end at the negative diffence. 

case 1: diff > 0.
    
    Either, max(longest Positive ending at (i-1), longest Negative ending at (i-1) + 1 (Curr))
    endAtPositive[i] = max(endAtPositive[i-1], endAtNegative[i-1]+1). Wiggle Sequence is + - + -...
    endAtNegative[i] = endAtNegative[i-1];

case 2: diff < 0.
    
    Either, max(longest Negative ending at (i-1), longest positive ending at (i-1) + 1 (Curr))

    endAtNegative[i] = max(endAtNegative[i-1], endAtPositive[i-1]+1).
    endAtPositive[i] = endAtPositive[i-1];

case 3: diff = 0.

    Don't do anything just remove 0 number from the array. Because here we talk about subsequence not
    about subset...

    endAtNegative[i] = endAtNegative[i-1]
    endAtPositive[i] = endAtPositive[i-1];


And at the last we check which one is max(endAtNegative[N-1], endAtPositive[N-1])

=>> Choice Diagram -> For the Current Differnce is positive then, LWS is either ending at negative_Seq_length + 1
                      or LWS ending at Positive in previous. Same for the negative just above.

==> Base Case -> LWS[1](1-th index) = 1, for single number is LWS. Here LWS[0] = 1. (For the 0th index)

==> Recurrance Relation: count[i] = Cover Above.



Here only last two state are matter, (endAtPositiveLength, endAtNegativeLength) so same as fibo
we can do by using 2 variable. check the last one.

==============================> Apporach and Time Complexity <=============================================
1) Top-Down + Bottom-UP Linear-DP:
Time: O(N)
Space: O(N)(Memorization)

1) Using Two State only Linear-DP:
Time: O(N)
Space: O(1)
*/

// Top-Down 
class Solution {
public:
    void wiggleMaxLength(int index, vector<int> &nums, int endAtPositive[], int endAtNegative[]) {

        // base case
        if(index == 0) {
            endAtPositive[0] = 1;
            endAtNegative[0] = 1;
            return;
        }

        wiggleMaxLength(index-1, nums, endAtPositive, endAtNegative);

        if(nums[index] - nums[index-1] > 0) {
            endAtPositive[index] = max(endAtPositive[index-1], endAtNegative[index-1]+1);
            endAtNegative[index] = endAtNegative[index-1];
        }
        else if(nums[index] - nums[index-1] < 0) {
            endAtNegative[index] = max(endAtPositive[index-1] + 1, endAtNegative[index-1]);
            endAtPositive[index] = endAtPositive[index-1];
        }
        else {
            endAtPositive[index] = endAtPositive[index-1]; 
            endAtNegative[index] = endAtNegative[index-1];
        }
    }

    int wiggleMaxLength(vector<int>& nums) {

        int endAtPositive[nums.size()], endAtNegative[nums.size()];
        memset(endAtNegative, 0, sizeof(endAtNegative));
        memset(endAtPositive, 0, sizeof(endAtPositive));

        wiggleMaxLength(nums.size() - 1, nums, endAtPositive, endAtNegative);

        return max(endAtPositive[nums.size()-1], endAtNegative[nums.size()-1]);
    }

};

// Bottom-UP
class Solution {
public:
    
int wiggleMaxLength(vector<int>& nums) {

    int n = nums.size();

    int endAtPositive[n], endAtNegative[n];
        
    // base case.
    endAtPositive[0] = endAtNegative[0] = 1;
    
    for(int i = 1; i < nums.size(); i++) {
        if(nums[i] - nums[i-1] > 0) {
            endAtPositive[i] = max(endAtNegative[i-1]+1, endAtPositive[i-1]);
            endAtNegative[i] = endAtNegative[i-1];
        }
        else if(nums[i] - nums[i-1] < 0) {
            endAtPositive[i] = endAtPositive[i-1];
            endAtNegative[i] = max(endAtPositive[i-1]+1, endAtNegative[i-1]);
        }
        else {
            endAtPositive[i] = endAtPositive[i-1];
            endAtNegative[i] = endAtNegative[i-1];
        }
    }

    return max(endAtPositive[n-1], endAtNegative[n-1]);
}

};

// using two state.
class Solution {
public:
    
int wiggleMaxLength(vector<int>& nums) {

    int n = nums.size();

    int endAtPositive = 1, endAtNegative = 1;
    
    for(int i = 1; i < nums.size(); i++) {
        if(nums[i] - nums[i-1] > 0) {
            endAtPositive = max(endAtNegative+1, endAtPositive);
            endAtNegative = endAtNegative;
        }
        else if(nums[i] - nums[i-1] < 0) {
            endAtPositive = endAtPositive;
            endAtNegative = max(endAtPositive+1, endAtNegative);
        }
    }

    return max(endAtPositive, endAtNegative);
}

};