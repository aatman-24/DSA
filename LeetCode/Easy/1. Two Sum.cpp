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
d
/*
==============================> Description <=============================================

Question : 1. Two Sum
Topic : Two Pointer, Hashing
Problems : https://leetcode.com/problems/two-sum/

==============================> Explanation <=============================================
1) Brute Force: Try all the pair.

2) Sorting + Linear Time: Sort the array and then apply Two Pointer Apporach.But In answer
index pair required that time it is not work. Like Here It is not worked.

3) Hashing: Check map contains the (target-curr). If yes return this pair otherwise
            add the current element into the map.

==============================> Apporach and Time Complexity <=============================================
1) Brute Force:
Time: O(N^2)
Space: O(1)

2) Sorting + Linear Time(not work here):
Time: O(NlogN) + O(N)
Space: O(1)

3) Hashing:
Time: O(N)
Space: O(N)

*/

class Solution {
public:

    vector<int> twoSum(vector<int>& nums, int target) {

        unordered_map<int, int> mp;

        for(int i = 0; i < nums.size(); i++) {

            if(mp.find(target-nums[i]) != mp.end()) {
                
                return {mp[target-nums[i]], i};
            }
            
            mp[nums[i]] = i;
        }


        return {-1,-1};

    }
};
