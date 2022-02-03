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

Question : 93. Restore IP Addresses
Topic : String, Backtracking
Problems : https://leetcode.com/problems/restore-ip-addresses/

==============================> Explanation <=============================================
1st approach: Proper Backtracking...
- But in this apporach too many invalid case occur..example(if s size is more than 3, for all that case it is invalid and checked.)

2nd Approach:
- We know all the group length is either [1,2,3] so we allow the group into specific range. And then check the validity...

==============================> Apporach and Time Complexity <=============================================

1) Backtracking
Time: O(2^N)
Space: O(1)


*/
class Solution {

    public:

    vector<vector<string>> store;

    bool isValid(string s) {
        
        // s should be [0, 255].
        if(s.size() <= 0 || s.size() > 3)
            return false;

        // first character should not be zero.
        if(s.size() > 1 && s[0] == '0')
            return false;
        
        int num = stoi(s);

        return num >= 0 & num <= 255;
    }


    void backtrack(string s, int n, vector<string> &temp) {

        // base case.
        if(n == 0) {
            
            // remaining string is valid, temp contain three valid values.
            if(isValid(s) && temp.size() == 3) {
                temp.push_back(s);
                store.push_back(temp);
                temp.pop_back();
            }
            
            return;
        }

        for(int i = 0; i < s.size(); i++) {
            if(isValid(s.substr(0, i))) {
                temp.push_back(s.substr(0, i));
                backtrack(s.substr(i, s.size()), n-1, temp);
                temp.pop_back();
            }
        }
    }

    vector<string> restoreIpAddresses(string s) {
        
        vector<string> temp;
        int N = 3;

        backtrack(s, N, temp);
        
        vector<string> answer;
        for(int i = 0; i < store.size(); i++) {
            string ip ="";
            for(int j = 0; j < store[i].size(); j++) {
                if(j != store[i].size() - 1) 
                    ip += store[i][j] + '.';
                else
                    ip += store[i][j];
            }
            answer.push_back(ip);
        }

        return answer;
    }

};




// optimized apporach.
class Solution {

public:
    vector<string> restoreIpAddresses(string s) {

        vector<string> ret;

        string ans;
        
        // length of first group.
        for (int a=1; a<=3; a++) {
            
            // second group length
            for (int b=1; b<=3; b++) {
                    
                // third group
                for (int c=1; c<=3; c++) {
                    
                    // fourt group.
                   for (int d=1; d<=3; d++) {
                        
                        if (a+b+c+d == s.length()) {

                            int A = stoi(s.substr(0, a));
                            int B = stoi(s.substr(a, b));
                            int C = stoi(s.substr(a+b, c));
                            int D = stoi(s.substr(a+b+c, d));

                            if (A<=255 && B<=255 && C<=255 && D<=255)
                                
                                if ( (ans=to_string(A)+"."+to_string(B)+"."+to_string(C)+"."+to_string(D)).length() == s.length()+3)
                                    ret.push_back(ans);
                        }  
                    }  
                }
                   
            }
              
        }
            
        
        return ret;
    }
};

   
