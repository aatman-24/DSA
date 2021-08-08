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

Question : 69. Sqrt(x)
Topic : Binary Search
Problems : https://leetcode.com/problems/sqrtx/

==============================> Explanation <=============================================
[1... sqrt(N)... N] for this range we can apply the binary search. And when our answer
high - low become negligible that time we found the answer.

And for checking the condition we use other function multiply/sqrt which return the 
square/pow(m,n).

*/


/*
==============================> Edge Case <=============================================


*/

#define eps 1e-6

class Solution {
public:
    
    double square(double m) {
        return m * m;
    }

    // log(N) time.
    int mySqrt(int x) {

        double low = 1, high = x;

        while((high - low) > eps) {

            double mid = (low + high) / 2.0;

            if(square(mid) < x) {
                low = mid;
            }
            else {
                high = mid;
            }
        }

        return (int)high;
    }
};



// m*m*m*.....(n times)
double multiply(double m, double n) {
    double ans = 1;
    for(int i = 1; i <= n; i++) {
        ans = ans * m;
    }
    return ans;
}


// for the nth root of m.
int NthSqrt(int m, int n) {

    double low = 1, high = x;

    while((high-low) > eps) {

        double mid = (low + high) / 2.0;

        if(multiply(mid, n) < m) {
            low = mid;
        }
        else {
            high = mid;
        }
    }

    return (int)high;
}