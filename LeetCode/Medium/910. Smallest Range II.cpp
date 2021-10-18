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

Question: 910. Smallest Range II
Topic : Sorting, Greedy
Problems : https://leetcode.com/problems/smallest-range-ii/

==============================> Explanation <=============================================

Idea is simple,

- First sort the array.
- Suppose there are two index i and j, i < j and A[i] < A[j].
        Subtracting K from A[i] will increase the diff between A[j] - (A[i]-K)
        Adding K into A[j] will increase the differnce A[j]+K - A[i].


So we don't perform this opreation,
        
Suppose there are elements,

        A[0]+K A[1]+K A[2]+K..... A[i]+K A[i+1]-K A[i+2]-K... A[n-2]-K A[n-1]-K

Adding K on left and Subtracting from right side elements give smaller differnce so we perform this way.

But after performing addition or subtraction we need to check new element A[i]+K or A[i]-K is maxi or mini. If
don't then we take A[0]+K and A[N-1]-K as mini and maxi.

And A[i]+K... A[i+1]-K is less difference then A[i]+K... A[i+2]-k so we just checking A[i] and A[i+1] elements.


==============================> Apporach and Time Complexity <=============================================
1) Sorting + Greedy:
Time: O(NlogN)
Space: O(1)
*/


class Solution {
public:

int smallestRangeII(vector<int>& A, int K) {

    sort(A.begin(), A.end());

    // left and right boundary.
    int left = A[0] + K, right = A[A.size() - 1] - K;

    int res = A[A.size()-1] - A[0]; // Curr (Max - min)

    for(int i = 0; i < A.size() - 1; i++) {

        // maxi from left side.
        int maxi = max(A[i]+K, right);
    
        // taking mini from the right side.
        int mini = min(A[i+1] - K, left);
        
        res = min(res, maxi - mini);
    }

    return res;
}
};