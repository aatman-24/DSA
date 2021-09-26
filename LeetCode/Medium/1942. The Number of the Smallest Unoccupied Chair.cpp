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

Question: 1942. The Number of the Smallest Unoccupied Chair
Topic : minHeap, Set
Problems : https://leetcode.com/problems/the-number-of-the-smallest-unoccupied-chair/

==============================> Explanation <=============================================
- Solved this type of question first,
--> first for here given that all friends arrivaltime is distinct so we can keep track of targetFriend by his
arrival time, if it is not given then you have to assign the friendNumber and after that sort the time interval
of them.
--> Intuition is that, when any time new friends comes we first remove all the outdated friends so we can reuse
their chair for current friends. And we assign the smallest number of chair to him so that we push free chair
into the set which store the value in increasing value.
--> For free chair I used set, we can also use map for that.

==============================> Apporach and Time Complexity <=============================================
N -> Times length.
1) minHeap:
Time:O(NlogN)
Space:O(N)
*/

class Solution {
public:
    int smallestChair(vector<vector<int>>& times, int targetFriend) {

            // We keep track of targetFriend by using arrival time of it because all friend have distinct arrival time.
            int targetFriendArrivalTime = times[targetFriend][0];

            // <leaving_time, seatNumber>
            priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;

            // Sort the time in incresing order.
            sort(times.begin(), times.end());

            // Keep track of free chair.
            set<int> st;
            
            int currentSeat;
            int seat = 0;

            for(auto it: times) {

                int arrivalTime = it[0];
                int leavingTime = it[1];

                // We first pop all the friends whose leaving time is less or equal current friend arrival time
                // and free chair will be added into the set.
                while(!pq.empty() && pq.top().first <= arrivalTime) {
                    st.insert(pq.top().second);
                    pq.pop();
                }

                // Now for the current friend, we check there is any chair available then we assign that.
                if(st.size() > 0) {
                    currentSeat = *(st.begin());
                    st.erase(st.begin());
                }
                // Otherwise new chair assigned to him.
                else {
                    currentSeat = seat;
                    seat++; 
                }

                pq.push({leavingTime, currentSeat});
                if(arrivalTime == targetFriendArrivalTime) {
                    return currentSeat;
                }
            }

            return 0;
        }
};