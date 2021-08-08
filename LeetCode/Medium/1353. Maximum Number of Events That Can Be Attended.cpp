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

Question : 1353. Maximum Number of Events That Can Be Attended
Topic : Greedy, PQ, Scheduling 
Problems : https://leetcode.com/problems/maximum-number-of-events-that-can-be-attended/
/*
==============================> Explanation <=============================================
- Scheduling Algorithm Templates 
- Sort the event which start first and end first. (Greedy)

Greedy algorithm proof:


- At some day, suppose both events E1 and E2 are available to choose to attend. For contradictory 
purpose, suppose the event E1 that is going to end sooner is not the best choice for now. Instead, 
E2 that ends later is the best choice for now. By choosing E2 now, you come up with a schedule S1.

- I claim that I can always construct another schedule S2 in which we choose E1 instead of E2 for now, 
  and S2 is not worse than S1.
    -In S1, from now on, if E1 is picked some time after, then I can always swap E1 and E2 in S1, 
        so I construct a S2 which is not worse than S1.
    -In S1, from now on, if E1 is not picked some time after, 
        then I can aways replace E2 in S1 with E1, so I construct a S2 which is not worse than S1.

So it is always better (at least not worse) to always choose the event that ends sooner.



- Simple language, suppose two events are [1,4] [1,9]
we know [1,4] is best to choose but suppose we taking the [1,9] and make schedule S which is best.

So we can contradictory say that is false with below reason,

- So after some time if we choose [1,4] because already [1,9] is choosen at day 1. so we can choose
[1,4] after day = 2, 3, 4 any time. so we can swap both event in S which is better than current S.

- If after some time we can not choose [1,4] due to some other events, then why just we replace
[1,9] with [1,4]. Because it gives the result same. 



- Here what we do is?

- use pq to choose the best end time for cuurent day. We add end time of event into queue when 
the day = event[i][0]. (Algorithm - 2)


- Algrithm - 1 when the pq is empty we choose the ith event start time as day. Add into pq.
and remove all event which is outdated. End time already finished compare to the current day.
*/


/*
==============================> Edge Case <=============================================


*/

class Solution {
public:

    // strict(O*logN)+ O(N) space
    int maxEvents(vector<vector<int>>& A) {
        priority_queue<int, vector<int>, greater<int>> pq;
        sort(A.begin(), A.end());
        int i = 0, res = 0, day = 0, n = A.size();
        while(pq.size() > 0 || i < n) {

            // pq is empty. We find the day from event is occured.
            if(pq.size() == 0) {
                day = A[i][0];
            }

            // After than we add all the events which already started or have same day to start.
            while(i < n && A[i][0] <= day) {
                pq.push(A[i++][1]);         // we push the end day of the event into pq.
            }

            pq.pop(); // occupied the best day for event
            res++;  day++;


            // all the event which is already ended. Bcz we consider the current day to pop from the queue.
            while(pq.size() > 0 && pq.top() < day) {
                pq.pop();
            }

        }

        return res;
    }
    
    // O(d + nlogn) where D is the range of A[i][1] + O(N) space
    int maxEvents(vector<vector<int>>& A) {
        priority_queue<int, vector<int>, greater<int>> pq;
        sort(A.begin(), A.end());
        int i = 0, res = 0, day = 0, n = A.size();
        for(int day = 0; day <= 1000000; day++) {

            // remove all outdated events 
            while(pq.size() > 0 && pq.top() <day) {
                pq.pop();
            }

            // event which start at current day add it's end day to the queue.
            while(i < n && A[i][0] == day) {
                pq.push(A[i++][1]);
            }

            if(pq.size() > 0) {
                pq.pop();
                res++;
            }

        }
        return res;
    }
};