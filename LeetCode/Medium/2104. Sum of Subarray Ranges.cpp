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

Question : 2104. Sum of Subarray Ranges
Topic : Monotonic-Increasing Stack
Problems : https://leetcode.com/problems/sum-of-subarray-ranges/

==============================> Explanation <=============================================

Parent Problem: 907. Sum of Subarray Minimums 

- Brute Force: Create all possible subarray, find min and max then perform res+=(max-min)

- Optimized, prefix sum: finding all possible subarray, we can sum the subarray by running max and min, or
                         using prefix method.

- Monotonic Increasing stack, Monotonic Decreasing Stack:

    How ?

    - We already defined method in 

        907. Sum of Subarray Minimums 
        https://github.com/aatman-24/DSA/blob/main/LeetCode/Medium/907.%20Sum%20of%20Subarray%20Minimums.cpp

        same method is used.

    If we use the left_boundary and right_boundary method, then we have to find it for both max
    and min.. separatley..


    - We used the running stack method....
    
    min: k > st.top()(j) < nums[i]..... 

        for that reason...

        while(!st.empty() && (i == n || nums[st.top()] > nums[i]))

        nums[i] is smaller than nums[j](st.top()) so we popped it from the stack to be minimum.


    max: k < st.top(j) >  nums[i]

    
        for that reason...

        while(!st.empty() && (i == n || nums[st.top()] < nums[i]))

        nums[i] is greater than nums[j](st.top()) so we popped it from the stack to be maximum.


==============================> Apporach and Time Complexity <=============================================

1) Two Pointer
Time: O(N)
Space: O(1)

*/

// O(N^3) N = 1000 -> TLE
class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        
        int sum = 0, n = nums.size();
        
        for(int i = 0; i < n; i++) {
            
            for(int j = i+1; j < n; j++) {
                
                int min_ele = INT_MAX, max_ele = INT_MIN;
                
                for(int k = i; k <= j; k++) {

                    min_ele = min(min_ele, nums[k]);
                    max_ele = max(max_ele, nums[k]);
                }

                sum += (max_ele - min_ele);
            }
        }

        return sum;   
    }
};



// O(N^2)
class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        
        int sum = 0, n = nums.size();
        
        for(int i = 0; i < n; i++) {
            
            int min_ele = nums[i], max_ele = nums[i];

            for(int j = i+1; j < n; j++) {
                
                min_ele = min(min_ele, nums[j]);
                max_ele = max(max_ele, nums[j]); 

                sum += (max_ele - min_ele);
            }
        }

        return sum; 
    }
};



// O(N)
class Solution {

    public:

    long long subArrayRanges(vector<int>& nums) {
     

        long long res = 0, n = nums.size();
        stack<int> st;

        int j,k;

        for(int i = 0; i <= n; i++) {

            while(!st.empty() && (i == n || nums[st.top()] > nums[i])) {

                j = st.top(); st.pop();
                k = st.empty() ? -1 : st.top();

                res -= (long)nums[j] * (i - j) * (j - k);
            }

            st.push(i);
        }

       st = stack<int>();

        for(int i = 0; i <= n; i++) {

            while(!st.empty() && (i == n || nums[st.top()] < nums[i])) {

                j = st.top(); st.pop();
                k = st.empty() ? -1 : st.top();

                res += (long)nums[j] * (i - j) * (j - k);
            }

            st.push(i);
        }


        return res;

    }
};