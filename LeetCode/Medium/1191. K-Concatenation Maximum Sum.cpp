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

Question: 1191. K-Concatenation Maximum Sum
Topic : Bottom-up Pattern=Cadane
Problems : https://leetcode.com/problems/k-concatenation-maximum-sum/

==============================> Explanation <=============================================
Dp variant = Cadane DP.	

- Problem is to find maxSubarraySum with repeating the array k times. And we know that we can find
maxsumarray sum using cadane algortihm but here some edge case involved.

Edge Case 1:
- [A1 A2 A3 A1 A2 A3 A1 A2 A3] If the Sum of entire array is negative then maxSum either be in (circular array)
or into the middle of array.
- Middle of Array(Regular) : [A2, A2A3]
- Circular of Array: [A3A1, A2A3A1]

So for that, We divide the problems... When k = 2, and remaining k - 2. Because we need to check circular array
is giving maximum sum or not...

- so using the [arr + arr] we check that using kadane. And also we check for the middle or regular as it is.


Edge Case 2:
- sum > 0.
- max(sum * (k-2) + prefix + sufix, cadane) 

[A1 A2 A3 .....(k-2).... A1 A2 A3]
- sum is greater than 0 then we directly add for (k-2) times.
- And we can either take all array or  (suffix of array) or (prefix of array).

[A1 A2 A3 .....(k-2).... A1 A2 A3] -> [A3 .....(k-2).... A1] (prefix + suffix) (But prefix and suffix maximum in seperatley)


- We need to find maximum of prefix and suffix so we can use it.

Method 2: (Same)
- Same method of above but without prefix and suffix...
- We make [arr + arr] and find the maxSubarraySum(which is automatically include prefix and suffix).
- So after that only need to check,
	if sum > 0:
		sum * (k-2) + maxSubarraySum
	else:
		maxSubarraySum

==============================> Apporach and Time Complexity <=============================================

1) Top-Down Pattern = Cadane
Time: O(N)
Space: O(1)

*/

#define mod 1000000007

class Solution {

public:

	int kConcatenationMaxSum(vector<int>& arr, int k) {

	    long maxSubArraySum = kadane(arr);
	    if(k == 1) {
	        return maxSubArraySum;
	    }
	    long prefix = prefixSum(arr);
	    long suffix = suffixSum(arr);

	    long sum = 0;
	    for(auto ele: arr) {
	        sum += ele;
	    }

	    if(sum > 0) {
	        return max((long)(sum) * (k-2) + prefix % mod + suffix % mod, maxSubArraySum % mod) % mod;
	    }
	    else {
	        return max((prefix+suffix) % mod, maxSubArraySum % mod) % mod;
	    }
	}

	long kadane(vector<int> &arr) {
	    long maxSum = INT_MIN, curSum = 0;
	    for(long ele: arr) {
	        curSum = max(ele, ((curSum + ele) % mod));
	        maxSum = max(maxSum, curSum);
	    }
	    return maxSum > 0 ? maxSum : 0;
	}

	long prefixSum(vector<int> &arr) {
	    long maxSum = INT_MIN, curSum = 0;
	    for(int i = 0; i < arr.size(); i++) {
	        curSum = (curSum + arr[i]) % mod;
	        maxSum = max(maxSum, curSum);
	    }
	    return maxSum;
	}   


	long suffixSum(vector<int> &arr) {
	    long maxSum = INT_MIN, curSum = 0;
	    for(int i = arr.size()-1; i >= 0; i--) {
	        curSum = (curSum + arr[i]) % mod;
	        maxSum = max(maxSum, curSum);
	    }
	    return maxSum;
	}   

};





#define mod 1000000007

class Solution {

    public:

    int kConcatenationMaxSum(vector<int>& a, int k) {
        int m_sum = 0, sz = a.size();
        for (auto i = 0, sum = 0; i < min(2, k) * sz; ++i) {
            sum = max(sum + a[i % sz], a[i % sz]);
            m_sum = max(m_sum, sum);
        }
        return ((long long)m_sum + 
            max(0ll, accumulate(begin(a), end(a), 0ll) * max(0, k - 2))) % 1000000007;
    }
};