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
Question : 30.4 Subarray with Palindromic Concatenation

/*
==============================> Edge Case <=============================================

*/
 
/*
==============================> Explanation <=============================================


*/

// O(N^2 * K)
// - Approach 1 : Create k size subarray and check whethere one of them is palindrome. 


// O(N*K)
// - Apporach 2 : Sliding window (present here)


bool isPalindrome(int n) {

    int temp = n, num = 0;

    // reverse the number
    while(temp) {
        num = num * 10 + temp % 10;
        temp /= 10;
    }
    return num == n;
}


// return first index if found otherwise return -1.
int findPalindromicSubarray(vector<int> arr, int k) {

    int num = 0;

    // form k size number.
    for(int i = 0; i < k; i++)
        num = num * 10 + arr[i];

    if(isPalindrome(num)) 
        return 0;
    
    // non-shrinkable silding window
    for(int j = k; j < arr.size(); j++) {
        num = (num % (int)pow(10, k-1)) * 10 + arr[j];
        if(isPalindrome(num)) 
            return j - k + 1;
    }

    return -1;
}





int main() {

    vector<int> arr = {2, 3, 5, 1, 1, 5};
    int k = 4;
    cout << findPalindromicSubarray(arr, k) << endl;

    return 0;
}