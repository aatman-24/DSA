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
Topic : String, Number Construction
Problems : https://leetcode.com/problems/integer-to-roman/


==============================> Explanation <=============================================

- At first sight, Greedy Algorithm works we already knew.

- But what about 4, 9, 40, 90...... How to make that number.....

- We just add those number into the array and make complete the greedy algortihm.

==============================> Apporach and Time Complexity <=============================================

1) Number Construction
Time: O(N)
Space: O(1)


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