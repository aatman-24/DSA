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

Question: 66. Plus One
Topic : Number Therory
Problems : https://leetcode.com/problems/plus-one/

==============================> Explanation <=============================================

First Approach: Automate whatever is given. Have idea about the (sum + carry) apporach which is same in LL.

Second Approach: Forward the carry until the not consume by number.

==============================> Apporach and Time Complexity <=============================================

1) Number Theory
Time: O(N)
Space: O(1)

*/


// Two times reverse the array.
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        
        vector<int> ans;
        
        reverse(digits.begin(), digits.end());

        int carry = 1;

        for(int num: digits) {

            int sum = carry + num;

            ans.push_back(sum % 10);

            carry = sum / 10;
        }

        if(carry != 0) {
            ans.push_back(carry);
        }

        reverse(ans.begin(), ans.end());

        return ans;
    }
};


// One time reverse the all array.
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        
        vector<int> ans;
        
        int n = digits.size(), carry = 1;

        for(int i = n - 1; i >= 0; i--) {

            int sum = carry + digits[i];

            ans.push_back(sum % 10);

            carry = sum / 10;
        }

        if(carry != 0) {
            ans.push_back(carry);
        }

        reverse(ans.begin(), ans.end());

        return ans;
    }
};




// Optimized Apporach
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
            
        int n = digits.size();
        
        for(int i = n - 1; i >= 0; i--) {

            if(digits[i] < 9) {
                digits[i]++;
                return digits;
            }

            digits[i] = 0;
        }

        // 999 -> 1000
        vector<int> ans(n + 1, 0);
        ans[0] = 1;

        return ans;
    }
};