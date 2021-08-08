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
d
/*
==============================> Description <=============================================

Question :  16. 3Sum Closest
Topic : Sorting, Two Pointer
Problems : https://leetcode.com/problems/3sum-closest/

==============================> Explanation <=============================================
- 3Sum Apporach. (Same) but keep track of minDiff. If found the differnce between and
target is less than minDiff then update the result and minDiff.

- All Apporach of 3Sum is apply to the here.

I used Most Optimized apporach here.


Time = O(NLogN) + O(N^2) = O(N^2)
Space = O(1)

*/


/*
==============================> Edge Case <=============================================

*/


class Solution {
public:

    int threeSumClosest(vector<int>& nums, int target) {

        int minDiff=INT_MAX, res;

        sort(nums.begin(), nums.end());

        for(int i = 0; i < nums.size() - 2; i++) {

            int left = i + 1, right = nums.size()-1;

            while(left < right) {

                int curSum = nums[i] + nums[left] + nums[right];

                if(abs(target - curSum) < minDiff) {
                    minDiff = abs(target - curSum);
                    res = curSum;
                }

                if(target == curSum) {
                    return curSum;
                }
                else if(curSum < target) {
                    left++;
                }
                else {
                    right--;
                }

            }
        }

        return res;

    }
};