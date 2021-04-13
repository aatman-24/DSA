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

Question : 1470. Shuffle the Array
Topic : Array
Problems :https://leetcode.com/problems/shuffle-the-array/
*/


class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        int m = 2*n;
        vi arr(m, 0);
        int k = 0;
        int i=0, j=n;
        while(k < m) {
            if(k % 2 == 0) {
                arr[k] = nums[i];
                i++;
            }
            else {
                arr[k] = nums[j];
                j++;
            }
            k++;
        }   
        return arr;
    }
};

