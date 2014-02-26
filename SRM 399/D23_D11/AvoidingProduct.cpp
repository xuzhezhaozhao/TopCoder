#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <iostream>
#include <sstream>
#include <iomanip>

#include <bitset>
#include <string>
#include <vector>
#include <stack>
#include <deque>
#include <queue>
#include <set>
#include <map>

#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <cmath>
#include <cstring>
#include <ctime>
#include <climits>


using namespace std;


// BEGIN CUT HERE
#define ARRSIZE(x) (sizeof(x)/sizeof(x[0]))
template<typename T> void print( T a ) {
	cerr << a;
}
static void print( long long a ) {
	cerr << a << "L";
}
static void print( string a ) {
	cerr << '"' << a << '"';
}
template<typename T> void print( vector<T> a ) {
	cerr << "{";
	for ( int i = 0 ; i != a.size() ; i++ ) {
		if ( i != 0 ) cerr << ", ";
		print( a[i] );
	}
	cerr << "}" << endl;
}
template<typename T> void eq( int n, T have, T need ) {
	if ( have == need ) {
		cerr << "Case " << n << " passed." << endl;
	} else {
		cerr << "Case " << n << " failed: expected ";
		print( need );
		cerr << " received ";
		print( have );
		cerr << "." << endl;
	}
}
template<typename T> void eq( int n, vector<T> have, vector<T> need ) {
	if( have.size() != need.size() ) {
		cerr << "Case " << n << " failed: returned " << have.size() << " elements; expected " << need.size() << " elements.";
		print( have );
		print( need );
		return;
	}
	for( int i= 0; i < have.size(); i++ ) {
		if( have[i] != need[i] ) {
			cerr << "Case " << n << " failed. Expected and returned array differ in position " << i << ".";
			print( have );
			print( need );
			return;
		}
	}
	cerr << "Case " << n << " passed." << endl;
}
static void eq( int n, string have, string need ) {
	if ( have == need ) {
		cerr << "Case " << n << " passed." << endl;
	} else {
		cerr << "Case " << n << " failed: expected ";
		print( need );
		cerr << " received ";
		print( have );
		cerr << "." << endl;
	}
}
// END CUT HERE

#define CHECKTIME() printf("%.2lf\n", (double)clock() / CLOCKS_PER_SEC)
typedef pair<int, int> pii;
typedef long long llong;
typedef pair<llong, llong> pll;
#define mkp make_pair

/*************** Program Begin **********************/
bool v[1001];
class AvoidingProduct {
public:
	inline int absi(int n) {return (n > 0 ? n : -n); }
	vector <int> getTriple(vector <int> A, int n) {
		vector <int> res;
		int x = -1, y = -1, z = -1;
		int dif = 10000000;
		memset(v, 0, sizeof(v));
		for (int i = 0; i < A.size(); i++) {
			v[ A[i] ] = true;
		}
		for (int i = 1; i <= n + 51; i++) {
			if (v[i] || dif < i - n) {
				continue;
			}
			for (int j = i; j <= n + 51; j++) {
				if (v[j] || dif < i * j - n) {
					continue;
				}
				for (int k = j; k <= n + 51; k++) {
					if (!v[k]) {
						if (absi(n - i * j * k) < dif) {
							x = i; y = j; z = k;
							dif = absi(n - i * j * k);
						}
					}
				}
			}
		}
		res.push_back(x); res.push_back(y); res.push_back(z);
		return res;
	}
};

/************** Program End ************************/

// BEGIN CUT HERE
void main( int argc, char* argv[] ) {
	{
		int aARRAY[] = {16, 1, 19, 2, 3, 4, 7, 8, 13, 47};
		vector <int> a( aARRAY, aARRAY+ARRSIZE(aARRAY) );
		int retrunValueARRAY[] = {6, 9, 9 };
		vector <int> retrunValue( retrunValueARRAY, retrunValueARRAY+ARRSIZE(retrunValueARRAY) );
		AvoidingProduct theObject;
		eq(0, theObject.getTriple(a, 470),retrunValue);
	}
	{
		int aARRAY[] = {1};
		vector <int> a( aARRAY, aARRAY+ARRSIZE(aARRAY) );
		int retrunValueARRAY[] = {2, 2, 2 };
		vector <int> retrunValue( retrunValueARRAY, retrunValueARRAY+ARRSIZE(retrunValueARRAY) );
		AvoidingProduct theObject;
		eq(1, theObject.getTriple(a, 10),retrunValue);
	}
	{
		int aARRAY[] = {1,2};
		vector <int> a( aARRAY, aARRAY+ARRSIZE(aARRAY) );
		int retrunValueARRAY[] = {3, 3, 3 };
		vector <int> retrunValue( retrunValueARRAY, retrunValueARRAY+ARRSIZE(retrunValueARRAY) );
		AvoidingProduct theObject;
		eq(2, theObject.getTriple(a, 10),retrunValue);
	}
	{
		int aARRAY[] = {1,3};
		vector <int> a( aARRAY, aARRAY+ARRSIZE(aARRAY) );
		int retrunValueARRAY[] = {2, 2, 2 };
		vector <int> retrunValue( retrunValueARRAY, retrunValueARRAY+ARRSIZE(retrunValueARRAY) );
		AvoidingProduct theObject;
		eq(3, theObject.getTriple(a, 12),retrunValue);
	}
	{
		int aARRAY[] = {1,3};
		vector <int> a( aARRAY, aARRAY+ARRSIZE(aARRAY) );
		int retrunValueARRAY[] = {2, 2, 4 };
		vector <int> retrunValue( retrunValueARRAY, retrunValueARRAY+ARRSIZE(retrunValueARRAY) );
		AvoidingProduct theObject;
		eq(4, theObject.getTriple(a, 13),retrunValue);
	}
	{
		int aARRAY[] = {1,15};
		vector <int> a( aARRAY, aARRAY+ARRSIZE(aARRAY) );
		int retrunValueARRAY[] = {2, 5, 9 };
		vector <int> retrunValue( retrunValueARRAY, retrunValueARRAY+ARRSIZE(retrunValueARRAY) );
		AvoidingProduct theObject;
		eq(5, theObject.getTriple(a, 90),retrunValue);
	}
}
// END CUT HERE
