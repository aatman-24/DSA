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

Question : 1362. Closest Divisorss
Topic : Number, Divisor
Problems : https://leetcode.com/problems/longest-palindromic-substring/
*/

class Solution {
public:

    vector<int> closestDivisor(int num) {
        int a, b;
        int DIFF = INT_MAX;
        for(int i = 1; i <= sqrt(num); i++) {
            if(num % i == 0) {
                if(abs(i - (num/i)) < DIFF) {
                    DIFF = abs(i - (num/i));
                    a = i; b = num/i;
                }
            }
        }
        return {a,b};   
    }

    // sqrt(N)
    vector<int> closestDivisors(int num) {

        vi pair1 = closestDivisor(num+1);
        vi pair2 = closestDivisor(num+2);

        if(abs(pair1[0] - pair1[1]) < abs(pair2[0] - pair2[1])) {
            return pair1;
        }
        return pair2;

    }   

        // Whatever occured first (n+1) % a== 0 or (n+2)%a == 0
        // by simply observation we can see that and don't need to find all divisor
        // O(N).
        vector<int> closestDivisors(int n) {
            for (int a = sqrt(n + 2); a > 0; --a) {
                if ((n + 1) % a == 0)
                    return {a, (x + 1) / a};
                if ((n + 2) % a == 0)
                    return {a, (x + 2) / a};
            }
            return {};
        }


};

