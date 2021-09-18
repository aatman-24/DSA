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

Question: 454. 4Sum II
Topic : Hashing
Problems : https://leetcode.com/problems/4sum-ii/

==============================> Explanation <=============================================
1) Brute Force. Four for loops.

2) Two Separte map and then visit the one map and check required into other map.

3) Using One map. Precompute the one map first. Then used this while performing 
opreation on nums3 and nums4.

It is not too much related with 4Sum. Rathar it is concept of 3sum+Hashing Technique.

==============================> Apporach and Time Complexity <=============================================

1) Brute Force:
Time: O(N^4)
Space: O(1)

2) Two Separte Hashmap:
Time: O(N^2)
Space: O(N^2)

3) One HashMap:
Time: O(N^2)
Space: O(N^2)

*/


class Solution {
public:

int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4)  {

        int n = nums2.size(), ans = 0;

        map<int,int> first, second;

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                first[nums1[i] + nums2[j]]++;
                second[nums3[i] + nums4[j]]++;
            }
        }

        for(auto it: first) {
            int required = -it.first, cnt1 = it.second;
            if(second.count(required)) {
                ans += (second[required] * cnt1);
            }
        }

        return ans;
    }
};


class Solution {
public:

    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4)  {

        int n = nums2.size(), ans = 0;

        map<int,int> first, second;

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                first[nums1[i] + nums2[j]]++;
            }
        }

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                int required = -(nums3[i] + nums4[j]);
                if(first.count(required)) {
                    ans += first[required];
                }
            }
        }
        
        return ans;
    }
};