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

Question: 263. Ugly Number
Topic : Number Theory
Problems : https://leetcode.com/problems/add-digits/

==============================> Explanation <=============================================

- Simulate the problem.

==============================> Apporach and Time Complexity <=============================================

1) Number Therory
Time: O(log2N) + O(log3N) + O(log5N) near to O(logN). here 2,3 and 5 is base.
Space: O(1)

*/

class Solution {
public:
    
    bool isUgly(int n) {
        
        // edge case.
        if(n == 0)
            return false;
        
        // remove all the factor of 2.
        while(n % 2 == 0) {
            n /= 2;
        }

        // remove all the factor of 3.
        while(n % 3 == 0) {
            n /= 3;
        }

        // remove all the factor of 5.
        while(n % 5 == 0) {
            n /= 5;
        }

        // if n is ugly number then n should be 1.
        return n == 1;
    }
};