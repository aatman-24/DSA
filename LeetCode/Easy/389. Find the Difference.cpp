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

Question : 389. Find the Difference
Topic : String, XOR
Problems : https://leetcode.com/problems/find-the-difference/

==============================> Explanation <=============================================


==============================> Apporach and Time Complexity <=============================================

1) String, XOR
Time: O(N)
Space: O(1)


*/

class Solution {

public:
    
    char findTheDifference(string s, string t) {
        
        int arr[26] = {0};
        
        for(auto ch: s)
            arr[ch-'a']++;
        
        for(auto ch: t)
            arr[ch-'a']--;
        
        char ans;
        
        for(int i = 0; i < 26; i++){
            if(arr[i]){
                ans = char(i) + 'a';
                break;
            }
        }
        
        return ans;
    }
};


class Solution {
public:
    char findTheDifference(string s, string t) {
        char r=0;
        for(char c:s) r ^=c;
        for(char c:t) r ^=c;
        return r;
    }
};