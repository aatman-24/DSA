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

Question : 367. Valid Perfect Square
Topic : Number Theory
Problems : https://leetcode.com/problems/valid-perfect-square/

==============================> Explanation <=============================================

Math Problem:

1 = 1
4 = 1 + 3
9 = 1 + 3 + 5
16 = 1 + 3 + 5 + 7
25 = 1 + 3 + 5 + 7 + 9
36 = 1 + 3 + 5 + 7 + 9 + 11
....
so 1+3+...+(2n-1) = (2n-1 + 1)n/2 = nn

2) Binary Search:

Constraint is given, 1 <= num <= 2^31 - 1

So either it is O(1) or O(logN).

- Increasing function so i got idea about Binary search.


==============================> Apporach and Time Complexity <=============================================

1) Math Problem
Time: O(N)
Space: O(1)

2) Binary Search
Time: O(logN)
Space: O(1)

*/


#define eps 1e-6
class Solution {
public:
    bool isPerfectSquare(int num) {
        long low = 0, high = num;
        while(low <= high) {
            long mid = (low + high) >> 1;
            if(abs(mid * mid - num) < eps)
                return true;
            else if(mid * mid < num)
                low = mid + 1;
            else 
                high = mid - 1;
        }
        return false;
    }
};