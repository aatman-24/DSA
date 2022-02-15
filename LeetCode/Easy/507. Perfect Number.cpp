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

Question : 507. Perfect Number
Topic : Number Therory
Problems : https://leetcode.com/problems/perfect-number/

==============================> Explanation <=============================================

- Find all divisor, using O(sqrt(N)) and sum it all and compare with num.

==============================> Apporach and Time Complexity <=============================================

1) Number Therory
Time: O(sqrt(N))
Space: O(1)

*/

class Solution {
public:
    bool checkPerfectNumber(int num) {
        
        if(num == 1)
            return false;
            
        int divisorSum = 0;

        for(int i = 1; i <= sqrt(num); i++) {

            if(num % i == 0) {

                divisorSum += i;

                if(i != 1)

                    divisorSum += (num / i);
            }



        }

        return divisorSum == num;

    }
};