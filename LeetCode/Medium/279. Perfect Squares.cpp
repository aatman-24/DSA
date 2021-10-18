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
==============================> Description <================================================

Question : 279. Perfect Squares
Topic : DP(Pattern=Linear, Pattern=2D)
Problems : https://leetcode.com/problems/perfect-squares/

==============================> Explanation <=================================================

1) 2D Dyanmic Programming (Coin Change Variant):

- Idea is that, first make the array with all the square number between (0 -> N). Now use the 
coin change variant, either take the square number from the array or don't take.

changes -> array of square numbers.
target -> N.

=>> Choice Diagram -> N -> coin[i-1] < target -> Then we take it or don't take it.
                           else : we don't take it.

==> Base Case -> For N = 0, dp[i][0] = 0, (When target is 0 no need any coin)
              -> dp[1][j] = j (Because using 1 change coin we need total jth coin).

==> Recurrance Relation: 
                        coin[i-1] <= j -> (dp[i][j-coin[i-1]] + 1, dp[i-1][j])
                        else: dp[i-1][j].


2) 1D Linear:

- If we define the problem state, then we need only one state only. How many way to sum up perfect numbers
when N is 100, 700, 300... (etc).

- We don't need the second state(which perfect number) from above solution which is wrong.

That is 1D Linear Problem not 2D....

If we find for N = 13, Using N = 4(pefect), N = 13 - 4, N = 9.
If we know the minimum perfect number for N = 9, then we directly use it, min(N = 9) + 1.


=>> Choice Diagram -> For all the perfect square numbers(PN) from (1 -> N):
                            minimum = min(minimum, solve(N - (PN)) + 1)

==> Base Case -> For N = 0, return 0.
              -> For N < 0, return INT_MAX.

==> Recurrance Relation: 
                if(i * i <= N)
                    min_way = min(min_way, solve(N - (i*i))), i = 1 -> N



==============================> Apporach and Time Complexity <=================================

1) Top-Down + Bottom-UP pattern=2D:
Time: O(N*M) -> m = N^2.
Space: O(N*M)(Memorization)

2) Top-Down + Bottom-UP pattern=Linear:
Time: O(N^2)
Space: O(N)(Memorization)


*/


// 1) Coin-Change Variant.
class Solution {
public:

    // for 10^4 there are total maximum upto 10^2 numbers.
    int dp[102][10002];

    int leastNumber(vector<int> arr, int n) {

        int m = arr.size();

        memset(dp, 0, sizeof(dp));

        // Using 1 as perfect number for every (1 -> N) needs jth coin of 1. 
        for(int j = 1; j <= n; j++) dp[1][j] = j;

        // For N = 0, No need any coin.
        for(int i = 0; i <= m; i++) dp[i][0] = 0;

        // For jth loop run on the Target.
         for(int j = 1; j <= n; j++){

            // ith loop run on the perfectNumbers. (on change of coin)
            for(int i = 2; i <= m; i++) { 

                // if perfect number is less than j(Target).
                if(arr[i-1] <= j) {

                    // Either check on [same_row][j-arr[i-1](perfect_number)] + 1(if we took arr[i-1]) 
                    // else we don't take the current coin.
                    dp[i][j] = min(1 + dp[i][j-arr[i-1]], dp[i-1][j]);
                }
                else {
                    dp[i][j] = dp[i-1][j];
                }
            }
        }

        // return [last_perfect_number][n].
        return dp[m][n];

    }

    // O(N*M) - O(N*M)
    // That is not ideal soultion. Worst Solution To use Stdarad DP Format Here(Coin Change)
    // I thought that It is Coin Change variants yes it is worked. But Take more time.
    int numSquares(int n) {

        vector<int> arr;
        
        for(int i = 1; i <= sqrt(n); i++) {
            arr.push_back(i*i);
        }

        return leastNumber(arr, n);    
    }
};





// Top-Down.
class Solution {

public:
    
    int MAX = 100000;

    int numSquares(int n, int t[]) {

        // Base Case.
        if(n == 0)
            return 0;

        if(t[n] != -1) {
            return t[n];
        }

        int min_val = MAX;

        for(int i = 1; i <= n; i++) {
            if(i * i <= n) {
                min_val = min(min_val, numSquares(n-(i*i), t)+1);
            }
        }
        
        return t[n] = min_val;
    }


    int numSquares(int n) {

        int t[n+1];
        memset(t, -1, sizeof(t));

        return numSquares(n, t);
    }
};


// Bottom-Up Approach.
class Solution {
public:
    
    int numSquares(int n) {

        int dp[n+1];

        // base case.
        dp[0] = 0;

        for(int i = 1; i <= n; i++) {

            int leastNumberOfSquare = 100000;           // Big Value of leastNumberOfSquare

            for(int j = 1; j <= i; j++) {

                // we use the perfect number (j * j)
                if(i - (j * j) >= 0) {

                    leastNumberOfSquare = min(leastNumberOfSquare, dp[i - (j*j)] + 1);
                }
            }

            dp[i] = leastNumberOfSquare;
        }

        return dp[n];
    }
};



// Well Defined Program. (Bottom-Up)
class Solution {
public:
    
    int numSquares(int n) {

        vector<int> leastNumberOfSquare(n+1, INT_MAX);
        leastNumberOfSquare[0] = 0;

        for(int i = 1; i <= n; i++) {

            for(int j = 1; j <= i; j++) {

                if(i - (j * j) >= 0) {

                    leastNumberOfSquare[i] = min(leastNumberOfSquare[i], leastNumberOfSquare[i - (j*j)] + 1);
                }
            }
        }

        return leastNumberOfSquare[n];
    }
};



// Bottom-Up Static.
class Solution 
{
public:
    int numSquares(int n) 
    {
        if (n <= 0)
        {
            return 0;
        }
        
        // cntPerfectSquares[i] = the least number of perfect square numbers 
        // which sum to i. Since cntPerfectSquares is a static vector, if 
        // cntPerfectSquares.size() > n, we have already calculated the result 
        // during previous function calls and we can just return the result now.
        static vector<int> cntPerfectSquares({0});
        
        // While cntPerfectSquares.size() <= n, we need to incrementally 
        // calculate the next result until we get the result for n.
        while (cntPerfectSquares.size() <= n)
        {
            int m = cntPerfectSquares.size();
            int cntSquares = INT_MAX;
            for (int i = 1; i*i <= m; i++)
            {
                cntSquares = min(cntSquares, cntPerfectSquares[m - i*i] + 1);
            }
            
            cntPerfectSquares.push_back(cntSquares);
        }
        
        return cntPerfectSquares[n];
    }
};