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

Question: 345. Reverse Vowels of a String

Topic : String

Problems : https://leetcode.com/problems/reverse-vowels-of-a-string/

==============================> Explanation <=============================================


==============================> Apporach and Time Complexity <=============================================

1) String
Time: O(N)
Space: O(1)

*/


class Solution {
public:

    bool isVowel(char ch) {
        if(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u')
            return true;
        if(ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U')
            return true;
        return false;
    }


    string reverseVowels(string s) {
    
        int i = 0, j = s.size() - 1;
        char temp;

        while(i < j) {

            while(i < j && !isVowel(s[i]))
                i++;

            while(i < j && !isVowel(s[j]))
                j--;

            if(i < j) {
                temp = s[i];
                s[i] = s[j];
                s[j] = temp;
            }
            
            i++; j--;
        }

        return s;
    }
};