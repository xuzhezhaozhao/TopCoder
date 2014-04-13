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

class TheSwapsDivTwo {
public:
    int find(vector <int> sequence) {
	int res = 0;
	int N = sequence.size();
	if (N == 2) {
		return 1;
	}
	sort(sequence.begin(), sequence.end());
	bool flag = false;
	for (int i = 0; i < N-1; i++) {
		for (int j = i+1; j < N; j++) {
			if (sequence[i] != sequence[j]) {
				++res;
			} else {
				flag = true;
			}
		}
	}
	if (flag) {
		++res;
	}
	return res;
    }

};

/************** Program End ************************/

// BEGIN CUT HERE
void main( int argc, char* argv[] ) {
    {
	int sequenceARRAY[] = {4, 7, 4};
	vector <int> sequence( sequenceARRAY, sequenceARRAY+ARRSIZE(sequenceARRAY) );
	TheSwapsDivTwo theObject;
	eq(0, theObject.find(sequence),3);
    }
    {
	int sequenceARRAY[] = {1, 47};
	vector <int> sequence( sequenceARRAY, sequenceARRAY+ARRSIZE(sequenceARRAY) );
	TheSwapsDivTwo theObject;
	eq(1, theObject.find(sequence),1);
    }
    {
	int sequenceARRAY[] = {9, 9, 9, 9};
	vector <int> sequence( sequenceARRAY, sequenceARRAY+ARRSIZE(sequenceARRAY) );
	TheSwapsDivTwo theObject;
	eq(2, theObject.find(sequence),1);
    }
    {
	int sequenceARRAY[] = {22, 16, 36, 35, 14, 9, 33, 6, 28, 12, 18, 14, 47, 46, 29, 22, 14, 17, 4, 15, 28, 6, 39, 24, 47, 37};
	vector <int> sequence( sequenceARRAY, sequenceARRAY+ARRSIZE(sequenceARRAY) );
	TheSwapsDivTwo theObject;
	eq(3, theObject.find(sequence),319);
    }
}
// END CUT HERE
