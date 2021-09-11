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

Question : 131. Palindrome Partitioning (IMP)
Topic : Array, Backtracking
Problems : https://leetcode.com/problems/palindrome-partitioning/

==============================> Explanation <=============================================
- Here We try to make partition at every index(BFS). If left side of part is palindrome
then we go to the depth(DFS) and check for the right side until we reached the end of the
string. If we reached that mean it is possible.

- BFS make partition from (index, endOfString) and DFS go to the depth if is possible.

- Make tree and visualzie it.


NOT SURE,

But if String Length is -> N.

Time = O(2^N)(Try out every index partition)(Just same as subset problem) * O(N^2)(For Loop + _isPalindrome)
Space = O(N)(Path) + O(N)(Aux)


==============================> Edge Case <=============================================


*/

class Solution {
public:
    vector<vector<string>> ans;

    bool _isPalindrome(string s, int l, int r) {
        while(l <= r) {
            if(s[l] != s[r]) return false;
            l++; r--;
        }
        return true;
    }

    void backtrack(string s, int start, vector<string> &tmp) {

        if(s.size() == start) {
            ans.push_back(tmp);
            return;
        }

        for(int i = start; i < s.size(); i++) {
            if(_isPalindrome(s, start, i)) {
                tmp.push_back(s.substr(start, i+1-start));
                backtrack(s, i+1, tmp);
                tmp.pop_back();
            }   
        }
        
    }

    vector<vector<string>> partition(string s) {
        ans.clear();
        vector<string> tmp;
        backtrack(s, 0, tmp);   
        return ans;  
    }

};

/*
s = 'aabaa'

a a b a a
a a b aa
a aba a
aa b a a
aa b aa
aabaa

*/

// Striver Code:
// both Are Same.


class Solution {
public:
    vector<vector<string>> ans;

    bool _isPalindrome(string s, int l, int r) {
        while(l <= r) {
            if(s[l] != s[r]) return false;
            l++; r--;
        }
        return true;
    }

    void backtrack(int index, string s, vector<string> &path, vector<vector<string>> &ans) {

        if(s.size() == index) {
            ans.push_back(path);
            return;
        }

        for(int i = index; i < s.size(); ++i) {
            if(_isPalindrome(s, index, i)) {
                path.push_back(s.substr(index, i+1-index));
                backtrack(index+1, s, path, ans);
                path.pop_back();
            }   
        }
        
    }

    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> path;
        backtrack(0, s, path, res);   
        return ans;  
    }

};
