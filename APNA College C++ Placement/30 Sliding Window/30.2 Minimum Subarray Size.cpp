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
Question : 30.2 Minimum Subarray Size 

/*
==============================> Edge Case <=============================================

*/
 
/*
==============================> Explanation <=============================================

*/

// Apporach 1 : O(N^2)
// Using Two for loop try all subarray.


// O(N) - Sliding window
int smallestSubarrayWithSum(int arr[], int n, int x) {
    int sum = 0, minLength = n + 1, start = 0, end = 0;

    while(end < n) {

        while(sum <= x && end < n) {
            sum += arr[end++];
        }

        while(sum > x && start < n) {
            minLength = min(minLength, end - start);
            sum -= arr[start++];
        }
    }

    return minLength;
}

int main()
{
    int arr[] = {1, 4, 45, 6, 10, 19};
    int x = 51;
    int n = 6;

    cout << "min length " << smallestSubarrayWithSum(arr, n, x) << endl;

    return 0;
}
 

 
