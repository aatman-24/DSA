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

Question: 357. Count Numbers with Unique Digits
Topic : Math
Problems : https://leetcode.com/problems/count-numbers-with-unique-digits/

==============================> Explanation <=============================================

simple maths, Form the number which all have unique digits.

n = 0, 1 number
n = 1, X(0-9) 10 numbers
n = 2, [X(1-9)] * [X(0-9)-1] = 9 * 9 = 81 numbers... and 0 can not be placed at first position.
n = 3, [X(1-9)] * [X(0-9)-1] * [X(0-9)-2] = 9 * 9 * 8= 81 numbers
....
n < 10.. 

We subtract 1 from the choice bcz previous used digit.

==============================> Apporach and Time Complexity <=============================================
1) Math:
Time: O(N)
Space: O(N)(Memorization)
*/


class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {

        if(n == 0) return 1;

        int res = 10;
        int uniqueDigit = 9;
        int availableDigit = 9;
        for(int i = 1; i < n; i++) {
            uniqueDigit *= availableDigit;
            res += uniqueDigit;
            availableDigit--;
        }

        return res;
    }
};