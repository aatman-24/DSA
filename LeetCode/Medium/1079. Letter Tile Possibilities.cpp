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

Question: 1079. Letter Tile Possibilities
Topic : Backtracking
Problems :  https://leetcode.com/problems/letter-tile-possibilities/

==============================> Explanation <=============================================
1) First Method is to generate the permutation of string but we should avoid duplicate permutation for that
reason set is used which only allow the unique permuataion.

2) Second Method Which is used DFS + Backtracking is more accurate for this problem. Here we don't need
actual substring but only the count. So How we peform DFS ?

- Answer is we are going to visit the alphabets once at a time if freq[i] > 0. 
For the current alphabets we add ans = 1. Now we try to make other combination for the remaining characters
with prefix of current alphabets ans += other combinations.


Ex...

Use Pen and Papper you understand.

A -> A -> B   A, AA, AAB
     B -> A   AB, ABA

B -> A -> A   B, BA, BAA

==============================> Apporach and Time Complexity <=============================================

1) Permutation:
Time:O(N * N!)
Space:O(N!)


2) DFS + Backtrack: 
Time: O(26*N) ->> (Not Sure)
Space: O(1)
*/



class Solution {
public:
    
  set<vector<char>> visited;

  void backtrack(string tiles, vector<char> &curr, vector<bool> &marked) {
      
      if(tiles.size() == curr.size())
          return;

      for(int i = 0; i < tiles.size(); i++) {

          if(marked[i] == false) {

              marked[i] = true;
              curr.push_back(tiles[i]);
              
              if(!visited.count(curr)) {
                  visited.insert(curr);
                  backtrack(tiles, curr, marked);
              }    


              marked[i] = false;
              curr.pop_back(); 
          }
      }
  }

  int numTilePossibilities(string tiles) {

      vector<bool> marked(tiles.size(), false);

      vector<char> temp;
      backtrack(tiles, temp, marked);

      return visited.size();
  }




class Solution {
public:
    
    int dfs(int count[]) {

        int ans = 0;

        for(int i = 0; i < 26; i++) {

            if(count[i] > 0) {

                count[i]--;

                // for the current single [Ch]
                ans++;

                // Add the current [Ch + "Combination of Remaining character"]
                ans += dfs(count);

                // backtrack.
                count[i]++;
            }

        }

        return ans;
    }


    int numTilePossibilities(string tiles) {

        int count[26] = {0};
        for(char ch: tiles) {
            count[ch-'A']++;
        }

        return dfs(count);
    }
};