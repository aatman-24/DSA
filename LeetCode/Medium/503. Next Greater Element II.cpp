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

Question : 503. Next Greater Element II
Topic : Monotonic-Increasing Stack
Problems : https://leetcode.com/problems/next-greater-element-ii/

==============================> Explanation <=============================================



Varinat 1, Without rotation.

Go simple 0 -> N.


Varinat 2, We can go from right->left if value is not found. 

1  10 5  8
10 -1 8 10 Answer


So for that we can add same array at the end of array.

1  10 5 8  1 10  5 8
[10 -1 8 10] 10 -1 8 -

So rathar than doing physically we can perform using virtually using % opearator.

0 -> N - 1
0 -> 2N - 1 + %


More help...

TUF: Stack & Queue Playlist



==============================> Apporach and Time Complexity <=============================================

1) Two Pointer
Time: O(N)
Space: O(1)

*/


// Start from the head.
// Monotono Increasing Stack.: We add index from the start, if any time  nums[index] < nums[i], means current
// nums[i] is greater than for all nums[index] we put the value ans[index] = nums[i
class Solution {
public:
    
    vector<int> nextGreaterElements(vector<int>& nums) {
            
        int N = nums.size();
        
        stack<int> st;

        vector<int> greater(N, -1);

        for(int i = 0; i < 2*N - 1; i++) {

            while(!st.empty() && nums[st.top()] < nums[i%N]) {

                int index = st.top(); st.pop();

                if(index < N)
                    greater[index] = nums[i%N];
            }

            st.push(i%N);
        }

        return greater;
    }
};


// Start from the back.
// Any value from [0, i-1] will see the st.top() as greater value... so
// removing smaller element will does not affect while current nums[i] is greater than already in stack.
class Solution {
public:
    
    vector<int> nextGreaterElements(vector<int>& nums) {
            
        int N = nums.size();
        
        stack<int> st;

        vector<int> greater(N, -1);

        for(int i = 2*N-1; i >= 0; i--) {

            while(!st.empty() && st.top() <= nums[i%N]) {
                st.pop();
            }

            if(i < N)
                greater[i] = st.empty() ? -1 : st.top();

            st.push(nums[i%N]);
        }

        return greater;
    }
};