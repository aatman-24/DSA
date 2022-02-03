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

Question : 414. Third Maximum Number
Topic : Array
Problems : https://leetcode.com/problems/third-maximum-number/

==============================> Explanation <=============================================
1) Brute Force: O(N^2)

2) Sort the array: O(NlogN)

3) MinHeap: O(NlogK) 

4) Keep track of max1, max2 and max3.

==============================> Apporach and Time Complexity <=============================================

1) Array
Time: O(N)
Space: O(1)

*/


class Solution {
public:
    int thirdMax(vector<int>& nums) {
        
        long one = LONG_MIN, two = LONG_MIN, three = LONG_MIN;
        for (int num : nums) {
            if (num == one || num == two || num == three)
                continue;
            
            if (num > one) {
                three = two;
                two = one;
                one = num;
            } else if (num > two) {
                three = two;
                two = num;
            } else if (num > three) {
                three = num;
            }
        }
        
        return three == LONG_MIN ? one : three;
    }
};