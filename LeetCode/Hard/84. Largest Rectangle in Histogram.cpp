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
#pattern 1: Monotone Increasing Stack 


Question : 84. Largest Rectangle in Histogram
Topic : Monotone Increasing stack
Problems : https://leetcode.com/problems/largest-rectangle-in-histogram/


/*
==============================> Edge Case <=============================================
2] solution: i == n.size() when all elements are coverd and all are in incresing order for that.

*/

/*
==============================> Explanation <=============================================
Apporach is same for both solution. for maximum the width we expand both side until we 
found element which is smaller than current element. 


2nd Soultion why it works?

- In stack we store element into increasing order only. for,
- right boundary we found with curr[i] is less than or i == height.size()
- left boundary using poping the element from the stack. if stack is empty we use 0 otherwise
next element of the top of stack. means first smallest element index + 1.

1] width = (abs(right_boundary[i] - i) + abs(left_boundary[i] - i]) + 1(current))

2] Width is calculated = (i(right) - left) * currentHeight
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