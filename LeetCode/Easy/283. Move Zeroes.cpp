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

Question: 283. Move Zeroes
Topic :Two Pointer, Logic
Problems : https://leetcode.com/problems/move-zeroes/

==============================> Explanation <=============================================

Check both approach.

==============================> Apporach and Time Complexity <=============================================

1) Two Pointer/logic
Time: O(N)
Space: O(1)

*/

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
    
        if(nums.size() <= 1)
            return;

        int n = nums.size();


        int zeroPtr = 0, nonZeroPtr = 1;
        
        while(nonZeroPtr < n && zeroPtr < n) {

            while(zeroPtr < n && nums[zeroPtr] != 0)
                zeroPtr++;

            // nonZeroPtr must be forward than zeroPtr.
            if(nonZeroPtr <= zeroPtr)
                nonZeroPtr = zeroPtr + 1;
            
            while(nonZeroPtr < n && nums[nonZeroPtr] == 0)
                nonZeroPtr++;

            // update both pointer value.
            if(zeroPtr < n && nonZeroPtr < n) {
                nums[zeroPtr] = nums[nonZeroPtr];
                nums[nonZeroPtr] = 0;
            }

            zeroPtr++; nonZeroPtr++;
        }
    }
};


// same as, dp space apporach.. left side value is not override so 
// we cover left value first and after that fill remaining zero.
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
    
        if(nums.size() <= 1)
            return;

        int n = nums.size();
        
        int insertPos = 0;

        for(int i = 0; i < n; i++) {
            if(nums[i] != 0)
                nums[insertPos++] = nums[i];
        }

        for(int i = insertPos; i < n; i++)
            nums[i] = 0;
    }
};