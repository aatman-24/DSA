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

Question: 132. Palindrome Partitioning II
Topic : Top-Down Bottom-up Pattern=DPOnString, Manancher
Problems : https://leetcode.com/problems/palindrome-partitioning-ii/

==============================> Explanation <=============================================
Dp variant = IntervalDP. Tried but result into TLE.

I try to make the cuts between every index. And form the substring [i, j] check it using isPalindrome().
And store the result. But it results into the TLE. It Take O(N^3) Time. O(N^2) to form the substring
and O(N) to check it is palindrome or not.

dp[i][j] -> Represent the minimum number of cuts needed for [i, j] range.

1) Choise Diagram: 

- For(i, j)
    choose minimum of this -> cuts(i, k) + 1 + cuts(k, j)

2) Base Case: dp[i][i] -> 0. or if(isPalindrome(i, j)) -> return 0 no need to break the word further.

3) Recurrance Relation:

dp[i][j] = min(dp[i][j], dp[i][k] + 1 + dp[k+1][j] );
       

2) DP on Palindrome:

dp[i][j] = (s[i] == s[j]) && (dp[i+1][j-1] == true) (If i, j is not boundary cases)
dp[i][j] = (s[i == s[j]]) (If i and j is boundary case)

isPalindrome[i][j] = s[i] == s[j] && ((i + 1 > j - 1) || isPalindrome[i+1][j-1]))

See second algorithm.....


3)

Remember if palindrome string is given then first think about exploring it from the middle with
both even and odd length. Which is Manancher-like Algorithm.

Check both Algorithm.


==============================> Apporach and Time Complexity <=============================================

1) Top-Down Bottom-up Pattern = IntervalDP
Time: O(N^3)
Space: O(N^3)

2) DP on Palindrome:
Time: O(N^2)
Space: O(N^2)

2) Manancher-like Algorithm
Time: O(N^2)
Space: O(N)

*/


// TLE.
class Solution {
public:
    int t[2001][2001];

    bool isPalindrome(int i, int j, string s) {
        while(i <= j) {
            if(s[i] != s[j])
                return false;
            t[i][j] = 0;
            i++; j--;
        }
        return true;
    }

    int minCut(int i, int j, string s) {

        if(t[i][j] != -1)
            return t[i][j];

        if(isPalindrome(i, j, s)) {
            return t[i][j] = 0;
        }

        int cutNeeded = INT_MAX;

        for(int k = i; k < j; k++) {
            cutNeeded = min(cutNeeded, minCut(i, k, s) + minCut(k+1, j, s) + 1);
        }

        return t[i][j] = cutNeeded;
    }

    int minCut(string s) {

        memset(t, -1, sizeof(t));

        return minCut(0, s.size()-1, s);
    }
};

//Top-Down Into TLE.
class Solution {
public:

    bool isPalindrome(int i, int j, string s) {
        while(i <= j) {
            if(s[i] != s[j])
                return false;
            i++; j--;
        }
        return true;
    }


    int minCut(string s) {
        
        int N = s.size();

        if(N <= 1)
            return 0;

        int dp[N+1][N+1];
        memset(dp, 0, sizeof(dp));

        for(int len = 1; len < N; len++) {

            for(int i = 0; i + len < N; i++) {
                
                int j = i + len;
                
                if(isPalindrome(i, j, s))
                    dp[i][j] = 0;

                else { 

                    dp[i][j] = INT_MAX;

                    for(int k = i; k < j; k++) {

                        dp[i][j] = min(dp[i][j], dp[i][k] + 1 + dp[k+1][j]);

                    }
                }

            }
        }

        return dp[0][N-1];
    }
};



class Solution {

public:
   
    int minCut(string s) {

        int N = s.size();
        if(N <= 1)
            return 0;

        int cuts[N+1];

        bool isPalindrome[N+1][N+1];        
        
        for(int j = 0; j < N; j++) {

            // With String Length ith there will be maximum (i-1) cuts. For Each Characters are separate.
            cuts[j] = j;

            // [j, i] is palindrome or not is based on
            // s[j] == s[i] && A | B
            // A -> s[j+1, i-1] is also palindrome.
            // B -> j+1 > i-1 No need to check any other range is palindrome or not.

            for(int i = 0; i <= j; i++) {

                if(s[i] == s[j] && ((i + 1 > j - 1) || isPalindrome[i+1][j-1])) {

                    isPalindrome[i][j] = true;

                    // If i == 0 then [0, j] is palindrome so no need of any cut.
                    // Otherwise cuts[j] = min(cuts[j], cuts[i-1] + 1)
                    cuts[j] = (i == 0) ? 0 : min(cuts[j], cuts[i-1] + 1);
                }

            }

        }

        return cuts[N-1];
    }
};







// Manancher-like Algorithm.
class Solution {

public:
   
    int minCut(string s) {

        int N = s.size();
        if(N <= 1)
            return 0;

        int cuts[N+1];

        // 1 based indexs for the cuts[] array.
        for(int i = 0; i <= N; i++) 
            cuts[i] = i-1;

        for(int i = 1; i < N; i++) {

            /// cuts[] array is 1 based index. So we take the left most cuts[i-j] + 1/ cuts[i-j-1] + 1.

            // odd length
            for(int j = 0; (i - j) >= 0 && (i + j) < N && s[i-j] == s[i+j]; j++)
                cuts[i+j+1] = min(cuts[i+j+1], cuts[i-j]+1);        // cut[i-j] is leftmost string

            // even length
            for(int j = 0; (i - j - 1) >= 0 && (i + j) < N && s[i-j-1] == s[i+j]; j++)
                cuts[i+j+1] = min(cuts[i+j+1], cuts[i-j-1]+1);
        }

        return cuts[N];
    }
};