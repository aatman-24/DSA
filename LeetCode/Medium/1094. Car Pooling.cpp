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

Question: 1094. Car Pooling
Topic : minHeap, LeaveTimePriorityQueue
Problems : https://leetcode.com/problems/car-pooling/

==============================> Explanation <=============================================
- In this type of question,

1) Leave Time With Priority Queue: Keep track of capacity... simulate with time.
- sort the trips. (min ArrivalTime, min Passanger, min LeavingTime)
- Create a minHeap (<leaveTime, capacityBecomeFree>)
- Add all the trips one by one,
    - for the ith acitivity, arrivalTime = trips[i][0]
    - Free all the seat which passanger leave time is less or equal arrivalTime
    - then check enough seat there to onboard currnet passanger. if not return false
- return true.


2) Simulation the process (Train):
- Here Stops = 1001.
- So we can simpley simulate the process. 
- we create array of stops[1001] = {0};
- add passanger at "to"(it[1]) stops and remove passanger at "from"(it[2]).
- i = 0 -> 1001. capacity -= stops[i]. if capacity become negative at any time return false.
- otherwise return true.


Parent: 1942. The Number of the Smallest Unoccupied Chair


==============================> Apporach and Time Complexity <=============================================

1) Leave Time + Priority Queue:
Time: O(NlogN)
Space: O(N)

2) Simluation of process(Train leave and come at stop):
Time: O(1001)
Space:O(M) -> M = 1001
*/


class Solution {
public:

    static bool sort_func(vector<int> &v1, vector<int> &v2) {
        if(v1[1] == v2[1]) {
            if(v1[0] == v2[0]) {
                return v1[2] < v2[2];
            }
            return v1[0] < v2[0];
        }
        return v1[1] < v2[1];
    }

    bool carPooling(vector<vector<int>>& trips, int capacity) {

        sort(trips.begin(), trips.end(), sort_func);
        priority_queue<pair<int,int>,vector<pair<int,int>>, greater<pair<int,int>>> pq;

        for(int i = 0; i < trips.size(); i++) {

            int arrival = trips[i][1];
            while(!pq.empty() && pq.top().first <= arrival) {
                capacity += pq.top().second; pq.pop();
            }

            if(capacity < trips[i][0])
                return false;

            capacity -= trips[i][0];
            pq.push({trips[i][2], trips[i][0]});
        }

        return true;
    }
};



class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {

        int M = 1001;
        vector<int> stops(M, 0);

        for(auto it: trips) {

            // pick up the it[0] passanger from the it[1] stop.
            stops[it[1]] += it[0];

            // depart the it[1] passanger from the it[2] stop.
            stops[it[2]] -= it[0];
        }

        int i = 0; 
        while(i < M) {
            capacity -= stops[i];
            if(capacity < 0)
                return false;
            i++;
        }

        return true;
    }
};