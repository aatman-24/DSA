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

Question : 187. Repeated DNA Sequences
Topic : Map
Problems : https://leetcode.com/problems/repeated-dna-sequences/

==============================> Explanation <=============================================

1st Approach:
- map<string, int> and check all the string having more than one count.


2nd Approach:
- 10 letter with 4 bytes take = 40 bytes.

We can reduce it,

0 = 00 (bits in binary number system) = 'A'

1 = 01 (bits in binary number system) = 'C'

2 = 10 (bits in binary number system) = 'G'

3 = 11 (bits in binary number system) = 'T'

So 10 letters with 2 bits take = 20 bits < 32 bits < 4 bytes....


We just need to map the current string into the decimal value,

A A C C T C C G G T

00 00 01 01 11 01 01 10 10 11 = 00000101110101101011 (binary) = 23915 (decimal)

- Every time we perform (two bit left shifting)
- Mask the current character binary value...



==============================> Apporach and Time Complexity <=============================================

1) Mapping
Time: O(N)
Space: O(10*N) -> O(N)

*/

class Solution {

    public:
    
    vector<string> findRepeatedDnaSequences(string s) {

        if(s.size() < 10)
            return {};
        
        map<string, int> mp;

        for(int i = 0; i <= s.size() - 10; i++) {

            string seq = s.substr(i, 10);

            if(mp.count(seq)) {
                mp[seq]++;
            }
            else {
                mp[seq] = 1;
            }
        }

        vector<string> ans;
        for(auto it: mp) {
            if(it.second > 1) {
                ans.push_back(it.first);
            }
        }

        return ans;

    }
};




// Optimized Apporach for Mapping.
class Solution {

    public:
    
    vector<string> findRepeatedDnaSequences(string s) {

        if(s.size() < 10)
            return {};
        
        map<int, int> mp;
        set<string> ans;

        map<char, int> charToByte;
        charToByte['A'-'A'] = 0;
        charToByte['C'-'A'] = 1;
        charToByte['G'-'A'] = 2;
        charToByte['T'-'A'] = 3;

        for(int i = 0; i < s.size() - 9; i++) {

            int mask = 0;

            for(int j = i; j < i + 10; j++) {

                // left shift two bits.
                mask <<= 2;

                // mask the last two bits.
                mask |= charToByte[s[j] - 'A'];
            }


            if(mp.count(mask)) {
                ans.insert(s.substr(i, 10));
            }
            else {
                mp[mask] = 1;
            }

        }

        return vector<string>(ans.begin(), ans.end());

    }
};