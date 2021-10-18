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

Question: 983. Minimum Cost For Tickets
Topic : Linear-DP Pattern=CoinChange
Problems : https://leetcode.com/problems/minimum-cost-for-tickets/

==============================> Explanation <=============================================
- Idea is that,

--> Just think about what we can do if we at ith day right now and it is running Day?
- We must buy the pass either of the 1,7,20 days on that day but we don't know which is best at that
moment. Okay not problem we apply the brute force and check which is best.
- We remove the brute force by DP.
- In short we have three options we can do at the ith day so we just explore all of that and take the
best decision from them.

- We create a array for day 0->365 and mark all the running and remaining is same as coin change problem.

1) Choise Diagram: Choose the pass which can give minimum ticket for that day.

2) Base Case: N <= 0 -> return 0.

3) Recurrence Relation: 

    dp[i] = min(dp[i-1]+cost[1], dp[i-7]+cost[7], dp[i-20]+cost[20]) -> here number represent the day.

            cost[7] -> 7th day pass price.
            dp[i-7] -> skip the 7th day.


==============================> Apporach and Time Complexity <=============================================

M = 365
1) Bottom-UP Linear-DP Pattern=CoinChange
Time: O(M)
Space: O(M)

*/


class Solution {
public:
    
int N = 365;
int dayPass[3] = {1, 7, 30};

    int mincostTickets(int N, int isWorking[], vector<int> &costs, int t[]) {

        // day is negative no cost.
        if(N <= 0)
            return 0;

        if(t[N] != -1)
            return t[N];

        // If it is working day then must purchase atleast one of the pass.
        if(isWorking[N]) {

            int min_tickets = INT_MAX;
            
            // we try three of them which ever give minimum cost.
            for(int i = 0; i < 3; i++) {
                min_tickets = min(min_tickets, mincostTickets(N-dayPass[i], isWorking, costs, t) + costs[i]);
            }
            
            return t[N] = min_tickets;
        }
        else {

            // not working day then we jump to the next day.
            return t[N] = mincostTickets(N-1, isWorking, costs, t);
        }
    }

    int mincostTickets(vector<int>& days, vector<int>& costs) {

        int t[N+1];
        memset(t, -1, sizeof(t));

        int isWorking[N+1];
        memset(isWorking, 0, sizeof(isWorking));

        // mark all the days which are working.
        for(int day: days)
            isWorking[day] = 1;

        return mincostTickets(N, isWorking, costs, t);

    }
};





class Solution {
public:
    
    int N = 365;
    int dayPass[3] = {1, 7, 30};

    int mincostTickets(vector<int>& days, vector<int>& costs) {

        int dp[N+1];
        memset(dp, 0, sizeof(dp));

        int isWorking[N+1];
        memset(isWorking, 0, sizeof(isWorking));

        for(int day: days)
            isWorking[day] = 1;

        dp[0] = 0;

        for(int day = 1; day <= N; day++) {
            
            if(isWorking[day] == 1) {
                
                int min_ticket = INT_MAX;
                
                for(int j = 0; j < 3; j++) {
                    
                    if(dayPass[j] <= day) {
                        
                        min_ticket = min(min_ticket, dp[day-dayPass[j]] + costs[j]);
                    }

                    // this is must needed. Because there are case such that, on 1 day pass -> 10
                    // and 7 day pass -> 5 or // 30 day pass -> 1.
                    else {
                        min_ticket = min(min_ticket, 0 + costs[j]);
                    }
                }
                dp[day] = min_ticket;
            }
            else {
                dp[day] = dp[day-1];
            }
        }

        return dp[N];
    }

};