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

Question: 349. Intersection of Two Arrays
Topic : Map, Set
Problems : https://leetcode.com/problems/intersection-of-two-arrays/

==============================> Explanation <=============================================
Brute Force: Check each element of nums1 into the nums2. 

Optimized using the map + set: map could be map<int,int>, unordered_map<int,int> 

==============================> Apporach and Time Complexity <=============================================

1) Brute Force
Time: O(N^2)
Space: O(1)

2) Map + Set
Time: O(min(N, M))  N and M is size of nums1 and nums2.
Space: O(min(N, M))
*/

class Solution {
public:

    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
    
        if(nums2.size() < nums1.size())
            return intersection(nums2, nums1);

        set<int> st;

        // add elements into the map.
        int mp[1001] = {0};
        for(int num: nums1)
            mp[num] = 1;

        for(int num: nums2) {
            if(mp[num]) {
                st.insert(num);
            }
        }

        return vector<int>(st.begin(), st.end());
    }
};