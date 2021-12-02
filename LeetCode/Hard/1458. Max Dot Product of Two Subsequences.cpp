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

Question: 1458. Max Dot Product of Two Subsequences
Topic : Bottom-up Pattern=LCS
Problems : https://leetcode.com/problems/max-dot-product-of-two-subsequences/

==============================> Explanation <=============================================
Dp variant = LCS

How I Identify the Pattern ?
- It is simple we can take any pair of the (i, j) from s1 and s2 and maximize the product of sum.
So Either take it current(i,j) or don't take it. 

1) Choise Diagram: 
	Take it,
		A[i] * B[j] + maxProduct(i-1, j-1, A, B)
	Don't take it,
		max(maxProduct(i-1, j, A, B),maxProduct(i, j-1, A, B))

But Problem is that here we have to take atleast one pair (i, j)... so for that we "don't take" it 
if and only if have current (i) and (j) is not the last elements into the array.
	
2) Base Case: i == 0 || j == 0 -> return 0.

3) Recurrance Relation:
	dp[i][j] = A[i-1]*B[j-1] + (dp[i-1][j-1], 0);
	if(i > 1)
		dp[i][j] = max(dp[i][j], dp[i-1][j])
	if(j > 1)
		dp[i][j] = max(dp[i][j], dp[i][j-1])

==============================> Apporach and Time Complexity <=============================================

1) Top-Down Pattern = LCS
Time: O(N^2)
Space: O(N^2)

*/

class Solution {
public:
	
	vector<vector<int>> t;

	int maxDotProduct(int i, int j, vector<int> &A, vector<int> &B) {
		
		if(i == 0 || j == 0)
			return 0;

		if(t[i][j] != INT_MIN)
			return t[i][j];

		// Take the current (i-j) pairs.
		int maxProduct = A[i-1] * B[j-1] + max(maxDotProduct(i-1, j-1, A, B), 0);
		
		// If It is not the last I then, we don't take the current (i, j) so we try for (i-1, j)
		if(i > 1)
			maxProduct = max(maxProduct, maxDotProduct(i-1, j, A, B));	

		// If it is not the last element of B then we don't take the current(i, j) and try for (i, j-1).
		if(j > 1)
			maxProduct = max(maxProduct, maxDotProduct(i, j-1, A, B));

		return t[i][j] = maxProduct;
	}

	int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {

		t.assign(501, vector<int>(501, INT_MIN));

		return maxDotProduct(nums1.size(), nums2.size(), nums1, nums2);
	}

};



class Solution {
public:
    
    int maxDotProduct(vector<int>& A, vector<int>& B) {

        int n = A.size(), m = B.size();

        int dp[n+1][m+1];
        memset(dp, 0, sizeof(dp));
        
        for(int i = 1; i <= n; i++) {
            
            for(int j = 1; j <= m; j++) {

                dp[i][j] = A[i-1] * B[j-1] + max(dp[i-1][j-1], 0);

                if(i > 1)
                    dp[i][j] = max(dp[i][j], dp[i-1][j]);

                if(j > 1)
                    dp[i][j] = max(dp[i][j], dp[i][j-1]);

            }
        }


        return dp[n][m];
    }
};