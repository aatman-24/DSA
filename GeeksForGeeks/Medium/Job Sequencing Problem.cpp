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

Question : Job Sequencing Problem
Topic : Scheduling, Greedy
Problems : https://practice.geeksforgeeks.org/problems/job-sequencing-problem-1587115620/1#
/*
==============================> Explanation <=============================================
- Sort the Algorithm in Maximum Profit. If profit is same then maximum deadline.
As learned in to college we first allcoate the last deadline time to the job
so that other can also maintain his jobs.

Time = O(N*logN) + O(N*K) K = is maximum deadline.
Space = O(1) = we used mark[] array but it is okay it size is only 100.


*/


/*
==============================> Edge Case <=============================================


*/

struct Job 
{ 
    int id;  // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
};

class Solution 
{
    public:
    //Function to find the maximum profit and the number of jobs done.
    
        vector<int> JobScheduling(Job arr[], int n) { 
    
        // used 101 because 100 is given. But in general this should be
            // maximum deadline among all the jobs.
        int mark[101] = {0};
    
        sort(arr, arr+n, [](Job a, Job b) {
            if(a.profit == b.profit) return a.dead > b.dead;
            return a.profit > b.profit;
        });
    
    
        int profit = 0;
        int count = 0;
    
        for(int i = 0; i < n; i++) {
            for(int j = arr[i].dead; j > 0; j--) {
                if(mark[j] == 0) {
                    mark[j] = 1;
                    profit += arr[i].profit;
                    count += 1;
                    break;
                }
            }
        }
    
        vector<int> ans = {count, profit};
        
        return ans;       
    }

};