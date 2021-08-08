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

Question : 1465. Maximum Area of a Piece of Cake After Horizontal and Vertical Cuts
Topic : Greedy
Problems : https://leetcode.com/problems/maximum-area-of-a-piece-of-cake-after-horizontal-and-vertical-cuts/
/*
==============================> Explanation <=============================================
After Sorting,

- Max Height And Max Width can be,

- 0 -> first minimum cut
- any two consecutive cuts differnce
- last maximum cut -> height

Differnce of this whatever is maximum can be maximum height and width.


*/


/*
==============================> Edge Case <=============================================


*/

class Solution {
public:


    int maxArea(int h, int w, vector<int>& hc, vector<int>& vc) 
    {
        int m = hc.size(), n = vc.size();
        
        sort(hc.begin(), hc.end());
        sort(vc.begin(), vc.end());
        
        int max_h = hc[0], max_v = vc[0];
        
        for(int i = 1; i < m; i++)
            max_h = max(max_h, hc[i] - hc[i - 1]);
        max_h = max(max_h, h - hc.back());  // well written.
        
        for(int i = 1; i < n; i++)
            max_v = max(max_v, vc[i] - vc[i - 1]);
        max_v = max(max_v, w - vc.back());
        
        return (long)max_h * max_v % 1000000007;
        
    }
};