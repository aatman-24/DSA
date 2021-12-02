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

Question: 665. Non-decreasing Array
Topic : Greedy
Problems : https://leetcode.com/problems/non-decreasing-array/

==============================> Explanation <=============================================

- Logic is that,

if(nums[i-1] > nums[i]) {
    then, we can change either nums[i] or nums[i-1] so we can not take decision based on these
    two.

    so we check, if(nums[i-2] <= nums[i]) then it is clear we need to change middle(nums[i-1]) update nums[i] = nums[i-1]
                 if(nums[i-2] > nums[i]) then we have to change nums[i] for some greater value. nums[i-1] = nums[i] / nums[i-2].
}

we update the value with same value reason is to make it increasing array neighbors can have same
value.. if given that stricly increasing array then we have to take
    nums[i] = nums[i-1] + 1
    nums[i-1] = nums[i-2] + 1,   and also check some other condition as well.

- credit is use for one time allowance.

==============================> Apporach and Time Complexity <=============================================

1) Logic, Greedy
Time: O(N)
Space: O(1) 

*/


class Solution {
public:

    bool checkPossibility(vector<int>& nums) {
        
        if(nums.size() == 1)
            return true;

        bool oneCredit = true;

       if(nums[0] > nums[1]) {
            nums[0] = nums[1];
            oneCredit = false;
       }

        for(int i = 2; i < nums.size(); i++) {

            if(nums[i-1] > nums[i] && oneCredit) {
                if(nums[i-2] > nums[i]) {
                    nums[i] = nums[i-1];
                    oneCredit = false;
                }
                else if(nums[i-2] <= nums[i]) {
                    nums[i-1] = nums[i-2];   // also nums[i-1] = nums[i] possible.
                    oneCredit = false;
                }
            }
            else if (nums[i-1] > nums[i] && !oneCredit){
                return false;
            }
        }
        return true;

    }
};
