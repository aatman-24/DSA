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

Question : 581. Shortest Unsorted Continuous Subarray
Topic : Array, Sort
Problems : https://leetcode.com/problems/shortest-unsorted-continuous-subarray/
*/


class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        vi arr(nums);
        sort(arr.begin(), arr.end());
        int start = 0, end = nums.size()-1;
        while(start <= end && nums[start]==arr[start]) start++;
        while(end >= 0 && nums[end] == arr[end]) end--;

        if(start < end) return end-start+1;
        else return 0;
    }
};


int main() {
	Solution ob;
	vi arr = {2,6,4,8,10,9,15};
	cout << ob.solve(arr) << endl;
}