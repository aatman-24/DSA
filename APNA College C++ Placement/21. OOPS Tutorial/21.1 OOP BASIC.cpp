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

Series : OOP
Question : 21.1 OOP BASIC
Topic : 
// Problems :
*/



class student {

public:

	string name;
	int age;

	student() {
		cout << "This is Default Constructor" << endl;
		name = "Aatman";
		age = 21;
	}

	student(string name, int age) {
		cout << "This is patemetereized cosntructor" << endl;
		this->name = name;
		this->age = age;
	}

	student(student &a) {
		cout << "This is Copy Constructor " << endl;
		name = a.name;
		age = a.age;
	}

	bool operator == (student &a) {
		return name == a.name && age == a.age;
	}
};


int main() {

	student a;
	student b("Hasti", 15);

	cout << b.name <<  ' ' << b.age << endl;
	student c = b;


	if(a == c) {
		cout << "Same " << endl;
	}
	else {
		cout << "Not same" << endl;
	}


	return 0;
}

