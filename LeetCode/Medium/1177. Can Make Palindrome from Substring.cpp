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

Question: 1177. Can Make Palindrome from Substring
Topic : BitManipulation + XOR Prefix
Problems : https://leetcode.com/problems/can-make-palindrome-from-substring/

==============================> Explanation <=============================================
Prefix XOR.....

- Here you can rearrange the character to form the palindrome. So we first store prefix XOR at every index
which can help while querying of substring.


0       1    2   3      4   5
        a    b   c      d   a
0000  0001 0011 0111 1111 1110


It Indicate the freq is ever or odd...


So when query, abcda -> (0, 4) -> arr[0] ^ arr[4+1] -> ans = 1110

So How many total distinct char is there, -> 3

but if it is odd length string then we can subtract one from it -> 3 - 1 = 2 (Two differnt characters)

-> means need 2/2 (1) char to change.

==============================> Apporach and Time Complexity <=============================================
1) BitManipulation + XOR Prefix:
Time: O(N)
Space: O(N) 
*/



class Solution {
public:
    
    vector<bool> canMakePaliQueries(string s, vector<vector<int>>& queries) {

        vector<int> arr(s.size()+1, 0);

        int mask = 0;
        for(int i = 0; i < s.size(); i++) {
            mask ^= (1 << int(s[i]-'a'));
            arr[i+1] = mask;
        }

        vector<bool> answer;

        for(auto it: queries) {

            int i = it[0], j = it[1], cost = it[2];

            // both index same then no need to check.
            if(i == j) {
                answer.push_back(true);
                continue;
            }

            int left = arr[i];
            int mask2 = (left ^ arr[j+1]);

            // check how many bit is set. (total different character)
            int setBit = 0;
            for(int k = 0; k < 26; k++) {
                if(mask2 & (1 << k))
                    setBit++;
            }

            // if odd length string subtract one from it.
            if((j - i + 1) % 2 == 1)
                setBit--;   

            // half of the cost can be sustain.
            if((setBit + 1) / 2 <= cost)
                answer.push_back(true);
            else 
                answer.push_back(false);

        }

        return answer;

    }

};