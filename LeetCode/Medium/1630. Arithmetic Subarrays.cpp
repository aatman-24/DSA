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

Question : 1630. Arithmetic Subarrays
Topic : Sort, Greedy
Problems : https://leetcode.com/problems/arithmetic-subarrays/

/*
==============================> Edge Case <=============================================


*/


/*
==============================> Explanation <=============================================


*/


class Solution {
public:
    vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) {

        int size = l.size();

        vector<bool> result;

        for(int i = 0; i < size; i++) {

            int left = l[i];
            int right = r[i];

            vector<int> tmp(right-left+1, 0);

            for(int i = left; i <= right; i++) {
                tmp[i-left] = nums[i];
            }

            sort(tmp.begin(), tmp.end());
            
            int j, diff;
            diff = tmp[1] - tmp[0]
            bool flag = true;
            for(j = 1; j < tmp.size() && flag; j++) {
                if(tmp[j] - tmp[j-1] != diff) {
                    flag = false;
                    break;
                }
            }        
            result.push_back(flag);

        }

        return result;    
    }
};