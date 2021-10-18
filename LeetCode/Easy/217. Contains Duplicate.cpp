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

Question: 217. Contains Duplicate
Topic : Hashing
Problems : https://leetcode.com/problems/contains-duplicate/

==============================> Explanation <=============================================

==============================> Apporach and Time Complexity <=============================================
2) Hashing:
Time: O(N)
Space: O(N)

*/

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {

        unordered_map<int,int> mp;
        for(int num: nums) {
            if(mp.count(num)) {
                return true;
            }
            mp[num] = 1;
        }

        return false;
    }
};