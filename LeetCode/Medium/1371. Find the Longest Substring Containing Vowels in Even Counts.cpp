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

Question: 1371. Find the Longest Substring Containing Vowels in Even Counts
Topic : prefixSum
Problems : https://leetcode.com/problems/find-the-longest-substring-containing-vowels-in-even-counts/

==============================> Explanation <=============================================
- Remember it, using Two sum concept or prefix sum,

Vowels need to be in even state, count is not matter so that reason we use bit manipulation.

Bit Represenation:

5 4 3 2 1 0
u o i e a X(Other)

Same as prefix sum or Two sum concept, We store the current state into the map. If the same state is
reappearing second time it means that (prev, curr] If bit is toggle in state then it toggled two times
or don't toggle. In short, Even number of times vowel encounter between this two state. prev is not inclusive.

So using that logic we form the solution:

using map which store <state, i> -> i indicate at which index the state is formed.

So next time if state is found at j th index the result is (j - i).

(same as prefix sum -> a b c d e -> the result is {c, d, e} then we check e - b == target.)


Here is one edge case to handle,

when, bcbcbc this type of string is given, that time we represent this state using -> 000000
And we want that other(X) can not change this state.


So for that reason we first perform left shift and again right shift. So (1 << 0) = 1. (1 >> 1) = 0
and peforming XOR with 0 is state it self. state ^ 0 = state.

                                       a       e       i       o       u       other
"aeiou".indexOf(s.charAt(i)) + 1       1       2       3       4       5       0 (index)
1 << tmp                               2       4       8      16      32       1 (number need 0 not 1)
(1 << tmp) >> 1                        1       2       4       8      16       0
Binary                                 1      10     100    1000   10000       0


2) Here, if the other is not found then it return -1 so make it 0 we add +1. Then same logic as above.


==============================> Apporach and Time Complexity <=============================================
1) Prefix Sum + Bit Manipulation:
Time: O(N)
Space: O(1) 

2) Prefix sum with Four Matrix:
Time: O(K * M * N)
Space: O(M*N)

*/


class Solution {
public:

    int findTheLongestSubstring(string s) {


        // map the char to state(curr) index.
        unordered_map<char, int> charToIndex;
        charToIndex['a'] = 1;
        charToIndex['e'] = 2;
        charToIndex['i'] = 3;
        charToIndex['o'] = 4;
        charToIndex['u'] = 5;
     // charToIndex['Other'] = 0 

        // Store the Visited State.
        // If the same state is reappear that means between (prev, curr) state have even number of vowels. 
        // so we store <state, i> i represnt at which index this state happen.
        unordered_map<int, int> visitedState;

        // 000000 indicate no vowels is stored at -1.
        visitedState[0] = -1;

        // Keep track of state(cur) and ans.
        int ans = 0, cur = 0;

        for(int i = 0; i < s.size(); i++) {

            char ch = s[i];

            // Initial the index = 0 (Other, Not Vowel).
            int index = 0;
            if(charToIndex.count(ch)) {

                // If it is vowel overwrite the vowel index.
                index = charToIndex[ch];
            }

            // Here we calculate which bit needs to toggle for (aeiou). But for the other state should
            // be remain same.

            // Left shift give us exact which bit is needs to filp in state. But there is problem
            // suppose if index = 0(Other) (1 << 0) = 1. It means that needs to filp the 0th bit.
            // But index = 0(other) it means no change in state. So Overcome this edge case,

            // We perform one right shift after that, which ultimately divide the number by 2.
            // and again make it 0. Performing XOR with 0 is same.

            int temp = (1 << index);
            temp = temp >> 1;
            cur ^= temp;

            if(visitedState.count(cur)) {

                // For the longest we don't make any change into the visitedState.
                ans = max(ans, i - visitedState[cur]);
            }
            else {
                visitedState[cur] = i;
            }
        }

        return ans;
    }
};


    int findTheLongestSubstring(string s) {
        unordered_map<int, int> m{{0, -1}};
        int res = 0, n = s.length(), cur = 0;
        for (int i = 0; i < n; i++) {
            cur ^= 1 << string("aeiou").find(s[i]) + 1 >> 1;
            if (!m.count(cur)) m[cur] = i;
            res = max(res, i - m[cur]);
        }
        return res;
    }#include <bits/stdc++.h>
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

