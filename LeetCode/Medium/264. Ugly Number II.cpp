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

Question: 264. Ugly Number II
Topic : Heap, PQ
Problems : https://leetcode.com/problems/ugly-number-ii/

==============================> Explanation <=============================================
solve this problem with DP. Only Heap is implemented. Not completed this queuestion.

1) Add All the Element 2^a * 3^b * 5^c. Add all the elements into the array and count it.
a, b, c -> 1 to 1690. Avoid the INTEGER FLOW.

2) Use Priority Queue. Only add the elements which is popped from pq. Mutliply it with
primes (2, 3, 5) and then add it.

3) DP (Remaining)


==============================> Apporach and Time Complexity <=============================================

1) Brute Force:
Time: O((1690)^3)
Space: O((1690)^3)

2) Heap:
Time: O(N*logN)
Space: O(3*N)


*/

class Solution {
public:

    int nthUglyNumber(int n) {

        int ugly[n];
        ugly[0] = 1;

        priority_queue<int, vector<int>, greater<int>> pq;
        vector<int> primes = {2, 3, 5};

        for(int i = 0; i < 3; i++) {
            pq.push(primes[i]);
        }

        int i = 1;

        while(i < n) {

            int num = pq.top(); pq.pop();

            if(ugly[i-1] != num) {
                ugly[i] = num;
                i++;

                for(int i = 0; i < 3; i++) {

                    // To avoid INT Flow.
                    if(num < (INT_MAX / primes[i])) pq.push(num*primes[i]);
                }
            }
        }

        return ugly[n-1];
    }
};