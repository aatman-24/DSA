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

Question : 537. Complex Number Multiplication
Topic : String
Problems : https://leetcode.com/problems/complex-number-multiplication/
*/


#define ZERO 48

class Solution {
public:
    
    int power(int base, int n) {
        int res = 1;
        while(n) {
            if(n % 2) res *= base;
            base *= base;
            n /= 2;
        }
        return res;
    }

    // convert "123" into 123.
    int makeNumberFromString(string s, int pos) {

        int n = s.size();
        int m = n;
        int res = 0;
        while(n--) {
            res += ((int(s[m-n-1]) - ZERO) * power(10, n));
        }
        
        if(!pos) res *= -1;
        return res;
    } 


    // return a and b from (a+bi)
    void getNumberFromString(string s, int &a, int &b) {

        int n = s.size();
        int i = 0;
        bool pos = s[0] == '-' ? false : true;
        string n1 = "", n2 = "";
        while(i < n) {
            if(!pos) i++;

            while(s[i] != '+') {
                n1 += s[i];
                i++;
            }
            a = makeNumberFromString(n1, pos);


            i++;

            pos = s[i] == '-' ? false : true;
            if(!pos) i++;
            while(s[i] != 'i') {

                n2 += s[i];
                i++;
            }
            b = makeNumberFromString(n2, pos);
            break;
        }

    }

    // (a+bi) * (c+di)
    string multiplication(int a, int b, int c, int d) {
        int real = (a*c) - (b*d);
        int img = (a*d) + (b*c);
        string result = "";
        return to_string(real) + '+' + to_string(img) + 'i';
    }


    string complexNumberMultiply(string num1, string num2) {
        int a,b,c,d;
        getNumberFromString(num1, a, b);
        getNumberFromString(num2, c, d); 
        return multiplication(a,b,c,d);
    }


};