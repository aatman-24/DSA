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

Question: 231. Power of Two
Topic : Bit Manipulation
Problems : https://leetcode.com/problems/power-of-two/

==============================> Explanation <=============================================

==============================> Apporach and Time Complexity <=============================================

1) Bit Manipulation
Time: O(logN) -> O(32) -> O(1)
Space: O(1)

*/


// If n is power of 2 then last remainder should be 1.
class Solution {
public:
    bool isPowerOfTwo(int n) {
        
        while(n) {

            if(n % 2)
                break;

            n = n / 2;
        }

        return n == 1;
    }
};




class Solution {
public:
    bool isPowerOfTwo(int n) {
        
        if(n <= 0) return false;
        
        for(int i = 0; i < 32; i++) {
            
            if(n == (1 << i))     
                return true;
    
        }

        return false;
    }
};



// If given number n is power of 2. That means out of 32 bit only 1 bit is set other all are unset.
// performing (n & (n - 1)) unset the last set bit in N. But here only one bit is set so it must be zero int our case.
class Solution {
public:
    bool isPowerOfTwo(int n) {
        
        if(n <= 0) return false;
        
        return (n & (n - 1)) == 0;
    }
};