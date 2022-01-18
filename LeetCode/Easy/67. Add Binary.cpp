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

Question: 67. Add Binary
Topic : String
Problems : https://leetcode.com/problems/add-binary/

==============================> Explanation <=============================================

- Binary Addition. Start from the reverse.

==============================> Apporach and Time Complexity <=============================================

1) Binary Addition
Time: O(N)
Space: O(1)

*/


class Solution {
public:
    string addBinary(string a, string b) {
        
        string ans;
        int m = a.size(), n = b.size();
        int i = m - 1, j = n - 1, carry = 0;
        int sum;

        while(i >= 0  || j >= 0) {

            sum = carry;

            if(i >= 0)
                sum += int(a[i--] - '0');


            if(j >= 0)
                sum += int(b[j--] - '0');

            if(sum % 2 == 0) {
                ans += '0';
            }
            else {
                ans += '1';
            }

            carry = sum / 2;
        }

        if(carry > 0) {
            ans += '1';
        }

        reverse(ans.begin(), ans.end());

        return ans;
    }
};