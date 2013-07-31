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

class AfraidOfEven {
public:
    vector <int> restoreProgression(vector <int> seq) {
	int size = seq.size();
	int dif, s0, s1;
	bool flag = true;
	bool ok = false;
	for (int i = 0; i < 32 && !ok; i++) {
		for (int j = 0; j < 32 && !ok; j++) {
			flag = true;
			ok = false;
			s0 = (int)pow(2.0, i) * seq[0];
			s1 = (int)pow(2.0, j) * seq[1];
			dif = s1 - s0;
			for (int k = 2; k < size; k++) {
				if ( (s0 + k * dif) % seq[k] != 0) {
					flag = false;
					break;
				}
				bool flag2 = false;
				for (int m = 0; m < 32; m++) {
					if ( (s0 + k * dif) / seq[k] == (int)pow(2.0, m) ) {
						flag2 = true;
						break;
					}
				}
				if (!flag2) {
					flag = false;
					break;
				}
			}
			if (flag) {
				ok = true;
				break;
			}
		}
	}

	for (int i = 0; i < size; i++) {
		seq[i] = s0 + i * dif;
	}

	return seq;
    }
};

/************** Program End ************************/

// BEGIN CUT HERE
void main( int argc, char* argv[] ) {
    {
	int seqARRAY[] = {1, 125, 999, 749};
	vector <int> seq( seqARRAY, seqARRAY+ARRSIZE(seqARRAY) );
	int retrunValueARRAY[] = {1, 500, 999, 1498 };
	vector <int> retrunValue( retrunValueARRAY, retrunValueARRAY+ARRSIZE(retrunValueARRAY) );
	AfraidOfEven theObject;
	eq(0, theObject.restoreProgression(seq),retrunValue);
    }
    {
	int seqARRAY[] = {9, 7, 5, 3, 1};
	vector <int> seq( seqARRAY, seqARRAY+ARRSIZE(seqARRAY) );
	int retrunValueARRAY[] = {9, 7, 5, 3, 1 };
	vector <int> retrunValue( retrunValueARRAY, retrunValueARRAY+ARRSIZE(retrunValueARRAY) );
	AfraidOfEven theObject;
	eq(1, theObject.restoreProgression(seq),retrunValue);
    }
    {
	int seqARRAY[] = {999, 999, 999, 999};
	vector <int> seq( seqARRAY, seqARRAY+ARRSIZE(seqARRAY) );
	int retrunValueARRAY[] = {999, 999, 999, 999 };
	vector <int> retrunValue( retrunValueARRAY, retrunValueARRAY+ARRSIZE(retrunValueARRAY) );
	AfraidOfEven theObject;
	eq(2, theObject.restoreProgression(seq),retrunValue);
    }
    {
	int seqARRAY[] = {7, 47, 5, 113, 73, 179, 53};
	vector <int> seq( seqARRAY, seqARRAY+ARRSIZE(seqARRAY) );
	int retrunValueARRAY[] = {14, 47, 80, 113, 146, 179, 212 };
	vector <int> retrunValue( retrunValueARRAY, retrunValueARRAY+ARRSIZE(retrunValueARRAY) );
	AfraidOfEven theObject;
	eq(3, theObject.restoreProgression(seq),retrunValue);
    }
    {
	int seqARRAY[] = {749, 999, 125, 1};
	vector <int> seq( seqARRAY, seqARRAY+ARRSIZE(seqARRAY) );
	int retrunValueARRAY[] = {1498, 999, 500, 1 };
	vector <int> retrunValue( retrunValueARRAY, retrunValueARRAY+ARRSIZE(retrunValueARRAY) );
	AfraidOfEven theObject;
	eq(4, theObject.restoreProgression(seq),retrunValue);
    }
}
// END CUT HERE
