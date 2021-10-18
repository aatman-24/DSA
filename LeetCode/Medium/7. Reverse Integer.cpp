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

Question:  7. Reverse Integer
Topic : Number Theory
Problems : https://leetcode.com/problems/reverse-integer/

==============================> Explanation <=============================================
- Knew it!!!
- Consider the Edge Case.
==============================> Apporach and Time Complexity <=============================================

1) Reverse the number
Time: O(N)
Space: O(1)

*/

class Solution {
public:
int reverse(int x) {
    int ans = 0;
    
    while(x) {

        // cheking the next step is out of bound or not.
        if(ans < INT_MIN/10 || ans > INT_MAX/10)
            return 0;

        ans = ans * 10 + x % 10;
        x /= 10;
    }
    return ans;
}
};