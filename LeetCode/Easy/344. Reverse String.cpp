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

Question: 344. Reverse String
Topic : String
Problems : https://leetcode.com/problems/reverse-string/

==============================> Explanation <=============================================

- swapping the leftmost and rightmost value.

==============================> Apporach and Time Complexity <=============================================

1) String
Time: O(N/2)
Space: O(1)

*/


class Solution {
public:
    void reverseString(vector<char>& s) {
        char temp;
        int n = s.size();
        for(int i = 0; i < n/2; i++) {
            temp = s[i];
            s[i] = s[n-1-i];
            s[n-1-i] = temp;
        }
    }
};