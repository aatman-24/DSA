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

Question : 556. Next Greater Element III
Topic : Permutation, Two Pointer
Problems : https://leetcode.com/problems/next-greater-element-iii/

==============================> Explanation <=============================================

Same as, next Permuatation....

Using the same digits, find the greater but smallest number is nothing but next permuatation.

Link: 31. Next Permutation

https://github.com/aatman-24/DSA/blob/main/LeetCode/Medium/31.%20Next%20Permutation.cpp

Example...


N = 91543
digits = [9,1,5,4,3]
digits = [9,1(i),5,4,3] nums[i] < nums[i+1]
digits = [9,1(i),5,4,3(j)] nums[j] > nums[i]
digits = [9,3(i),5,4,1(j)] swap(nums[j], nums[i])
digits = [9,3(i),1,4,5(j)] reverse(i+1, N)

found, ans = 93145.

We can use next_permuatation(digits.begin(), digits.end()) to find next permuataion in c++, Interviewer don't allow :))


==============================> Apporach and Time Complexity <=============================================

1) Two Pointer
Time: O(N)
Space: O(1)

*/


class Solution {

public:

    // Extract digits and return it. 123 -> {1, 2, 3}
    vector<int> getDigit(int n) {

        vector<int> digits;

        while(n) {

            digits.push_back(n % 10);
            n /= 10;
        }

        reverse(digits.begin(), digits.end());

        return digits;
    }


    int nextGreaterElement(int n) {
     
        vector<int> digits = getDigit(n);

        int N = digits.size();

         // find first occurance nums[i] < nums[i+1] from the end of array.
        int i;
         for(i = N - 2; i >= 0; i--) {
            if(digits[i] < digits[i+1])
                break;
         }

         // n is 4321, 321... no greater element than itself.
         if(i == -1)
            return -1;


        // find digits[j] > digits[i]
        int j;
        for(j = N - 1; j >= 0; j--) {
            if(digits[j] > digits[i])
                break;
        }

        // (ith and jth) digit swap.
        swap(digits[i], digits[j]);

        // reverse the [i+1, N] 
        reverse(digits.begin() + i + 1, digits.end());


        long ans = 0;
        for(int k = 0; k < digits.size(); k++) {
            ans = ans * 10 + digits[k];
        }

        // number found, but does not fit into INT32.
        if(ans > INT_MAX)
            return -1;

        return (int)ans;

    }
};