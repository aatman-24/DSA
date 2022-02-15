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

Question : 1009. Complement of Base 10 Integer
Topic : Bit Manipulation
Problems : https://leetcode.com/problems/complement-of-base-10-integer/

==============================> Explanation <=============================================
Same: 476. Number Complement

- Question is easy like,
    Finding Complement means perform XOR with 1, but problem is that we should perform XOR until
    the bit is set into the num.

    1101
    1111
    -----
    0010

- Here all the methods is finding mask to xor with num.

https://leetcode.com/problems/number-complement/discuss/1650035/C%2B%2BPython-Simple-Solutions-w-Explanation-or-Brute-Force-%2BBit-Manipulation-Tricks-%2B-In-Built
==============================> Apporach and Time Complexity <=============================================

1) All
Time: O(1), O(1)
Space: O(1)

*/


// start from RHB, skip all the 0 bits into the num.
// after perfrom xor with all bits left.
class Solution {
public:
    int findComplement(int num) {
        int i = 31;
        while((num & (1 << i)) == 0) i--;
        while(i >= 0) {
            num = num ^ (1 << i);
            i--;
        }
        return num;
    }
};


// here we use the temp = num, we pefrom right shift until temp(num) become zero, during that we make the mask(1111)
// for required bits.
class Solution {
public:
    int findComplement(int num) {
        int mask = 0;
        while(int temp = num; temp; temp >>= 1)
            mask = (mask << 1) | 1;
        return mask^num;
    }
};


// we take mask = 1, we unset the bit from the right until (mask & num) result into 1. When
// 0000101
// 1111000
// such situation left, (mask & num) result into the zero. so we filp all the bits of mask, ~mask and perform xor.

class Solution {
public:
    int findComplement(int num) {
        uint mask = -1; // [all bit set to 1]
        while(mask & num) mask <<= 1;
        return ~mask ^ num;
    }
};



// we start from LHB.. we perform xor with bit by bit, until i <= num.
// i =     0110101
// num =   1000000
// that means RHB side set bit is still left so we continue, once the i > num, num has reamining bit(right <- left) all zero.

class Solution {
public:
    int findComplement(int num) {
        int i = 1;
        while(i <= num) {
            num ^= i;
            i <= 1;
        }
        return num;
    }
};



class Solution {
public:
    int findComplement(int num) {
        if(num == 0)
            return 1;
        uint i = 1;
        while(i <= num) {
            num ^= i;
            i <<= 1;
        }
        return num;
    }
};
