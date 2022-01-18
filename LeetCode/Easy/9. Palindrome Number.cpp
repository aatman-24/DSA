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
d
/*
==============================> Description <=============================================

Question :  9. Palindrome Number
Topic : Maths
Problems : https://leetcode.com/problems/palindrome-number/

==============================> Explanation <=============================================
- Due to limit, we can not directly got reverse number using palindrome trick here.
- We get the reverse number until the X > reverse_number. After that if X is even length then reverse_number also even length
we directly compare it.
- And if it is odd length then we compare X/10 == reverse_number.


==============================> Edge Case <=============================================
1) Maths
Time: O(10) -> Maximum 10 digit for int representation.
Space: O(1)
*/


class Solution {
public:
    bool isPalindrome(int x) {
        
        // Negative Number
        // And the number end with 0 can not be palindrome.
        if(x<0|| (x!=0 &&x%10==0)) return false;
        
        int sum=0;
        
        // Perform Until X > 0.
        while(x>sum)
        {
            sum = sum*10+x%10;
            x = x/10;
        }
        
        // if x is even length then, it must be  x == sum.
        // if x is odd length them, x == sum / 10
        return (x==sum)||(x==sum/10);
    }
};