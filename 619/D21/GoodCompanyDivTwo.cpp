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
#define FOREACH(it, X) for(__typeof((X).begin()) it = (X).begin(); it != (X).end(); ++it)

/*************** Program Begin **********************/

class GoodCompanyDivTwo {
public:
	int countGood(vector <int> superior, vector <int> workType) {
	int res = 0;
	int N= superior.size();
	for (int i = 0; i < N; i++) {
		set <int> s;
		s.insert(workType[i]);
		bool ok = true;
		for (int j = i + 1; j < N; j++) {
			if (superior[j] == i) {
				if (s.find(workType[j]) != s.end()) {
					ok = false;
					break;
				}
				s.insert(workType[j]);
			}
		}
		if (ok) {
			++res;	
		}
	}
		return res;
	}

};

/************** Program End ************************/

// BEGIN CUT HERE
int main( int argc, char* argv[] ) {
	{
		int superiorARRAY[] = {-1, 0};
		vector <int> superior( superiorARRAY, superiorARRAY+ARRSIZE(superiorARRAY) );
		int workTypeARRAY[] = {1, 2};
		vector <int> workType( workTypeARRAY, workTypeARRAY+ARRSIZE(workTypeARRAY) );
		GoodCompanyDivTwo theObject;
		eq(0, theObject.countGood(superior, workType),2);
	}
	{
		int superiorARRAY[] = {-1, 0};
		vector <int> superior( superiorARRAY, superiorARRAY+ARRSIZE(superiorARRAY) );
		int workTypeARRAY[] = {1, 1};
		vector <int> workType( workTypeARRAY, workTypeARRAY+ARRSIZE(workTypeARRAY) );
		GoodCompanyDivTwo theObject;
		eq(1, theObject.countGood(superior, workType),1);
	}
	{
		int superiorARRAY[] = {-1, 0, 1, 1};
		vector <int> superior( superiorARRAY, superiorARRAY+ARRSIZE(superiorARRAY) );
		int workTypeARRAY[] = {1, 4, 3, 2};
		vector <int> workType( workTypeARRAY, workTypeARRAY+ARRSIZE(workTypeARRAY) );
		GoodCompanyDivTwo theObject;
		eq(2, theObject.countGood(superior, workType),4);
	}
	{
		int superiorARRAY[] = {-1, 0, 1, 0, 0};
		vector <int> superior( superiorARRAY, superiorARRAY+ARRSIZE(superiorARRAY) );
		int workTypeARRAY[] = {3, 3, 5, 2, 2};
		vector <int> workType( workTypeARRAY, workTypeARRAY+ARRSIZE(workTypeARRAY) );
		GoodCompanyDivTwo theObject;
		eq(3, theObject.countGood(superior, workType),4);
	}
	{
		int superiorARRAY[] = {-1, 0, 1, 1, 1, 0, 2, 5};
		vector <int> superior( superiorARRAY, superiorARRAY+ARRSIZE(superiorARRAY) );
		int workTypeARRAY[] = {1, 1, 2, 3, 4, 5, 3, 3};
		vector <int> workType( workTypeARRAY, workTypeARRAY+ARRSIZE(workTypeARRAY) );
		GoodCompanyDivTwo theObject;
		eq(4, theObject.countGood(superior, workType),7);
	}
	{
		int superiorARRAY[] = {-1, 0, 0, 1, 1, 3, 0, 2, 0, 5, 2, 5, 5, 6, 1, 2, 11, 12, 10, 4, 7, 16, 10, 9, 12, 18, 15, 23, 20, 7, 4};
		vector <int> superior( superiorARRAY, superiorARRAY+ARRSIZE(superiorARRAY) );
		int workTypeARRAY[] = {4, 6, 4, 7, 7, 1, 2, 8, 1, 7, 2, 4, 2, 9, 11, 1, 10, 11, 4, 6, 11, 7, 2, 8, 9, 9, 10, 10, 9, 8, 8};
		vector <int> workType( workTypeARRAY, workTypeARRAY+ARRSIZE(workTypeARRAY) );
		GoodCompanyDivTwo theObject;
		eq(5, theObject.countGood(superior, workType),27);
	}
	return 0;
}
// END CUT HERE
