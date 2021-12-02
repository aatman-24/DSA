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

Question: 1160. Find Words That Can Be Formed by Characters
Topic : String, Counting
Problems : https://leetcode.com/problems/find-words-that-can-be-formed-by-characters/
==============================> Explanation <=============================================

- Count the frequency of main Word and all the words. If any character frequency for word is more than main word then
that word can not be constrctured using main word.


==============================> Apporach and Time Complexity <=============================================

1) String, Counting
Time: O(N)
Space: O(1)

*/






class Solution {

    public:

    bool canConstruct(string word, int count[]) {

        int freq[26] = {0};
        for(char ch: word) freq[ch-'a']++;

        for(int i = 0; i < 26; i++) {
                
            // If current word need more frequency than count. Return false.
            if(freq[i] > count[i]) {
                return false; 
            }
                
        }

        return true;
    }

    int countCharacters(vector<string>& words, string chars) {
        

        // Count Frequence of char in given chars.
        int count[26] = {0};
        for(char ch: chars) count[ch-'a']++;
        

        int total = 0;
        for(auto word: words) {

            // Check if word can be constructed using only limited frequencey of chars.
            if(canConstruct(word, count)) {
                total += word.size();
            }
        }

        return total;
    }

};