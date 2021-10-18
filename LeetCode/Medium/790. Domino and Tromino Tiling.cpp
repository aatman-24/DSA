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

Question: 790. Domino and Tromino Tiling
Topic : Bottom-UP Linear-DP Pattern=Puzzle
Problems : https://leetcode.com/problems/domino-and-tromino-tiling/

==============================> Explanation <=============================================
https://leetcode.com/problems/domino-and-tromino-tiling/discuss/116581/Detail-and-explanation-of-O(n)-solution-why-dpn2*dn-1%2Bdpn-3

In short,

dp[n] = dp[n-1] * {1 (|)} + dp[n-2] * {1 (=)} + (dp[n-3] ... dp[0]) * {2 Ways} check on above.

1) Choise Diagram: Check the Link.

2) Base Case: dp[0] = 1, dp[1] = 1, dp[2] = 2, dp[3] = 5

3) Recurrence Relation: 2*dp[n-1]+dp[n-3]
                    
dp[n]=dp[n-1]+dp[n-2]+ 2*(dp[n-3]+...+d[0])
    =dp[n-1]+dp[n-2]+dp[n-3]+dp[n-3]+2*(dp[n-4]+...+d[0])

dp[n-1] = dp[n-2] + dp[n-3] + 2 * (dp[n-4]...dp[0]) (putting n into the first equation)

    =dp[n-1]+dp[n-3]+(dp[n-2]+dp[n-3]+2*(dp[n-4]+...+d[0])) 
    =dp[n-1]+dp[n-3]+dp[n-1]
    =2*dp[n-1]+dp[n-3]

Space optimization is possible needs only last four 4 states. 

==============================> Apporach and Time Complexity <=============================================

1) Bottom-UP Linear-DP Pattern=Puzzle
Time: O(N)
Space: O(N)

*/


// Top-Down
class Solution {
public:

    int numTilings(int N) {
        int md=1e9;
        md+=7;

        vector<long long> dp(1001,0);
        dp[1]=1;
        dp[2]=2;
        dp[3]=5;
        
        if(N<=3)
            return dp[N];
        
        for(int i=4;i<=N;++i){
            dp[i]=2*dp[i-1]+dp[i-3]; 
            dp[i]%=md;
        }
        return dp[N];
        
    } 

};
