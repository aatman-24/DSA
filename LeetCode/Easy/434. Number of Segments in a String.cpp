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

Question : 434. Number of Segments in a String
Topic : String, String
Problems : https://leetcode.com/problems/number-of-segments-in-a-string/
==============================> Explanation <=============================================

- Avoid starting space.
- Consider contiguous space as single space.

==============================> Apporach and Time Complexity <=============================================

1) String
Time: O(N)
Space: O(1)

*/


class Solution {
public:
    int countSegments(string s) {
        
        int i = 0, count = 0, N = s.size();

        while(i < N && s[i] == ' ') i++;

        while(i < N) {
            
            while(i < N && s[i] != ' ') i++;
            count++;
            
            while(i < N && s[i] == ' ') i++;
        }
        
        return count;
    }
};


