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

Question: 974. Subarray Sums Divisible by K
Topic : prefixsum
Problems : https://leetcode.com/problems/subarray-sums-divisible-by-k/

==============================> Explanation <=============================================
- In this type of question,

1) Brute force: make subarray using two for loop and third loop for the sum.

2) prefix sum: When Multiplication and division there then choose the mod opreator because any time if
current sum is a % K == current sum b % K then, from [i+1, j] subarray is divisible by K.
Rules to remember for this type of question:
Addition/Subtraction: Store the direct Sum.
Multiplication/Division: Store the (cursum % K) into map.
negative number -> perform the mod opreator on positive number so make the current sum positive first.



Parent: 523. Continuous Subarray Sum

==============================> Apporach and Time Complexity <=============================================

1) Brute Force:
Time:O(N^3)
Space:O(1)

2) Prefix sum:
Time:O(N)
Space:O(N)


*/


class Solution {
public:
    
    int subarraysDivByK(vector<int>& nums, int k) {

        unordered_map<int, int> mp;

        // Base case, form [0, i] sum is zero it means it divisible by K. 
        mp[0] = 1;

        int sum = 0, ans = 0;

        for(int i = 0; i < nums.size(); i++) {

            sum += nums[i];

            // Make Sum Positive.
            if(sum < 0) {
                int i = 1;
                while(sum + k * i < 0) {
                    i++;
                }
                sum += k * i;
            }

            sum = sum % k;
            
            if(mp.count(sum)) {
                ans += mp[sum];
            }

            mp[sum]++;

        }

        return ans;
    }
};


class Solution {
public:
    
    int subarraysDivByK(vector<int>& nums, int k) {

        unordered_map<int, int> mp;
        mp[0] = 1;

        int sum = 0, ans = 0;

        for(int i = 0; i < nums.size(); i++) {
            
            sum += nums[i];

            int rem = sum % k;

            // Make it Positive. It's works.
            if(rem < 0)
                rem += k;

            if(mp.count(rem)) {
                ans += mp[rem];
            }

            mp[rem]++;
        }

        return ans;
    }

};


class Solution {
public:
    
       int subarraysDivByK(vector<int>& nums, int k) {

        unordered_map<int, int> mp;
        mp[0] = 1;

        int sum = 0, ans = 0, rem;

        for(int i = 0; i < nums.size(); i++) {
            
            sum += nums[i];

            sum = sum % k;

            if(sum < 0)
                sum += k;

            if(mp.count(sum)) {
                ans += mp[sum];
            }

            mp[sum]++;

        }

        return ans;
    }

};