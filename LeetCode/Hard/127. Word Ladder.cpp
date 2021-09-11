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

Question: 127. Word Ladder
Topic : BFS, Hashing
Problems : https://leetcode.com/problems/word-ladder/

==============================> Explanation <=============================================
Keep track of Visited Word. Using Extra Space.

You can also remove the visited words from the dict. So don't form the loop. Check
the 126 Word Ladder II.

- Both 127 and 126 sovled diffrently.

126 -> Consider Path as BFS.
127 -> Consider Word as BFS.

==============================> Apporach and Time Complexity <=============================================

N = Word.size, M = Given Words

1) Standard BFS:
Time: O(N^26)(Combination) + O(N^26*logM)(Every Word check once time) + O(M)(Every dict word popped from queue in worst case) = O(N^26*logM).   
Space: O(M)

*/

class Solution {
public:

    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {

        int n = beginWord.size();

        unordered_map<string, string> dict, visited;
        for(string word: wordList) {
            dict[word] = word;
        }

        if(!dict.count(endWord))
            return 0;


        queue<string> q;
        q.push(beginWord);
        visited[beginWord] = beginWord;


        int level = 1;

        while(!q.empty()) {     // O(M) (For all the Words it is visited only once).

            int size = q.size();
            for(int i = 0; i < size; i++) {

                string word = q.front(); q.pop();

                if(word == endWord)
                    return level;

                for(int i = 0; i < n; i++) {        //For current word try all N^26 combination.

                    for(char ch = 'a'; ch <= 'z'; ch++) {

                        string nw_word = word;
                        nw_word[i] = ch;

                        if(dict.count(nw_word) && !visited.count(nw_word)) {
                            visited[nw_word] = nw_word;
                            q.push(nw_word);
                        }
                    }
                }
            }
            level++;
        }

        return 0;
    }
};