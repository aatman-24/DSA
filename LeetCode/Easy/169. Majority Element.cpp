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

Question: 169. Majority Element
Topic : Hashing, Bit-Manipulation, Counting
Problems : https://leetcode.com/problems/majority-element/

==============================> Explanation <=============================================

1) Brute Force: Count Each Occurance of Element.

2) Hashing: use the map to count occurance of each element.

3) Sorting: Sort the Array then count.

4) Boyer-moore Voting: https://www.geeksforgeeks.org/boyer-moore-majority-voting-algorithm/.
                       Here given that answer is exist so we don't need to check/confirm
                       using second loop.


5) Bit-Manipulation: We just count the how many time each bit(1-32) is set into the
                     all number if it is more than n/2 times we mask with majority.
                     This is General Apporach.




==============================> Apporach and Time Complexity <=============================================
1) Brute Force:
Time: O(N^2)
Space: O(1)

2) Hashing:
Time: O(N)
Space: O(N)

3) Sorting:
Time: O(NlogN)
Space: O(1)

4) Counting:
Time: O(N)
Space: O(1)

5) Bit-Manipulation: (General Approach)
Time: O(32N)
Space:  O(1)

*/

class Solution {
public:

int majorityElement(vector<int>& nums)  {

    int majority = nums[0], count = 1;

    for(int i = 1; i < nums.size(); i++) {

        // appoint the current element as majority.
        if(count == 0) {
            majority = nums[i];
            count++;
        }
        else if(nums[i] == majority) {
            count++;
        }
        else {
            count--;
        }
    }

    return majority;
}


};

class Solution {
public:

int majorityElement(vector<int>& nums) {

    int majority = 0; 
    
    for(int i = 0; i < 32; i++) {
        
        int mask = 1 << i;
        
        int count = 0;
        
        for(auto num: nums) {
    
            if(num & mask) {
                count++;
            }
        }

        if(count > (nums.size()/3)) {
            majority = majority | mask;
        }
    }

    return majority;
}

};