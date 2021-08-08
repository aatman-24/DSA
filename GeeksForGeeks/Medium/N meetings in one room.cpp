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

Question : N meetings in one room
Topic : Scheduling, Greedy
Problems : https://practice.geeksforgeeks.org/problems/n-meetings-in-one-room-1587115620/1
/*
==============================> Explanation <=============================================
-  Function to find the maximum number of meetings that can
   be performed in a meeting room.

- sort the (start_time, end_time, ID) based on end of end_time and after that
  ID in aceseding order.

- Why ID ? -> Because when event end_time is same then ID is matter which
one is given first you consider that one. start_time is also same some time
so ID is better choise.


*/


/*
==============================> Edge Case <=============================================


*/


class Solution
{
    
    struct Meeting {
        public:
            int start;
            int end;
            int ID;
    };
    
    
    public:

        int maxMeetings(int start[], int end[], int n) {

            struct Meeting arr[n];

            for(int i = 0; i < n; i++) {
                arr[i].start = start[i]; arr[i].end = end[i]; arr[i].ID = i+1;
            }

            sort(arr, arr+n, [](Meeting m1, Meeting m2) {
                if(m1.end == m2.end) {
                    return m1.ID < m2.ID;
                }
                return m1.end < m2.end;
            });


            int result = 1;
            int end_time = arr[0].end; 

            int i = 1;
            while(i < n) {
                if(arr[i].start > end_time) {
                    result++;
                    end_time = arr[i].end;
                }
                i++;
            }

            return result;
        }
};