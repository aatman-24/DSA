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

Question : 179. Largest Number
Topic : Array, Sorting
Problems : https://leetcode.com/problems/largest-number/
*/



/*
Edge Case: 
when [0,0,0] at a time return 0. not 000.
*/


class Solution {
    public:
    
        static bool sort_fun(int &a, int &b) {
            return to_string(a) + to_string(b) > to_string(b) + to_string(a);
        }


        string largestNumber(vector<int>& nums) {

            sort(nums.begin(), nums.end(), sort_fun);

            string res = "";
            for(int num: nums) {
                res += to_string(num);
            }

            if(res[0] == '0' && res.size() > 1) {  // "0000" -> "0";
                return "0";
            }

            return res;
    }
};
