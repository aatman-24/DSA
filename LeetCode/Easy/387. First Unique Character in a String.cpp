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

Question : 387. First Unique Character in a String
Topic : String
Problems : https://leetcode.com/problems/first-unique-character-in-a-string/

==============================> Explanation <=============================================

- Fill the map entry when first time string is traversed.
- And when second time traverse check, mp[s[i]] == 1 or not. if yes then return it.

==============================> Apporach and Time Complexity <=============================================

1) String
Time: O(N)
Space: O(1)

*/

class Solution {
public:
    int firstUniqChar(string s) {
        
        int arr[26] = {0};
        
        for(auto ch: s) {
            arr[ch-'a']++;
        }

        for(int i = 0; i < s.size(); i++) {
            if(arr[s[i]-'a'] == 1)
                return i;
        }

        return -1;
    }
};