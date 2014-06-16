#include <algorithm>
#include <iostream>
#include <sstream>

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

/*************** Program Begin **********************/

class TheExperimentDiv2 {
public:
    vector <int> determineHumidity(vector <int> intensity, int L, vector <int> leftEnd) {
	vector <int> res;
	int M = leftEnd.size();
	bool absorbed[50];
	memset(absorbed, 0, sizeof(absorbed));

	for (int i = 0; i < M; i++) {
		int sum = 0;
		for (int j = leftEnd[i]; j < leftEnd[i] + L; j++) {
			if (!absorbed[j]) {
				absorbed[j] = true;
				sum += intensity[j];
			}
		}
		res.push_back(sum);
	}

	return res;
    }

};

/************** Program End ************************/

// BEGIN CUT HERE
void main( int argc, char* argv[] ) {
    {
	int intensityARRAY[] = {3, 4, 1, 1, 5, 6};
	vector <int> intensity( intensityARRAY, intensityARRAY+ARRSIZE(intensityARRAY) );
	int leftEndARRAY[] = {3, 1, 0};
	vector <int> leftEnd( leftEndARRAY, leftEndARRAY+ARRSIZE(leftEndARRAY) );
	int retrunValueARRAY[] = {12, 5, 3 };
	vector <int> retrunValue( retrunValueARRAY, retrunValueARRAY+ARRSIZE(retrunValueARRAY) );
	TheExperimentDiv2 theObject;
	eq(0, theObject.determineHumidity(intensity, 3, leftEnd),retrunValue);
    }
    {
	int intensityARRAY[] = {5, 5};
	vector <int> intensity( intensityARRAY, intensityARRAY+ARRSIZE(intensityARRAY) );
	int leftEndARRAY[] = {0, 0};
	vector <int> leftEnd( leftEndARRAY, leftEndARRAY+ARRSIZE(leftEndARRAY) );
	int retrunValueARRAY[] = {10, 0 };
	vector <int> retrunValue( retrunValueARRAY, retrunValueARRAY+ARRSIZE(retrunValueARRAY) );
	TheExperimentDiv2 theObject;
	eq(1, theObject.determineHumidity(intensity, 2, leftEnd),retrunValue);
    }
    {
	int intensityARRAY[] = {92, 11, 1000, 14, 3};
	vector <int> intensity( intensityARRAY, intensityARRAY+ARRSIZE(intensityARRAY) );
	int leftEndARRAY[] = {0, 3};
	vector <int> leftEnd( leftEndARRAY, leftEndARRAY+ARRSIZE(leftEndARRAY) );
	int retrunValueARRAY[] = {103, 17 };
	vector <int> retrunValue( retrunValueARRAY, retrunValueARRAY+ARRSIZE(retrunValueARRAY) );
	TheExperimentDiv2 theObject;
	eq(2, theObject.determineHumidity(intensity, 2, leftEnd),retrunValue);
    }
    {
	int intensityARRAY[] = {2, 6, 15, 10, 8, 11, 99, 2, 4, 4, 4, 13};
	vector <int> intensity( intensityARRAY, intensityARRAY+ARRSIZE(intensityARRAY) );
	int leftEndARRAY[] = {1, 7, 4, 5, 8, 0};
	vector <int> leftEnd( leftEndARRAY, leftEndARRAY+ARRSIZE(leftEndARRAY) );
	int retrunValueARRAY[] = {39, 14, 110, 0, 13, 2 };
	vector <int> retrunValue( retrunValueARRAY, retrunValueARRAY+ARRSIZE(retrunValueARRAY) );
	TheExperimentDiv2 theObject;
	eq(3, theObject.determineHumidity(intensity, 4, leftEnd),retrunValue);
    }
}
// END CUT HERE
