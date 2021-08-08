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

Question : 991. Broken Calculator
Topic : Number
Problems : https://leetcode.com/problems/broken-calculator/
*/


/*

while(y > x){
  if Y is odd then we must move to the y+1(even).
  else Y is even then we can reach y/2 and try to get y/2 optimally.\
  cnt++;
}
return x - y + cnt

proof : https://leetcode.com/problems/broken-calculator/discuss/236565/Detailed-Proof-Of-Correctness-Greedy-Algorithm

We if can get number using multiplication/divison then we first try it then and only we use
addition/substraction.


if y is even then then we need to find (cost + 1, y/2);
if y is odd  then we need to find (cost+1, y+1) bcz we can not decrement y.here
*/



class Solution {
public:
    // O(LOGN)
    int brokenCalc(int x, int y) {
        int cnt = 0;
        while(y > x) {

            if(y % 2) {
                y++;
            }
            else {
                y /=2;
            }
            cnt++;
        }
        return cnt + x - y;
    }
};