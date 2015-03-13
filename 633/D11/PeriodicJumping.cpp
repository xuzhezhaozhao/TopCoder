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

#define CHECKTIME() printf("%.2lf\n", (double)clock() / CLOCKS_PER_SEC)
typedef pair<int, int> pii;
#define mkp make_pair

/*************** Program Begin **********************/

class PeriodicJumping {
public:
	int minimalTime(int x, vector <int> jumpLengths) {
		long long res = 0;
		int N = jumpLengths.size();
		long long T = 0;

		for (auto x : jumpLengths) {
			T += x;
		}

		x = (x > 0 ? x : -x);
		
		long long cnt = x / T;
		cnt = max(0LL, cnt - 1LL);

		res += cnt * N;

		long long c = x - (cnt * T);
		if (0LL == c) {
			return 0;
		}
		long long sum = c;
		long long mx = c;	
		for (int i = 0; i < 2 * N; i++) {
			mx = max<long long>(mx, jumpLengths[i % N]);
			sum += jumpLengths[i % N];
			if (sum - mx >= mx) {
				return res + i + 1;
			}
		}

		return res;
	}

};

/************** Program End ************************/
// BEGIN CUT HERE
#define ARRSIZE(x) (sizeof(x)/sizeof(x[0]))
template<typename T> void print( T a ) { cerr << a; }
static void print( long long a ) { cerr << a << "L"; }
static void print( string a ) { cerr << '"' << a << '"'; }
template<typename T> void print( vector<T> a ) {
	cerr << "{";
	for ( int i = 0 ; i != a.size() ; i++ ) {
		if ( i != 0 ) cerr << ", ";
		print( a[i] );
	}
	cerr << "}" << endl;
}
template<typename T> void eq( int n, T have, T need ) {
	if ( have == need ) { cerr << "Case " << n << " passed." << endl; } 
	else {
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
		print( have ); print( need ); return;
	}
	for( int i= 0; i < have.size(); i++ ) {
		if( have[i] != need[i] ) {
			cerr << "Case " << n << " failed. Expected and returned array differ in position " << i << ".";
			print( have ); print( need ); return;
		}
	}
	cerr << "Case " << n << " passed." << endl;
}
static void eq( int n, string have, string need ) {
	if ( have == need ) { cerr << "Case " << n << " passed." << endl;
	} else {
		cerr << "Case " << n << " failed: expected ";
		print( need ); cerr << " received "; print( have );
		cerr << "." << endl;
	}
}

int main( int argc, char* argv[] ) {
	{
		int jumpLengthsARRAY[] = {1,2,3,4,5,6,7,8,9,10};
		vector <int> jumpLengths( jumpLengthsARRAY, jumpLengthsARRAY+ARRSIZE(jumpLengthsARRAY) );
		PeriodicJumping theObject;
		eq(0, theObject.minimalTime(15, jumpLengths),5);
	}
	{
		int jumpLengthsARRAY[] = {954311621, 771996165, 394202445, 337189612} ;
		vector <int> jumpLengths( jumpLengthsARRAY, jumpLengthsARRAY+ARRSIZE(jumpLengthsARRAY) );
		PeriodicJumping theObject;
		eq(1, theObject.minimalTime(-1000000000, jumpLengths),1);
	}
	{
		int jumpLengthsARRAY[] = {10};
		vector <int> jumpLengths( jumpLengthsARRAY, jumpLengthsARRAY+ARRSIZE(jumpLengthsARRAY) );
		PeriodicJumping theObject;
		eq(2, theObject.minimalTime(1, jumpLengths),2);
	}
	{
		int jumpLengthsARRAY[] = {2,3,4,500,6,7,8};
		vector <int> jumpLengths( jumpLengthsARRAY, jumpLengthsARRAY+ARRSIZE(jumpLengthsARRAY) );
		PeriodicJumping theObject;
		eq(3, theObject.minimalTime(-10, jumpLengths),11);
	}
	{
		int jumpLengthsARRAY[] = {1};
		vector <int> jumpLengths( jumpLengthsARRAY, jumpLengthsARRAY+ARRSIZE(jumpLengthsARRAY) );
		PeriodicJumping theObject;
		eq(4, theObject.minimalTime(-1000000000, jumpLengths),1000000000);
	}
	{
		int jumpLengthsARRAY[] = {19911120};
		vector <int> jumpLengths( jumpLengthsARRAY, jumpLengthsARRAY+ARRSIZE(jumpLengthsARRAY) );
		PeriodicJumping theObject;
		eq(5, theObject.minimalTime(0, jumpLengths),0);
	}
	return 0;
}
// END CUT HERE
