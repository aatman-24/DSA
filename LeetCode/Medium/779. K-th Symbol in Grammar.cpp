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

Question : 779. K-th Symbol in Grammar
Topic : Array, Recursion.
Problems : 779. K-th Symbol in Grammar
*/

class Solution {
public:
   

    int kthGrammar(int N, int K) {
        if(N == 1 && K == 1) return 0;
            int mid = pow(2, N-1) / 2 ;
            if(K <= mid) {
                return kthGrammar(N-1, K);
            }
            else {
                return !kthGrammar(N-1, K - mid);
            }
    }

};

/* Explanation 

N = 1 0
N = 2 0 | 1
N = 3 0 1 | 1 0
N = 4 0 1 1 0 | 1 0 0 1


Two observation : for any N the first half part is same as N - 1.
    and second half part of N is invert of N - 1.

    solve(N,K) -> if(K <= mid) -> solve(N-1, K)
                  if(K > mid) -> !solve(N-1, K - mid)

    and base case which is given N == 1 && K == 1 (return 0);

    how you find mid ?

    it is (2^N-1) / 2 (from the observation).

    Ex N = 4, K = 5

    (4,5) -> (mid = 4 , K = 5 - 4 = 1)  (3,1) ->  (2, 1) -> (1,1)
       1  <-    (invert)       <-        0    <-  0   <-  0

*/