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

==============================> Explanation <=============================================
- Here we need to find rectangle area with can hold the maximum water.
Idea is simple,
If height[l] < height[l+k], then maximum water can be hold on left side is height[l].
   height[r-k] > height[r], then maximum water can be hold on right side is height[r]. 

- Means any two line(l,r) can make the area is ->  min(height[l], height[r]) * (r - l).

1) Create all the pair of (l, r) and try to find the maximum area.

2) Two Pointer Approach:

- Intution behind this algorithm is that, we start from both the ends as left and right.
- Now we calculate the distance for current (left, right).
- Whichever side height is less we increase that pointer reason is that, Fixing that pointer/side
don't make the any change in maxArea. Whatever maxArea coverd with this point is already covered.
so we increase that point.

Example...  

    4(l) 9 12 7 8 14(r)
    area = min(4, 14) * (5) = 20
    Now, finding for [4 to 8], [4 to 7], [4 to 12], [4 to 9] don't make better result than 4.
    That's why we increase the point which has less height. 


==============================> Apporach and Time Complexity <=============================================

*/


class Solution {
public:

    int maxArea(vector<int>& height) {

        int ans = 0;
        for(int i = 0; i < height.size(); i++) {
            for(int j = i + 1; j < height.size(); j++) {
                ans = max(ans, min(height[i], height[j]) * (j - i));
            }
        }

        return ans;
    }
};



class Solution {
public:

    int maxArea(vector<int>& height) {
        int l = 0, r = height.size() - 1;
        int maxArea = 0, currentArea = 0;
        while(l < r) {
            if(height[l] < height[r]) {
                currentArea = min(height[l],height[r]) * (r-l);
                maxArea = max(maxArea, currentArea);
                l++;
            }
            else {
                currentArea = min(height[l],height[r]) * (r-l);
                maxArea = max(maxArea, currentArea);
                r--;
            }
        }
        return maxArea;
    }

};



