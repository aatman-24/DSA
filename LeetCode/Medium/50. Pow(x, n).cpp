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
d
/*
==============================> Description <=============================================

Question : 50. Pow(x, n)
Topic : Math, Binary Exponetation
Problems : https://leetcode.com/problems/powx-n/

==============================> Explanation <=============================================
1) How to Handle the Overflow for int n. change it type to the long long or long.

2) How to perform the pow for negative n. -> 

    2^-1 = 1 / 2

    So here same if n < 0. X = 1 / x and n *= -1. Make n positive but x become x = 1/x.

    Other all things remain same.

*/


/*
==============================> Edge Case <=============================================


*/

class Solution {
public:

    // 1) Recursion 

    // 2) Iterative

    // Binary Exponetation O(logN) [Number Therory]
   double myPow(double x, int m) {

        if(m == 0) return 1;

        // Handle Overflow.
        long n = m;

        // If n is negative. then n -> positive. but x become 1 / x.
        if(n < 0) {
            n = -n;
            x = 1 / x;
        }

        double ans = 1.0, base = x;

        while(n > 0) {

            if(n % 2) {
                ans *= base;
            }

            base = base * base;
            n = n >> 1;
        }       

        return ans;
    }


};
