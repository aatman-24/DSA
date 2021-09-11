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

Question : 21.3 Inheritance in OOP's
Topic : 
// Problems :
*/

// 1. Single Inheritance
class A {
public:
	void fun() {
		cout << "Inherited";
	}
};

class B : public A {

};


// 2. Mutilple Inheritance
class C {
public:
	void funC() {
		cout << "Func C" << endl;
	}
};

class D {
public:
	void funD() {
		cout << "Func D" << endl;
	}

};

class E: public C, public D {
public:

};

// 3. Multilevel Inheritance

class F {
public:
	void funF() {
		cout << "Func F" << endl;
	}
};

class G : public F {
public:
	void funG() {
		cout << "Func G" << endl;
	}

};

class H: public G {
public:

};


// 4. Hybrid Inheritance
// 5. Hierarchical Inheritance

int main() {

	H e;
	e.funF();
	e.funG();

	return 0;

}

