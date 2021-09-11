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

Question : 21.2  Encapsulation
Topic : 
// Problems :
*/




class A {

	public:
		int a;
		void funcA() {
			cout << "public is invoked" << endl;
		}
	private:
		int b;
		void funcB() {
			cout << "Private is invoked" << endl;
		}
	protected:
		int c;
		void funcC() {
			cout << "protected is invoked" << endl;
		}
};


int main() {

	A tmp;
	tmp.funcA();
	// tmp.funcB(); ERROR

	return 0;
}

