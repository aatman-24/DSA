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

Question: 350. Intersection of Two Arrays II

Topic : Map, Sorting + Two Pointer

Problems : https://leetcode.com/problems/intersection-of-two-arrays-ii/

==============================> Explanation <=============================================
1) Brute Force: Check each elements of nums1 is into the nums2 or not. Take O(N^2) times.

2) Map: Store all the numbers of nums1(smaller one) into the map with freq.. and check each element of nums2 into the map or not.

3) Sorting + Two Pointer: Sort both array and select the portion which have same elements using two pointer.

==============================> Apporach and Time Complexity <=============================================

1) Brute Force
Time: O(N*M)
Space: O(1)

2) Map
Time: O(min(N, M))
Space: O(min(N, M))

3) Sorting + Two Pointer
Time: O(NlogN) + O(MLogM)
Space: O(1)

*/

class Solution {
public:

    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
    
        if(nums2.size() < nums1.size())
            return intersection(nums2, nums1);

        vector<int> ans;

        // add elements into the map.
        int mp[1001] = {0};
        for(int num: nums1)
            mp[num]++;

        for(int num: nums2) {
            if(mp[num]) {
                ans.insert(num);
                mp[num]--;
            }
        }

        return ans;
    }
};



// Sort + Two Pointer Selection.....
class Solution {
public:

    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
    
        if(nums2.size() < nums1.size())
            return intersect(nums2, nums1);

        vector<int> ans;

        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());

        int i = 0, j = 0;
        while(i < nums1.size() && j < nums2.size()) {

            if(nums1[i] == nums2[j]) {
                ans.push_back(nums1[i]);
                i++; j++;
            }
            else if(nums1[i] < nums2[j]) {
                i++;
            }
            else {
                j++;
            }
        }

        return ans;
    }
};