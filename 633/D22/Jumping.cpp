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
class Jumping {
public:
	string ableToGet(int x, int y, vector <int> jumpLengths) {
		double c = sqrt( x * x + y * y );
		double sum = (double) accumulate( jumpLengths.begin(), jumpLengths.end(), 0 );
		sum += c;
		double mx = (double)(*max_element(jumpLengths.begin(), jumpLengths.end()));
		mx = max(c, mx);
		if ( sum - mx >= mx ) {
			return "Able";
		}
		return "Not able";
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
		int jumpLengthsARRAY[] = {2, 5};
		vector <int> jumpLengths( jumpLengthsARRAY, jumpLengthsARRAY+ARRSIZE(jumpLengthsARRAY) );
		Jumping theObject;
		eq(0, theObject.ableToGet(5, 4, jumpLengths),"Able");
	}
	{
		int jumpLengthsARRAY[] = {4};
		vector <int> jumpLengths( jumpLengthsARRAY, jumpLengthsARRAY+ARRSIZE(jumpLengthsARRAY) );
		Jumping theObject;
		eq(1, theObject.ableToGet(3, 4, jumpLengths),"Not able");
	}
	{
		int jumpLengthsARRAY[] = {6};
		vector <int> jumpLengths( jumpLengthsARRAY, jumpLengthsARRAY+ARRSIZE(jumpLengthsARRAY) );
		Jumping theObject;
		eq(2, theObject.ableToGet(3, 4, jumpLengths),"Not able");
	}
	{
		int jumpLengthsARRAY[] = {100, 100};
		vector <int> jumpLengths( jumpLengthsARRAY, jumpLengthsARRAY+ARRSIZE(jumpLengthsARRAY) );
		Jumping theObject;
		eq(3, theObject.ableToGet(0, 1, jumpLengths),"Able");
	}
	{
		int jumpLengthsARRAY[] = {500};
		vector <int> jumpLengths( jumpLengthsARRAY, jumpLengthsARRAY+ARRSIZE(jumpLengthsARRAY) );
		Jumping theObject;
		eq(4, theObject.ableToGet(300, 400, jumpLengths),"Able");
	}
	{
		int jumpLengthsARRAY[] = {1,2,3,4,5,6,7,8,9,10};
		vector <int> jumpLengths( jumpLengthsARRAY, jumpLengthsARRAY+ARRSIZE(jumpLengthsARRAY) );
		Jumping theObject;
		eq(5, theObject.ableToGet(11, 12, jumpLengths),"Able");
	}
	{
		int jumpLengthsARRAY[] = {1,2,3,4,5,6,7,8,9,100};
		vector <int> jumpLengths( jumpLengthsARRAY, jumpLengthsARRAY+ARRSIZE(jumpLengthsARRAY) );
		Jumping theObject;
		eq(6, theObject.ableToGet(11, 12, jumpLengths),"Not able");
	}
	return 0;
}
// END CUT HERE
