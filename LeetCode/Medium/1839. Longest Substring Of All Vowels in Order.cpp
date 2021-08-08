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

Question : 1839. Longest Substring Of All Vowels in Order
Topic : Two pointer
Problems : https://leetcode.com/problems/longest-substring-of-all-vowels-in-order/
*/


class Solution {
public:
    int longestBeautifulSubstring(string word) {
        int i=0, j=0, cnt=1;
        int ans=0;

        while(j < word.size()) {
            while(j < word.size() && word[j] <= word[j+1]) {
                if(word[j] < word[j+1]) cnt++;
                j++;
            }
            if(cnt == 5) {
                ans = max(ans, j - i + 1);
            }
            i = j + 1;
            j++;
            cnt = 1;
        }
        return ans;
    }
};
