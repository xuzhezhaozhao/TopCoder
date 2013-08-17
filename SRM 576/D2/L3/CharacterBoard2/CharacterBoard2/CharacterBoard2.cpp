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
const int MOD = 1e9 + 9;
class CharacterBoard2 {
private:
	// Finds x raised to the y-th exponent modulo MOD
	int modPow(int x, int y)
	{
		long long res = 1, a = x;
		while (y > 0) {
			if (y & 1) {
				res = (res * a) % MOD;
			}
			a = (a * a) % MOD;
			y >>= 1;
		}
		return static_cast<int> (res);
	}
public:
    int countGenerators(vector <string> fragment, int W, int i0, int j0) {
	long long res = 0;
	int N = fragment.size();
	int M = fragment[0].size();
	string gen;
	int pos[10][10];
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			pos[i][j] = ( (i + i0) * W + (j + j0) );			
		}
	}

	for (int len = 1; len <= W; len++) {
		gen.assign(len, '#');
		bool ok = true;
		int fill = 0;

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				int index = pos[i][j] % len;
				if ('#' == gen[index]) {
					gen[index] = fragment[i][j];
					++fill;
				} else if (gen[index] != fragment[i][j]) {
					ok = false;
					break;
				}
			}
			if (!ok) {
				break;
			}
		}
		if (!ok) {
			continue;
		}
		res += modPow(26, len - fill);
		res %= MOD;
	}

	return static_cast<int> (res);
    }
};

/************** Program End ************************/

// BEGIN CUT HERE
void main( int argc, char* argv[] ) {
    {
	string fragmentARRAY[] = {"dea",
	    "abc"};
	vector <string> fragment( fragmentARRAY, fragmentARRAY+ARRSIZE(fragmentARRAY) );
	CharacterBoard2 theObject;
	eq(0, theObject.countGenerators(fragment, 7, 1, 1),1);
    }
    {
	string fragmentARRAY[] = {"xyxxy"};
	vector <string> fragment( fragmentARRAY, fragmentARRAY+ARRSIZE(fragmentARRAY) );
	CharacterBoard2 theObject;
	eq(1, theObject.countGenerators(fragment, 6, 1, 0),28);
    }
    {
	string fragmentARRAY[] = {"gogogo",
	    "jijiji",
	    "rarara"};
	vector <string> fragment( fragmentARRAY, fragmentARRAY+ARRSIZE(fragmentARRAY) );
	CharacterBoard2 theObject;
	eq(2, theObject.countGenerators(fragment, 6, 0, 0),0);
    }
    {
	string fragmentARRAY[] = {"abababacac",
	    "aaacacacbb",
	    "ccabababab"};
	vector <string> fragment( fragmentARRAY, fragmentARRAY+ARRSIZE(fragmentARRAY) );
	CharacterBoard2 theObject;
	eq(3, theObject.countGenerators(fragment, 882, 10, 62),361706985);
    }
    {
	string fragmentARRAY[] = {"asjkffqw",
	    "basjkffq",
	    "qbasjkff",
	    "qqbasjkf"};
	vector <string> fragment( fragmentARRAY, fragmentARRAY+ARRSIZE(fragmentARRAY) );
	CharacterBoard2 theObject;
	eq(4, theObject.countGenerators(fragment, 9031, 9024, 1959),173947456);
    }
}
// END CUT HERE
