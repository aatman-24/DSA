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

Question: 43. Multiply Strings
Topic : Math
Problems : https://leetcode.com/problems/multiply-strings/

==============================> Explanation <=============================================
1) It is method which we used in childhood to perform multiplication. Here it is simulation
of that method.

2) It looks great from Interview perspective.
https://leetcode.com/problems/multiply-strings/discuss/17605/Easiest-JAVA-Solution-with-Graph-Explanation

If ith index digit of num1 is multiply with jth index digit in num2 then its result,

carry stored at -> i + j index.
value stored at -> i + j + 1 index. 

==============================> Apporach and Time Complexity <=============================================

1) Childhood Multiplication:
Time: O(m*n)
Space: O(m+n)

2) Modification of method 1:
Time: O(m*n)
Space: O(m+n)
*/


class Solution {
public:

    string multiply(string num1, string num2) {

        if(nums1 == "0" || nums2 == "0")
            return "0";

        if(num1.size() < num2.size()) {
            string tmp = num1;
            num1 = num2;
            num2 = tmp;
        }

        int n = num1.size(), m = num2.size();

        int MAX_SIZE = n+m; // It can be num1 + num2 maximum.
        vector<int> ans(MAX_SIZE, 0);

        for(int j = m - 1; j >= 0; j--) {

            // Keep track of Carry and index of result(k). Index(k) is subtract by 1 
            // every time when j decrease.
            int carry = 0, k = MAX_SIZE-1-(m-1-j);
        
            for(int i = n - 1; i >= 0; i--) {

                int value = (int(num1[i]-'0') * int(num2[j]-'0')) + ans[k] + carry;
                ans[k--] = value % 10;
                carry = value / 10;

            }

            // The last carry bit directly add into the res[k].
            if(carry > 0) {
                ans[k] = carry;
            }
        }

        string res = "";
        int i = 0;

        // Remove all the zero in front of ans array.
        while(i < MAX_SIZE && ans[i] == 0) i++;

        while(i < MAX_SIZE) {
            res += to_string(ans[i]);
            i++;
        }
        
        return res == "" ? "0" : res;
    }
};



class Solution {
public:

    string multiply(string nums1, string nums2) {

        if(nums1 == "0" || nums2 == "0")
            return "0";

        if(nums1.size() < nums2.size()) {
            string tmp = nums1;
            nums1 = nums2;
            nums2 = tmp;
        }

        int n = nums1.size(), m = nums2.size();

        int MAX_SIZE = n + m;
        vector<int> ans(MAX_SIZE, 0);

        for(int j = m - 1; j >= 0; j--) {

            for(int i = n - 1; i >= 0; i--) {
                
                int value = (int(nums1[i]-'0') * int(nums2[j]-'0')) + ans[i+j+1]; //(it is carry of previous digit).

                // last digit
                ans[i+j+1] = value % 10;

                // We sum up the carry at i+j which is used while calculating value.
                ans[i+j] += (value / 10);
            }
        }

        string res = "";
        int i = 0;
        while(i < MAX_SIZE && ans[i] == 0) i++;

        while(i < MAX_SIZE) {
            res += to_string(ans[i]);
            i++;
        }

        return res;
    }
};