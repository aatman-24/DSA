#include <bits/stdc++.h>
#define ll long long
#define REP(i,n) for(int i = 0; i < n; i++)
#define REP1(i,n) for(int i = 1; i <= n; i++)
#define debug cout << "Ok" << endl;
#define mod 1000000007

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

Question : 319. Bulb Switcher
Topic : Array
Problems : https://leetcode.com/problems/bulb-switcher/
*/


// A bulb ends up on iff it is switched an odd number of times.

// Call them bulb 1 to bulb n. Bulb i is switched in round d if and only if d divides i. 
// So bulb i ends up on if and only if it has an odd number of divisors.
// Divisors come in pairs, like i=12 has divisors 1 and 12, 2 and 6, and 3 and 4. 
// Except when i is a square, like 36 has divisors 1 and 36, 2 and 18, 3 and 12, 4 and 9, and 
// double divisor 6. So bulb i ends up on if and only if i is a square.

// O(1) - O(1).
class Solution {
public:
    int bulbSwitch(int n) {
        return sqrt(n); 
    }
};