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

Question : 279. Perfect Squares
Topic : DP, Number
Problems : https://leetcode.com/problems/longest-palindromic-substring/
*/

class Solution {
public:

        int dp[10001][102];

        int leastNumber(vi arr, int n) {
            int m = arr.size();

            memset(dp, 0, sizeof(dp));

            // for(int j = 0; j <= n; j++) dp[0][j] = INT_MAX-1;
            for(int j = 1; j <= n; j++) dp[1][j] = j;
            for(int i = 0; i <= m; i++) dp[i][0] = 0;

            for(int i = 2; i <= m; i++) {
                for(int j = 1;  j <= n; j++) {

                    if(arr[i-1] <= j) {
                        dp[i][j] = min(1 + dp[i][j-arr[i-1]], dp[i-1][j]);
                    }
                    else {
                        dp[i][j] = dp[i-1][j];
                    }
                }
            }
            return dp[m][n];

        }

        // O(N*M) - O(N*M)
        // That is not ideal soultion. Worst Solution To use Stdarad DP Format Here(Coin Change)
        // I thought that is Coin Change variants yes it is worked. But Take more time.
        int numSquares(int n) {
            vi arr;
            for(int i = 1; i <= sqrt(n); i++) {
                arr.push_back(i*i);
            }

            return leastNumber(arr, n);    
        }


        // HERE is good idea to use result as static so we don't need to 
        // compute it every time/.
        // O(N * SQRT(N)) - O(MAX_N)
        int numSquares(int n) {
            static vector<int> result;
            if(result.size() == 0) {
                result.push_back(0);
            }
            while(result.size() <= n) {
                int m = result.size();
                int tmpMin = INT_MAX;
                for(int i = 1; i * i <= m; i++) {
                    tmpMin = min(tmpMin, result[m - i*i]+1);
                }
                result.push_back(tmpMin);
            }
            return result[n];
        }
};
