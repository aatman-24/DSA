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

Question : 1512. Number of Good Pairs
Topic : Array
Problems : https://leetcode.com/problems/number-of-good-pairs/
*/

class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        int cnt = 0;
        int n = nums.size();
        map<int,int> mp;
        for(int i = 0; i < n; i++) {
            if(mp.find(nums[i]) == mp.end()) mp[nums[i]] = 1;
            else mp[nums[i]]++;
        }

        // int cnt = 0;
        for(auto i : mp) {
            if(i.second > 1) {
                cnt += ((i.second) * (i.second-1) / 2);
            } 
        }

        return cnt;
        
}
};