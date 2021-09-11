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

Question : 27. Remove Element
Topic : Array
Problems : https://leetcode.com/problems/remove-duplicates-from-sorted-array/
==============================> Explanation <=============================================
Both are same.
The last tail extra element is what is that it is does not matter.


O(N) - O(1).
*/


/*
==============================> Edge Case <=============================================




*/


class Solution {
public:

    int removeElement(vector<int>& nums, int val) {

        int val_index = -1; 
        int j = 0;
        int count = 0;

        while(j < nums.size()) {

            if(nums[j] == val && val_index == -1) {
                val_index = j;
            }

            if(nums[j] == val)
                count++;

            if(nums[j] != val && val_index >= 0) {
                nums[val_index] = nums[j];
                val_index++;
            }

            j++;
        }

        return nums.size() - count;
    }

    int removeElement(int A[], int n, int elem) {
        int begin=0;

        for(int i=0;i<n;i++) 
            if(A[i]!=elem) 
                A[begin++]=A[i];
            
        return begin;
    }
};