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

Question: 849. Maximize Distance to Closest Person
Topic : Two Pointer.
Problems : https://leetcode.com/problems/maximize-distance-to-closest-person/

==============================> Explanation <=============================================

- Solved by using extra space, O(N) Similar to Raining Trapping Water.


Found out that: 

So the problem is to find the maximum distance between two continuous 1 in an array, 
and just return half of that maximum value...(also before the first 1 and after the last 1 will be two special cases)

==============================> Apporach and Time Complexity <=============================================

1) Trapping Rain Water:
Time: O(N)
Space: O(N) 


1) Two Pointer
Time: O(N)
Space: O(1)

*/





class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
       
        int N = seats.size();

        vector<int> left(N, 0), right(N, 0);
        
        if(seats[0] != 1)
            left[0] = 100000;
        
        if(seats[N-1] != 1)
            right[N-1] = 100000;

        for(int i = 1; i < N; i++) {
            if(seats[i] != 1) {
                left[i] = left[i-1] + 1;
            }
        }

        for(int i = N - 2; i >= 0; i--) {
            if(seats[i] != 1) {
                right[i] = right[i+1] + 1;
            }
        }

        int ans = 0;
        for(int i = 0; i < N; i++) {
            if(seats[i] != 1) {
                ans = max(ans, min(left[i], right[i]));
            }
                
        }

        return ans;
    }
};




class Solution {
public:

    int maxDistToClosest(vector<int>& seats) {
        
        // Left keep track of previous 1 position.
        int left = -1, maxDist = 0;
        int N = seats.size();

        for(int i = 0; i < seats.size(); i++) {

            if(seats[i] == 0)
                continue;

            if(left == -1) {
                maxDist = max(maxDist, i);
            }
            else {
                maxDist = max(maxDist,  (i - left)/2);
            }
            
            
            // update the last position of 1 to the current index.
            left = i;
        }


        // Special Case... [1, 0, 0, 0, 0]
        if(seats[N-1] == 0) {
            maxDist = max(maxDist, N - 1 - left);
        }
        
        
        return maxDist;
    }
};