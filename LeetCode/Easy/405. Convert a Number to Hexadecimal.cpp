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

Question : 405. Convert a Number to Hexadecimal
Topic : Number Therory
Problems : https://leetcode.com/problems/convert-a-number-to-hexadecimal/

==============================> Explanation <=============================================

- We use the mask 1111 (4 bit) to find the hex number.
- we perform this for 8 times.
- right shift by 4 bit.
- so at the end num become zero if positive, for negative we have to handle that case.

==============================> Apporach and Time Complexity <=============================================

1) Number Therory
Time: O(1)
Space: O(1)

*/


class Solution {
public:
    string toHex(int num) {
        
        if(num == 0) {
            return "0";
        }

       map<int, char> mp = {{0, '0'}, {1, '1'}, {2, '2'},{3, '3'},{4, '4'}, {5, '5'}, {6, '6'}, {7, '7'}, {8, '8'}, {9, '9'},
                            {10, 'a'}, {11, 'b'}, {12, 'c'}, {13, 'd'}, {14, 'e'}, {15, 'f'}};

        string res = "";
        
        if(num > 0) {
            while (num) {
                res = mp[num % 16] + res;
                num /= 16;
            }
        }
        else {
            u_int n = num;
            while(n) {
                res = mp[n % 16] + res;
                n /= 16;
            }
        }

        return res;
    }
};


class Solution {
public:
    string toHex(int num) {
        
        if(num == 0) {
            return "0";
        }

       map<int, char> mp = {{0, '0'}, {1, '1'}, {2, '2'},{3, '3'},{4, '4'}, {5, '5'}, {6, '6'}, {7, '7'}, {8, '8'}, {9, '9'},
                            {10, 'a'}, {11, 'b'}, {12, 'c'}, {13, 'd'}, {14, 'e'}, {15, 'f'}};

        string res = "";
        int word = 0;

        // we only allowd 8 words. not more than that.(handle negative number) (ffff ffff)
        while(num && word++ < 8) {
            res = mp[num & 0xf] + res;
            num = num >> 4; // right shift by 4 bit.
        }
        
        return res;
    }
};

