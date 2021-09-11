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
Question : 32.5 Number of Subarrays with Sum Zero

/*
==============================> Explanation <=============================================
- Logic is that we used prefix sum + map. Suppose at 
ith index prefix sum = x
jth index prefix sum = x
that means (i+1, j) subarray total sum = 0. So we used this logic.

we count prefix sum occurace.
map[prefix_sum] > 1 then we choose any two index(i,j) which make subarray sum = 0.

so total number of way = n * (n-1) / 2. (n = num of occurace of prefix sum) 

Edge case is that... from the [start of array, current] sum is 0. so we additionaly add
this type of subarray.

*/

/*
==============================> Edge Case <=============================================

*/
 

// count total number of subarray whose sum is 0.
int countNumberofSubarray(vector<int> arr) {

    // count the frequency of prefix sum
    map<int, int> mp;
    int sum = 0;
    for(int n : arr) {
        sum += n;
        mp[sum]++;
    }


    int cnt = 0;
    for(auto ii : mp) {

        // if ii.first == 0 then direct add into count.
        if(ii.first == 0) {
            cnt += ii.second;
        }

        // otherwise choose any two prefix sum is which is equal. number of way is nC2.
        // so if ii.second = 1 then no addition automatic it become 0.
        int c = ii.second;
        cnt += (c * (c-1)) / 2;
    }

    return cnt;
}

int main() {

    vector<int> arr = {1, -1, 1, -1};
    cout << countNumberofSubarray(arr) << endl;

    return 0;
}