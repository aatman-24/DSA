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

Question : 424. Longest Repeating Character Replacement
Topic : Sliding Window
Problems : https://leetcode.com/problems/longest-repeating-character-replacement/

/*
==============================> Explanation <=============================================
First time I bit confuse with charMaxOccur is remain same when 
we reduce the window frame using start++. But What if the charMaxOccur
is the reduce character occurance why we don't need to maintain 
charMaxOccur when we reduce frame ?

See,  

BBBBAAACCCC, k = 3| BBBBAAACCCC  

Answer can be -> BBBBAAA | AAACCCC 

-BBBBAAA (A = 3, B = 4, C = 0, max = 4, len = 7)
-BBBBAAAC (A = 3, B = 4, C = 1, max = 4, len = 7) (violate)
    BBBAAAC
- BBBAAACC (A = 3, B = 3, C = 2, max=4 , len = 7) (violate)
    BBAAACC
- BBAAACCC (A = 3, B = 2, C = 3, max=4, len = 7) (violate)
    BAAACCC
- BAAACCCC(A = 3, B = 1, C = 4, max = 4, len = 7) (violate)
    AAACCCC

- Conclusion Until further char occurance is not become max Until last max not decreasing is not
going to change result.

One more C.

- AAACCCCC (A = 3, B = 0, C = 5, max = 5, len = 8)
    result = AAACCCC (len = 8)

That's why not decreasing or checking for maxOccurace while shrink the windows is still valid.
*/

/*
==============================> Edge Case <=============================================

*/


class Solution {
public:

    int characterReplacement(string s, int k) {

        int n = s.size();
        int charMaxOccur = 0, maxLength = 0, start = 0;

        int count[26] = {0};

        for(int end = 0; end < n; end++) {

            count[s[end] - 'A']++;
            charMaxOccur = max(charMaxOccur, count[s[end]-'A']);

            if(end - start + 1 - charMaxOccur > k) {
                count[s[start]-'A']--;
                start++;
                
                charMaxOccur = 0;
                for(int i = 0; i < 26; i++) {
                    charMaxOccur = max(charMaxOccur, count[i]);
                }
            }

            maxLength = max(end-start+1, maxLength);
        }

        return maxLength;
    }


    // Same with above one.
    int characterReplacement(string s, int k) {

        int n = s.size();
        int charMaxOccur = 0, maxLength = 0, start = 0;

        int count[26] = {0};

        for(int end = 0; end < n; end++) {

            count[s[end] - 'A']++;
            charMaxOccur = max(charMaxOccur, count[s[end]-'A']);

            if(end - start + 1 - charMaxOccur > k) {
                count[s[start]-'A']--;
                start++;
            }

            maxLength = max(end-start+1, maxLength);
        }

        return maxLength;
    }
};