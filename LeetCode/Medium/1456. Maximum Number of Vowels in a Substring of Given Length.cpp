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

Question : 1456. Maximum Number of Vowels in a Substring of Given Length
Topic : Sliding Window
Problems : https://leetcode.com/problems/maximum-number-of-vowels-in-a-substring-of-given-length/

/*
==============================> Explanation <=============================================


*/

class Solution {

public:
    
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        
        int satisified = 0, makeSatisified = 0, maxSatisified = 0, n = customers.size();
        
        for(int i = 0; i < n; i++) {

            if(i >= minutes) {
                makeSatisified -= customers[i-minutes] * grumpy[i-minutes];
            }
            
            if(grumpy[i] == 0) {
                satisified += customers[i];
            }
            else {
                makeSatisified += customers[i];
            }

            maxSatisified = max(maxSatisified, makeSatisified);
        }

        return maxSatisified + satisified;
    }

};