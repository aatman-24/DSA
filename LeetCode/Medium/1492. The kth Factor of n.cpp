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

Question : 1492. The kth Factor of n
Topic : Number
Problems : https://leetcode.com/problems/the-kth-factor-of-n/
*/



class Solution {
public:


    // O(sqrt(N)) - O(DIVISOR)
    int kthFactor(int n, int k) {
        if(k == 1) return 1;

        vi tmp;
        tmp.push_back(1);
        tmp.push_back(n);

        for(int i = 2; i <= sqrt(n); i++) {
            if(n % i == 0) {
                tmp.push_back(i);
                if(i != sqrt(n)) tmp.push_back(n/i);
            }
        }

        sort(tmp.begin(), tmp.end());

        // cout << tmp.size() << endl;

        if(k > tmp.size()) return -1;
        return tmp[k-1];
    }


    // O(sqrt(N)) - O(1)
    int kthFactor(int n, int k) {

        float upto = sqrt(n);

        for(int i = 1; i < ceil(upto); i++) {
            if(n % i == 0) {
                k--;
                if(k == 0) return i;
            }
        }

        for(int i = upto; i > 0; i--) {
            if(n % i == 0) {
                k--;
                if(k == 0) return n/i;
            }
        }

        return -1;
    }


};