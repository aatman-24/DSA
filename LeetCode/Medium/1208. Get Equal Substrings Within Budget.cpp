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

Question: 1208. Get Equal Substrings Within Budget
Topic : Sliding Window
Problems : https://leetcode.com/problems/get-equal-substrings-within-budget/

==============================> Explanation <=============================================
1) Sliding Window:

-Given that, find the substring...
Change the input of string s and t into an array of difference.
Then it's a standard sliding window problem.

If Given that, find the subsequence...
- Greedy Approach using minHeap.
 


==============================> Apporach and Time Complexity <=============================================
1) Sliding Window:
Time: O(N)
Space: O(N) 

*/



class Solution {
public:

    int equalSubstring(string s, string t, int maxCost) {

        vector<int> arr(s.size(), 0);

        for(int i = 0; i < s.size() ; i++) {
            arr[i] = abs(int(s[i] - t[i]));
        }

        int ans = 0, i = 0, j = 0;
        while(j < s.size()) {
            maxCost -= arr[j];
            while(maxCost < 0)
                maxCost += arr[i++];
            ans = max(ans, j - i + 1);
            j++;
        }

        return ans;
    }
};