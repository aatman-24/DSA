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

Question : 485. Max Consecutive Ones
Topic : Two Pointer
Problems : https://leetcode.com/problems/max-consecutive-ones/

==============================> Explanation <=============================================

Map can also be used.(prefix sum)
Simple Two pointer approach.


==============================> Apporach and Time Complexity <=============================================

1) Two Pointer
Time: O(N)
Space: O(1)

*/

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        
        int n = nums.size();

        // head point to index from consecutive one start.
        // tail point to index where conseuctive one end. after that index.
        int head = 0, tail = -1;
        int ans = 0;

        while(head < n) {

            while(head < n && nums[head] != 1)
                head++;
            
            tail = head + 1;

            while(tail < n && nums[tail] == 1)
                tail++;

            if(head < n)
                ans = max(ans, tail - head);
            
            head = tail;
        }

        return ans;
    }
};