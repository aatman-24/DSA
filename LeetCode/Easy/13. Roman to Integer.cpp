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

Question: 13. Roman to Integer
Topic : String
Problems : https://leetcode.com/problems/roman-to-integer/

==============================> Explanation <=============================================
- In First Apporach, We make string of two characters and check that string is in map or not if yes then we add that('IV', 'IX')
into the sum. Otherwise consider single character only.

- Second Approach is logical. If you see, two characters roman number (IV, IX) found that first character is smaller than second character
so we can use that approach. In roman number, VI(11) you found that first character is bigger than second one, so when first
is smaller than second means we need to subtract that character. 

    IV -> -1 + 5 = 4. 

==============================> Apporach and Time Complexity <=============================================

1) String
Time: O(N)
Space: O(1)

*/

class Solution {

public:

unordered_map<string, int> pair_mp;
unordered_map<char, int> mp;

void fill_PairMapping() {
    pair_mp["IV"] = 4;
    pair_mp["IX"] = 9;
    pair_mp["XL"] = 40;
    pair_mp["XC"] = 90;
    pair_mp["CD"] = 400;
    pair_mp["CM"] = 900;
}

void single_Mapping() {
    mp['I'] = 1;
    mp['V'] = 5;
    mp['X'] = 10;
    mp['L'] = 50;
    mp['C'] = 100;
    mp['D'] = 500;
    mp['M'] = 1000;
}

int romanToInt(string s) {

    fill_PairMapping();
    single_Mapping();
    
    int ans = 0;

    int i = 0, n = s.size() - 1;

    bool pair = false;

    while(i <= n) {

        pair = false;

        if(i+1 <= n) {

            string pair_m = s.substr(i, 2);
            
            if(pair_mp.count(pair_m)) {
                pair = true;
                ans += pair_mp[pair_m];
                i += 2;
            }
        }

        if(!pair) {
            ans += mp[s[i]];
            i++;
        }
    }

    return ans;
}
};




int romanToInt(string s) 
{
    unordered_map<char, int> T = { { 'I' , 1 },
                                   { 'V' , 5 },
                                   { 'X' , 10 },
                                   { 'L' , 50 },
                                   { 'C' , 100 },
                                   { 'D' , 500 },
                                   { 'M' , 1000 } };
                                   
   int sum = T[s.back()];
   for (int i = s.length() - 2; i >= 0; --i) 
   {

       // Observation
       if (T[s[i]] < T[s[i + 1]])
       {
           sum -= T[s[i]];
       }
       else
       {
           sum += T[s[i]];
       }
   }
   
   return sum;
}