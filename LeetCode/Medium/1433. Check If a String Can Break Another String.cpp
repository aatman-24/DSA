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

Question : 1433. Check If a String Can Break Another String
Topic : String
Problems : https://leetcode.com/problems/check-if-a-string-can-break-another-string/


*/



#define A 97


class Solution {
public:
    int arr[26], brr[26];

    // O(NlogN) - O(1)
    bool checkIfCanBreak(string s1, string s2) {

        sort(s1.begin(), s1.end());
        sort(s2.begin(), s2.end());

        int n = s1.size();
        int i = 0;

        while(i < n && s1[i] == s2[i]) i++;
        if(i == n) return true;


        if(s1[i] < s2[i]) {
            while(i < n && s1[i] <= s2[i]) i++;
            return i == n;
        }
        else {
            while(i < n && s1[i] >= s2[i]) i++;
            return i == n;
        }

    }

    // O(N) - O(1)
    bool checkIfCanBreak(string s1, string s2) {
        memset(arr, 0, sizeof(arr));
        memset(brr, 0, sizeof(brr));

        int n = s1.size();

        for(int i = 0; i < n; i++) {
            arr[s1[i] - A]++;
            brr[s2[i] - A]++;
        }

        int cnt1 = 0, cnt2 = 0;
        bool flag1 = false, flag2 = false;

        for(int i = 0; i < 26; i++) {
            cnt1 += arr[i];
            cnt2 += brr[i];

            if(cnt1 > cnt2) {
                if(flag2) return false;
                flag1 = true;
            }
            else if (cnt2 > cnt1) {
                if(flag1) return false;
                flag2 = true;
            }
        }

        return true;
    }


};