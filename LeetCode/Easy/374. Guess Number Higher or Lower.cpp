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

Question: 374. Guess Number Higher or Lower
Topic : Binary Search
Problems : https://leetcode.com/problems/guess-number-higher-or-lower/

==============================> Explanation <=============================================

- Binary Search... 

==============================> Apporach and Time Complexity <=============================================

1) Binary Search
Time: O(logN)
Space: O(logN)

*/

/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is lower than the guess number
 *			      1 if num is higher than the guess number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution {
public:

int guessNumber(int n) {

    long low = 1, high = n;

    while(low <= high)  {

        int mid = (low + high) >> 1;


        if(guess(mid) == 0) {
            return mid;
        }

        if(guess(mid) < 0) {
            high = mid - 1;
        }
        else {
            low = mid + 1;
        }

    }

    return -1;
}
};