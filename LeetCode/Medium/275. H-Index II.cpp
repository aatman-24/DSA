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
d
/*
==============================> Description <=============================================

Question : 275. H-Index II
Topic : Binary Search
Problems : https://leetcode.com/problems/h-index-ii/

==============================> Explanation <=============================================

- Here We need to find h index such that, atleast h element have score greater than h
and remaining needs to have less than or equal to h.



*/


/*
==============================> Edge Case <=============================================


*/

class Solution {
public:

    // 1) Brute Force = O(N) Find from the behind once the condition met this is the index. which
    // can be solution.

    int hIndex(vector<int>& citations) {

        int count = 0, index = citations.size() - 1;

        while(index >= 0 && (count+1) <= citations[index]) {
                count++; index--;
        }
        return count;
    }

    // 2) Binary Search:


    int hIndex(vector<int>& citations) {

        int l = 0, h = citations.size() - 1;
        int len = citations.size();

        while(l <= h) {

            int mid = (l + h) >> 1;

            // search on left side.
            if (citations[mid] >= len-mid) h = mid - 1;
            else l = mid + 1;
        }

        return len - l;
        
    }

};