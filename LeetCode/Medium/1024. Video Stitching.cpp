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

Question:  1024. Video Stitching
Topic :Top-Down  Pattern= Interval DP
Problems : https://leetcode.com/problems/video-stitching/

==============================> Explanation <=============================================
- Dp variant = Interval Variant, 

- We find best clip which can we extend for the current T.

If clip[0] <= T and T <= clip[1] then we can use the clip. but we find the best clip which we could extend
and also has minimum  number of clip used.

dp[i] -> Indicate the number of minimum clip required to make the upto ith time.

1) Choise Diagram: -> Choose the clip which can be extensible and have minimum clip.

2) Base Case: T == 0 -> No clip required.
              
3) Recurrance Relation:
    
        dp[i] = min(dp[i], dp[clip[0]] + 1);


==============================> Apporach and Time Complexity <=============================================

1) Top-Down Bottom-UP Pattern= Interval DP
Time: O(N^2)
Space: O(N)

*/

class Solution {
public:
    
    int t[102];

    int videoStitching(int T, vector<vector<int>> &clips) {
        
        // For T == 0, No clip is required.
        if(T == 0)
            return 0;

        if(t[T] != -1)
            return t[T];
        

        t[T] = 101;         // 101 is not problem to take here.
        

        // find the best clip which cover current T and have minimum number of clip used.
        for(auto it: clips) {

            if(it[0] <= T && T <= it[1]) {


                t[T] = min(t[T], videoStitching(it[0], clips) + 1);
            }
        }

        return t[T];

    }

    int videoStitching(vector<vector<int>>& clips, int time) {

        sort(clips.begin(), clips.end());

        memset(t, -1, sizeof(t));
        
        int ans = videoStitching(time, clips);
        
        return  ans == 101 ? -1 : ans;
    }
};


class Solution {
public:
    
    int videoStitching(vector<vector<int>>& clips, int time) {

        int N = clips.size();

        sort(clips.begin(), clips.end());

        vector<int> dp(time+1, 101);

        // base case.
        dp[0] = 0;
        
        for(int T = 1; T <= time; T++) {
            for(auto it: clips) {
                if(it[0] <= T && T <= it[1]) {
                    dp[T] = min(dp[T], dp[it[0]] + 1);
                }
            }
        }
       
        return dp[time] == 101 ? -1 : dp[time];
    }
};