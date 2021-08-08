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

Question : 1838. Frequency of the Most Frequent Element
Topic : Sliding Window
Problems : https://leetcode.com/problems/frequency-of-the-most-frequent-element/

/*
==============================> Explanation <=============================================
We used Prefix sum


- sort the array first.
Intution is that, when arr = [2, 3, 4] k = 5
we check at index = 2...     

if(arr[end] * (end - begin) - (sum of arr[begin...end]) <= k) then it's valid otherwise not at a time we shrink the window.

Here,  (end - begin) = number of element which can be arr[end].

*/

/*
==============================> Edge Case <=============================================

*/

// 



#define ll long long

class Solution {
public:

    // Shrinkable Sliding window O(N)
    int maxFrequency(vector<int>& nums, int k) {

        sort(begin(nums), end(nums));
        int n = nums.size();
        int begin = 0, end = 0, res = 1, sum = 0;

        while(end < n) {

            sum += nums[end];

            while(nums[end] * (end - begin + 1) - sum > k) {
                sum -= nums[begin++];
            }
            res = max(res, (++end - begin));
        }

        return res;
    }


    // Non-Shrinkable O(N)
    int maxFrequency(vector<int>& nums, ll k) {

        sort(begin(nums), end(nums));
        int n = nums.size();
        ll begin = 0, end = 0, sum = 0;

        while(end < n) {

            sum += nums[end];

            if(nums[end] * (end - begin + 1) - sum > k) {
                sum -= nums[begin++];
            }
            end++;
        }

        return end-begin;
    }

};