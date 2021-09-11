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
Question : 30.3 Form Number Divisible by 3

/*
==============================> Edge Case <=============================================

*/
 
/*
==============================> Explanation <=============================================
A number is divisible by 3 if and only if sum of its digit is divisible by 3 In any group.

369 -> 3 + 6 + 9 = 18 % 3 = 0
369 -> 36 + 9 = 45 % 3 = 0
369 -> 3 + 69 = 72 % 3 = 0

*/


// Non-shrinkable sliding window 
void computeNumberFromSubarray(vector<int> arr, int k) {

    pair<int,int> ans;
    int sum = 0;

    // create a window of size k
    for(int i = 0; i < k; i++) sum += arr[i];
    bool found = (sum % 3 == 0);
    if(found) ans = make_pair(0, k-1);

    for(int i = k; i < arr.size() && !found; i++) {
        sum = sum + arr[i] - arr[i-k];
        found = (sum % 3 == 0);
        if(found) ans = make_pair(i-k+1, i);
    } 

    if(found) {
        cout << "Number is : ";
        for(int i = ans.first; i <= ans.second ; i++) {
            cout << arr[i];
        }
        cout << endl;
    }
    else {
        cout << "NOT FOUND" << endl;
    }


}


int main() {

    vector<int> arr = {84, 23, 45, 12, 56, 82};
    int k = 3;


    computeNumberFromSubarray(arr, k);

    return 0;
}