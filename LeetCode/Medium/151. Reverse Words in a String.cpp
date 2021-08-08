#include <bits/stdc++.h>
#define ll long long
#define REP(i,n) for(int i = 0; i < n; i++)
#define REP1(i,n) for(int i = 1; i <= n; i++)
#define debug cout << "Ok" << endl;
#define mod 1000000007

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

Question : 151. Reverse Words in a String
Topic : String, Pointer
Problems : https://leetcode.com/problems/reverse-words-in-a-string/
/*
==============================> Explanation <=============================================
1) - break the word and push into the stack. And last make new string 
by poping out from the stack. so overall the new string is into reverse
order and all the unnecessary space removed into new string.


2) - reverse the all string. so we don't need to use the stack. 
now find the word and reverse it so now again it comes to right order.
and remove duplicate space.

storeIndex reprsent the pointer where the new character is going to place.


and at last from the [storeIndex, s.end()] need to erase because we already
copy it in string previously.
*/


/*
==============================> Edge Case <=============================================


*/

class Solution {
    public:

    // O(N) + O(N) [Stack Solution]
    string reverseWords(string s) {

        stack<string> st;
        string tmp, ans;

        for(int i = 0; i <= s.size(); i++) {

            // Add last string whatever it into stack.
            if(i == s.size()) {
                if(tmp.size() > 0) st.push(tmp);
                break;
            }
            
            // if empty char encounter and tmp.size() > 0 menas some
            // word already made we push into the stack.
            if(s[i] == ' ') {
                if(tmp.size() > 0) st.push(tmp);
                tmp = "";
            }
            else {
                tmp += s[i];
            }
        }

        // make string from the stack.
        while(!st.empty()) {
            ans += st.top(); st.pop();
            if(!st.empty()) ans += ' ';
        }

        return ans;

    }


    // Inplace O(N) - O(1).
    string reverseWords(string &s) {

        // reverse all string.
        reverse(s.begin(), s.end());
        int storeIndex = 0; // update new string.
        for(int i = 0; i < s.size(); i++) {
            if(s[i] != ' ') {
                // space after every word.
                if(storeIndex != 0) s[storeIndex++] = ' ';
                int j = i;
                while(j < s.size() && s[j] != ' ') s[storeIndex++] = s[j++];
                //reverse the word whole word. so word is in right order.
                // (j - i) represent the word size.
                // s.begin() + stroeIndex point to the last of the word.
                reverse(s.begin() + storeIndex - (j - i), s.begin() + storeIndex);
                i = j;
            }
        }
        s.erase(s.begin() + storeIndex, s.end());
        return s;
    }

};