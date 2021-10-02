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

Question: 1922. Count Good Numbers
Topic : Math
Problems :  https://leetcode.com/problems/count-good-numbers/

==============================> Explanation <=============================================
- Nothing Special...

If n is odd then -> even odd even
if n is even then -> even odd even odd

for even have -> 5 choice
for odd have -> 4 choice

==============================> Apporach and Time Complexity <=============================================

1) Power With Exponential:
Time:O(logN) + O(logM) -> N = number of even pos, M = odd pos
Space:O(1)

*/


 #define ll long long

class Solution {
public:
    // evens  = 0, 2, 4, 6, 8  => 5 evens
    // primes = 2, 3, 5, 7     => 4 primes
  
    int p = 1e9 + 7;
    
    // calculating x^y efficeiently
    ll power(long long x, long long y) {
      long long res = 1;    

      x = x % p; // Update x if it is more than or equal to p
      if (x == 0) return 0; 

      while (y > 0) {
        // If y is odd, multiply x with result
        if (y & 1) res = (res*x) % p;
        
        // we have did the odd step is it was odd, now do the even step
        y = y>>1; // dividing y by 2, y>>1 is same as y/2
        x = (x*x) % p;
      }
      return res;
    }
  
    int countGoodNumbers(long long n) {
      ll count_of_4s = n/2;
      ll count_of_5s = n - count_of_4s;
      ll ans = ((power(4LL, count_of_4s) % p  * power(5LL, count_of_5s) % p) % p);
      return (int)ans;
    }
};