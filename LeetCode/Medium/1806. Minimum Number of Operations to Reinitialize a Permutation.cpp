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

Question : 1314. Matrix Block Sum
Topic : DP, Kadane
Problems : https://leetcode.com/problems/matrix-block-sum/
*/

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

Question : 1806. Minimum Number of Operations to Reinitialize a Permutation
Topic : Array, Permutation, Tracking
Problems : https://leetcode.com/problems/minimum-number-of-operations-to-reinitialize-a-permutation/
*/


class Solution {
public:
    
    bool checkOrder(vi arr) {
        REP(i, arr.size()) {
            if(i != arr[i]) return false;
        }
        return true;
    } 

    // O(N^2) - O(N).
    int reinitializePermutation(int n) {

        vi arr(n,0);
        REP(i,n) arr[i] = i;
        int cnt = 0;
        int start_flag = 0;
        while(start_flag == 0 || !checkOrder(arr)) {
            vi tmp(n,0);
            for(int i = 0; i < n; i++) {
                if(i % 2 == 0) tmp[i] = arr[i/2];
                else tmp[i] = arr[n/2 + (i-1)/2];
            }
            arr = tmp;
            cnt++;
            start_flag = 1;
        }
        return cnt;

    }

    // O(N) - O(1).
    int reinitializePermutation(int n) {

        int track_1_index = 1, cnt = 0;
        while(cnt == 0 || track_1_index > 1) {
            track_1_index = (track_1_index * 2) % (n-1);
            cnt++;
        }
        return cnt;

    }

    // O(N) - O(1).
    int reinitializePermutation(int n) {
        int track_1_index = 1, cnt = 0;
        while(cnt == 0 || track_1_index > 1) {
            if(track_1_index < n/2) {
                track_1_index *= 2;
            }
            else {
                track_1_index = (track_1_index - (n/2)) * 2 + 1;
            }
            cnt++;
        }
        return cnt;
    }

};