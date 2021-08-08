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

Question : 622. Design Circular Queue
Topic : Circular Queue
Problems : https://leetcode.com/problems/design-circular-queue/
*/

/*
==============================> Edge Case <=============================================

Enqueue:
    - if full return false;
    
Dequeue
    - if empty return false;
    - if (front == rear) means last element in queue that's why set both front,rear = -1

Empty
    - if(front == -1 && rear == -1) empty

Full
    - if(rear + 1 == front) full.

*/


/*
==============================> Explanation <=============================================

*/

class MyCircularQueue {
    
public:
    
    int front, rear, size;
    int *arr;
    
    MyCircularQueue(int k) {
        arr = new int[k];
        front = -1;
        rear = -1;
        size = k;
    }
    
    bool enQueue(int value) {
        if(isFull())
            return false;
        rear = (rear+1) % size;
        arr[rear] = value;
        if(front == -1)
            front = (front+1) % size;
        return true;
    }
    
    
    bool deQueue() {
        if(isEmpty())
            return false;
        if(front == rear){
            rear = -1;
            front = -1;   
        }
        else
            front = (front+1) % size;
        return true;
    }
    
    int Front() {
        if(isEmpty()) {
            return -1;
        }
        return arr[front];
        
    }
    
    int Rear() {
        if(isEmpty()){
            return -1;
        }
        return arr[rear];
    }
    
    bool isEmpty() {
        if(front == -1 && rear == -1)
            return true;
        if(front == -1)
            return true;
        return false;
    }
    
    bool isFull() {
        return (rear+1)%size == front;
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */