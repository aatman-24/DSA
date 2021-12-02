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

Question: 1130. Minimum Cost Tree From Leaf Values
Topic : Top-Down Pattern=IntervalDP, Stack, Monto
Problems : https://leetcode.com/problems/minimum-cost-tree-from-leaf-values/

==============================> Explanation <=============================================

- Dp variant = IntervalDP.

- We try to make all the subtrees by cutting into [i, j] and separate the left and right tree which is subproblems.

1) Choise Diagram: 
    - We can choose any k from [i, j-1] and make the left subtree (i, k) and right subtree from (k+1, j).
    - Here we use two memo, first one for the subtree sum and second one for maximum value from (i, j).

2) Base Case: i == j return nums[i]. 
              
3) Recurrance Relation:

      dp[i, j] = dp[i, k] + dp[k + 1, j] + max(A[i, k]) * max(A[k + 1, j])


BUT BUT BUT this problem is solved using brute-force(O(N^2)) and stack(O(N)).. Read this post...

Problem reduced : Given an array A, choose two neighbors in the array a and b,
we can remove the smaller one min(a,b) and the cost is a * b.
What is the minimum cost to remove the whole array until only one left?


Must Read this one first: https://leetcode.com/problems/minimum-cost-tree-from-leaf-values/          
        
==============================> Apporach and Time Complexity <=============================================

1) Top-Down Pattern=IntervalDP
Time: O(N^3) (If calculate max value for left and right separately)
Space: O(N^2) (one 2D matrix for the subtree sum)


2) Top-Down Pattern=IntervalDP
Time: O(N^2)
Space: O(N^2) (one for subtree sum) + (one for max value)

3) MonoStack:
Time: O(N)
Space: O(N)

*/

class Solution {
public:

    // keep track of subtree sum for [i, j] indexs.
    int t1[41][41];

    // keep track of max value between [i, j] indexs.
    int t2[42][42];

    int mctFromLeafValues(int i, int j, vector<int> &arr) {

        // single elememt return it.
        if(i == j) {
            t2[i][j] = arr[i];
            return arr[i];
        }

        if(t1[i][j] != -1)
            return t1[i][j];

        // min sum among all the subtrees.
        int minValue = INT_MAX;

        int max_value = 0;
        
        for(int k = i; k < j; k++) {

            int cost = mctFromLeafValues(i, k, arr) + mctFromLeafValues(k+1, j, arr) + t2[i][k] * t2[k+1][j];
        
            if(cost < minValue) {
                minValue = cost;
                max_value = max(t2[i][k], t2[k+1][j]);
            }
        }


        // max_value
        t2[i][j] = max_value;

        // subtree sum.
        return t1[i][j] = minValue;
    }


    int mctFromLeafValues(vector<int>& arr) {

        memset(t1, -1, sizeof(t1));
        memset(t2, -1, sizeof(t2));

        // sum of array.
        int sum = 0;
        for(auto num: arr)
            sum += num;

        // we added so remove it.
        return mctFromLeafValues(0, arr.size()-1, arr) - sum;

    }
};



// Mono-stack.
class Solution {

public:

    int mctFromLeafValues(vector<int>& arr) {

        int cost = 0;

        stack<int> st;
        st.push(INT_MAX);

        for(auto num: arr) {
            
            while(st.top() <= num) {
                

                // remove the st.top()(min_value) from the array.
                int mid = st.top(); st.pop();

                cost += mid * min(st.top(), num);
            }

            st.push(num);
        }


        // [INT_MAX, 5, 3, 1] perform all multiplication and add into the cost.
        while(st.size() > 2) {
            int num = st.top(); st.pop();
            cost += st.top() * num;
        }

        return cost;
    }
};