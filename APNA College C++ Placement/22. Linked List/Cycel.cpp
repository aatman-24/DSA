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

Question : 22.5 Detection and Removal of Cycle in Linked List
Topic : 
// Problems :
*/

void makeCycle(node* &head, int pos) {
	node* temp = head;
	node* startNode;

	int count = 1;
	while(temp -> next != NULL) {

		if(count == pos) {
			startNode = temp;
		}

		count++;
		temp = temp -> next;
	}

	temp -> next = startNode;
}


bool detectCycle(node* &head) {

	node* slow = head;
	node* fast = head;

	while(fast != NULL && fast->next->next != NULL) {
		slow = slow -> next;
		fast = fast -> next -> next;

		if(fast == slow) {
			return true;
		}
	}

	return false;

}

void removeCycle(node* &head) {
	
}



int main() {
}