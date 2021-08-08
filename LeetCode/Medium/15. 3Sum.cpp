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


- simple for the first pointer. we check weather prvious number is same 
then we don't start again with same number.


- when we found the triplet {i, begin, end} indexs. Now to avoid duplicate we again 
see for the one of the pointer begin or end.
The next nums[begin] should not be same as current triplet nums[begin].
we can do the same for the end pointer also. but if we already covered two pointer than 
for the end pointer no need to handle duplicate. It automatic never allowed the duplicate.

Duplicate Case = -2 0 0 2 2 

*/


/*
==============================> Edge Case <=============================================


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
                    while(begin < end && nums[end] == nums[2]) end--;
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