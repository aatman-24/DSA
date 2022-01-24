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

Question : 383. Ransom Note
Topic : String
Problems : https://leetcode.com/problems/ransom-note/

==============================> Explanation <=============================================

CTCI: 1.2 Check Permuataion
https://github.com/aatman-24/Cracking-the-Coding-Interview/blob/main/1.%20Array%20and%20Strings/1.2%20Check%20Permuataion.cpp

==============================> Apporach and Time Complexity <=============================================

1) String
Time: O(N)
Space: O(1)


*/


class Solution {
public:
    
    bool canConstruct(string ransomNote, string magazine) {
        
        if(ransomNote.size() > magazine.size())
            return false;

        int arr[26] = {0};
        
        for(auto ch: magazine)
            arr[ch-'a']++;
        
        for(auto ch: ransomNote) {
            arr[ch-'a']--;
            if(arr[ch-'a'] < 0)
                return false;
        }
        
        return true;
    }
};