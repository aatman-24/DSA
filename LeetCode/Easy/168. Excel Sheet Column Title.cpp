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

Question: 168. Excel Sheet Column Title
Topic : Number Therory, DecimalToBinary
Problems : https://leetcode.com/problems/excel-sheet-column-title/

==============================> Explanation <=============================================

171. Excel Sheet Column Number

Here, We convert decimal to Binary...(Simliar)

==============================> Apporach and Time Complexity <=============================================

1) Number Therory, DecimalToBinary
Time: O(N)
Space: O(1)

*/




#define ll long long

class Solution {
public:


    string convertToTitle(int n) {
     
        string ans;

        while(n) {
            n--;            // set 0th based index. 
            int idx = n % 26;
            ans += char(int('A') + idx);
            n = n / 26;
        }
        
        reverse(ans.begin(), ans.end());
        
        return ans;
    }
};