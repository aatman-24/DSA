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

Question: 219. Contains Duplicate II
Topic : Hashing
Problems : https://leetcode.com/problems/contains-duplicate-ii/

==============================> Explanation <=============================================

==============================> Apporach and Time Complexity <=============================================
2) Hashing:
Time: O(N)
Space: O(N)

*/

class Solution {
public:
bool containsNearbyDuplicate(vector<int>& nums, int k) {

    unordered_map<int,int> mp;
    for(int i = 0; i < nums.size(); i++) {
        if(mp.count(nums[i])) {
            
            if(i - mp[nums[i]] <= k) {
                return true;
            }
        }
         mp[nums[i]] = i;
    }

    return false;
}
};