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

Question: 258. Add Digits
Topic : Number Theory
Problems : https://leetcode.com/problems/add-digits/

==============================> Explanation <=============================================

- Simulate the problem.

==============================> Apporach and Time Complexity <=============================================

1) Number Therory
Time: O(logN)
Space: O(1)

*/


class Solution {
public:

    int getSum(int num) {
        int sum = 0;
        while(num) {
            sum += num % 10;
            num = num/10;
        }
        return sum;
    }


    int addDigits(int num) {
        while(num > 9) {
            num = getSum(num);
        }
        return num;
    }
};