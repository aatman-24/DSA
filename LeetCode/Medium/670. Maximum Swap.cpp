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
d
/*
==============================> Description <=============================================

Question : 670. Maximum Swap
Topic : Greedy
Problems : https://leetcode.com/problems/maximum-swap/
/*
==============================> Explanation <=============================================

- Find the leftmost number which can be swapped with rightmost greater number.


Time Complexity = 9*9 = 81 
Space Complexity = 9

*/


/*
==============================> Edge Case <=============================================


*/

class Solution {
public:

    int getMaxDigit(string &number, int j) {

        // make the current digit as maximum.
        int maxIdx = j;
        for(int i = j; i < number.size(); i++) {

            // 13939 swap with rightmost digit to get greater number -> 92931
            // and also we don't swap any digit with given digit. (number[i] != number[j]) then and only we
            // allow to get change maxIdx.
            if(number[i] >= number[maxIdx] && number[i] != number[j]) {     
                maxIdx = i;
            }

        }
        return maxIdx;
    }

    int maximumSwap(int num) {

        // covert to the string.
        string number = to_string(num);

        // We found the leftMost digit is which can be swapped with any digit which come after it which 
        // is greatest.
        for(int i = 0; i < number.size(); i++) {

            int tmp = getMaxDigit(number, i);

            // If currnet digit is not the biggest then we swap with tmp and break;
            if(tmp != i) {
                swap(number[i], number[tmp]);
                break;
            }
        }
        
        return stoi(number);                // convert string to integer.

        // stod -> convert string to double.
        // stof -> convert string to float.

    }
};