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

Question: 136. Single Number
Topic : XOR, Bit Manipulation
Problems : https://leetcode.com/problems/single-number/
==============================> Explanation <=============================================
- Xoring of same number going to be zero.
==============================> Apporach and Time Complexity <=============================================


*/

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans = 0;
        for(auto num: nums) {
            ans ^= num;
        }
        return ans;
    }   
};