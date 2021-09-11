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
d
/*
==============================> Description <=============================================

Question : 268. Missing Number
Topic : Array
Problems : https://leetcode.com/problems/missing-number/
==============================> Explanation <=============================================
1) Using Sum. sum contain [0,N] so whatever is remain is the answer.

2) XOR. (Every element from [0, N] is xor two times. So if number xor two time which result into the zero.
So whatever is missing is only xor one time so still it is one time into answer).

*/


/*
==============================> Edge Case <=============================================




*/



class Solution {
public:

    int missingNumber(vector<int>& nums) {
        int n = nums.size() + 1;
        int sum = (n * (n-1)) / 2;
        for(auto num: nums)
            sum -= num;
        return sum;
    }


    int missingNumber(vector<int>& nums) {
        int res = nums.length;
        for(int i=0; i<nums.length; i++){
            res ^= i;
            res ^= nums[i];
        }
        return res;
    }
};