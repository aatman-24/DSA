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
Topic : Two pointer
Problems : https://leetcode.com/problems/trapping-rain-water/
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
                if(arr[l] < leftMax) {
                    res += (leftMax - arr[l]);
                }
                else {
                    leftMax = arr[l];
                }
                l++;
            }
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


    // Stack = O(N).
    int trap(vector<int>& arr) {
        stack<int> st;
        int res = 0;
        for(int i = 0; i < arr.size(); i++) {
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