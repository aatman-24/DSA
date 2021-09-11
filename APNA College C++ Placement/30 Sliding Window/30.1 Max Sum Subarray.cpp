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
Question : 30.1 Max Sum Subarray

/*
==============================> Edge Case <=============================================

*/
 
/*
==============================> Explanation <=============================================

*/

void maxSubarraySum(int arr[], int n, int k, int x) {

    int sum=0, ans=0;
    for(int i = 0; i < k; i++) 
        sum += arr[i];

    if(sum < x) ans = sum;  

    for(int i = k; i < n; i++) {

        sum -= arr[i-k];
        sum += arr[i];

        if(sum < x) {
            ans = max(ans, sum);
        }
    }

    cout << "Max sum can possible is: "  << ans << endl;

}


int main()
{
    int arr[] = {7, 5, 4, 6, 8, 9};
    int k = 3;
    int x = 20;
    int n = 6;

    maxSubarraySum(arr, n, k, x);

    return 0;
}
 

 
