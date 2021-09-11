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

Question : 21.4 Polymorphism in Object Oriented Programming
Topic : 
// Problems :
*/

// function overloading

class A {
public:
	void func() {
		cout << "I am function with no arguments" << endl;
	}
	void func(int x) {
		cout << "I am function with INT arguments" << endl;
	}
	void func(double x) {
		cout << "I am function with Double arguments" << endl;
	}
};


// Opreator overloading
class Complex {
private:
	int real, img;
public:

	Complex() {
		real = 0;
		img = 0;
	}

	Complex(int r, int t) {
		real = r;
		img = t;
	}

	Complex operator + (Complex const &obj) {
		Complex res;
		res.img = img + obj.img;
		res.real = real + obj.real;
		return res;
	}

	void display() {
		cout << real << '+' << img << 'i' << endl;
	}
};



// Virtual Function
class base {
public:
	virtual void print() {
		cout << "BASE Class : print is invoked" << endl;
	}
	void display() {
		cout << "BASE Class: display is invoked" << endl;
	}
};


class derived : public base {
public:
	void print() {
		cout << "DERIVED Class: print is invoked" << endl;
	}
	void display() {
		cout << "DERIVED Class: display is invoked" << endl;
	}
};

// METHOD IN WHICH VIRTUAL IS ATTACHED THAT IS NOT CALLED BUT SUBCLASS METHOD IS INVOKED.


int main() {

	// A obj;
	// obj.func();
	// obj.func(3);
	// obj.func(3.3);


	// Complex c1(12,7), c2(6,7);
	// Complex c3 = c1 + c2;
	// c3.display();

	base *baseptr;
	derived d;
	baseptr = &d;

	baseptr->print();
	baseptr->display();


	return 0;

}

