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

Question: 954. Array of Doubled Pairs
Topic : Hashing
Problems : https://leetcode.com/problems/array-of-doubled-pairs/

==============================> Explanation <=============================================
Ideas is clear,

- sort the array.
- make the entry into the map. <number, freq>
- Greedy Apporach,
   start from the smallest and look for the arr[i] * 2. 
   but when it is negative number,
      -8 occurs before the -4 so when arr[i] is negative we look for arr[i]/2.
   Edge case: if number right now is -5 then not possible to get divided by 2 number.
              That time we return false directly. In short if there is -5 then there should
              be -10 also which is visited first and neutral -5. But right now we encounterd
              -5 that means there is no -10.
   - Any time constraint is not valid we return false.



==============================> Apporach and Time Complexity <=============================================
1) Brute Force:
Time: O(NlogN) + O(N^2)(Make pair)
Space: O(1)


1) HashMap:
Time: O(N)
Space: O(N)

*/



class Solution {
public:

    bool canReorderDoubled(vector<int>& arr) {

       int n = arr.size();

       sort(arr.begin(), arr.end());

       map<int,int> mp;
       for(int i = 0; i < n ; i++)
            mp[arr[i]]++;

       for(int i = 0; i < n; i++) {
            
            if(mp[arr[i]] > 0) {

                mp[arr[i]]--;
                
                // Negative Odd Number. 
                if(arr[i] < 0 && abs(arr[i]) % 2) {
                    return false;
                }

                // Negative then arr[i]/2 else arr[i]*2.
                int searchFor = arr[i] < 0 ? arr[i] / 2 : 2*arr[i];

                if(mp.count(searchFor) && mp[searchFor] > 0)
                    mp[searchFor]--;
                else
                    return false;   
            }
    
       }

       return true;
    }

};