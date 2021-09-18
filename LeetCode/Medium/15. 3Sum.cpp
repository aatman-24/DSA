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

Question : 15. 3Sum
Topic : Two pointer.
Problems : https://leetcode.com/problems/3sum/
/*
==============================> Explanation <=============================================
Two Sum Technique.

How to Handle Duplicate ?

- Ideas is that, For the first pointer i, we check that if nums[i] and nums[i-1] are same
then we don't start from i we skipped it.

- After that, In loop
    
    If we found triplet = {i, begin, end} this tripplet. Then While searching in loop,

    we try to make differnt triplet so skip all the nums[begin] which is same as triplet[begin]
    and same with end pointer also. 

Duplicate Case = -2 0 0 2 2 

*/


/*
==============================> Apporach and Time Complexity  <=============================================
1) Brute Force:
Time: O(N^3)
Space: O(1)

2) HashMap:
Time: O(NlogN)(Sort) + O(N^2)(Traverse through the Pair)
Space: O(N)

2) Two Pointer Apporach:
Time: O(NlogN)(Sort) + O(N^2)
Space: O(1)

*/

class Solution {
    public:
    vector<vector<int>> threeSum(vector<int>& nums) {

        vector<vector<int>> ans;

        // no triplet can be construct.
        if(nums.size() <= 2) return ans;

        // sort the number.
        sort(nums.begin(), nums.end());

        for(int i = 0 ; i < nums.size() - 2; i++) {

            // we never start with same number which is previous one.
            if(i > 0 && nums[i-1] == nums[i]) continue;

            // left and right pointer.
            int begin = i + 1, end = nums.size() - 1; 

            while(begin < end) {

                int total = nums[i] + nums[begin] + nums[end];

                if(total == 0) {
                    vector<int> triplet = {nums[i], nums[begin], nums[end]}; 
                    ans.push_back(triplet);

                    // we avoid the same num[begin] until we found other number as nums[begin].
                    // so duplicate is not going to take place.
                    while(begin < end && nums[begin] == triplet[1]) begin++;
               
                    // we can do for the end pointer also. But we already maintain the two
                    // pointer which does not allow the duplicate. so if just do the end--;
                    // then it's also work.
                    while(begin < end && nums[end] == triplet[2]) end--;
                    // end--; also work 
                }
                else if(total < 0) {
                    begin++;
                }
                else {
                    end--;
                }
            }
        }
        return ans;
    }
};



class Solution {
public:

    vector<vector<int>> threeSum(vector<int>& nums) {

        vector<vector<int>> ans;
        
        sort(nums.begin(), nums.end());

        if(nums.size() < 3)
            return ans;

        // Here target is 0. That's why there should be number which is start less or zero 
        // In starting of the array.
        if(nums[0] > 0)
            continue;

        // Store the {nums[i], last_index_nums[i]}. 
        map<int,int> mp;
        for(int i = 0 ; i < nums.size(); i++) {
            mp[nums[i]] = i;
        }
        
        for(int i = 0; i < nums.size() - 1; i++) {

            // Avoid such number. It don't give the triplet for target 0.
            if(nums[i] > 0)
                continue;

            for(int j = i + 1; j < nums.size(); j++) {

                int required = 0 - nums[i] - nums[j];

                // Check If required is in the map and Index should be i < j < required.
                // To avoid the duplication we always add the last required element's .
                if(mp.count(required) && mp[required] > j) {
                    ans.push_back({nums[i], nums[j], required});
                }

                // Skip the all duplicate of nums[j] if they are.
                j = mp[nums[j]];
            }

            // Skip all the duplicate of nums[i] if they are.
            i = mp[nums[i]];
        }

        return ans;
    }
};