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

Question: 948. Bag of Tokens
Topic : Sorting, Greedy
Problems : https://leetcode.com/problems/bag-of-tokens/

==============================> Explanation <=============================================

- Buy Cheapest and sell at most expensive.

==============================> Apporach and Time Complexity <=============================================
2) Sorting + Two Pointer:
Time: O(NlogN)
Space: O(1)

*/

class Solution {
public:
    
int bagOfTokensScore(vector<int>& tokens, int power) {

    sort(tokens.begin(), tokens.end());
    int i = 0, score = 0, j = tokens.size() - 1, ans = 0;
    while(i <= j) {
        if(power >= tokens[i]) {
            power -= tokens[i++];
            score++;
            ans = max(ans, score);
        }
        else if(score > 0) {
            power += tokens[j--];
            score--;
        }
        else {
            break;
        }
    }
    return ans;
}
};