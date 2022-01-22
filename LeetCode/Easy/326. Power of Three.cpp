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

Question: 326. Power of Three

Topic : Number Therory

Problems : https://leetcode.com/problems/power-of-three/

==============================> Explanation <=============================================

- First Approach.
- In Second Apporach we find maximum 3^K < INT_MAX. Now all the 3^i Divide that 3^K so remainder is must be zero. This is worked here
because 3 is prime number. It is not going to work for 4, 6, 8...

==============================> Apporach and Time Complexity <=============================================

1) 
Time: O(log3N) -> log 3 base N.
Space: O(1)

*/





// O(logN)
class Solution {
public:

    bool isPowerOfThree(int n) {

        if(n <= 0)
            return false;
        
        while(n % 3 == 0) {
            n /= 3;
        }

        return n == 1;
    }
};



// O(logN)
class Solution {
public:
    int const Max3PowerInt = 1162261467; // 3^19, 3^20 = 3486784401 > MaxInt32
    int const MaxInt32 = 2147483647; // 2^31 - 1
    bool isPowerOfThree(int n) {
        if (n <= 0 || n > Max3PowerInt) return false;
        return Max3PowerInt % n == 0;
    }
};


