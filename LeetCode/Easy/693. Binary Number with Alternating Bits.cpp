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

Question: 693. Binary Number with Alternating Bits
Topic : Bit Manipulaton
Problems : https://leetcode.com/problems/binary-number-with-alternating-bits/

==============================> Explanation <=============================================

- First shift the N by either left or right by 1.
- Here we shift the N on right by 1.
- Peform the XOR with original N.
- Store into the N. Now in N if some bit is zero it means that bit and its right hand side neighbor has same bits.

From here we can check each bit using loops and check wheather any of bit is unset then we return false otherwise true.

- Or we can use trick... we add 1 into the N and then perform the & operation with N itself. which overflow the 32 bit and
result is zero.

Explanation:

Suppose, If no bit is same in adjancent then,

    Xor result is -> 11111
                        +1
                    100000

    So last 5 bit is taken only into the consideration so it will be zero. so we check with that. 




==============================> Apporach and Time Complexity <=============================================

1)  Bit Manipulaton
Time: O(1)
Space: O(1)

*/


class Solution {
public:
    bool hasAlternatingBits(long long n) {
        
        n = n ^ (n >> 1);

        return (n & (n + 1)) == 0;
    }
};