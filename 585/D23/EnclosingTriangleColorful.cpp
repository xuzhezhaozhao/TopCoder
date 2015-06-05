#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <climits>
#include <cmath>

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

/************** Program  Begin *********************/

struct rec {
	int x;
	int y;
};

const int MaxN = 50;
static rec p[MaxN];

void rotate(int m)
{
	for (int i = 0; i < MaxN; i++) {
		int temp = p[i].x;
		p[i].x = m - p[i].y;
		p[i].y = temp;
	}
}

int cacl(int m, int n)
{
	int ans = 0;
	for (int j = 1; j < m; j++) {
		int first = 0;
		int two = 0;
		for (int u = 1; u < n; u++) {
			if ( (p[u].y - j) * p[first].x > (p[first].y - j) * p[u].x ) {
				first = u;
			}
			if ( (p[u].y - j) * p[two].x < (p[two].y - j) * p[u].x ) {
				two = u;
			}
		}
		for (int k = 1; k < m; k++) {
			int three = 0;
			for (int u = 1; u < n; u++) {
				if ( (k-p[u].y)*(m-p[three].x) < (k-p[three].y)*(m-p[u].x) ) {
					three = u;
				}
			}
			for (int i = 1; i < m; i++) {
				if ( 
				(m-j)*p[first].x < (p[first].y-j)*i ||
				(k-j)*p[two].x > (p[two].y-j)*m || 
				(k-m)*(m-p[three].x) > (k-p[three].y)*(m-i) 
				) {
					continue;
				}
				++ans;
			}
		}
	}
	return ans;
}

class EnclosingTriangleColorful {
public:
	int getNumber(int m, vector <int> x, vector <int> y);
};

int EnclosingTriangleColorful::getNumber(int m, vector<int> x, vector<int> y)
{
	int ans = 0;
	int n = x.size();
	for (int i = 0; i < n; i++) {
		p[i].x = x[i];
		p[i].y = y[i];
	}
	for (int i = 0; i < 4; i++) {
		ans += cacl(m, n);
		rotate(m);
	}
	return ans;
}

/************** Program End ************************/

// BEGIN CUT HERE
void main( int argc, char* argv[] ) {
	{
		int xARRAY[] = { 1, 2, 3 };
		vector <int> x( xARRAY, xARRAY+ARRSIZE(xARRAY) );
		int yARRAY[] = { 1, 3, 2 };
		vector <int> y( yARRAY, yARRAY+ARRSIZE(yARRAY) );
		EnclosingTriangleColorful theObject;
		eq(0, theObject.getNumber(4, x, y),8);
	}
	{
		int xARRAY[] = { 1, 1, 6, 6 };
		vector <int> x( xARRAY, xARRAY+ARRSIZE(xARRAY) );
		int yARRAY[] = { 1, 6, 1, 6 };
		vector <int> y( yARRAY, yARRAY+ARRSIZE(yARRAY) );
		EnclosingTriangleColorful theObject;
		eq(1, theObject.getNumber(7, x, y),0);
	}
	{
		int xARRAY[] = { 2 };
		vector <int> x( xARRAY, xARRAY+ARRSIZE(xARRAY) );
		int yARRAY[] = { 2 };
		vector <int> y( yARRAY, yARRAY+ARRSIZE(yARRAY) );
		EnclosingTriangleColorful theObject;
		eq(2, theObject.getNumber(4, x, y),72);
	}
	{
		int xARRAY[] = { 2, 6, 7, 6 };
		vector <int> x( xARRAY, xARRAY+ARRSIZE(xARRAY) );
		int yARRAY[] = { 7, 7, 9, 3 };
		vector <int> y( yARRAY, yARRAY+ARRSIZE(yARRAY) );
		EnclosingTriangleColorful theObject;
		eq(3, theObject.getNumber(10, x, y),52);
	}
	{
		int xARRAY[] = { 7, 6, 5, 4, 3 };
		vector <int> x( xARRAY, xARRAY+ARRSIZE(xARRAY) );
		int yARRAY[] = { 1, 4, 7, 10, 13 };
		vector <int> y( yARRAY, yARRAY+ARRSIZE(yARRAY) );
		EnclosingTriangleColorful theObject;
		eq(4, theObject.getNumber(15, x, y),150);
	}
	{
		int xARRAY[] = { 117, 183, 181, 118, 132, 128, 184, 150, 168, 121, 
			179, 132, 168, 182, 119, 117, 180, 120, 175, 177, 
			116, 175, 128, 163, 181, 178, 123, 118, 172, 143, 
			163, 157, 179, 122, 121, 119, 157, 122, 150, 180, 
			137, 177, 125, 123, 172, 125, 137, 143, 120, 178 }
		;
		vector <int> x( xARRAY, xARRAY+ARRSIZE(xARRAY) );
		int yARRAY[] = { 157, 157, 132, 163, 181, 180, 150, 116, 181, 125, 
			125, 119, 119, 163, 132, 143, 172, 172, 179, 178, 
			150, 121, 120, 118, 168, 123, 178, 137, 120, 117, 
			182, 117, 175, 177, 175, 168, 183, 123, 184, 128, 
			118, 122, 179, 122, 180, 121, 182, 183, 128, 177 }
		;
		vector <int> y( yARRAY, yARRAY+ARRSIZE(yARRAY) );
		EnclosingTriangleColorful theObject;
		eq(5, theObject.getNumber(300, x, y),21690886);
	}
}
// END CUT HERE