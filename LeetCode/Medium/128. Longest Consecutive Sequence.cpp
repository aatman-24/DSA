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

Question : 128. Longest Consecutive Sequence
Topic : Map
Problems : https://leetcode.com/problems/longest-consecutive-sequence/

==============================> Explanation <=============================================

- Unordered_map take O(1) time for lookup.
- We first make entry into the map.
- Second time we make the streak for previous number to find the longest streak.

==============================> Apporach and Time Complexity <=============================================

1) Map
Time: O(N)
Space: O(N)


*/


class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        
        unordered_map<int,int> mp, visited;
        
        // make entry of each number into the map.
        for(auto num: nums)
            mp[num] = 1;

        int ans = 0;
        
        for(auto num: nums) {

            // if the number is already visited, skip it.
            if(visited.count(num))
                continue;

            // current number.
            int longest = 1;

            // we find the previous number into map until we got... and mark as visited each one.
            while(mp.count(num-1)) {
                visited[num-1] = 1;
                num = num - 1;
                longest++;
            }

            ans = max(ans, longest);
        }

        return ans;
    }
};