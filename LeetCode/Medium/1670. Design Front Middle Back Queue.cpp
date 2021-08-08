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

Question : 1670. Design Front Middle Back Queue
Topic : Queue
Problems : https://leetcode.com/problems/design-front-middle-back-queue/
/*
==============================> Explanation <=============================================


*/


/*
==============================> Edge Case <=============================================

*/



class FrontMiddleBackQueue {

public:
    int *arr;
    int n;

    FrontMiddleBackQueue() {
        arr = new int[1001];
        n = 0;
    }
    

    void pushFront(int val) {
        for(int i = n - 1; i >= 0; i--)
            arr[i+1] = arr[i];
        arr[0] = val;
        n++;
    }
    
    void pushMiddle(int val) {
        int mid = n / 2;
        for(int i = n - 1; i >= mid; i--)
            arr[i+1] = arr[i];
        arr[mid] = val;
        n++;
    }
    
    void pushBack(int val) {
        arr[n] = val;
        n++;
    }
    
    int popFront() {
        if(n == 0)
            return -1;

        int ele = arr[0];

        for(int i = 0; i < n - 1; i++) {
            arr[i] = arr[i+1];
        }

        n--;
        return ele;
    }
    
    int popMiddle() {
        if(n == 0)
            return -1;

        int mid = (n-1) / 2;
        int ele = arr[mid];
        for(int i = mid; i < n - 1; i++) {
            arr[i] = arr[i+1];
        }
        n--;
        return ele;
    }
    
    int popBack() {
        if(n == 0)
            return -1;

        int ele = arr[n-1];
        n--;
        return ele;
    }
};


// we need to maintain size such that a.size() <= b.size() || b.size() + 1


// push_back -> b deque end a2b()
// push_middle -> a deque end a2b()
// push_front -> a deque front b2a()

// pop_back = from b 
// pop_front = from a if a empty then from b
// pop_middle = from a if (a.size == b.size) otherwise from b front.



class FrontMiddleBackQueue {
    deque<int> a, b;
    void a2b() {
        if (a.size() <= b.size()) return;
        b.push_front(a.back());
        a.pop_back();
    }
    void b2a() {
        if (b.size() <= a.size() + 1) return;
        a.push_back(b.front());
        b.pop_front();
    }
public:
    FrontMiddleBackQueue() {}

    void pushFront(int val) {
        a.push_front(val);
        a2b();
    }
    void pushMiddle(int val) {
        a.push_back(val);
        a2b();
    }
    void pushBack(int val) {
        b.push_back(val);
        b2a();
    }
    int popFront() {
        if (a.empty() && b.empty()) return -1;
        int ans;
        if (a.empty()) {
            ans = b.front();
            b.pop_front();
        } else {
            ans = a.front();
            a.pop_front();
            b2a();
        }
        return ans;
    }
    int popMiddle() {
        if (a.empty() && b.empty()) return -1;
        int ans;
        if (a.size() == b.size()) {
            ans = a.back();
            a.pop_back();
        } else {
            ans = b.front();
            b.pop_front();
        }
        return ans;
    }
    int popBack() {
        if (a.empty() && b.empty()) return -1;
        int ans = b.back();
        b.pop_back();
        a2b();
        return ans;
    }
};

/**
 * Your FrontMiddleBackQueue object will be instantiated and called as such:
 * FrontMiddleBackQueue* obj = new FrontMiddleBackQueue();
 * obj->pushFront(val);
 * obj->pushMiddle(val);
 * obj->pushBack(val);
 * int param_4 = obj->popFront();
 * int param_5 = obj->popMiddle();
 * int param_6 = obj->popBack();
 */