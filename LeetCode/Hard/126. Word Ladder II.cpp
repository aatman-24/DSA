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

Question: 126. Word Ladder II
Topic : BFS, Hashing
Problems : https://leetcode.com/problems/word-ladder-ii/

==============================> Explanation <=============================================

==============================> Apporach and Time Complexity <=============================================

1) Standard BFS -> TLE:
Time: 
Space: 


2) BFS on Path:
Time: O(N^3 * logN)(Not sure) 
Space: O(N^2)

*/

class Solution {
public:

    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {

        int n = beginWord.size();
      
        unordered_map<string, string> dict;
        for(string word: wordList) {
            dict[word] = word;
        }

        if(!dict.count(endWord))
            return {};

        // level[word] -> {{,word},{, word}} store all the path which end at the word.
        unordered_map<string, vector<vector<string>>> level;
        level[beginWord] = {{beginWord}};

        // we remove all the visited word after completing the current level so don't
        // form any loop. Because A -> B -> C (Shortest) compare to A -> D -> B -> C.
        dict.erase(beginWord);

        // For the current level.
        while(!level.empty()) {

            // New Added Word into the level stored here. (Concept of BFS).
            unordered_map<string, vector<vector<string>>> newLevel;

            // Try out all the word at the current level.
            for(auto [word, paths]: level) {

                // If it is endWord return level[word].
                if(word == endWord) {
                    return level[word];
                }
                else {

                    // Otherwise each pos try each characters.
                    for(int i = 0; i < n; i++) {    

                        for(char ch = 'a'; ch <= 'z'; ch++) {

                            string nw_word = word;
                            nw_word[i] = ch;
                            
                            // If new word is in dict means it is not visited yet.
                            if(dict.count(nw_word)) {
                                
                                // The for the current word, Add the nw_word at the end
                                // of each path. And create new entry into the newLevel.
                                for(auto path: paths) {
                                    path.push_back(nw_word);
                                    newLevel[nw_word].push_back(path);
                                }  
                            }
                        }
                    }
                }
            }

            // Newly Visited word should be erease from the dict. After completing
            // the level. Means that same element can be added into the different path
            // in the same level. But after not.

            // Rat -> {'Cat, Rat'}
            // Pat -> {'Cat, Pat'}

            // then, Vat Should be added into the both,

            // Rat -> 'Cat, Rat, Vat'
            // Pat -> 'Cat, Pat, Vat'

            // And Vat -> {'Cat, Rat, Vat', 'Cat, Pat, Vat'}.

            for(auto [word, _]: newLevel) {
                dict.erase(word);
            }

            // Swap the newLevel with level.
            level.swap(newLevel);
        }

        return vector<vector<string>>();
    }
};








// TLE, If we try to out bfs using word.
class Solution {
public:

    bool isFound(vector<string> &arr, string &target) {
        for(auto word: arr) {
            if(word == target)
                return true;
        }
        return false;
    }

    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {

        int n = beginWord.size();
        vector<vector<string>> ans;

        unordered_map<string, string> dict;
        for(string word: wordList) {
            dict[word] = word;
        }

        if(!dict.count(endWord))
            return ans;

        queue<pair<string, vector<string>>> q;
        q.push({beginWord, {beginWord}});
 
        while(!q.empty()) {

            int size = q.size();
            bool found = false;

            for(int i = 0; i < size; i++) {

                auto [word, seq] = q.front(); q.pop();

                if(word == endWord) {
                    found = true;
                    ans.push_back(seq);
                    continue;
                }

                for(int i = 0; i < n; i++) {

                    for(char ch = 'a'; ch <= 'z'; ch++) {

                        string nw_word = word;
                        nw_word[i] = ch;

                        if(dict.count(nw_word) && !isFound(seq, nw_word)) {
                            
                            seq.push_back(nw_word);
                            
                            q.push({nw_word, seq});
                            
                            seq.pop_back();
                        }
                    }
                }
            }
    
            if(found)
                break;
        }

        return ans;
    }
};