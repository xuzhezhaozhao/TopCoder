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

/*************** Program Begin **********************/
class BinPackingEasy {
public:
	int minBins(vector <int> item) {
		int res = 0;
		int n = item.size();
		sort(item.begin(), item.end());
		int i = 0, j = n - 1;
		while (i < j) {
			if (item[i] + item[j] <= 300) {
				++i; --j;
				++res;
			} else {
				--j;
				++res;
			}
		}
		if (i == j) {
			++res;
		}
		return res;
	}

};

/************** Program End ************************/

// BEGIN CUT HERE
void main( int argc, char* argv[] ) {
	{
		int itemARRAY[] = {150, 150, 150, 150, 150};
		vector <int> item( itemARRAY, itemARRAY+ARRSIZE(itemARRAY) );
		BinPackingEasy theObject;
		eq(0, theObject.minBins(item),3);
	}
	{
		int itemARRAY[] = {130, 140, 150, 160};
		vector <int> item( itemARRAY, itemARRAY+ARRSIZE(itemARRAY) );
		BinPackingEasy theObject;
		eq(1, theObject.minBins(item),2);
	}
	{
		int itemARRAY[] = {101, 101, 101, 101, 101, 101, 101, 101, 101};
		vector <int> item( itemARRAY, itemARRAY+ARRSIZE(itemARRAY) );
		BinPackingEasy theObject;
		eq(2, theObject.minBins(item),5);
	}
	{
		int itemARRAY[] = {101, 200, 101, 101, 101, 101, 200, 101, 200};
		vector <int> item( itemARRAY, itemARRAY+ARRSIZE(itemARRAY) );
		BinPackingEasy theObject;
		eq(3, theObject.minBins(item),6);
	}
	{
		int itemARRAY[] = {123, 145, 167, 213, 245, 267, 289, 132, 154, 176, 198};
		vector <int> item( itemARRAY, itemARRAY+ARRSIZE(itemARRAY) );
		BinPackingEasy theObject;
		eq(4, theObject.minBins(item),8);
	}
}
// END CUT HERE
