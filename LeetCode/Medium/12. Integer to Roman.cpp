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

Question : 12. Integer to Roman
Topic : String
Problems : https://leetcode.com/problems/integer-to-roman/

/*
==============================> Explanation <=============================================
Greedy Apporach Work Best. Whenever we found the number only starting with 4 | 9 
then and only we took. combination of Roman which we already took into array and
work as greedy.
*/


/*
==============================> Edge Case <=============================================
*/

class Solution {
public:

    string intToRoman(int num) {


        int arr[13] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9,  5,  4,  1};
        string roman[13] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
        
        string ans;
        int i = 0;
        while(num) {
            while(num - arr[i] >= 0) {
                num -= arr[i];
                ans += roman[i];
            }
            i++;
        }

        return ans;
    }
};