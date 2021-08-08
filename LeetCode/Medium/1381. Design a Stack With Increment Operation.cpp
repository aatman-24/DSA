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

Question : 1381. Design a Stack With Increment Operation
Topic : Stack
Problems : https://leetcode.com/problems/design-a-stack-with-increment-operation/
*/


/*
==============================> Edge Case <=============================================


*/


/*
==============================> Explanation <=============================================

*/


class CustomStack {
public:
    int* arr;
    int top, size, maxsize;
    
    CustomStack(int maxSize) {
        top = -1;
        arr = new int[maxSize];
        size = 0;
        maxsize = maxSize;
    }
    
    void push(int x) {
        if(size != maxsize) {
            top++;
            arr[top] = x;
            size++;
        }
    }
    
    int pop() {
        if(size != 0) {
            top--;
            size--;
            return arr[top+1];
        }
        return -1;
    }
    
    void increment(int k, int val) {
        if(size < k) {
            for(int i = 0; i < size; i++) {
                arr[i] += val;
            }
        }
        else {
            for(int i = 0; i < k; i++) {
                arr[i] += val;
            }
        }
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */