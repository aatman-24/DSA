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

Question: 939. Minimum Area Rectangle
Topic : Hashing
Problems : https://leetcode.com/problems/minimum-area-rectangle/

==============================> Explanation <=============================================
1) Brute Force: Use For loops and try to form the rectangle by checking coordinates of that
four points. (x1 == x2) && (y1 == y2) If that make rectangle then took it's area and keep track
of min area.

2) Optimized With Logic: 

C(x1,y2)       B(x2,y2)

A(x1,y1)       D(x2,y1)

- Using Two Points we check that, Other two points is given or not. Using A and B try to
get the B and D points.

- still it is O(N^4).

To reduce it, we use the hashmap,

x -> {y1, y2...}

We just need to check two condition,

1) mp[x1] contains y2 and 
2) mp[x2] contains y1 

then yes it formed the rectangle...

   area = (x1 - x2) * (y1 - y2).

So we try to make pair of A and B using O(N^2) and Get C and D in O(1) from the map+set.
But as you can see A and B all coordinates must be differnt. x1 != x2 && y1 != y2.

==============================> Apporach and Time Complexity <=============================================
1) BruteForce:
Time: O(N^4)
Space: O(1)

2) Optimized:
Time: O(N^2)
Space: O(N^2)

*/



class Solution {
public:

    int minAreaRect(vector<vector<int>>& points) {

       unordered_map<int, unordered_set<int>> mp;
       for(auto p : points) {
          mp[p[0]].insert(p[1]);
       }

       int ans = INT_MAX;

       int x1, x2, y1, y2;

       for(int i = 0; i < points.size() ; i++) {

          for(int j = i+1; j < points.size(); j++) {

             x1 = points[i][0];
             y1 = points[i][1];
             x2 = points[j][0];
             y2 = points[j][1];

            // both points coordinate should be differnt.
             if(x1 == x2 || y1 == y2)
                continue;

             // checking both [x1, y2] and [x2, y1] points exist or not to make rectangel

             if(mp[x1].count(y2) == 0)
                continue;

             if(mp[x2].count(y1) == 0)
                continue;

             ans = min(ans, abs((x1-x2) * (y1-y2)));
          }
       }

       return ans == INT_MAX ? 0 : ans;
    }
};