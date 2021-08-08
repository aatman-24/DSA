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
d
/*
==============================> Description <=============================================

Question : 8. String to Integer (atoi)
Topic : String 
Problems : https://leetcode.com/problems/string-to-integer-atoi/

==============================> Explanation <=============================================


*/


/*
==============================> Edge Case <=============================================


*/

class Solution {
public:
    int myAtoi(string str) {
        int res=0;
        bool is_positive = true;
        int i=0;
        
        while (str[i] == ' ') // count leading spaces
            i++;
        
        if (str[i] == '-') // check sign
        {
            is_positive = false;
            i++;
        }
        else if (str[i] == '+')
        {
            is_positive = true;
            i++;
        }
        str.erase(0,i); // remove leading spaces and sign
        
        for (int i=0;i<str.size();i++)
        {
            if (isdigit(str[i]))
            {
                int value = str[i] - '0';
                
                // Handle the Overflow.
                if ((res > (INT_MAX - value)/10) && (is_positive))
                    return INT_MAX;
                if ((res > (INT_MAX - value)/10) && (!is_positive))
                    return INT_MIN;

                (res*=10) += value;
            }
            else // no more digits
                break;
        }
        
        if (!is_positive)
            return -res;
        return res;
    }
};