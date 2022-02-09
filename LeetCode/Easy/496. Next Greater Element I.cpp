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

Question : 496. Next Greater Element I
Topic : Stack + Map
Problems : https://leetcode.com/problems/next-greater-element-i/

==============================> Explanation <=============================================

Brute Force:

- Find the greater[] for nums2.
- For each value of nums1, find j such that nums1[i] == nums[j] and find the greater element
of nums2[j].

Optimized:

- Find the greater[] for nums2.
- Store the result of nums2 and greater[] into the map. <nums[j], index>
- For each value of nums1[i], we don't need to find nums2[j], we directly use the map to get
the index.
- Using that index we can get greater number by greater[index].

Optimized Space:

- We can use greater<value, greater_value> to do the same by eliminating the greater[] space.




==============================> Apporach and Time Complexity <=============================================

1) Brute Force + Stack
Time: O(N*M)
Space: O(M)

1) Map + Stack
Time: O(N+M)
Space: O(2M) -> O(M)

*/



class Solution {
public:

    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {

        // map the, nums2 array entry <value, index>
        unordered_map<int,int> mp;
        for(int i = 0; i < nums2.size(); i++) {
            mp[nums2[i]] = i;
        }

        // Find the greater element for nums2 array.
        vector<int> greater(nums2.size(), -1);
        stack<int> st;
        
        for(int i = 0; i < nums2.size(); i++) {

            while(!st.empty() && nums2[st.top()] < nums2[i]) {
                int index = st.top(); st.pop();
                greater[index] = nums2[i];
            }

            st.push(i);
        }


        vector<int> ans(nums1.size(), -1);
        

        for(int i = 0; i < nums1.size(); i++) {
            
            // given that nums1 is subset of nums2, so no need to check 
            // nums1 value is available in nums2 or not.

            // nums1[i] -> value
            // mp[value] -> index
            // greater[index] -> greater number.
            ans[i] = greater[mp[nums1[i]]];
        }

        return ans;
    }
}; 




// Same as above, eliminate the extra space for greater[]. By directly 
// Mapping with unordered_map.
class Solution {
public:

    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {

        // map<value, greater>, initialize with -1 as greater element for all value.
        unordered_map<int,int> greater;
        for(int i = 0; i < nums2.size(); i++) {
            mp[nums2[i]] = -1;
        }

        // find greater element for all the value and 
        // directly store into the greater.
        stack<int> st;
        for(int i = 0; i < nums2.size(); i++) {

            while(!st.empty() && nums2[st.top()] < nums2[i]) {
                int index = st.top(); st.pop();
                greater[nums2[index]] = nums2[i];
            }

            st.push(i);
        }

        // same as above.
        vector<int> ans(nums1.size(), -1);
        for(int i = 0; i < nums1.size(); i++) {
            ans[i] = greater[nums1[i]];
        }

        return ans;
    }
}; 