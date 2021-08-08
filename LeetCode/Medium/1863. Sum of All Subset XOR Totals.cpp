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

Question : 1863. Sum of All Subset XOR Totals
Topic : Math, subset, Logic, Observation
Problems : https://leetcode.com/problems/sum-of-all-subset-xor-totals/
*/

// Refer This -> https://leetcode.com/problems/sum-of-all-subset-xor-totals/discuss/1211177/Simple-trick-oror-4-lines-of-code-oror-Explained!!
 
class Solution {
public:

    // O(2^N) - Generate all subset using bitwise manipulation.
    int subsetXORSum(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        for(int subsetMask = 0; subsetMask < (1 << n); subsetMask++) {
            int tmp = 0;
            for(int i = 0; i < n; i++) {
                if(subsetMask & (1 << i)) {
                    tmp = tmp ^ nums[i];
                }
            }
            ans += tmp;
        } 
        return ans;       
    }

    // Pure logic + observation
    int subsetXORSum(vector<int>& nums) {
        int ans = 0;
        for(auto num : nums) {
            ans |= num;
        }
        return ans * pow(2, nums.size()-1);
    }

};