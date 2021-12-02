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

Question: 1220. Count Vowels Permutation
Topic : Top-Down Bottom-up Pattern=MultidimesionalDP
Problems : https://leetcode.com/problems/count-vowels-permutation/

==============================> Explanation <=============================================

- Dp variant = UnboundedKnapsack.

Total N = 20000 Layers, M = 27 character [a-z].


1) Choise Diagram: We just try out all the possible ways with dp. We just follow the characters 
                   which is given and add that ways into answer.

2) Base Case:  N = 1, All {a,e,i,o,u} characters are 1 length so return 5.
                
3) Recurrance Relation:
            
        - Add all the followed characters of the current string with  ans += (n-1, alternative)
        
        - ch is current characters.

        for(auto adj: mp[ch]) {
            ways += helper(adj, n-1) % mod;
        }


- Space optimization is possible... 

==============================> Apporach and Time Complexity <=============================================

1) Top-Down Bottom-up Pattern=MultidimesionalDP
Time: O(N^2)
Space: O(N*M)


*/


#define mod 1000000007

class Solution {
    
    public:
    map<char,vector<char>> mp;

    void initialize_mapping() {
        mp['a'] = {'e'};
        mp['e'] = {'a', 'i'};
        mp['i'] = {'a','e','o','u'};
        mp['o'] = {'i','u'};
        mp['u'] = {'a'};
    }


    vector<vector<long>> t;

    long helper(char ch, int n) {
        
        if(n == 1)
            return 1;

        if(t[n][ch-'a'] != -1)
            return t[n][ch-'a'];

        long ways = 0;
        for(auto adj: mp[ch]) {
            ways += helper(adj, n-1) % mod;
        }

        return t[n][ch-'a'] = ways % mod;
    }

    int countVowelPermutation(int n) {

        initialize_mapping();
        t.assign(30000, vector<long>(27, -1));

        long ans = 0;
        for(auto ch: mp) {
            ans += helper(ch.first, n) % mod;
        }

        return ans % mod;
    }
};



#define mod 1000000007

class Solution {
    
    public:
    map<char,vector<char>> mp;

    void initialize_mapping() {
        mp['a'] = {'e'};
        mp['e'] = {'a', 'i'};
        mp['i'] = {'a','e','o','u'};
        mp['o'] = {'i','u'};
        mp['u'] = {'a'};
    }

    int countVowelPermutation(int n) {
        
        // base case.
        if(n == 1)
            return 5;

        initialize_mapping();

        long dp[n+1][28];
        memset(dp, 0, sizeof(dp));

        // base case
        dp[1]['a'-'a'] = dp[1]['e'-'a'] = dp[1]['i'-'a'] = dp[1]['o'-'a'] = dp[1]['u'-'a'] = 1;

        long ans = 0;
            
        for(int i = 2; i <= n; i++) {
        
            for(auto ch: mp) {
                
                char x = ch.first;
                
                for(auto adj: mp[x]) {

                    dp[i][x-'a'] += dp[i-1][adj-'a'] % mod;
                }

                if(i == n)
                    ans += dp[i][x-'a'] % mod;
            }
        }

        return ans % mod;
    }
};