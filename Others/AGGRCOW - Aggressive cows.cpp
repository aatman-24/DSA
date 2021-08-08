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
d
/*
==============================> Description <=============================================

Question :  AGGRCOW - Aggressive cows
Topic : Binary Search
Problems : https://www.spoj.com/problems/AGGRCOW/

==============================> Explanation <=============================================
Why Binary Search ?


-> Placing the Cow at start from the minimum distance to the maximum distance
it is monotonic increasing function.

At dist = 1 -> We can put the M Way the cow.


dist = 10 -> If we can put the N way the cow then M > N. 


So using greedy and Binary Search we need to find the  maximum of minimum distance is between to
any two cow when we place.
*/


/*
==============================> Edge Case <=============================================

*/



// Greedily Check Whather It is possible to place the all The Cow
// of using dist.
bool canPlace(vi &arr, int dist, int C) {

    int coordinate = arr[0], placed = 1;

    for(int i = 0; i < arr.size(); i++) {

        if(arr[i] - coordinate >= dist) {
            placed++;
            coordinate = arr[i];
        }

        if(placed == C) return true;
    }

    return false;
}


int minimumDistance(vi &arr, int C) {

    sort(arr.begin(), arr.end());
    int N = arr.size();
    
    // Minimum distance can be 1 between Cows.
    // And maximum is arr[N-1]-arr[0] when only two cows is there.
    int low = 1, high = arr[N-1] - arr[0], res = 0;


    while(low <= high) {

        int mid = (low + high) >> 1;


        // If distance between mid is possible we try to find maximum of it
        // so move low = mid + 1. and answer is mid.
        if(canPlace(arr, mid, C)) {
            res = mid;
            low = mid + 1;
        }
        // Otherwise decrease the distance.
        else {
            high = mid - 1;
        }

    }

    return res;
}


int main() {

    int t; cin >> t;
    while(t--) {

        int N, C;
        cin >> N >> C;
        vector<int> arr(N, 0);
        REP(i, N) cin >> arr[i];

        cout << minimumDistance(arr, C) << endl;

    }

    return 0;

}