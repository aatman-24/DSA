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

Question : 1817. Finding the Users Active Minutes
Topic : Hashing, Array
Problems : https://leetcode.com/problems/finding-the-users-active-minutes/
*/
class Solution {
public:

    // O(N*LOGN)
    vector<int> findingUsersActiveMinutes(vector<vector<int>>& logs, int k)     {

        int n = logs.size();
        vi ans(k,0);

        sort(logs.begin(),logs.end());


        int i = 0, ID, cnt;
        while(i < n) {
            ID = logs[i][0];
            int start = i;
            cnt = 0;
            while(i < n && ID == logs[i][0]) {
                if(i == start) cnt++;
                if(i > start && logs[i-1][1] != logs[i][1]){
                    cnt++;
                }
                i++;
            }
            ans[cnt-1] += 1;
        }

        return ans;
    }

};