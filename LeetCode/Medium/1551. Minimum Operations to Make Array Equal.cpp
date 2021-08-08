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

Question : 1551. Minimum Operations to Make Array Equal
Topic : Number
Problems : https://leetcode.com/problems/minimum-operations-to-make-array-equal/
*/


class Solution {
public:
    // O(N)
    int minOperations(int n) {
        int avg = n;
        int cost = 0;
        int upto = n/2;
        int odd = 1;
        while(upto > 0) {
            cost += (avg - odd);
            odd += 2;
            upto--;
        } 
        return cost;
    }


    // O(1)
    int minOperations(int n) {
        if(n & 1){ // Odd Case
            int N = (n - 1) / 2;  // number of elements before mid element
            return N * (N + 1); 
        }
        int N = n / 2;  // number of elements before mean of mid elements
        return N * N; 
    }
};