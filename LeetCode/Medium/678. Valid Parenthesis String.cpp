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

Question : 678. Valid Parenthesis String
Topic : Greedy
Problems : https://leetcode.com/problems/valid-parenthesis-string/

==============================> Explanation <=============================================

STACK solution = https://leetcode.com/problems/valid-parenthesis-string/discuss/107572/Java-using-2-stacks.-O(n)-space-and-time-complexity.
https://leetcode.com/problems/valid-parenthesis-string/discuss/543521/Java-Count-Open-Parenthesis-O(n)-time-O(1)-space-Picture-Explain
*/


/*
==============================> Edge Case <=============================================


*/

class Solution {
public:

    // Interview like solution O(N) + O(N) Used Two stack for leftBracket Index and Star Index.
    bool checkValidString(string s) {
        stack<int> leftID, starID;
        for(int i = 0; i < s.size(); i++) {

            char ch = s[i];

            if(ch == '(')
                leftID.push(i);

            else if(ch == '*')
                starID.push(i);

            else {
                // If don't have ( this or * to balance the ).
                if(leftID.empty() && starID.empty()) return false;

                // Have ( this to maintain this ).
                if(!leftID.empty())
                    leftID.pop();
                else 
                    starID.pop();       // Otherwise use * for it.
            }

        }

        // when the sequence at the last, left bracket is after the *. After performing above alogrithm.
        // **(, *(, *((


        // **(**), **(** -> This is not the case here. Because when we perform above one. Then 
        // leftID is empty because at last we pop either leftID or starID.
        // But after that type of sequence found then that is problem.

        while(!leftID.empty() && !starID.empty()) {
            if(leftID.top() > starID.top())
                return false;
            leftID.pop(); starID.pop();
        }


        return leftID.empty();
    }
    

    // O(N) + O(1)
    bool checkValidString(string s) {
        int cmin = 0, cmax = 0; // open parenthess count in range [cmin, cmax].

        for(char ch: s) {

            if(ch == '(') {
                cmin++;
                cmax++;
            }
            else if(ch == ')') {
                cmin--;
                cmax--;
            }
            else {
                cmax++; // * consider as (
                cmin--; // * consider as )
            
                // Nothing -> * consider as empty string;
            }


            if(cmax < 0) {          // This time ) close bracket is more than count of [( + *].
                return false;       // We only perform cmax-- when we encounter the ).
            }

            cmin = max(0, cmin);    // We again make the cmin to zero. Reason is that when we encounter
                                    // * that time we perform the cmin--. So when we don't need to 
                                    // add convert * to ) this that time we also perform this. So 
                                    // for this we have to make it 0 again. Only handle extra close
                                    // bracket added by *.
        }

        return cmin == 0;           // Return true if can found `openCount == 0` in range [cmin, cmax]
                                    // Case Like ((() -> cmin = 2 at last.

    }

};