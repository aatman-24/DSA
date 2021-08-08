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

Question : Minimum Platforms
Topic : Scheduling, Greedy
Problems : https://practice.geeksforgeeks.org/problems/minimum-platforms-1587115620/1#

/*
==============================> Explanation <=============================================
- Needs to find the minimum number of platform required.

- We sort the arrival time and deparature time array separately. Yes, train[i]
arrival time and departure time combination is not important here. Because
arrival[i] denote the one train arrive at this time. Now check for the
empty platform if it is assign to the train otherwise add one more.
- Same with departure time.


- So Here we count how many train are currently at platform or how many
occupied. After sorting, 

    arr[i] <= dep[j] -> means we need one more platform.
    arr[i] > dep[j] -> means need to relaese one platform.

    Keep track of maximum platform. Two Pointer Apporach.


How it is different with standard problem ?

- There we count the max activity which can be complete. Here If we
compare the acitivity with train then we don't need to count how many
train take the place because all the train take the place but need to 
count how many of them maximum take place together so it is differnt.

*/


/*
==============================> Edge Case <=============================================


*/


// Time:  O(2N) + O(2N*logN) = O(NlogN)
// Space: O(1)
int findPlatform(int arr[], int dep[], int n) {

    sort(arr, arr+n);
    sort(dep, dep+n);

    // first train occupied the platform.
    int result = 1;

    // platform needed for given instance of time.
    int plat_needed = 1;            // for the first train


    int i = 1;                      // i -> arrival time train pointer
    int j = 0;                     // j -> deparature time train pointer


    while(i < n && j < n) {

        // platform_required
        if(arr[i] <= dep[j]) {
            plat_needed++; i++;
        }
        else if(arr[i] > dep[j]) {
            plat_needed--; j++;     // platform_released
        }

        result = max(result, plat_needed);
    }

    return result;
}
