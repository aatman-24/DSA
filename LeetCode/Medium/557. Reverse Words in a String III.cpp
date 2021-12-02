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

Question: 557. Reverse Words in a String III
Topic : String, Two Pointer.
Problems : https://leetcode.com/problems/reverse-words-in-a-string-iii/

==============================> Explanation <=============================================

- 

==============================> Apporach and Time Complexity <=============================================

1) Two Pointer
Time: O(N)
Space: O(1) / O(N)[For the Stack]

*/


class Solution {
public:

    bool checkPossibility(vector<int>& nums) {
        
        if(nums.size() == 1)
            return true;

        bool oneCredit = true;

       if(nums[0] > nums[1]) {
            nums[0] = nums[1];
            oneCredit = false;
       }

        for(int i = 2; i < nums.size(); i++) {

            if(nums[i-1] > nums[i] && oneCredit) {
                if(nums[i-2] > nums[i]) {
                    nums[i] = nums[i-1];
                    oneCredit = false;
                }
                else if(nums[i-2] <= nums[i]) {
                    nums[i-1] = nums[i-2];   // also nums[i-1] = nums[i] possible.
                    oneCredit = false;
                }
            }
            else if (nums[i-1] > nums[i] && !oneCredit){
                return false;
            }
        }
        return true;

    }
};
