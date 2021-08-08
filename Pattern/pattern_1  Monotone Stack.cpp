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

/*  List of Problems:


1856. Maximum Subarray Min-Product
907. Sum of Subarray Minimums
239. Sliding Window Maximum (Decreasing queue) (Hard)
85. Maximal Rectangle (Hard)
1081. Smallest Subsequence of Distinct Characters || 316. Remove Duplicate Letters



*/



//  1856. Maximum Subarray Min-Product
    vector<int> finalPrices(vector<int>& prices) {
        int n = prices.size();
        vector<int> ans(prices);
        stack<int> st;

        for(int i = 0; i < n; i++) {
            while(!st.empty() && prices[st.top()] >= prices[i]) {
                int j = st.top(); st.pop();
                ans[j] -= prices[i];
            }
            st.push(i);
        }

        return ans;
    }

//  907. Sum of Subarray Minimums
    int sumSubarrayMins(vector<int>& arr) {

        int n = arr.size();
        vector<int> left_boundary(n,0), right_boundary(n,0);
        stack<int> st;

        for(int i = 0; i < n; i++) {
            while(!st.empty() && arr[st.top()] >= arr[i]) st.pop();
            if(st.empty()) {
                left_boundary[i] = -1;
            }
            else {
                left_boundary[i] = st.top();
            }
            st.push(i);
        }

        while(!st.empty()) st.pop();

        for(int i = n-1; i >= 0; i--) {
            while(!st.empty() && arr[st.top()] > arr[i]) st.pop();
            if(st.empty()) {
                right_boundary[i] = n;
            }
            else {
                right_boundary[i] = st.top();
            }
            st.push(i);
        }

        ll totalSum = 0;

        for(int i = 0; i < n; i++) {
            ll tmpSum = 1LL;
            if(abs(i - left_boundary[i]) > 0) tmpSum *= (i - left_boundary[i]);
            if(abs(right_boundary[i] - i) > 0) tmpSum = ((tmpSum % mod) * (right_boundary[i] - i) % mod) % mod;
            tmpSum = ((tmpSum % mod) * (arr[i] % mod)) % mod;
            totalSum = (totalSum % mod + tmpSum % mod) % mod;
        }

        return (int)totalSum % mod;
    }

//  239. Sliding Window Maximum (Decreasing queue)
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {

        vector<int> ans;
        deque<int> q;

        for(int i = 0; i < k; i++)
        {
            while(!q.empty() && nums[q.back()] <= nums[i]) {
                q.pop_back();
            }
            q.push_back(i);
        }
        ans.push_back(nums[q.front()]);

        for(int i = k; i < nums.size(); i++) {

            // if q.front() is out of window remove it
            while(!q.empty() && i - q.front() >= k) q.pop_front();

            // this is for incresing queue
            while(!q.empty() && nums[q.back()] <= nums[i]) {
                q.pop_back();
            }

            // add smaller element if we have window for it.
            if(q.size() < k) q.push_back(i);

            ans.push_back(nums[q.front()]);
        }
        return ans;
    }


//  85. Maximal Rectangle (Hard)
    int maximalRectangle(vector<vector<char>>& matrix) {

        if(matrix.size() == 0) return 0;
        
        int nRow = matrix.size(), nCol = matrix[0].size(), maxArea = 0;

        stack<int> st;

        int height[nCol];
        memset(height, 0, sizeof(height));

        for(int row = 0; row < nRow; row++) {

            while(!st.empty()) st.pop();

            // From here Same to largest-rectangle-in-histogram
            for(int col = 0; col <= nCol; col++) {

                // to handle edge case (col == nCol) pop everything from stack.
                if(col < nCol) {
                    if(matrix[row][col] == '0')
                        height[col] = 0;
                    else
                        height[col] += 1;
                }
     
                // Monotone Increasing stack. (1 2 3 4) like that.
                while(!st.empty() && (col == nCol || height[st.top()] >= height[col])) {
                    int col_index = st.top(); st.pop();

                    // left denote width of rectangle left side. and col is right side.
                    int left = st.empty() ? 0 : st.top() + 1;
                    int area = (col - left) * height[col_index];
                    maxArea = max(maxArea, area);
                }
                st.push(col);
            }
        }
        return maxArea;
    }

//  316. Remove Duplicate Letters
    string removeDuplicateLetters(string s) {

        int visited[26], count[26];

        memset(visited, 0, sizeof(visited));
        memset(count, 0, sizeof(count));

        for(int i = 0; i < s.size(); i++)
            count[s[i] - 'a']++;

        stack<char> st;

        for(int i = 0; i < s.size(); i++) {

            count[s[i]-'a']--;

            // abcbc for second b we can skip it because using former b(1) we make same 
            // sequence. And also we already in increasing order then why do we add 
            // this character b(3) and pop the c ?
            if(visited[s[i]-'a']) 
                continue; 

            // only allowed pop opreation if st.top() is again going to occur after s[i].
            // if not then we don't pop it and push s[i] after it.
            while(!st.empty() && count[st.top() - 'a'] != 0 && st.top() > s[i]) {
                visited[st.top() - 'a'] = 0;
                st.pop();
            }
            st.push(s[i]);
            visited[s[i] - 'a'] = 1;
        }

            
        string res = "";
        while(!st.empty()) {
            res += st.top();
            st.pop();
        }

        reverse(res.begin(), res.end());

        return res;
    }