Question: 1371. Find the Longest Substring Containing Vowels in Even Counts
Topic : prefixSum, BitManipulation
Problems : https://leetcode.com/problems/find-the-longest-substring-containing-vowels-in-even-counts/

==============================> Explanation <=============================================
- Remember it, using Two sum concept or prefix sum,

Vowels need to be in even state, count is not matter so that reason we use bit manipulation.

Bit Represenation:

5 4 3 2 1 0
u o i e a X(Other)

Same as prefix sum or Two sum concept, We store the current state into the map. If the same state is
reappearing second time it means that (prev, curr] If bit is toggle in state then it toggled two times
or don't toggle. In short, Even number of times vowel encounter between this two state. prev is not inclusive.

So using that logic we form the solution:

using map which store <state, i> -> i indicate at which index the state is formed.

So next time if state is found at j th index the result is (j - i).

(same as prefix sum -> a b c d e -> the result is {c, d, e} then we check e - b == target.)


Here is one edge case to handle,

when, bcbcbc this type of string is given, that time we represent this state using -> 000000
And we want that other(X) can not change this state.


So for that reason we first perform left shift and again right shift. So (1 << 0) = 1. (1 >> 1) = 0
and peforming XOR with 0 is state it self. state ^ 0 = state.

                                       a       e       i       o       u       other
"aeiou".indexOf(s.charAt(i)) + 1       1       2       3       4       5       0 (index)
1 << tmp                               2       4       8      16      32       1 (number need 0 not 1)
(1 << tmp) >> 1                        1       2       4       8      16       0
Binary                                 1      10     100    1000   10000       0


2) Here, if the other is not found then it return -1 so make it 0 we add +1. Then same logic as above.


==============================> Apporach and Time Complexity <=============================================
1) Prefix Sum + Bit Manipulation:
Time: O(N)
Space: O(1) 

2) Prefix sum with Four Matrix:
Time: O(K * M * N)
Space: O(M*N)

*/


class Solution {
public:

    int findTheLongestSubstring(string s) {


        // map the char to state(curr) index.
        unordered_map<char, int> charToIndex;
        charToIndex['a'] = 1;
        charToIndex['e'] = 2;
        charToIndex['i'] = 3;
        charToIndex['o'] = 4;
        charToIndex['u'] = 5;
     // charToIndex['Other'] = 0 

        // Store the Visited State.
        // If the same state is reappear that means between (prev, curr) state have even number of vowels. 
        // so we store <state, i> i represnt at which index this state happen.
        unordered_map<int, int> visitedState;

        // 000000 indicate no vowels is stored at -1.
        visitedState[0] = -1;

        // Keep track of state(cur) and ans.
        int ans = 0, cur = 0;

        for(int i = 0; i < s.size(); i++) {

            char ch = s[i];

            // Initial the index = 0 (Other, Not Vowel).
            int index = 0;
            if(charToIndex.count(ch)) {

                // If it is vowel overwrite the vowel index.
                index = charToIndex[ch];
            }

            // Here we calculate which bit needs to toggle for (aeiou). But for the other state should
            // be remain same.

            // Left shift give us exact which bit is needs to filp in state. But there is problem
            // suppose if index = 0(Other) (1 << 0) = 1. It means that needs to filp the 0th bit.
            // But index = 0(other) it means no change in state. So Overcome this edge case,

            // We perform one right shift after that, which ultimately divide the number by 2.
            // and again make it 0. Performing XOR with 0 is same.

            int temp = (1 << index);
            temp = temp >> 1;
            cur ^= temp;

            if(visitedState.count(cur)) {

                // For the longest we don't make any change into the visitedState.
                ans = max(ans, i - visitedState[cur]);
            }
            else {
                visitedState[cur] = i;
            }
        }

        return ans;
    }
};


    int findTheLongestSubstring(string s) {
        unordered_map<int, int> m{{0, -1}};
        int res = 0, n = s.length(), cur = 0;
        for (int i = 0; i < n; i++) {
            cur ^= 1 << string("aeiou").find(s[i]) + 1 >> 1;
            if (!m.count(cur)) m[cur] = i;
            res = max(res, i - m[cur]);
        }
        return res;
    }