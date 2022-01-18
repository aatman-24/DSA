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

Question: 461. Hamming Distance
Topic : Bit Manipulation
Problems : https://leetcode.com/problems/hamming-distance/

==============================> Explanation <=============================================

Brute Force: Check Every bit is same or not on both x and y.

Optimized: First find xor of x and y. Now using "last bit unset" strategy how many bit are set. 

==============================> Apporach and Time Complexity <=============================================

1) Bit Manipulation
Time: O(32)
Space: O(1)

*/


class Solution {
public:
    int hammingDistance(int x, int y) {
        

        int count = 0;
        for(int i = 0; i < 32; i++) {

            // make the mask by setting each bit from (0 to 32).
            int mask = 1 << i;
            
            if((mask & x) != (mask & y)) {
                count++;
            }
        }

        return count;
    }
};



class Solution {
public:
    int hammingDistance(int x, int y) {
        
        int count = 0;

        // xor the x and y this operation set the bit in N where x and y have different bit.
        int n = x ^ y;

        // using the "last bit unset" strategy we can count total bit set into the n.
        while(n) {
            count++;
            n = n & n - 1;
        }

        return count;
    }
};
