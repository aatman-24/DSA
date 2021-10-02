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

Question: 1415. The k-th Lexicographical String of All Happy Strings of Length n
Topic : String, Same Sized Step(Rank), BFS
Problems : https://leetcode.com/problems/the-k-th-lexicographical-string-of-all-happy-strings-of-length-n/

==============================> Explanation <=============================================


2) This type of question is already solved previous...

If we need N length string using {a, b, c} then,

- Starting with each char have (2^N-1) Occurance. We use this logic...

N = 3, K = 8.

aba
abc
aca
acb
bab
bac
bca
bcb ->>>>>(Ans)
cab
cac
cba
cbc

In Lexographical order is need to maintain and no same char have are placed together.


K = 8(1's order) K = 7 (0's order)
rank = K / 2^(N-1) = 7 / 4 = 1. choice = abc.
So first char is b.

For b we can use next char -> {a, c}
K = K % (2^(N-1)) = 7 % 4 = 3
N = 2.
rank = K / (2^(N-1)) = 3 / 2 = 1.
Next char is C.


N = 1.
K = K % (2^(N-1)) = 3 % 2 = 1.
next char -> {a, b}.
So we choose B again.

Answer is BCB.

==============================> Apporach and Time Complexity <=============================================
2) BFS:
Time:O(3*2^N-1) (Possible all that all string is generated of N length).
Space:O(3*2^N-1)

1) Rank(Step)Same size:
Time:O(N)
Space:O(1)
*/


class Solution {
public:

       string getHappyString(int n, int k) {

       queue<string> q;
       q.push("a");
       q.push("b");
       q.push("c");

       while(!q.empty()) {

          string x = q.front(); q.pop();
          
          // when size is n then we subtract k by 1.
          if(x.size() == n) {
             k--;
             if(k == 0)
                return x;
          }

          string a, b;
           
          if(x[x.size()-1] == 'a') {
             a = x + 'b';
             b = x + 'c';
          }
          else if(x[x.size()-1] == 'b') {
             a = x + 'a';
             b = x + 'c';
          }
          else {
             a = x + 'a';
             b = x + 'b';
          }

          if(a.size() <= n) {
             q.push(a);
          }

          if(b.size() <= n) {
             q.push(b);
          }

       }

       return "";

    }
};




class Solution {
public:

    string getHappyString(int n, int k) {

       string ans = "";

       if(k > 3* int(pow(2, n-1)))
          return ans;

       k--; // 0 based index.

       // map indicate that if prev char is key then next char is mp[key][index].
       // we need this one reason is that avoid same char to each other and lexo order.
       unordered_map<char, vector<char>> mp;
       mp['x'] = {'a', 'b', 'c'};
       mp['a'] = {'b', 'c'};
       mp['b'] = {'a', 'c'};
       mp['c'] = {'a', 'b'};

       // in start we have three choice for that reason.
       char prev = 'x';

       while(n > 1) {

          int index = k / pow(2, n-1);

          ans += mp[prev][index];
          prev = mp[prev][index];

          // remaining..
          k = k % int(pow(2, n-1));

          n--;
       }


       ans += mp[prev][k];

       return ans;
    }
};