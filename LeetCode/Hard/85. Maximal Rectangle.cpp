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

Question : 85. Maximal Rectangle
Topic : Monotone Stack, Stack
Problems : https://leetcode.com/problems/maximal-rectangle/

/*
==============================> Explanation <=============================================
84. Largest Rectangle in Histogram (copy of it) just need to keep track of height
for every row.

suppose, 
0 0 1 1 0 | h[] = {0, 0, 1, 1, 0}
0 1 1 0 1 | h[] = {0, 1, 2, 0, 1}
1 1 1 1 0 | h[] = {1, 2, 2, 1, 0}

if we encounter matrix[i][j] = 0 then h[j] = 0 if matrix[i][j] = 1 then h[j] += 1 (cumulative sum).
Other is same as (84).

*/


/*
==============================> Edge Case <=============================================
(col == nCol) pop everything from stack. and calculate maxArea.



*/


class Solution {
public:

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

};