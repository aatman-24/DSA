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

Question : 504. Base 7
Topic : Maths
Problems : https://leetcode.com/problems/base-7/

==============================> Explanation <=============================================

Converting base10 to base-x is same for all the x. here x = 7.


==============================> Apporach and Time Complexity <=============================================

1) Maths
Time: O(1), O(1)
Space: O(1)

*/


class Solution {
public:
    
    string convertToBase7(int num) {
        
        if(num == 0)
            return "0";
        
        bool neg = num < 0 ? true: false;
        num = abs(num);

        string ans = "";
        while(num) {
            ans += to_string(num % 7);
            num /= 7;
        }

        if(neg)
            ans += '-';

        reverse(ans.begin(), ans.end());

        return ans;

    }
};
