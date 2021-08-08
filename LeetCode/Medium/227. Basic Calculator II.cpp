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

Question : 227. Basic Calculator II
Topic : String
Problems : https://leetcode.com/problems/basic-calculator-ii/
/*
==============================> Explanation <=============================================
We keep track of last sign. If last sign is * || / then we direct perform the opreation.
But if it is + or - then we add the element with this sign. So at last when 
we traverse the all the string we perform only addition opreation bcz all opreation
is already performed.
*/


/*
==============================> Edge Case <=============================================


*/

class Solution {
public:

    bool isSpace(char ch) {
        return ch == ' ';
    }

    bool isOpreator(char ch) {
        if(ch == '+' || ch == '-' || ch == '*' || ch == '/')
            return true;
        return false;
    }

    bool isDigit(char ch) {
        if(ch >= '0' && ch <= '9')
            return true;
        return false;
    }

    int calculate(string s) {

        stack<ll> st;
        ll tmp = 0LL;
        char sign = '+';

        for(int i = 0; i < s.size(); i++) {

            if(isDigit(s[i])) {
                tmp = tmp * 10 + s[i] - '0';
            }
           
            if((!isSpace(s[i]) && !isDigit(s[i])) || i == s.size() - 1) {
                if(sign == '-') {
                    st.push(-tmp);
                }
                else if(sign == '+') {
                    st.push(tmp);
                }
                else {
                    int num;
                    if(sign == '*') {
                        num = st.top() * tmp;
                    }
                    else {
                        num = st.top() / tmp;
                    }
                    st.pop();
                    st.push(num);
                }
                sign = s[i];
                tmp = 0;
            }
        }

        ll ans = 0;
        while(!st.empty()) {
            ans += st.top();
            st.pop();
        }

        return (int)ans;

    }


    // My solution Not look good. Accepted.
    int calculate(string s) {

        stack<ll> st;
        stack<char> opreator;
        ll tmp = 0LL;

        for(int i = 0; i < s.size(); i++) {

            if(isDigit(s[i])) {
                tmp = tmp * 10 + s[i] - '0';
            }
            else if(isSpace(s[i])) continue;
            else {
                if(isOpreator(s[i])) {

                    if(!opreator.empty()) {
                        char ch = opreator.top(); opreator.pop(); 
                        if(ch == '*') {
                            int topnum = st.top(); st.pop();
                            st.push(topnum * tmp);  
                        }
                        if(ch == '/') {
                            int topnum = st.top(); st.pop();
                            st.push(topnum / tmp);
                        }
                        if(ch == '-') {
                            st.push(-tmp);
                        }
                        if(ch == '+')
                            st.push(tmp);
                    }
                    else {
                        st.push(tmp);
                    }
                    opreator.push(s[i]);
                    tmp = 0;
                }
            }
        }

        if(!opreator.empty()) {
            char op = opreator.top(); opreator.pop();
            if(ch == '*') {
                int topnum = st.top(); st.pop();
                st.push(topnum * tmp);
            }
            else if(ch == '/') {
                int topnum = st.top(); st.pop();
                st.push(topnum / tmp);
            }
            else if(ch == '-') {
                st.push(-tmp);
            }
            else {
                st.push(tmp);
            }
        }
        else {
            st.push(tmp);
        }

        int ans = 0;
        while(!st.empty()) {
            ans += st.top();
            st.pop();
        }
        return (int)ans;
    }


};