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

Question : 42. Trapping Rain Water
Topic : Two pointer, Stack, Prefix-Array
Problems : https://leetcode.com/problems/trapping-rain-water/

==============================> Explanation <=============================================

Brute Force: At ith index how much water is stored is based on leftmost and rightmost maximum height. So At each index
             we go leftmost and rightmost side and find maximum leftMax and rightMax.

             water = min(leftMax, rightMax) - height[i];
             total_water += max(0, water);

Optimized Brute Force: Rathar than finding leftMax and rightMax, for each index... why we don't calculate it first and use
            it when needed. Which reduce O(N^2) -> O(3N).


Two Pointer Approach:
        - user two pointer l = 0, r = n - 1.
        - used two pointer leftMax = 0, rightMax = 0 
        - Now in loop until l <= h,
            whichever arr[l] or arr[h] is smaller we shrink that side. And check that height of that point is 
            lesser or greater than it (leftMax or rightMax)(check on code).
        - We keep track of leftMax and rightMax. and total water.



Monotonic Decreasing Stack:

    - Ideas is that, we mono decreasing stack. If new value is added we check if it is lesser than top we directly add it
    otherwise we remove all the element which is less than curr_val. 

    - Points which is popped from the stack will contribute into total_waters. check in code.
        
      5 2 4(C)

      Then... 2 is removed... min(5, 4) - 2 = 2 * width(here 1) = 2(points) added into total water.
    
     Here, 5 and 4 work as leftMax and rightMax for 2 points.

    In example i taken the values but in code we use index to get height and width.
    
==============================> Apporach and Time Complexity <=============================================

1) Brute Force
Time: O(N^2)
Space: O(1)

2) Optimized Brute Force
Time: O(3N)
Space: O(N)

1) Two Pointer Approach
Time: O(N)
Space: O(1)

1) Monotonic Decreasing Stack
Time: O(N)
Space: O(N)

*/


class Solution {
public:
    
    // Brute-Force = O(N^2)


    // prefix, suffix = O(3N)
    int trap(vector<int>& height) {
        
        int n =  height.size();
        if(n <= 1) return 0;

        int prefix[n], suffix[n];
        prefix[0] = height[0];
        suffix[n-1] = height[n-1];

        for(int i = 1; i < n; i++) prefix[i] = max(prefix[i-1], height[i]);
        for(int i = n-2; i >= 0; i--) suffix[i]  = max(suffix[i+1], height[i]);

        int sumOfWater = 0;

        for(int i = 0; i < n; i++) {
            sumOfWater += (min(prefix[i], suffix[i]) - height[i]);
        }
        return sumOfWater;
    }


    // Two pointer = O(N)
    int trap(vector<int>& arr) {
        int n = arr.size();
        int l = 0, r = n-1;
        int res = 0;
        int leftMax=0, rightMax=0;

        while(l <= r) {


            if(arr[l] <= arr[r]) {
                    
                // If arr[l] is less than leftMax... add (leftMax - arr[l]) water.
                if(arr[l] < leftMax) {
                    res += (leftMax - arr[l]);
                }
                // Otherwise make leftMax = arr[l].
                else {
                    leftMax = arr[l];
                }
                l++;
            }
            // same on right side.
            else {
                if(arr[r] < rightMax) {
                    res += (rightMax - arr[r]);
                }
                else {
                    rightMax = arr[r];
                }
                r--;
            }
        }
        return res;
    }


    // Monotonic Decreasing Stack = O(N).
    int trap(vector<int>& arr) {
        stack<int> st;

        int res = 0;

        for(int i = 0; i < arr.size(); i++) {


            // |
            // | . |
            // | | |            . -> this point add min(3, 2) = min(2) - 1(height) = 1 into total_water.
            while(!st.empty() && arr[st.top()] < arr[i]) {
                int cur = st.top();
                st.pop();
                if(st.empty()) {
                    break;
                }
                int height = min(arr[st.top()], arr[i]) - arr[cur];
                int width = i - st.top() - 1;
                res += (height * width);
            }
            st.push(i);
        }
        return res;
    }
    
};