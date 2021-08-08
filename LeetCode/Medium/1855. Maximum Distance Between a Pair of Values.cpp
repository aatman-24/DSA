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

Question : 1855. Maximum Distance Between a Pair of Values
Topic : Two pointer
Problems : https://leetcode.com/problems/maximum-distance-between-a-pair-of-values/
*/


class Solution {
public:

    // start from the tail O(N)
    int maxDistance(vector<int>& nums1, vector<int>& nums2) {

        int i = nums1.size() - 1, j = nums2.size() - 1, ans = 0;

        while(i >= 0 && j >= 0) {

            while(j >= 0 && nums1[i] > nums2[j]) j--;
            if(j < i) i = j;

            while(i >= 0 && i <= j && nums1[i] <= nums2[j]) {
                i--;
            }

            if(j != -1)
                ans = max(ans, j-i-1);
            j--;
        }
        return ans;
    }


    // Start from the head O(N)
    int maxDistance(vector<int>& A, vector<int>& B) {
        int i = 0, j = 0, res = 0, n = A.size(), m = B.size();
        while (i < n && j < m) {
            if (A[i] > B[j])
                i++;
            else
                res = max(res, j++ - i);
        }
        return res;
    }

};
