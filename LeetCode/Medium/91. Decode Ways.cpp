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

Question: 91. Decode Ways
Topic : Top-Down Bottom-up Pattern=Fibonacci Linear DP
Problems : https://leetcode.com/problems/decode-ways/


==============================> Explanation <=============================================
Not got idea directly but,

Here, dp[i] -> represent the number of way to decode the string upto [0, i-1] string.

1) Choise Diagram(0 based index):

if(s[i-1] is valid) -> then we can directly add s[i-1] to all the string which is already formed
                       upto s[i-2].

if(s[i-2] + s[i-1] is valid) -> then we directly add the (s[i-1]+s[i-2]) string which is already
                            formed upto the s[i-3].

2) Base Case:
dp[0] = 0. Number of way decode the empty string is 1. (picking from empty bucket is 1)
dp[1] = s[i-1] == '0' we directly return 0. else dp[1] = 1. (valid char)

3) Recurrance Relation: 

if(s[i-1] is valid)
    dp[i] = dp[i-1];        (add s[i-1] to all dp[i-1] string directly)

if(s[i-2]+s[i-1] is valid)
    dp[i] += dp[i-2]        (add s[i-2]+s[i-1] to all dp[i-2] string)

if(s[i-1] == 0)
    dp[i] = 0;

==============================> Apporach and Time Complexity <=============================================

0) Brute Force take O(2^N).. Using Recursion...

1) Top-Down Bottom-up Pattern=Fibonacci Linear DP
Time: O(N)
Space: O(N)

*/



class Solution {
public:
    
    int t[101];

    int numDecodings(int i, string s) {
        
        // Empty String can be decoded one way. 
        // Same as pick the item from the empty bucket which answer is 1. Not pick is also one way.
        if(i == 0)
            return 1;

        // s[0] must be in {'1','9'} in range, we already check if string start with 0 we return 0. 
        if(i == 1) {
            return 1;
        }

        if(t[i] != -1)
            return t[i];

        // here if s[i-1]='0' is already coverd here.
        int numWay = 0;

        // Expand from the (i-2)index by appending (i-1)th char into all string.
        if(s[i-1] >= '1' && s[i-1] <= '9')
            numWay = numDecodings(i-1, s);

        // Expand from the (i-3)index by appending (i-2)+(i-1)th string as single char for all string.
        if(i-2 >=0 && (s[i-2]=='1'|| s[i-2]=='2'&& s[i-1]<'7'))
            numWay += numDecodings(i-2, s);

        return t[i] = numWay;
    }
    
    int numDecodings(string s)  {
            
        if(s[0] == '0')
            return 0;
        
        int n = s.size();
        memset(t, -1, sizeof(t));
   
        return numDecodings(n, s);
    }
};





class Solution {
public:
    
       int numDecodings(string s)  {
            
        if(s[0] == '0')
            return 0;
        
        int n = s.size();
        int dp[n+1];
        memset(dp, 0, sizeof(dp));
        
        dp[0] = 1;       // no picking is one way.
        dp[1] = 1;      // s[0] should be valid. not valid case coverd first.

        for(int i = 2; i <= n; i++) {

            // Expand from the (i-2)index by appending (i-1)th char into all string.
            if(s[i-1] >= '1' && s[i-1] <= '9')
                dp[i] += dp[i-1];    

            // Expand from the (i-3)index by appending (i-2)+(i-1)th string as single char for all string.
            if(i-2 >=0 && (s[i-2]=='1'|| s[i-2]=='2'&& s[i-1]<'7'))
                dp[i] += dp[i-2];
        }
   
        return dp[n];
    }
};
