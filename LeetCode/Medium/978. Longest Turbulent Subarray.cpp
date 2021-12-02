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

Question: 978. Longest Turbulent Subarray
Topic : Bottom-up Pattern=Cadane
Problems : https://leetcode.com/problems/longest-turbulent-subarray/

==============================> Explanation <=============================================
Dp variant = Cadane DP.	


Ideas is that,

We take the relationship with previous element either increment or decrement.... and keep track of
that relationship....

1) Choise Diagram: 

if(A[i-1] == A[i])
	inc[i] = 1
	dec[i] = 1
else if(A[i-1] < A[i])
	inc[i] = dec[i-1] + 1
	dec[i] = 1 (start new sequence)
else
	inc[i] = 1
	dec[i] = inc[i-1] + 1

2) Base Case: inc[0] = 1, dec[0] = 1.

3) Recurrance Relation:

Check above,

space optimization is possible...


==============================> Apporach and Time Complexity <=============================================

1) Bottom up Pattern = Cadane
Time: O(N)
Space: O(1) / O(N)

*/


class Solution {
public:
	int maxTurbulenceSize(vector<int>& arr) {

	    int n = arr.size();
	    int inc[n], dec[n];
	    
	    inc[0] = 1;
	    dec[0] = 1;

	    int ans = 1;

	    for(int i = 1; i < arr.size(); i++) {
	        
	        if(arr[i-1] == arr[i]) {
	            dec[i] = 1;
	            inc[i] = 1;
	        }
	        else if(arr[i-1] < arr[i]) {
	            dec[i] = 1;
	            inc[i] = dec[i-1] + 1;
	        }
	        else {
	            dec[i] = inc[i-1] + 1;
	            inc[i] = 1;
	        }

	        ans = max(ans, max(dec[i], inc[i]));
	    }

	    return ans;
	}
};


// space optimization...
class Solution {
public:
    int maxTurbulenceSize(vector<int>& arr) {

        int n = arr.size();

        int inc = 1;
        int dec = 1;

        int ans = 1;

        for(int i = 1; i < arr.size(); i++) {
            
            if(arr[i-1] == arr[i]) {
                dec = 1;
                inc = 1;
            }
            else if(arr[i-1] < arr[i]) {
                inc = dec + 1;
                dec = 1;
                
            }
            else {
                dec = inc + 1;
                inc = 1;
            }

            ans = max(ans, max(dec, inc));
        }

        return ans;
    }
};