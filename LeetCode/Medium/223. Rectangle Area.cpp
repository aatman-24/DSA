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

Question: 223. Rectangle Area
Topic : Logic, Math, Geometry
Problems : https://leetcode.com/problems/rectangle-area/

==============================> Explanation <=============================================
Idea is simple,

= Covered Area - Overlapped Area

==============================> Apporach and Time Complexity <=============================================

1) Logic:
Time: O(1)
Space: O(1)

*/

class Solution {
public:

int computeArea(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2) {

    // can not be negative. When both rect are differnt one that time min() condition give
    // negative value which can not be so adjust it.
    int X = 0, Y = 0; 

    // X -> (ax1 bx1 ax2 bx2) or (ax1 bx1 bx2 ax2)
    if(ax1 < bx1) {
        X = max(X, min(ax2 - bx1, bx2 - bx1));
    }
    // oppsite of above one. bx1 lead.
    else if(bx1 < ax1) {
        X = max(X, min(bx2-ax1, ax2 - ax1));
    }
    // which ever is min(ax2, bx2) if finished first it is inside of other one.
    else {
        X = max(X, min(ax2, bx2) - ax1);
    }

    // Same with y dimesion.
    if(ay1 < by1) {
        Y = max(Y, min(ay2 - by1, by2 - by1));
    }
    else if(by1 < ay1) {
        Y = max(Y, min(by2 - ay1, ay2 - ay1));
    }
    else {
        Y = max(Y, min(ay2, by2) - ay1);
    }

    return (ax2 - ax1) * (ay2 - ay1) + (bx2 - bx1) * (by2 - by1) - X * Y;
}
};