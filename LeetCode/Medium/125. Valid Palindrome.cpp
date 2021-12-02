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

Question: 125. Valid Palindrome
Topic : String, Palindrome
Problems : https://leetcode.com/problems/valid-palindrome/

==============================> Explanation <=============================================


==============================> Apporach and Time Complexity <=============================================

1) Top-Down Pattern = Cadane
Time: O(N)
Space: O(1)

*/

class Solution {
public:
	bool isPalindrome(string s) {

		// create new string.
	    string temp;
	    for(char ch: s) {

	    	// lowercase || [0-9]
	        if(('a' <= ch && ch <= 'z') || ('0' <= ch && ch <= '9')) {
	            temp += ch;
	        }
	        else if('A' <= ch && ch <= 'Z') {
	            temp += char(int(ch) + 32);
	        }
	    }
	    
	    
	    // Check for palindrome.
	    int size = temp.size();
	    int i = 0, j = temp.size() - 1;
	    while(i < j) {
	        if(temp[i] != temp[j]) {
	            return false;
	        }
	        i++; j--;
	    }
	    return true;
	}

};



class Solution {
public:
    
    bool isPalindrome(string s) {

        int i = 0, j = s.size() - 1;
        while(i < j) {

            while(i < j && isalnum(s[i]) == false) i++;
            while(i < j && isalnum(s[j]) == false) j--;

            if(toupper(s[i]) != toupper(s[j]))
                return false;

            i++; j--;
        }

        return true;
    }

};