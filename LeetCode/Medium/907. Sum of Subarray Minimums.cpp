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

Question : 907. Sum of Subarray Minimums
Topic : Monotone  stack
Problems : https://leetcode.com/problems/sum-of-subarray-minimums/
pattern : 1 



/*
==============================> Explanation <=============================================
pattern : 1 same method
https://leetcode.com/problems/sum-of-subarray-minimums/discuss/178876/stack-solution-with-very-detailed-explanation-step-by-step

here we calculate the width of both side and (multiply it so we find how many times) curr
arr[i] needs to count.


arr[i] * (i - left_boundary[i]) * (right_boundary[i] - i)

left_boundary[i] denote the first smallest element of curr arr[i] at left side. same for
right_boundary[i].

*/


/*
==============================> Edge Case <=============================================

Here we make change into left_boundary and right_boundary as per requirements.

here we store the smallest element index (rather than last greater element index). so also
st.empty() condition is change due to this (-1 rather than 0 and n rather than n-1).


Second edge Case which is IMP.

handle duplicates.
we only allow one side duplicate not both side. mean one stack is strict increasing
and second one non-strict increasing.

Why? If we allowed both then.

71 55(L) 82 55(R)

LEFT contribute to this 
71 55(L)
55(L)
55(L) 82
55(L) 82 55(R) [duplicate]
71 55(L) 82 55(R) [duplicate]


Right contribute to this
71 55(L) 82 55(R) [duplicate]
55(L) 82 55(R) [duplicate]
82 55(R)
55(R)

Reason is that when we allow left side non-strict it means that,
55(L) < 55(R).

Now if also allowed right side as non-strict then it means that 55(L) > 55(R) which is not
possible.


so we only allowed one side not both side.
*/


#define mod 1000000007
#define ll long long

class Solution {
    public:

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
};