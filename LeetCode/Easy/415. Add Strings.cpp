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

Question : 415. Add Strings
Topic : String, Number Therory
Problems : https://leetcode.com/problems/add-strings/

==============================> Explanation <=============================================

- same as linkedlist to addition of two numbers.

==============================> Apporach and Time Complexity <=============================================

1) String, Number Therory
Time: O(N^2) (Adding string) In java StringBuilder is used which take O(N) time.
Space: O(1)

*/


class Solution {

public:

    string addStrings(string num1, string num2) {
        
        if(num1.size() > num2.size())
            return addStrings(num2, num1);

        if(num1.size() == 0)
            return num2;

        string sum="";
        
        int i = num1.size() - 1, j = num2.size() - 1, carry = 0;
        
        while(i >= 0 || j >= 0) {

            int temp_sum = carry;

            if(i > 0)
                temp_sum += (num1[i--] - '0');

            if(j > 0)
                temp_sum += (num2[j--] - '0');

            sum += to_string(temp_sum % 10);

            carry = temp_sum / 10;
        }

        if(carry > 0) {
            sum += to_string(carry);
        }

        reverse(sum.begin(), sum.end());

        return sum;

    }
};