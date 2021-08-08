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

Question :1217. Minimum Cost to Move Chips to The Same Position
Topic : Logic array
Problems : https://leetcode.com/problems/minimum-cost-to-move-chips-to-the-same-position/

/*
==============================> Explanation <=============================================
odd to odd | even to even cost = 0
only odd to even or even to odd = cost =  1

so if we find which pos has maximum coin then the opposite can be over choice to move.

so answer is minimum of both.


*/

/*
==============================> Edge Case <=============================================

*/

// 

class Solution {
public:
    int minCostToMoveChips(vector<int>& position) {

        int odd = 0, even = 0;

        for(int pos : position) {
            if(pos % 2) odd++;
            else even++;
        }

        return min(odd, even);


    }

};