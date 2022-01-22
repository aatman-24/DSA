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

Question: 342. Power of Four
Topic : Bit Manipulation
Problems : https://leetcode.com/problems/power-of-four/

==============================> Explanation <=============================================

Check code below.

==============================> Apporach and Time Complexity <=============================================

1) Bit Manipulation
Time: O(logN) -> O(1)
Space: O(1)

*/


// Iterative
class Solution {
public:
    bool isPowerOfFour(int n) {

        if(n <= 0)
            return false;
        

        while(n % 4 == 0) {
            n /= 4;
        }
        return n == 1;
    }
};


class Solution {
public:
    bool isPowerOfFour(int n) {

        if(n <= 0)
            return false;
        
        // If n is power of four then only single bit is active(set). 
        // So here we check if more than one bit is set then 
        // it is not power of Four.         Ex: 4 -> 100 16-> 10000
        if(n & (n-1))
            return false;

        // check all powerof4 upto INT_MAX Limit and compare with n.
        for(int i = 0; i < 32; i+=2) {
            if(n == (1 << i)) {
                return true;
            }
        }

        return false;
    }
};



class Solution {
public:
    bool isPowerOfFour(int n) {

        if(n <= 0)
            return false;
        
        // If n is power of four then only single bit is active(set). 
        // So here we check if more than one bit is set then 
        // it is not power of Four.         Ex: 4 -> 100 16-> 10000
        if(n & (n-1))
            return false;

        // If give number is powerof4 then format is:         100100100...
        // so doing and operation with                        101010101 will return 0. then it is power of 4.


        // Example: 16 -> 0000 0000 0001 0000
        //                1010 1010 1010 1010  
        //              = 0000 0000 0001 0000
        //              = 0  (so yes 16 is power of four)

        // In short, mask = AAAAAAAA or (1010 1010 1010 1010) if given n is power of four then only one single 0th value
        // bit is set so performing And with that result is zero. so it is powerof 4.


        return !(n & (0xAAAAAAAA));
    }
};