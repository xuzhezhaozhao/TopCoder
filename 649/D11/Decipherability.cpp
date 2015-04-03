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

class Decipherability {
public:
    string check(string s, int K) {
		string certain = "Certain";
		string uncertain = "Uncertain";
		int N = s.size();
		if (N == K) {
			return certain;
		}

		for (int pos = 0; pos < N - K; pos++) {
			if (duplicateChar(s.substr(pos, K + 1))) {
				return uncertain;
			}
		}
		return certain;
    }

	bool duplicateChar(string s) {
		int count[26] = {0};
		for (char c : s) {
			int index = c - 'a';
			++count[index];
			if (count[index] > 1) {
				return true;
			}
		}
		return false;
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
        Decipherability theObject;
        eq(0, theObject.check("snuke", 2),"Certain");
    }
    {
        Decipherability theObject;
        eq(1, theObject.check("aba", 1),"Certain");
    }
    {
        Decipherability theObject;
        eq(2, theObject.check("aba", 2),"Uncertain");
    }
    {
        Decipherability theObject;
        eq(3, theObject.check("abcdabcd", 3),"Certain");
    }
    {
        Decipherability theObject;
        eq(4, theObject.check("koukyoukoukokukikou", 2),"Uncertain");
    }
    {
        Decipherability theObject;
        eq(5, theObject.check("wolfsothe", 8),"Uncertain");
    }
    {
        Decipherability theObject;
        eq(6, theObject.check("aa", 2),"Certain");
    }
	return 0;
}
// END CUT HERE
