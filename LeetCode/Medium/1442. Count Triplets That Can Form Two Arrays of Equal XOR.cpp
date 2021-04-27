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

Question : 1314. Matrix Block Sum
Topic : DP, Kadane
Problems : https://leetcode.com/problems/matrix-block-sum/
*/

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

Question : 1442. Count Triplets That Can Form Two Arrays of Equal XOR
Topic : Array, Prefix-Sum
Problems : https://leetcode.com/problems/count-triplets-that-can-form-two-arrays-of-equal-xor/
*/

arr = [0, 1, 2, 3, 4, 5]
xor = [0, 01, 012, 0123, 01234, 012345]

then if (xor[i] == xor[j]) means that i = 2 and j = 5 -> 012 ^ 012345 -> xorof(345) index.
bcz xorof(i==j) = 0.



// O(N^2).
class Solution {
public:
    
    int countTriplet(vi A) {
        A.insert(A.begin(), 0);
        int n = A.size(), res = 0;
        REP(i,n) cout << A[i] << ' ';
        cout << endl;
        for(int i = 1; i < n; i++) {
            A[i] ^= A[i-1];
        }

        REP(i,n) cout << A[i] << ' ';
        cout << endl;
        
        for(int i = 0; i < n; ++i) {
            for(int j = i + 1; j < n; ++j) {
                if(A[i] == A[j]) {
                    res += j - i - 1;
                }
            }
        }
        return res;
}

 int countTriplets(vector<int>& A) {
        int n = A.size() + 1;
        vi prefix(n, 0);
        for(int i = 1; i < n; ++i) {
            prefix[i] = prefix[i-1] ^ A[i-1];
        }

        REP(i,n) cout << prefix[i] << ' ';
        cout << endl;

        int res = 0;
        for(int i = 0; i < n; ++i) {
            for(int j = i + 1; j < n; ++j) {
                if(prefix[i] == prefix[j]) {
                    res += j - i - 1;
                }
            } 
        }
        return res;
    }

};