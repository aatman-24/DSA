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

Question : 1701. Average Waiting Time
Topic : 2D-Array
Problems : https://leetcode.com/problems/average-waiting-time/
*/



class Solution {
public:
    // O(N) - O(1).
     double averageWaitingTime(vector<vector<int>>& customers) {
        ll wait_time = 0;
        ll cur_time = 0;
        ll n = customers.size();
        for(int i = 0; i < n; i++) {
            cur_time =  max(cur_time, 1LL*customers[i][0]) + customers[i][1];
            wait_time += (cur_time - customers[i][0]);
        }
        double ans = (wait_time * 1.0) / n;
        return ans;
}
};