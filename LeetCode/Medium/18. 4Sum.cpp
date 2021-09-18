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

Question : 18. 4Sum
Topic : Array, HashMap, Two Pointer, Sorting
Problems : https://leetcode.com/problems/4sum/
*/


/*
==============================> Explanation <=============================================
1) Using for four loops with additional duplication avoid technique we can get all
quadruplets.

2) Same as we used in three sum,
- sort the array. 
- first add all the single elements in map.
- now using three loop construct the required number and check that wheater it is in map
or not. If yes add it.
- At each loop add the duplication avoidance technique.

3) For duplication, used map with string so no duplicate is added two times into
the result.

4) Sorting + Two Pointer Apporach(CC Persepective)

*/


/*
==============================> Apporach and Time Complexity <=============================================
1) Brute Force:
Time: O(N^4)
Space: O(1)

2) HashMap for checking Last number:
Time: O(NlogN)(Sort) + O(N^3)(Traverse through the Pair)
Space: O(N)

3) Hashmap for Duplication:
Time: O(NlogN)(Sort) + O(N^3)(Traverse through the Pair)
Space:O(N)

2) Sorting + Two Pointer Apporach:
Time: O(NlogN)(Sort) + O(N^3)
Space: O(1)

*/



class Solution {
public:   

        // O(N^3) - O(N)
       vector<vector<int>> fourSum(vector<int>& nums, int target) {

            vector<vector<int>> ans;

            if(nums.size() < 4) {
               return ans;
            }
            map<string, string> mp;
            
            sort(nums.begin(), nums.end());
            for(int i = 0; i < nums.size() - 3; i++) {
                for(int j = i + 1; j < nums.size() - 2; j++) {
                    int total = nums[i] + nums[j];
                    int lh = j + 1, rh = nums.size() - 1;
                    while(lh < rh) {
                        int curr = total + nums[lh] + nums[rh];
                        if(curr == target) {
                            string tmp = to_string(nums[i]) + '_' + to_string(nums[j]) + '_' + to_string(nums[lh]) + '_' + to_string(nums[rh]);
                            if(mp.find(tmp) == mp.end()) {
                                ans.push_back({nums[i], nums[j], nums[lh], nums[rh]});
                                mp[tmp] = tmp;
                            }
                            lh++; rh--;
                        }
                        else if(curr < target) {
                            lh++;
                        }
                        else {
                            rh--;
                        }
                    }
                }
            }
            return ans;
    }



    // O(N^3) - O(1)
     vector<vector<int>> fourSum(vector<int>& nums, int target) {

        vector<vector<int>> ans;

        if(nums.size() < 4)
            return ans;

        sort(nums.begin(), nums.end());

        for(int i = 0; i < nums.size() - 3; i++) {

            if(i>0&&nums[i]==nums[i-1]) continue;

            for(int j = i + 1; j < nums.size() - 2; j++) {

                if(j>i+1&&nums[j]==nums[j-1]) continue;

                int total = nums[i] + nums[j];

                int lh = j + 1, rh = nums.size() - 1;

                while(lh < rh) {

                    int curr = total + nums[lh] + nums[rh];

                    if(curr == target) {
                        ans.push_back({nums[i], nums[j], nums[lh], nums[rh]});
                        do{lh++;}while(nums[lh]==nums[lh-1]&&lh<rh);
                        do{rh--;}while(nums[rh]==nums[rh+1]&&lh<rh);
                    }
                    else if(curr < target) {
                        lh++;
                    }
                    else {
                        rh--;
                    }
                }
            }
        }
        return ans;
    }
};