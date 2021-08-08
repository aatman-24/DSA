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

Question : 71. Simplify Path
Topic : String
Problems : https://leetcode.com/problems/simplify-path/
/*
==============================> Explanation <=============================================
stringstream -> It make stream of string like when we take the input from
the command. Just like cin.

getline(cin, variablename, default='\n') -> we already used the 
getline function. Default it break the stream at newline. But third
parameter we can set it.

- Here we need to split the string by '/'. so we used this.


- Here we use the stack we push all the folder into the stack. but if
'.' current director we did not do anything. and when the '..' parent 
directory we pop the last folder from the stack. 
- And last make the string for the answer using the stack.
*/


/*
==============================> Edge Case <=============================================


*/

class Solution {
public:

    // O(N) - O(N)
    string simplifyPath(string path) {
        string res, tmp;
        vector<string> st;
        stringstream ss(path);

        while(getline(ss, tmp, '/')) {
            if(tmp == "" || tmp == ".") continue;
            else if(tmp != "..") st.push_back(tmp);
            else if(!st.empty()) st.pop_back();
        }

        for(auto str: st) res += "/" + str;
        return res.empty() ? "/" : res;

    }
};