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

Question: 1488. Avoid Flood in The City
Topic : set, minHeap
Problems : https://leetcode.com/problems/avoid-flood-in-the-city/

==============================> Explanation <=============================================

Idea is that,

- 1 2 0 ? (on 1 and 2 there are rain and on 3rd day is empty so we can make any of 1 or 2 lake empty)
but we don't know which one because at ?(1) then we must empty the 1 lake and 2 then 2 lake.
- so it is clear that on dryday which lake needs to empty, we can know after the drydays which lake has
first chance to again rain on it.
- so we keep track of fullakes and drydays.

- Intuition is that,

- if any day there is rain on lake, then we first check that lake is already full or not (using fulllakes)
if yes then check on which day(fulllakes[lake]) it becomes full. Then check there is any
dryday after that day(using drydays) if yes then we assign that dryday to empty the current lake which
rained on that second time. if no drydays then floodss.......


Greedy Apporach, We choose nearest dryday for after the lake become full. 


Rathar than using set for the drydays we can use minHeap.


==============================> Apporach and Time Complexity <=============================================
K = drydays
N = rainy days

1) Set + Map (minHeap + Map):
Time: O(NlogN)
Space: O(K) + O(N) 

*/


class Solution {
public:

    vector<int> avoidFlood(vector<int>& rains) {

        int N = rains.size();

        // Initialy set -1 for all day. We overwrite its later.
        vector<int> ans(N, -1);

        // fullakes keep track of lake become full at which day. <lake_num, day>
        unordered_map<int,int> fulllakes;

        // keep track of dry days.
        set<int> drydays;

        for(int i = 0; i < rains.size(); i++) {

            // If norain means drydays just inserts into drydays.
            if(rains[i] == 0) {
                drydays.insert(i);

                // we overwrite it if this days is used to keep dry any lake.
                ans[i] = 1;
            }
            else {

                // lake on which rain happening.
                int lake = rains[i];

                // If this lake is already full we try to make it empty first if possible.
                if(fulllakes.count(lake)) {

                    // We first got the day on which it become full.
                    int prevday = fulllakes[lake];

                    // try to find dryday just after the prevDay(lake become full).
                    auto it = drydays.lower_bound(prevday);

                    // If not found then there is flood.
                    if(it == drydays.end()){
                        return {};
                    }
                    else {

                        // found then we set that dryday to empty the current lake.
                        int dryday = *it;
                        ans[dryday] = lake;

                        // Erase the dryday from drydays.
                        drydays.erase(dryday);
                    }
                }


                // first time lake become full.
                fulllakes[lake] = i;

                // no need of this.
                ans[i] = -1;
            }
        }

        return ans;
    }
};