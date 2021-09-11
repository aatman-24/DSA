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
Question : 30.5 Perfect Numbers in Subarrays

/*
==============================> Edge Case <=============================================

*/
 
/*
==============================> Explanation <=============================================
Algorithm (sliding window maxSum of k size window)
- convert array into 0 and 1 
        if perfect number = 1
        else = 0
- maxSum sliding window of size k as usual. 


Perfect Number: Perfect number is number whose divisor sum is equal to 
that number. ex... 6 is perfect number. divisior = 1 + 2 + 3 = 6.

*/

// O(N^2*K*sqrt(N)) N^2 = generate subarray + K*sqrt(N) for checking k number is it perfect or not.
// Apporach 1 : Generate all subarrays of size k && count number of pefect numbers

// Apporach 2: O(N*sqrt(N)) 
// - first fill up the array with 0 and 1. O(N*sqrt(N)) (checking perfect or not)
// - sliding window techinque O(N)


int isNumberPerfect(int n) {

    if(n == 1) return 0;

    int sum = 1;
    for(int i = 2; i < sqrt(n); i++) {

        if(n % i == 0) {
            if(i == n / i) sum += i;
            else sum += i + n/i;
        }

    }
    return sum == n;

}

int maxSum(int arr[], int n, int k)  {
    if(n < k) {
        cout << "Invalid Values" << endl;
        return -1;
    }

    int res = 0;
    for(int i = 0; i < k; i++)
        res += arr[i];

    int sum = res;
    for(int i = k; i < n; i++) {
        sum += arr[i] - arr[i-k];
        res = max(res, sum); 
    }

    return res;
}

int maxNumberOfPerfects(int arr[], int n, int k) {
    for(int i = 0; i < n; i++)
        arr[i] = isNumberPerfect(arr[i]);

    return maxSum(arr, n, k);
}

int main() {

   int arr[] = {28, 2, 3, 6, 496, 99, 8128, 24};
    int k = 4;
    int n = sizeof(arr)/ sizeof(int);


    cout << maxNumberOfPerfects(arr, n, k) << endl;

    return 0;
}