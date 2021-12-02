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

Question: 680. Valid Palindrome II
Topic : String, Palindrome
Problems : https://leetcode.com/problems/valid-palindrome-ii/

==============================> Explanation <=============================================

- Same as Palindrome Checking,

But when we at (i, j) match, if it does't match then we delete one character for only once, 
so we either delete i or j.

If we delete the ith char, then we again need to check (i+1, j) is palindrome or not.
If we delete the jth char, then we again need to check (i, j - 1) is palindrome or not.

based on that we return true or false.

==============================> Apporach and Time Complexity <=============================================

1) String, Palindrome
Time: O(N)
Space: O(1)

*/

class Solution {
public:

    bool isPalindrome(string s, int i, int j) {
        
        while(i < j) {

            if(s[i] != s[j])
                return false;

            i++; j--;
        }

        return true;
    }


    bool validPalindrome(string s) {
        

        int i = 0, j = s.size() - 1;
      
        while(i < j) {

            if(s[i] != s[j]) {
                
                if(isPalindrome(s, i+1, j) || isPalindrome(s, i, j-1))
                    return true;
                else
                    return false;
                }
                
            i++; j--;
        }

        return true;
    }

};