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
#include <ctime>

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

class CombinationLockDiv1 {
public:


    int minimumMoves(vector <string> P, vector <string> Q) {
	string s, t;
	vector <int> v, w;
	for (int i = 0; i < P.size(); i++) {
		s += P[i];
	}
	for (int i = 0; i < Q.size(); i++) {
		t += Q[i];
	}

	int N = s.size();
	v.resize(N);
	for (int i = 0; i < N; i++) {
		int dif = t[i] - s[i];
		if (dif < 0) {
			dif += 10;
		}
		v[i] = dif;
	}
	w.resize(N);
	for (int i = 0; i < N; i++) {
		int dif = v[i];
		if (i > 0) {
			dif = v[i] - v[i-1];
		}
		if (dif < 0) {
			dif += 10;
		}
		w[i] = dif;
	}
	w.push_back(10 - v[N-1]);
	sort(w.begin(), w.end());
	int ret = 0x7fffffff;
	for (int i = 0; i < N + 1; i++) {
		int ct1 = 0, ct2 = 0;
		for (int j = 0; j < i; j++) {
			ct1 += w[j];
		}
		for (int j = i; j < N + 1; j++) {
			ct2 += w[j] ? (10 - w[j]) : 0;
		}
		if (ct1 == ct2) {
			ret = min(ret, ct1);
		}
	}

        return ret;
    }

};


/************** Program End ************************/

// BEGIN CUT HERE
void main( int argc, char* argv[] ) {
    {
        string PARRAY[] = {"123"};
        vector <string> P( PARRAY, PARRAY+ARRSIZE(PARRAY) );
        string QARRAY[] = {"112"};
        vector <string> Q( QARRAY, QARRAY+ARRSIZE(QARRAY) );
        CombinationLockDiv1 theObject;
        eq(0, theObject.minimumMoves(P, Q),1);
    }
    {
        string PARRAY[] = {"1"};
        vector <string> P( PARRAY, PARRAY+ARRSIZE(PARRAY) );
        string QARRAY[] = {"7"};
        vector <string> Q( QARRAY, QARRAY+ARRSIZE(QARRAY) );
        CombinationLockDiv1 theObject;
        eq(1, theObject.minimumMoves(P, Q),4);
    }
    {
        string PARRAY[] = {"6","07"};
        vector <string> P( PARRAY, PARRAY+ARRSIZE(PARRAY) );
        string QARRAY[] = {"","60","7"};
        vector <string> Q( QARRAY, QARRAY+ARRSIZE(QARRAY) );
        CombinationLockDiv1 theObject;
        eq(2, theObject.minimumMoves(P, Q),0);
    }
    {
        string PARRAY[] = {"1234"};
        vector <string> P( PARRAY, PARRAY+ARRSIZE(PARRAY) );
        string QARRAY[] = {"4567"};
        vector <string> Q( QARRAY, QARRAY+ARRSIZE(QARRAY) );
        CombinationLockDiv1 theObject;
        eq(3, theObject.minimumMoves(P, Q),3);
    }
    {
        string PARRAY[] = {"020"};
        vector <string> P( PARRAY, PARRAY+ARRSIZE(PARRAY) );
        string QARRAY[] = {"909"};
        vector <string> Q( QARRAY, QARRAY+ARRSIZE(QARRAY) );
        CombinationLockDiv1 theObject;
        eq(4, theObject.minimumMoves(P, Q),2);
    }
    {
        string PARRAY[] = {"4423232218340"};
        vector <string> P( PARRAY, PARRAY+ARRSIZE(PARRAY) );
        string QARRAY[] = {"6290421476245"};
        vector <string> Q( QARRAY, QARRAY+ARRSIZE(QARRAY) );
        CombinationLockDiv1 theObject;
        eq(5, theObject.minimumMoves(P, Q),18);
    }
}
// END CUT HERE
