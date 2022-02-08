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

Question : 84. Largest Rectangle in Histogram
Topic : Monotone Increasing stack
Problems : https://leetcode.com/problems/largest-rectangle-in-histogram/

==============================> Explanation <=============================================

Approach 1:

- For the current H[i] we find the left and right boundary which less than H[i]. Doing that we find
the (length) of Rectangle and we already have H[i] height.

- For current ith we find left and right boundary separately.

- width = (abs(right_boundary[i] - i) + abs(left_boundary[i] - i]) + 1(current))

- Area is calculated = (i(right) - left) * currentHeight



Approach 2: Monotone Increasing Stack 

- Right boundary is itself.. current i.
- We only find the left boundary using the same concept.
- left boundary < H[i].

Edge Case - i == n.size() when all elements are coverd and all are in incresing order for that.

-Apporach is same for both solution. for maximum the width we expand both side until we 
found element which is smaller than current element. 





==============================> Apporach and Time Complexity <=============================================
1) Stack + Vector:
Time: O(N)
Space: O(N)

2) Stack
Time: O(N)
Space: O(N)

*/


class Solution {

    public:
    
    int largestRectangleArea(vector<int>& H) {

            int n = H.size();

            vector<int> left_boundary(n, 0), right_boundary(n,0);

            stack<int> st;

            for(int i = 0; i < n; i++) {
                
                while(!st.empty() && H[st.top()] >= H[i]) st.pop();
                
                if(st.empty())
                    left_boundary[i] = 0;
                else
                    left_boundary[i] = st.top() + 1;
                
                st.push(i);
            }

            while(!st.empty()) st.pop();   
        
            for(int i = n-1; i >= 0; i--) {
                while(!st.empty() && H[st.top()] >= H[i]) st.pop();
                if(st.empty())
                    right_boundary[i] = n-1;
                else
                    right_boundary[i] = st.top() - 1;
                st.push(i);
            }

            int maxArea = 0;
            for(int i = 0; i < n; i++) {
                maxArea = max(maxArea, H[i] * (abs(left_boundary[i] - i) + abs(right_boundary[i] - i) + 1));
            }

            return maxArea;
    }

    int largestRectangleArea(vector<int>& H) {
    
        stack<int> st;

        int maxHeight = 0;

        for(int i = 0; i <= H.size(); i++) {
            
            // Either i == H.size()
            // Or H[st.top()] >= H[i].. we need to find boundary H[st.top()] < H[i]. so we can
            // use current H[i] as maximum height.
            while(!st.empty() && (i == H.size() || H[st.top()] >= H[i])) {

                int j = st.top(); st.pop();
                
                int left = st.empty() ? 0 : st.top() + 1;
                
                maxHeight = max(maxHeight, (i - left) * H[j]);
            }

            st.push(i);
        }
        return maxHeight;
    }
};