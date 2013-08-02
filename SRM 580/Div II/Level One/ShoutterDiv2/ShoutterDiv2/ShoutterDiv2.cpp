#include <algorithm>
#include <numeric>
#include <iterator>
#include <functional>

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

class ShoutterDiv2 {
public:
    int count(vector <int> s, vector <int> t) {
	int res = 0;
	for (int i = 0; i < s.size() - 1; i++) {
		for (int j = i + 1; j < s.size(); j++) {
			if (t[i] >= s[j] && t[j] >= s[i]) {
				++res;
			}
		}
	}
	return res;
    }

};

/************** Program End ************************/

// BEGIN CUT HERE
void main( int argc, char* argv[] ) {
    {
	int sARRAY[] = {1, 2, 4};
	vector <int> s( sARRAY, sARRAY+ARRSIZE(sARRAY) );
	int tARRAY[] = {3, 4, 6};
	vector <int> t( tARRAY, tARRAY+ARRSIZE(tARRAY) );
	ShoutterDiv2 theObject;
	eq(0, theObject.count(s, t),2);
    }
    {
	int sARRAY[] = {0};
	vector <int> s( sARRAY, sARRAY+ARRSIZE(sARRAY) );
	int tARRAY[] = {100};
	vector <int> t( tARRAY, tARRAY+ARRSIZE(tARRAY) );
	ShoutterDiv2 theObject;
	eq(1, theObject.count(s, t),0);
    }
    {
	int sARRAY[] = {0,0,0};
	vector <int> s( sARRAY, sARRAY+ARRSIZE(sARRAY) );
	int tARRAY[] = {1,1,1};
	vector <int> t( tARRAY, tARRAY+ARRSIZE(tARRAY) );
	ShoutterDiv2 theObject;
	eq(2, theObject.count(s, t),3);
    }
    {
	int sARRAY[] = {9,26,8,35,3,58,91,24,10,26,22,18,15,12,15,27,15,60,76,19,12,16,37,35,25,4,22,47,65,3,2,23,26,33,7,11,34,74,67,32,15,45,20,53,60,25,74,13,44,51};
	vector <int> s( sARRAY, sARRAY+ARRSIZE(sARRAY) );
	int tARRAY[] = {26,62,80,80,52,83,100,71,20,73,23,32,80,37,34,55,51,86,97,89,17,81,74,94,79,85,77,97,87,8,70,46,58,70,97,35,80,76,82,80,19,56,65,62,80,49,79,28,75,78};
	vector <int> t( tARRAY, tARRAY+ARRSIZE(tARRAY) );
	ShoutterDiv2 theObject;
	eq(3, theObject.count(s, t),830);
    }
}
// END CUT HERE
