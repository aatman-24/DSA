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

Question: 190. Reverse Bits
Topic : Bit Manipulation
Problems : https://leetcode.com/problems/reverse-bits/

==============================> Explanation <=============================================

==============================> Apporach and Time Complexity <=============================================

1) Bit Manipulation
Time: O(32)
Space: O(1)

*/


class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t ans = 0;
        for(int i = 0; i < 32; i++) {
            if(n & (1 << i)) {
                uint32_t mask = 1 << (32 - i - 1);
                ans = ans | mask;
            }
        }
        return ans;
    }
};