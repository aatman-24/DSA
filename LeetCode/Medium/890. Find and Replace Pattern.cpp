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

Question : 890. Find and Replace Pattern
Topic : String
Problems : https://leetcode.com/problems/find-and-replace-pattern/
*/

// Here IF first string char is already marked then it match with its mapper not any other.
// If second string char is already matched and first one not then must return false bcz
// second string can not match two char of first string.
// we mark second and first string char and also maintain first string mapper.

#define A 97

// O(N*M) // N number of words. and M len of words[i].
class Solution {
public:
    
        int  mark[30];
        int  mark2[30];
        char mapper[30];
    
        bool isMatch(string s, string t) {

            if(s.size() != t.size()) return false;

            memset(mark, 0, sizeof(mark));
            memset(mark2, 0, sizeof(mark2));
            int n = s.size();

            REP(i,n) {
                int index1 = int(s[i])- A;
                int index2 = int(t[i])- A;

                if(mark[index1] == 1) {
                    if(mapper[index1] != t[i] ) return false;
                }
                else if(mark2[index2] == 1) {
                    return false;
                }
                else {
                    mark2[index2] = 1;
                    mapper[index1] = t[i];
                    mark[index1] = 1;
                }
            }

            return true;
        
        }

    
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        vector<string> ans;
        REP(i, words.size()) {
            if(isMatch(words[i], pattern)) ans.push_back(words[i]);
        }
          
        return ans;
    }
};