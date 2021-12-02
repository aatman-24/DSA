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

Question: 278. First Bad Version
Topic : Binary Serach
Problems : https://leetcode.com/problems/first-bad-version/

==============================> Explanation <=============================================

- Binary Search, If mid is badNumber then we store into the ans and try to find [low, mid-1]
                 If not then try to find on right side [mid+1, high].


==============================> Apporach and Time Complexity <=============================================

1) Binary Serach
Time: O(LogN)
Space: O(1)

*/

// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
int firstBadVersion(int n) {

    long ans = -1;

    long low = 1, high = n;

    while(low <= high) {

        long mid = (low + high) >> 1;

        if(isBadVersion(mid)) {
            ans = mid;
            high = mid - 1;
        }
        else {
            low = mid + 1;
        }

    }


    return ans;
}
};