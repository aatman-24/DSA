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

Question : 1358. Number of Substrings Containing All Three Characters
Topic : Sliding Window
Problems : https://leetcode.com/problems/number-of-substrings-containing-all-three-characters/

/*
==============================> Explanation <=============================================
- we first find the window that contain all three character.

- once we find it(counter=3) then all the character after it can make substring.
ex.. abcabc
    window = abc
    substring abc, abca, abcab, abcabc = (4)
so we count it ans += (n - end) (6 - 2) = 4
    - then we shrink the window until we again make it invalid (coutner != 3).
    - and every time we update ans with same value.

    ex... aaabca
          window = aaabc (end = 4, n = 6)
          first time ans = (6 - 4) = 2 (aaabc, aaabca)
          next time ans = (6 - 4) = 2 (aabc, aabca)
          third time ans = (6 - 4) = 2 (abc, abca)

          and fourt time we found that (counter != 3) so now we expand end pointer as usual. 
*/

/*
==============================> Edge Case <=============================================

*/

// 


class Solution {
public:
    int numberOfSubstrings(string s) {

        // here I can take three counter or 3 size array.
        int map[128] = {0};
        int begin = 0, end = 0, n = s.size(), ans = 0, counter=0;

        while(end < n) {

            if(map[s[end]] == 0) counter++;
            map[s[end]]++;

            // all three character are in our window.
            while(counter == 3) {

                // substring count.
                ans += (n - end);

                // if begin pointer character is last occurace in our window.
                if(map[s[begin]] == 1) counter--;

                // update the frequency of begin pointer character.
                map[s[begin++]]--;
            }

            end++;
        }

        return ans;
    }
};