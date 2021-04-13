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

Question : 1395. Count Number of Teams
Topic : Array
Problems : https://leetcode.com/problems/count-number-of-teams/
*/


// Time Complexity  O(N^2). Can be Improvde using Fenwick Tree.
class Solution {
public:
    int numTeams(vector<int>& rating) {
        int n = rating.size();
        if(n <= 2) return 0;
        int ans = 0;
        int lftS, lftB, rhtS, rhtB;

        for(int i = 1; i < n - 1; i++) {

            lftB = lftS = rhtB = rhtS = 0;

            int j = i - 1;
            while(j >= 0) {
                if(rating[j] < rating[i]) lftS++;
                else if(rating[j] > rating[i]) lftB++;
                j--;
            }

            int k = i + 1;
            while(k < n) {
                if(rating[i] < rating[k]) rhtB++;
                else if(rating[i] > rating[k]) rhtS++;
                k++;
            }

            ans += (lftS * rhtB) + (lftB * rhtS);

        }

        return ans;
    }
};