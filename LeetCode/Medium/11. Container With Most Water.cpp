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

Question : 11. Container With Most Water
Topic : Two pointer
Problems : https://leetcode.com/problems/container-with-most-water/
*/


// MaxArea has max water. Initution behind this probelm is same as rain trapping. but
// here we rain is not matter to us need to find just maxarea.






class Solution {
public:

    int maxArea(vector<int>& height) {
        int l = 0, r = height.size() - 1;
        int maxArea = 0, maxTmp = 0;
        while(l < r) {
            if(height[l] < height[r]) {
                maxTmp = min(height[l],height[r]) * (r-l);
                maxArea = max(maxArea, maxTmp);
                l++;
            }
            else {
                maxTmp = min(height[l],height[r]) * (r-l);
                maxArea = max(maxArea, maxTmp);
                r--;
            }
        }
        return maxArea;
    }

};