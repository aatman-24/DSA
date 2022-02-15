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

Question : 492. Construct the Rectangle
Topic : Math
Problems : https://leetcode.com/problems/construct-the-rectangle/

==============================> Explanation <=============================================
Find the closest. Binary Search is not possible here. Just find the boundary, lower and closer.
==============================> Apporach and Time Complexity <=============================================

1) Math
Time: O(sqrt(N))
Space: O(1)

*/

class Solution {
public:

    vector<int> constructRectangle(int area) {
    
        int x = area, y =  1;

        for(int L = area/2; L >= 1; L--) {

            int W = (area) / L;

            if(W > L)
                break;

            // find the closest.
            if(W * L == area && L >= W && (L - W) < (x - y)) {
                x = L;
                y = W;
            }

        }

        return {x, y};
    }
};



class Solution {
public:

    vector<int> constructRectangle(int area) {
    
        int w = sqrt(area);

        while(area % w != 0)
            w--;

        return {area/w, w};
    }
};

