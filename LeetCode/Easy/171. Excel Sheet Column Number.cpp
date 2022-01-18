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

Question: 171. Excel Sheet Column Number
Topic : Binary to Decimal(Base 26)
Problems : https://leetcode.com/problems/excel-sheet-column-number/

==============================> Explanation <=============================================
Here base is 26. Because 26 different character. Start from A - Z.

253 = 2 ^ 10^2 + 5 * 10 ^ 1 + 3 * 10 ^ 0

Same Rule Apply Here,


AB = 1 * 26 ^ 1 + 2 * 26 ^ 0 = 28 


Binary to Decimal Convert.

==============================> Apporach and Time Complexity <=============================================

1) Number Therory
Time: O(N)
Space: O(1)

*/




#define ll long long

class Solution {
public:

    static ll power(ll base, ll n) {

        ll ans = 1;

        while(n) {

            if(n % 2)
                ans *= base;

            base *= base;

            n /= 2;
        }

        return ans;
    }



    int titleToNumber(string s) {
     
        ll ans = 0;
        ll n = s.size();

        for(ll i = n - 1; i >= 0; i--) {

            ans += (s[i] - 'A' + 1) * power(26, n - 1 - i);
        }

        return (int)ans;

    }
};