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

Question : 1647. Minimum Deletions to Make Character Frequencies Unique
Topic : Greedy
Problems : https://leetcode.com/problems/minimum-deletions-to-make-character-frequencies-unique/
/*
==============================> Explanation <=============================================
- Greedy

- Who has most freq we don't change it. After that we take care that no character has freq same or greater than 
previous.

- count frequency
- sort
- take care that, arr[i] < arr[i-1]
*/


/*
==============================> Edge Case <=============================================


*/

class Solution {
public:

    int minDeletions(string s) {

        // store the occurace of the characters.
        int arr[26] = {0};

        // count occurance.
        for(char ch : s) arr[ch - 'a']++;

        // sort the array. (3, 3, 2)
        sort(arr, arr+26, greater<int>());

        int cost = 0;

        for(int i = 1; i <= 26; i++) {

            // arr[i] is always less than arr[i-1]. So until not we add cost.
            while(arr[i] > 0 && arr[i-1] = arr[i]) {
                arr[i]--; cost++;
            }
        }

        return cost;
    }



    // O(N) - O(1)
    int minDeletions(string s) {

        // store the occurace of the characters.
        int arr[26] = {0};

        // count occurance.
        for(char ch : s) arr[ch - 'a']++;

        // sort the array. (3, 3, 2)
        sort(arr, arr+26, greater<int>());

        int cost = 0;

        for(int i = 1; i < 26; i++) {
            if(arr[i] > 0 && arr[i-1] <= arr[i]) {
                int prev = arr[i];
                arr[i] = max(arr[i-1] - 1, 0);  // we replace the arr[i] just less that arr[i-1] but not negative.
                cost += (prev - arr[i]);        // add cost.
            }
        }

        return cost;

    }

};