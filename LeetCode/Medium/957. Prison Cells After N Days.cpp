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

Question: 957. Prison Cells After N Days
Topic : Hashing
Problems : https://leetcode.com/problems/prison-cells-after-n-days/

==============================> Explanation <=============================================
- Idea is simple,

There are 8 position and among them [0, 7] must be 0. So remaining is 6. 2^6 state possible.
Means there are cycle for sure. so we use that logic and avoid extra state which is already
visited.

It is noticed that, at 14 step there is cycle. Don't tell in InterView.

==============================> Apporach and Time Complexity <=============================================
1) HashMap:
Time: O(M) M can be 2^6 maximum.
Space: O(M)
*/



class Solution {
public:

    vector<int> nextDay(vector<int> &prevDayCells) {

        int n = prevDayCells.size();

        vector<int> currDayCells(prevDayCells);

        for(int i = 1; i < n - 1; i++) {
            if(prevDayCells[i-1] == prevDayCells[i+1])
                currDayCells[i] = 1;
            else
                currDayCells[i] = 0;
        }

        currDayCells[0] = 0;
        currDayCells[n-1] = 0;
        return currDayCells;
    }


    vector<int> prisonAfterNDays(vector<int>& cells, int n) {

        map<vector<int>, int> visited;

        int cycle = 0;
        bool hasCycle = false;

        for(int i = 0; i < n; i++) {
      
            // here, if current cells next day is starting point of the cycle
            // we break at current cells.
            vector<int> next = nextDay(cells);
        
            if(!visited.count(next)) {
                visited[next] = 1;
                 cycle++;
            }
            else {
                hasCycle=true;
                break;
            }

            cells = next;
        }


        if(hasCycle) {
           n %= cycle;

           // again peform go upto the n.
           for(int i = 0; i < n; i++) {
              cells = nextDay(cells);
           }
        }
        
            return cells;
    }

};