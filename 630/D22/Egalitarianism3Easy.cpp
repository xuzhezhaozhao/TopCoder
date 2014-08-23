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
typedef pair<int, int> pii;
typedef long long llong;
typedef pair<llong, llong> pll;
#define mkp make_pair

/*************** Program Begin **********************/
int D[20][20];
class Egalitarianism3Easy {
public:
	int N, res;
	int backtrack(int p, vector<int> S)
	{
		if (p == N) {
			// check S
			if (S.size() < 2) {
				return 0;
			}
			int d = D[ S[0] ][ S[1] ];
			bool ok = true;
			for (int i = 0; i < S.size(); i++) {
				for (int j = i + 1; j < S.size(); j++) {
					if (D[ S[i] ][ S[j] ] != d) {
						ok = false;
					}
				}
			}
			if (ok) {
				res = max<int>(res, S.size());
			}
			return 0;
		}
		// add p
		S.push_back(p);
		backtrack(p + 1, S);
		
		// not add p
		S.pop_back();
		backtrack(p + 1, S);
		return 0;
	}

    int maxCities(int n, vector <int> a, vector <int> b, vector <int> len) {
        res = 1;
	int sn = a.size();
	this->N = n;
	for (int i = 0; i < 20; i++) {
		for (int j = 0; j < 20; j++) {
			D[i][j] = 123456789;
		}
	}

	for (int i = 0; i < sn; i++) {
		D[ a[i] - 1 ][ b[i] - 1 ] = D[ b[i] - 1 ][ a[i] - 1 ] = len[i];
	}
	for (int i = 0; i < n; i++) {
		D[i][i] = 0;
	}

	for (int k = 0; k < n; k++) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				D[i][j] = min(D[i][j], D[i][k] + D[k][j]);
			}
		}
	}

	backtrack(0, vector<int>());

	return res;
    }

};

/************** Program End ************************/

// BEGIN CUT HERE
void main( int argc, char* argv[] ) {
    {
        int aARRAY[] = {1,1,1};
        vector <int> a( aARRAY, aARRAY+ARRSIZE(aARRAY) );
        int bARRAY[] = {2,3,4};
        vector <int> b( bARRAY, bARRAY+ARRSIZE(bARRAY) );
        int lenARRAY[] = {1,1,1};
        vector <int> len( lenARRAY, lenARRAY+ARRSIZE(lenARRAY) );
        Egalitarianism3Easy theObject;
        eq(0, theObject.maxCities(4, a, b, len),3);
    }
    {
        int aARRAY[] = {1,2,3,2,3};
        vector <int> a( aARRAY, aARRAY+ARRSIZE(aARRAY) );
        int bARRAY[] = {2,3,4,5,6};
        vector <int> b( bARRAY, bARRAY+ARRSIZE(bARRAY) );
        int lenARRAY[] = {2,1,3,2,3};
        vector <int> len( lenARRAY, lenARRAY+ARRSIZE(lenARRAY) );
        Egalitarianism3Easy theObject;
        eq(1, theObject.maxCities(6, a, b, len),3);
    }
    {
        int aARRAY[] = {1,1,1,1,1,1,1,1,1};
        vector <int> a( aARRAY, aARRAY+ARRSIZE(aARRAY) );
        int bARRAY[] = {2,3,4,5,6,7,8,9,10};
        vector <int> b( bARRAY, bARRAY+ARRSIZE(bARRAY) );
        int lenARRAY[] = {1000,1000,1000,1000,1000,1000,1000,1000,1000};
        vector <int> len( lenARRAY, lenARRAY+ARRSIZE(lenARRAY) );
        Egalitarianism3Easy theObject;
        eq(2, theObject.maxCities(10, a, b, len),9);
    }
    {
        int aARRAY[] = {1};
        vector <int> a( aARRAY, aARRAY+ARRSIZE(aARRAY) );
        int bARRAY[] = {2};
        vector <int> b( bARRAY, bARRAY+ARRSIZE(bARRAY) );
        int lenARRAY[] = {3};
        vector <int> len( lenARRAY, lenARRAY+ARRSIZE(lenARRAY) );
        Egalitarianism3Easy theObject;
        eq(3, theObject.maxCities(2, a, b, len),2);
    }
    {
        Egalitarianism3Easy theObject;
        eq(4, theObject.maxCities(1, vector <int>(), vector <int>(), vector <int>()),1);
    }
}
// END CUT HERE
