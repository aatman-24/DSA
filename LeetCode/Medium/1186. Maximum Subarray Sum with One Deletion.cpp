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

Question: 1186. Maximum Subarray Sum with One Deletion
Topic : Bottom-up Pattern=Cadane
Problems : https://leetcode.com/problems/maximum-subarray-sum-with-one-deletion/
==============================> Explanation <=============================================
Dp variant = Cadane DP.	

Very clear,

If we don't take the current ith element then we divide the subarray in two parts, [0, i-1] [i+1, N]...
and choose maxSum from both the side and sum it and choose maxSum among them.

- We perfrom Cadane, two times first forward and second reverse... And if we skip ith then we take maxSubarray sum fro left and right
which is nothing but,   maxEndingat[i-1] + maxStartWith[i+1].

- And also we check that array sum itself is not bigger than what we found(means don'd remove any element).


1) Choise Diagram: Cadane

2) Base Case: 

3) Recurrance Relation:

==============================> Apporach and Time Complexity <=============================================

1) Top-Down Pattern = Cadane
Time: O(N)
Space: O(N)

*/

class Solution {
public:
    int maximumSum(vector<int>& arr) {

        int N = arr.size();

        vector<int> maxStartHere(N, 0), maxEndHere(N, 0);

        maxEndHere[0] = arr[0];
        maxStartHere[N-1] = arr[N-1];

        int maxSum = arr[0];

        for(int i = 1; i < N; i++)  {
            maxEndHere[i] = max(arr[i], maxEndHere[i-1] + arr[i]);
            maxSum = max(maxSum, maxEndHere[i]);
        }

        for(int i = N - 2; i >= 0; i--) {
            maxStartHere[i] = max(arr[i], maxStartHere[i+1] + arr[i]);
        }

        for(int i = 1; i < N-1; i++) {
            maxSum = max(maxSum, maxEndHere[i-1] + maxStartHere[i+1]);
        }


        return maxSum;
    }
};