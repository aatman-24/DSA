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

Question: 1753. Maximum Score From Removing Stones
Topic : maxHeap
Problems : https://leetcode.com/problems/maximum-score-from-removing-stones/

==============================> Explanation <=============================================

1) Use Priority Queue and Perform greedy Method which ever is two big number
subtract from then and count it.

2)

Another way of writing the conditions. Assuming a <= b <= c, there are two cases.

Case 1 : a+b <= c , which means we can at max pair every a,b with c
Case 2 : a+b > c, which means pair every c with the pile of a,b and then pair the stones of a,b with each other.

Dividing by two represents pairing, so we just need to find number of stones.
Case 1 We will simply double pile of a+b, since stones of c are greater than a+b
Case 2. We can pair all stones of c with stones in a+b, hence we add count of stones in c. The remaining stones of a,b are paired within themselves upon division by 2.


==============================> Apporach and Time Complexity <=============================================

1) MaxHeap:
Time: O(N*log3) -> N = max(a+b, c)
Space: O(1)

2) Logic:
Time: O(1)
Space: O(1)
*/


class Solution {
public:

    int maximumScore(int a, int b, int c) {

        vector<int> num = {a, b, c};
        sort(num.begin(), num.end());

        int count = 0;

        while(num[1] != 0) {
            num[1] -= 1;
            num[2] -= 1;
            sort(num.begin(), num.end());
            count++;
        }

        return count;
    }
};



class Solution {
public:
    int maximumScore(int a, int b, int c) {

        vector<int> num = {a, b, c};
        sort(num.begin(), num.end());

        a = num[0], b = num[1], c = num[2];

        // C value can not be more than a+b. Case-2.
        c = min(a+b, c);

        // number of pairing. Total number of coin which we have to select from. All are 
        // be part of pair.
        return (a + b + c) >> 1;
    }
};